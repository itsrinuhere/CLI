#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

main(){
  char *ip = " 127.0.0.1";
	int port = 5566;
  int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	//socket generation
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0){
		perror("error");
		exit(1);
	}
	printf("socket created");
	memset(&addr,"\0",sizeof(server_addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr=inet_addr(ip);

connect(sock,(Struct sockaddr*)&addr,sizeof(addr));
printf("connected to the server\n");


bzero(buffer,1024);
strcpy(buffer,"hello this is client");
printf("client : %s\n",buffer);
send(sock,buffer,strlen(buffer),0);

bzero(buffer,1024);
recv(sock,buffer,sizeof(buffer),0);
printf("server :%s\n ",buffer);
close(sock);
printf("disconnected");
 }