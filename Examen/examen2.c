#include <stdio.h>
#include <stdlib.h>   


int main()
{
	char arraychar[5];
	char letra = 'a';
	char* punteroChar;
	char* punteroCharDos;
    for (arraychar[5] = 0; arraychar[5] < 5; ++arraychar[5])
    {
    	do{

    	printf("arraychar [%i]: %s \n",arraychar[5] ,&letra );
    	letra++;
    	printf("imprimir\n");
    	}
    }


    

    return 0;
}