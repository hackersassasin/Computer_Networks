import os 

os.system("arp") 
os.system("scp /home/proglab/net.py proglab@192.168.0.142:/home/proglab/Desktop") 
os.system("scp /home/proglab/qwe.py proglab@192.168.0.142:/home/proglab/Desktop") 
os.system("ssh proglab@192.168.0.142 cd /home/proglab/Desktop python qwe.py") 
