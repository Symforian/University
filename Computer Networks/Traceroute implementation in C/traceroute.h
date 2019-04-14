/* 
Adrian Kamiński 288477
*/
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>
#include <assert.h>
#include <time.h>

u_int16_t compute_icmp_checksum (const void *buff, int length);
int send_icmps(int sockfd, int ttl, int id,struct sockaddr_in recipient);
void send_to_output(int i, struct in_addr *addrs, int time, int *respc);

int receive(int sockfd, int ttl,int id,int *respc, struct in_addr *addrs, int *mstime);
int read_one(int sockfd, int ttl, int id, struct in_addr *addr);


