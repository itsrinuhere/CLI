#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

main(){
	printf("server CLI \n");
	char *ip = " 127.0.0.1";
	int port = 5566;
	int server_sock,client_sock;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	//socket generation
	server_sock = socket(AF_INET,SOCK_STREAM,0);
	if(server_sock < 0){
		perror("error");
		exit(1);
	}
	printf("socket created");
	memset(&server_addr,'\0',sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr=inet_addr(ip);


	//binding
	 n = bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	 if(n<0){
		perror("bind error");
		exit(1);
	 }
	 printf("binded successfull with %d",port);
	 list(server_sock,5);
	 printf("listening");
	 while (1)
	 {
		addr_size = sizeof(client_addr);
		client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);
		printf("client connected");
		bzero(buffer,1024);
		recv(client_sock,buffer,sizeof(buffer),0);
		printf("client : %s \n",buffer);
		bzero(buffer,1024);
		strcpy(buffer,"hi this is server ");
		printf("server :%s ",buffer);
		send(client_sock,buffer,strlen(buffer),0);
		close(client_sock);
		printf("client disconnected");

	 }
	 
	 return 0;

}