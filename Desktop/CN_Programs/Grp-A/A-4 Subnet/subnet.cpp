#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;
class ping {
public:
fstream file;
    std::string ipadr;
    string word;

void pinging ()
{


while(1)
{

cout <<"1)Check IP Connection 2) Exit "<<endl;
int i;
cin>>i;

switch(i)

{

case 1:

    cout<<"Enter ip address to ping??";
    
    cin>>ipadr;

    system(std::string("ping -w 5 " + ipadr + " | cat > result.txt" ).c_str());
    system("chmod 777 result.txt");
    
    file.open("result.txt",std::ios::out |std::ios::in);
    system("cat result.txt");
    file>>word;
    file.close();
    
    if(word=="PING")
	cout<<"Same subnet";
    else
	cout<<"Different subnet";
    break;

case 2:

    return;
    break;
}
}

}
};

int main()
{


ping p;
system("ifconfig | grep broadcast ");

p.pinging();


return 0;
}

/*
output:

proglab@proglab:~$ g++ subnet.cpp
proglab@proglab:~$ ./a.out
1)Check IP Connection 2) Exit 
1
Enter ip address to ping??     
192.168.0.1
PING 192.168.0.1 (192.168.0.1) 56(84) bytes of data.
64 bytes from 192.168.0.1: icmp_seq=1 ttl=64 time=0.192 ms
64 bytes from 192.168.0.1: icmp_seq=2 ttl=64 time=0.160 ms
64 bytes from 192.168.0.1: icmp_seq=3 ttl=64 time=0.163 ms
64 bytes from 192.168.0.1: icmp_seq=4 ttl=64 time=0.149 ms
64 bytes from 192.168.0.1: icmp_seq=5 ttl=64 time=0.184 ms
64 bytes from 192.168.0.1: icmp_seq=6 ttl=64 time=0.156 ms

--- 192.168.0.1 ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 4997ms
rtt min/avg/max/mdev = 0.149/0.167/0.192/0.018 ms
Same subnet1)Check IP Connection 2) Exit 
2
proglab@proglab:~$ 

*/
