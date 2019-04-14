/* 
Adrian Kamiński 288477
*/
#include "traceroute.h"




int main(int argc, char* argv[])
{

	if(argc != 2)
	{
		printf("Wrong input\n");
		return -1;
	}

	int id = getpid();

	int sockfd =  socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return -1;
	}
	struct sockaddr_in recipient;
	bzero (&recipient, sizeof(recipient));
	recipient.sin_family = AF_INET;
	if(inet_pton(AF_INET, argv[1], &recipient.sin_addr) <= 0)
	{
		printf("Invalid ip adress\n");	
		return -1;
		
	}
	for(int i = 1;i <31;i++)
	{
		int respc =0;
		int timems;
		struct in_addr addrs[3];
		if (send_icmps(sockfd, i, id, recipient)==-1) return -1;
		int last = receive(sockfd,i ,id,&respc,addrs,&timems);
		if(last == -1) return -1;
		send_to_output(i,addrs,timems,&respc);
		if(last) break;
	}


	return 0;
}

