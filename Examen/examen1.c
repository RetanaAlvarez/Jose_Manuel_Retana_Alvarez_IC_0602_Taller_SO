#include <stdio.h>

int main()
{
	char y='y';
	char x='x';
	char* p;
	char* puntero;

	p=&x;
	printf("imprimir p: %s \n",&*p);
	p+=1;
	printf("imprimir p: %s \n",&*p);
	p+=2;//suma del numero 2 a la direcion del puntero
	printf("imprimir p: %s \n",&*p);
	puntero=&y;//almacenar mi puntero de la variable asignado el valor y
	printf("imprimir puntero: %s\n",&*puntero);

	printf("me marcar la variable del puntero pero marca error de simbolos\n");
	return 0;
}