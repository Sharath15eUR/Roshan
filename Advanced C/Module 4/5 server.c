#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int socketmain, socketclient, port=5000,i;
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

char buf[100],str[100];
read(socketclient,buf,100);
for(i=0;i<strlen(buf);i++){
	str[i]=buf[strlen(buf)-1-i];
}
if(strcmp(buf,str)==0)
	strcpy(buf,"Palindrome");
else
	strcpy(buf,"Not a Palindrome");
write(socketclient,buf,100);
printf("Result sent!\n");
close(socketmain);
return 0;
}
