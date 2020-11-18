// CLIENT SCRIPT
#include <stdio.h>
#include <sys/socket.h>	//For Sockets
#include <stdlib.h>
#include <netinet/in.h>	//For the AF_INET (Address Family)


fd = socket(AF_INET, SOCK_STREAM, 0);

server.sin_family = AF_INET;
server.sin_port = htons(8888);

inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);	//This binds the client to localhost

connect(fd, (struct sockaddr *)&serv, sizeof(serv)));	//This connects the client to the server

while(1)
{
	printf("Enter a message: ");
	fgets(message, 100, stdin);
	send(fd, message, strlen(message), 0);
	//An extra breaking condition can be added here (to terminate the while loop)
}
