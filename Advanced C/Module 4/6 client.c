#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int sockfd, port=5000;
struct sockaddr_in serv;
char buf[100];

if((sockfd=socket(AF_INET, SOCK_DGRAM, 0))<0){
printf("\nSocket cant be opened ");
exit(0);
}

bzero(&serv, sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_port=htons(port);

printf("\nEnter msg: ");
scanf("%s",buf);

sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&serv, sizeof(serv));

printf("Sent: %s\n",buf);
close(sockfd);
return 0;
}
