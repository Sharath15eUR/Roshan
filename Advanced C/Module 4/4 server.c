#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int socketmain, socketclient, port=5000;
struct sockaddr_in serv, clientaddr;
socklen_t clientlen;

if((socketmain=socket(AF_INET, SOCK_STREAM, 0))<0){
printf("\nServer cant open socket");
exit(0);
}

bzero(&serv, sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_addr.s_addr=htonl(INADDR_ANY);
serv.sin_port=htons(port);

if((bind(socketmain,(struct sockaddr*)&serv, sizeof(serv)))<0){
printf("\nserver bind failed");
exit(0);
}

listen(socketmain,5);

if((socketclient=accept(socketmain,(struct sockaddr*)&clientaddr, &clientlen))<0){
printf("\nclient is bad");
exit(0);
}

char buf[100];
printf("\nEnter msg to client: ");
scanf("%s",buf);
write(socketclient,buf,100);
close(socketmain);
return 0;
}
