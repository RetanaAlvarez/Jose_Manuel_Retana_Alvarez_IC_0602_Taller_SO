#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*librerias para los sockets*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
void main(){
	/*variables que se utilizaran*/
	int sockfd;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;
	/*los caracteres que pueden usar el texto y numeros*/
	char buffer[1024];
	int buffer1[1024];
	/*lo que necesita para conectar al una direccion y puerto*/
	sockfd=socket(PF_INET, SOCK_STREAM, 0);
	printf("[+] Servidor Socket Creado Exitosamente\n");
	memset(&serverAddr, '\0',sizeof(serverAddr));
	/*conectar el socket servidor*/
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("10.0.2.15");

	/*enlaza la conexion*/
	bind(sockfd, (struct sockaddr*)&serverAddr,sizeof(serverAddr));
	printf("[+] Enlazar al número de puerto %d\n",PORT );

	listen(sockfd, 5);
	printf("[+] leyendo...\n");
	addr_size=sizeof(newAddr);
	
	/*permite que pueda escribir nuevos mensaje*/
	newSocket=accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

	/*----------------------escribir----------------------------------*/
	strcpy(buffer,"hola:\n");
	send(newSocket,buffer,strlen(buffer),0);
	/*strcpy(buffer,"ingresa el primer numero:\n");
	send(newSocket,buffer,strlen(buffer),0);
	strcpy(buffer,"ingresa el segundo numero:\n");
	send(newSocket,buffer,strlen(buffer),0);
	strcpy(buffer,"este es el resultado:\n");
	send(newSocket,buffer,strlen(buffer),0);

	/*----------------------leer enviado----------------------------------*/
	recv(sockfd, buffer, 1024, 0);
	printf("[+] Datos enviado: %s \n",buffer);


}	
