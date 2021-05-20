#include <stdio.h>
#include <stdlib.h>   

int main()
{
	int j;
	char arraychar[5];
	char letra='a';
	char* punteroChar=arraychar;
	char* punteroCharDos=arraychar;
	
	for (int q = 0; q < 1; ++q)
	{
		
		printf("me marca simbolos que se añaden o que no deberian salir \n");

		for (int j = 0; j < 5; ++j)
		{
		arraychar[j]=letra;
		punteroChar[j]=letra;
		punteroCharDos[j]=letra;
		letra++;
		
			if(j>=0 && j<5)
			{
				//imprime los valores mediante el orden que esta j (llega saltar el 0 con el 4 por que hay intermedio)
					printf("imprimir todos de puntero punteroCharDos [%d]: %s \n",j,&arraychar[j] );					
			}
			if (j==0)
				{
			printf("primer elemento de array [%d]: %s \n",j,&arraychar[j] );
			printf("primer elemento de punteroChar [%d]: %s \n",j,&punteroChar[j] );
			printf("primer elemento de punteroCharDos [%d]: %s\n",j,&punteroCharDos[j]);
				}
			if (j==4)
				{		
				printf("quinto elemento de array [%d]: %s \n",j,&arraychar[j] );
				printf("quinto elemento de punteroChar [%d]: %s \n",j,&punteroChar[j] );
				printf("quinto elemento de punteroCharDos [%d]: %s\n",j,&punteroCharDos[j]);
				}

		}
	}
	return 0;
}