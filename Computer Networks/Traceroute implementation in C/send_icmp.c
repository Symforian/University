/* 
Adrian Kamiński 288477
*/
#include "traceroute.h"

int send_icmps(int sockfd, int ttl, int id,struct sockaddr_in recipient)
{
	for(int i=0; i<3; i++)
	{

		struct icmphdr icmp_header;
		icmp_header.type = ICMP_ECHO;
		icmp_header.code = 0;
		icmp_header.un.echo.id = id;
		icmp_header.un.echo.sequence = ttl;
		icmp_header.checksum = 0;
		icmp_header.checksum = compute_icmp_checksum((u_int16_t*)&icmp_header,sizeof(icmp_header));

		setsockopt (sockfd, IPPROTO_IP, IP_TTL,&ttl, sizeof(ttl));

		ssize_t bytes = sendto(sockfd,&icmp_header,sizeof(icmp_header),
				 0,(struct sockaddr*)&recipient,sizeof(recipient));
		if(bytes <0)
		{
			fprintf(stderr, "send to error: %s\n", strerror(errno));
			return -1;
		}
					


	}
	return 0;
	

}
void send_to_output(int i, struct in_addr *addrs, int time, int *respc)
{
	printf("%d\t",i);
	if(*respc == 0) 
		printf("*");
	else
	{	
		char resp_addr0[20],resp_addr1[20],resp_addr2[20]; 
		inet_ntop(AF_INET, &(addrs[0]), resp_addr0, sizeof(resp_addr0));
		inet_ntop(AF_INET, &(addrs[1]), resp_addr1, sizeof(resp_addr1));
		inet_ntop(AF_INET, &(addrs[2]), resp_addr2, sizeof(resp_addr2));
		printf("%s",resp_addr0);

		if(*respc >1 && strcmp(resp_addr0,resp_addr1)!=0)
			printf(" %s",resp_addr1);

		if(*respc >2 && strcmp(resp_addr0,resp_addr2)!=0 && strcmp(resp_addr1,resp_addr2)!=0) 
			printf(" %s",resp_addr2);
		
		if(time == -1) printf("\t\t???");
		else printf("\t\t%dms",time);
	}
	printf("\n");
}


u_int16_t compute_icmp_checksum (const void *buff, int length)
{
	u_int32_t sum;
	const u_int16_t* ptr = buff;
	assert (length % 2 == 0);
	for (sum = 0; length > 0; length -= 2)
		sum += *ptr++;
	sum = (sum >> 16) + (sum & 0xffff);
	return (u_int16_t)(~(sum + (sum >> 16)));
}
