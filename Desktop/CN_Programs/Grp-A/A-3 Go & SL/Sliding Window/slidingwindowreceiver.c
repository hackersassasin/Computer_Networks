#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int sd,con,port,i;
char content[30],ack[3];
struct sockaddr_in cli;
	if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
	{
		printf("\n Socket problem");
		return 0;
}
bzero((char*)&cli,sizeof(cli));
cli.sin_family = AF_INET;
printf("ENTER PORT NO");
scanf("%d",&port);
cli.sin_port=htons(port);
cli.sin_addr.s_addr=htonl(INADDR_ANY);
con=connect(sd,(struct sockaddr*)&cli,sizeof(cli));
if(con==-1)
{
	printf("\n connection error");
	return 0;
}
i=recv(sd,content,30,0);
while(strcmp(content,"EOF") != 0)
{ 
printf("Received from Sender: Frame %s \n",content);
ph:
printf("\n Acknowledgement(ACK/NAK) : ");
scanf("%s",ack);
	if(!(strcmp(ack,"ack")==0 || strcmp(ack,"nak")==0 || 	strcmp(ack,"ACK")==0 || strcmp(ack,"NAK")==0))
	{
  		printf("\n Not a valid Acknowledgement..use ACK or NAK..\n ");
		goto ph;
	} 
send(sd,ack,5,0);
i=recv(sd,content,30,0);
}
printf("\n\n Bye...");
close(sd);
return 0;
}

/*Output
user@user-GA-MA74GMT-S2:~$ gcc receiver.c
user@user-GA-MA74GMT-S2:~$ ./a.out
ENTER PORT NO5005
Received from Sender: Frame 0 

 Acknowledgement(ACK/NAK) : ACK
Received from Sender: Frame 1 

 Acknowledgement(ACK/NAK) : ACK
Received from Sender: Frame 0 

 Acknowledgement(ACK/NAK) : NAK
Received from Sender: Frame 0 

 Acknowledgement(ACK/NAK) : ACK
Received from Sender: Frame 1 

 Acknowledgement(ACK/NAK) : ACK
Received from Sender: Frame 0 

 Acknowledgement(ACK/NAK) : 



*/
