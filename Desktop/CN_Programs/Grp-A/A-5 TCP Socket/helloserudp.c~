// Hello UDP Server

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h> 
#include<stdlib.h>

#define buffsize  150

int main(void)
{
  struct sockaddr_in servaddr,clientaddr; 
  char buff[buffsize],crcbuff[buffsize];
  int listenfd,connfd;
  int sin_size;

  if((listenfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	  perror("Socket Creation Error.\n");
  else
	  printf("Socket Created Successfully\n"); 
  bzero((char *) &servaddr, sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=inet_addr("192.168.0.140");
  servaddr.sin_port=htons(54321);
  if(bind(listenfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) == -1)
	 perror("Bind Error\n"); 
  listen(listenfd,4);
  sin_size = sizeof(struct sockaddr_in);
  for(;;)
  {
      if(recvfrom(listenfd,buff,buffsize,0,
	   (struct sockaddr *) &clientaddr, &sin_size) != buffsize)		  
	  perror("recvfrom error\n");
  else
	printf("%s\n",buff);
	 	 
}
close(connfd);
}
