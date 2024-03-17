#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int fd, socketclient, port=5000,i;
struct sockaddr_in serv, clientaddr;
socklen_t clientlen;
char buf[100];

if((fd=socket(AF_INET, SOCK_DGRAM, 0))<0){
printf("\nServer cant open socket");
exit(0);
}

bzero(&serv, sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_addr.s_addr=htonl(INADDR_ANY);
serv.sin_port=htons(port);

if((bind(fd,(struct sockaddr*)&serv, sizeof(serv)))<0){
printf("\nserver bind failed");
exit(0);
}

int l=sizeof(clientaddr);
recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&clientaddr, &l);
printf("\nReceived msg is: %s\n", buf);
close(fd);
return 0;
}
