#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int sockfd, n, port=5000;
struct sockaddr_in serv;
char buf[100];

if((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0){
printf("\nSocket cant be opened ");
exit(0);
}

bzero(&serv, sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_port=htons(port);

if((connect(sockfd,(struct sockaddr*)&serv, sizeof(serv)))<0){
printf("\nConnection failed");
exit(0);
}

printf("\nConnected!");

read(sockfd,buf,100);
printf("\nMsg from Server is %s\n", buf);
close(sockfd);
return 0;
}
