#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*librerias para los sockets*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void main()
{
	/*variables que se utilizaran*/
	int clienteSocket;
	struct sockaddr_in serverAddr;
	int nuevoSocket;
	struct sockaddr_in newAddr;
	
	socklen_t addr_size;
	/*los caracteres que pueden usar el texto y numeros*/
	char buffer[1024];
	int buffer1[1024];
	/*lo que necesita para conectar al una direccion y puerto*/
	clienteSocket=socket(PF_INET, SOCK_STREAM,0);
	printf("[-] Cliente Socket Creado Exitosamente\n");
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("10.0.2.15");

	/*conectar el socket cliente*/
	connect(clienteSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	printf("[-] Conectando a el servidor\n" );
	
	/*permite que pueda escribir nuevos mensaje*/
	nuevoSocket=accept(clienteSocket, (struct sockaddr*)&newAddr, &addr_size);
	
		
	/*----------------------leer recibido----------------------------------*/
	recv(clienteSocket, buffer, 1024, 0);
	printf("[-] Datos Recibido: %s \n",buffer);
	
	/*----------------------escribir----------------------------------*/
	strcpy(buffer,"adios\n");
	send(nuevoSocket,buffer,strlen(buffer),0);
	
}