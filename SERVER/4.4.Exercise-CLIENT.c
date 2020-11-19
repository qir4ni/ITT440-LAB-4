#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char message[4000], server_reply[4000];
	

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}


	server.sin_addr.s_addr = inet_addr("192.168.1.5"); //Please enter the ip address of your Server VM
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);	//Port is set 8888 to connect to server

	//Connect to remote server
	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected \n");

	/*int sizeOfStruct = sizeof(struct sockaddr_in);

	while(new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&sizeOfStruct))
	{
		recv(new_socket, message, 2000, 0);
		printf("Message from server: %s", server_reply);

		fgets(message, 2000, stdin);
		send(new_socket, message, 2000, 0);
	}*/
	int status = 1;
	while(status == 1)
	{
		printf("Enter your message for server: ");
		fgets(message, 4000, stdin);
		send(socket_desc, message, 4000, 0);

		recv(socket_desc, server_reply, 4000, 0);
		printf("\nMessage from server: %s", server_reply);
	}

	return 0;
}

