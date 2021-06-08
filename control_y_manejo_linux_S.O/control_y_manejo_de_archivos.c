#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE 100
#define TAM_NUMEROS 100000

int crear_archivo(char *nombre_arch);
int existe_archivo(char *nombre_arch);
void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);
FILE *abrir_Archivo_lectura_escritura(char *nombre_arch);
int tiene_datos_arch(char *nombre_arch);
FILE *abrir_Archivo_solo_Lectura(char *nombre_arch);
void imprimir_vector(int vector[], int tam);
void ordBurbuja(int a[], int n);
int total_numeros_Arch(char *nombre_arch);

int main(int argc, char const *argv[])
{
	
	FILE *ptrCf = NULL;
	int existe_arch = 0, total_numeros = 0, numero_introducir = 0;
	char nom_archivo[TAM_NOMBRE];			
	int contador_numeros = 0;
	int numero_del_arch = 0;
	int vector[TAM_NUMEROS], i = 0;
	int numeros_desde_archivo = 0;	
	
	do
	{
		printf("\tNombre del archivo donde guardara los datos:");
		gets(nom_archivo);
		if(crear_archivo(nom_archivo)){
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\tEl archivo -> %s <- Fue creado EXITOSAMENTE.\n", nom_archivo);	
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
		else{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\tEl archivo -> %s <- NO pudo crearse.\n", nom_archivo);			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}while(existe_arch );


	do{
		printf("\tIngresa el nombre del archivo donde viene letras o los parrafos \n\t(ejemplo 'letras.txt' con extension si tiene): ");
		gets(nom_archivo);
		existe_arch = existe_archivo(nom_archivo);
		if(existe_arch ){
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <- No EXISTE.\n", nom_archivo);
			printf("\tIntental de nuevo\n");
			printf("---------------------------------------------------------------\n\n");			

		}
		else{
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <- SI EXISTE.\n", nom_archivo);
			printf("---------------------------------------------------------------\n\n");			
		}
	}while(existe_arch );

	ptrCf = abrir_Archivo_lectura_escritura(nom_archivo);
	if (ptrCf== NULL){
		printf("---------------------------------------------------------------\n");			
		printf("\t El archivo %s No pudo abrirse\n",nom_archivo);
		printf("---------------------------------------------------------------\n\n");			
	}
	else{
		printf("---------------------------------------------------------------\n");			
		printf("Archivo %s Abierto correctamente.\n",nom_archivo);
		printf("---------------------------------------------------------------\n\n");			
		if (tiene_datos_arch(nom_archivo)){
			printf("---------------------------------------------------------------\n");			
			printf("\tEl archivo %s  Tiene Datos.\n",nom_archivo);
			printf("\tLectura de archivo\n");
			printf("---------------------------------------------------------------\n\n");			
			ptrCf= abrir_Archivo_solo_Lectura(nom_archivo);
			if (ptrCf==NULL){
				printf("---------------------------------------------------------------\n");			
				printf("\tEl archivo %s No pudo abrirse.\n",nom_archivo);
				printf("---------------------------------------------------------------\n\n");			
			}else{
				printf("---------------------------------------------------------------\n");			
				printf("\tArchio %s Abierto correctamente\n",nom_archivo);
				printf("---------------------------------------------------------------\n\n");			
				int c;
				printf("\tlas palabras que tiene el documento son: \n");			
				while((c=fgetc(ptrCf))!=EOF) 
				{
					putchar(c);
					if (c == ' ')
					{
						printf("\n");
					}
					
				}
				printf("\n\n");
				
		




				printf("---------------------------------------------------------------------------\n");
				printf("\t---> LECTURA TERMINADA <---\n");					
				printf("---------------------------------------------------------------------------\n\n");
				cerrar_archivo(ptrCf, nom_archivo);
				}
			}
		}


	return 0;
}
int tiene_datos_arch(char *nombre_arch){
	int hay_Datos = 0;
	FILE *ptrArchivo;
	int lee_linea = 0, contador = 0;
	ptrArchivo = abrir_Archivo_solo_Lectura(nombre_arch);
	if(ptrArchivo == NULL){
		printf("El archivo -> %s <- NO se pudo abrir desde tiene_datos_arch().\n\n", nombre_arch);			
		hay_Datos = 0;
	}
	else{
		//printf("Archivo -> %s <- abierto desde tiene datos.\n", nombre_arch);
		// leo si hay datos
		fscanf(ptrArchivo, "%d", &lee_linea);
		// mientras no sea fin de archivo.
		while(!feof(ptrArchivo)){
			contador++;
			// leo si hay datos
			fscanf(ptrArchivo, "%d", &lee_linea);
			if(contador > 0){
				hay_Datos = 1;
				break;
			}
		}
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return hay_Datos;
}

FILE *abrir_Archivo_lectura_escritura(char *nombre_arch){
		FILE *ptrArchivo;
		ptrArchivo = fopen(nombre_arch, "r+");
		if(ptrArchivo == NULL){
			printf("\n----> EL archivo %s No pudo abrirse (uso de r+).\n\n", nombre_arch);
		}
		return ptrArchivo;
	}
int existe_archivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 1;
	// Con r abre un archivo para lectura.
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 0;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}
void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", nombre_arch);
}
FILE *abrir_Archivo_solo_Lectura(char *nombre_arch){
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo == NULL ){
		// con r Abre un archivo para lectura.
		printf("---> El archivo -> %s <- NO pudo abrirse (uso de r).\n\n", nombre_arch);
	}	/*
	else{
		printf("---> Archivo -> %s <- Abierto (uso de r).\n", nombre_arch);
	}*/
	return ptrArchivo;
}
int crear_archivo(char *nombre_arch){
	int creado = 0;
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "w");
	if( ptrArchivo == NULL ){
		// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
		printf("----> El archivo -> %s <- no pudo crearse (abrir; uso de w).\n", nombre_arch);
	}	
	else{
		creado = 1;
		printf("----> Archivo -> %s <- Creado (abierto; uso de w).\n", nombre_arch);
		cerrar_archivo(ptrArchivo, nombre_arch);
	}
	return creado;
}
void ordBurbuja(int a[], int n){
	int interruptor = 1;
	int pasada, j, aux;
	for(pasada = 0; pasada < n-1 && interruptor; pasada++){
		interruptor = 0;
		for(j = 0; j < n-pasada-1; j++)
			if(a[j] > a[j+1]){
				interruptor = 1;
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}
	}
}
void imprimir_vector(int vector[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%5d", vector[i]);
		if((i+1)%5 == 0)
			printf("\n");		
	}
	printf("\n");
}