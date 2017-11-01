//Hello UDP Client
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h> 
 #include<arpa/inet.h> 
#include<stdlib.h>

#define buffsize  150

int main(void)
{
  struct sockaddr_in clientaddr; 
  char buff[buffsize];
  int sockfd,n;
  if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
	  perror("Socket Creation Error.\n");
  else
	  printf("Socket Created Successfully\n");
  bzero((char *) &clientaddr, sizeof(clientaddr));
  clientaddr.sin_family=AF_INET;
  clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  clientaddr.sin_port=htons(54321);
  if(connect(sockfd,(struct sockaddr *) &clientaddr, sizeof(clientaddr)) < 0 )		  	  perror("Connect error\n");
  else
	printf("Connected successfully\n");
  strcpy(buff,"Hello Server\n"); 
  if(sendto(sockfd,buff,buffsize,0,
	   (struct sockaddr *) &clientaddr, sizeof(clientaddr)) != buffsize)		  
	  perror("Send error\n");
  else
	printf("Buffer has sent successfully\n");
   
   close(sockfd);
   
  }
  
