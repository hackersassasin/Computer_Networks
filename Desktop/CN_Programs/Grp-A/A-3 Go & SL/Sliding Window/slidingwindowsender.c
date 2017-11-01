#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
main()
{
	int sd,i,r,bi,nsd,port,frame,prev_frame=0,count=0;;
	char ack[5],buff[30];
	struct sockaddr_in ser,cli;
	if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
	{
		printf("\n Socket problem");
		return 0;
	}
	printf("\n Socket created\n");
	bzero((char*)&cli,sizeof(ser));
	printf("ENTER PORT NO:\n");
	scanf("%d",&port);
	printf("\n Port Address is %d\n:",port);
	ser.sin_family=AF_INET;
	ser.sin_port=htons(port);
	ser.sin_addr.s_addr=htonl(INADDR_ANY);

	bi=bind(sd,(struct sockaddr *)&ser,sizeof(ser));
	if(bi==-1)
	{
 		printf("\n bind error, port busy, plz change port 			client and server");
		return 0;
	}
	i=sizeof(cli);
	listen(sd,5);
	nsd = accept(sd,((struct sockaddr *)&cli),&i);
	if(nsd==-1)
	{
		printf("\ncheck the description parameter\n");
		return 0;
	}
	printf("\nConnection accepted.");
	while(count<5)
	{
  		ph:
	  	printf("\nSending FRAME %d to the Receiver...				\n",prev_frame);
  		snprintf(buff,sizeof(buff),"%d",prev_frame);
  		send(nsd,buff,30,0);
		r = recv(nsd,ack,5,0);
  		if(strcmp(ack,"ack")==0 || strcmp(ack,"ACK")==0)
  		{
	    		count++;
    			if(prev_frame==0) prev_frame=1;
    			else prev_frame = 0;
  		}
  		else if(strcmp(ack,"nak")==0  || strcmp(ack,"NAK")==0)
  		{
    			printf("\n NAK: So again sending the Previous frame...\n");
    		goto ph;
  	}
}

printf("\n Bye..");
send(nsd,"EOF",4,0);
close(sd);
close(nsd);
return 0;
}
/* Output 
user@user-GA-MA74GMT-S2:~$ gcc sender.c
user@user-GA-MA74GMT-S2:~$ ./a.out

 Socket created
ENTER PORT NO:
5005

 Port Address is 5005
:
Connection accepted.
Sending FRAME 0 to the Receiver...

Sending FRAME 1 to the Receiver...

Sending FRAME 0 to the Receiver...

 NAK: So again sending the Previous frame...

Sending FRAME 0 to the Receiver...

Sending FRAME 1 to the Receiver...

Sending FRAME 0 to the Receiver...
*/
