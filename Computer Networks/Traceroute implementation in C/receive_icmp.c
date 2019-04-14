/* 
Adrian Kamiński 288477
*/
#include "traceroute.h"


int receive(int sockfd, int ttl,int id,int *respc, struct in_addr *addrs, int *mstime)
{
	fd_set descriptors;
	FD_ZERO (&descriptors);
	FD_SET (sockfd, &descriptors);

	int timeout=0;
	int read_one_status;
	int time=0;

	struct timeval tv; 
	tv.tv_sec = 1;	
	tv.tv_usec = 0;
	struct timespec t0, ti;

	if (clock_gettime(CLOCK_BOOTTIME,&t0)<0)
	{		
		fprintf(stderr, "clock gettime while setting t0 error: %s\n", strerror(errno)); 
		return -1;
	}
	while(*respc!=3 && timeout==0)
	{

	
		int ready = select(sockfd+1, &descriptors, NULL,NULL,&tv);
		if(ready == 1)
		{	
			struct in_addr *next_addr = addrs+*respc; 
			read_one_status = read_one(sockfd,ttl,id,next_addr);

			if(read_one_status == 1 || read_one_status == 2)
			{
				(*respc)++;
				if(clock_gettime(CLOCK_BOOTTIME,&ti)<0)
				{		
					fprintf(stderr, "clock gettime while setting ti error: %s\n", strerror(errno)); 
					return -1;
				}
				time += (ti.tv_sec-t0.tv_sec)*1000+(ti.tv_nsec - t0.tv_nsec)/1000000;
			}
		} 
		else if(ready == 0) timeout=1;
		else 
		{
			fprintf(stderr, "select error: %s\n", strerror(errno)); 
			return -1;
		}
	}
	if(*respc<3)
		*mstime = -1;
	else
		*mstime = time/(*respc); 


	return (read_one_status==2) ? 1 : 0;
}

int read_one(int sockfd, int ttl, int id, struct in_addr *addr)
{
	struct sockaddr_in 	sender;	
	socklen_t sender_len = sizeof(sender);
	u_int8_t buffer[IP_MAXPACKET];
	int packet_status = recvfrom (sockfd, buffer, IP_MAXPACKET, MSG_DONTWAIT, (struct sockaddr*)&sender, &sender_len);

	if (packet_status < 0 && (errno != EWOULDBLOCK || errno!=EAGAIN) )
	{
		fprintf(stderr, "recvfrom error: %s\n", strerror(errno)); 
		return -1;
	}

	struct ip *ip_ptr = (struct ip*) buffer;
	struct icmp * icmp_ptr = (struct icmp *) ((uint8_t*) ip_ptr + (4 * ip_ptr->ip_hl));

	if(icmp_ptr->icmp_type == ICMP_TIME_EXCEEDED)
	{
		struct ip *mov_ip_ptr = (struct ip*) ((uint8_t*)icmp_ptr+8);
		struct icmp *mov_icmp_ptr = (struct icmp *) ((uint8_t*) mov_ip_ptr + (4 * mov_ip_ptr->ip_hl));
		if(mov_icmp_ptr->icmp_seq == ttl && mov_icmp_ptr->icmp_id == id)
		{
			*addr = ip_ptr->ip_src;
			return 1;
		}
	}
	if(icmp_ptr->icmp_seq == ttl && icmp_ptr->icmp_id == id)
	{
		*addr = ip_ptr->ip_src;
		return 2;
	}
	return 0;

}


