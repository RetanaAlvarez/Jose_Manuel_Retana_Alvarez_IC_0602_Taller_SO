#include <stdio.h>
#include <stdlib.h>   

int main()
{
	int i=0;
	char arraychar[i];
	char letra='a';
	char* punteroChar=arraychar;
	char* punteroCharDos=arraychar;

	
    for (i; i < 5; ++i)
    {    	
    	printf("primer elemento de arraychar [%i]: %s \n",i ,&letra );
    letra++;
    }
    printf("primer elemento de punteroChar  %s\n",punteroChar  );
    printf("primer elemento de punteroCharDos  %s\n", punteroCharDos );
    printf("primer elemento de punteroChar  %s\n", punteroChar  );
    printf("quinto elemento del array  %s\n" ,&arraychar[4]  );
    
    	/*for (arraychar[5] ; arraychar[5] < 1; ++arraychar[5])
    {
    	
    	letra++;
    }

	printf("primer  elemento de arraychar :%c\n",arraychar[1]);
    printf("primer elemento del punteroChar%s\n",punteroChar );
    printf("primer elemento del punteroCharDos%s\n",punteroCharDos );
    printf("quinto elemento del punteroChar%s\n",punteroChar );
*/
    return 0;
}


 // ----> Crear un puntero hacia un <<char>> de nombre "punteroCharDos" e
	// inicializarlo con la dirección del primer elemento (index) del array "arrayChar".

//----> Imprimir el contenido del quinto elemento del array "arrayChar"
// ----> Imprimir el contenido del quinto elemento del puntero "punteroChar" con aritmética de punteros
// ----> Imprimir el contenido del quinto elemento del puntero "punteroCharDos" con aritmética de punteros
// ----> Imprimir el contenido de todos los elementos del puntero "punteroCharDos" con aritmética de punteros
// usar una Estructura Repetitiva
// ----> Imprimir el contenido de todos los elementos del puntero "punteroCharDos" con aritmética de punteros
// usar una Estructura Repetitiva*/
