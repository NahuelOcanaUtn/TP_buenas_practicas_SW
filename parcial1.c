#include <stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_VUELOS_PERMITIDOS 50
#define TAM_NOMBRE_VUELO 40
#define TAM_BUSQUEDA 40
#define OPCION_SALIR 5

struct aviones{
	int FrecuenciadeRadio;
	int distancia;
	char NombreDeVuelo[TAM_NOMBRE_VUELO];
};

void cargarVuelos(struct aviones *,int);
void frecuenciasCercanas(struct aviones*,int);
int main(int argc, char *argv[]) {
	struct aviones *vuelos;
	char vueloBuscado[20];
	int n,menu,i;
	
	do{
		printf("Cantidad de vuelos solicitados: ");
		scanf("%i",&n);
		if(n>=50){
			printf("Vuelos sobrepasados, vuelva introducir los vuelos\n");
		}
	} while(n>=50);
	vuelos=(struct aviones*)malloc(n*sizeof(struct aviones));
	
	cargarVuelos(vuelos,n);
	frecuenciasCercanas(vuelos,n);
	printf("MENU PRINCIPAL\n");
	printf("1. Recargar / Volver a ingresar datos de vuelos\n");
	printf("2. Mostrar todos los vuelos en el radar\n");
	printf("3. Buscar frecuencias de radio cercanas (con %% de tolerancia)\n");
	printf("4. Buscar vuelo por nombre / coincidencia de texto (strstr)\n");
	printf("%d. Salir del programa\n", OPCION_SALIR);
	printf("Ingrese una opcion: ");
	printf("\n");
	scanf("%i",&menu);
	switch (menu) {
	case 1:
		cargarVuelos(vuelos, cantidadVuelos);
		break;
		
	case 2:
		mostrarTodosLosVuelos(vuelos, cantidadVuelos);
		break;
		
	case 3:
		buscarFrecuenciasCercanas(vuelos, cantidadVuelos);
		break;
		
	case 4:
		buscarVueloPorNombre(vuelos, cantidadVuelos);
		break;
		
	case OPCION_SALIR:
		printf("\nLiberando memoria RAM asignada y saliendo del sistema...\n");
		break;
		
	default:
		printf("[Error]: Opcion invalida. Intente de nuevo.\n");
		break;
	} // end switch
	
} while (menu != OPCION_SALIR);
	printf("Que vuelo esta buscando?\n");
	gets(vueloBuscado);
	/*for(i=0;i<n;i++){
		if(strcmp(avion[i],vueloBuscado)){
			printf("Se encontro el vuelo %s perdido por el radas bien ahi marino",vuelos[i].NombredeVuelo);
		}
	}*/
	
	free(vuelos);
	
	return 0;
}
void cargarVuelos(struct aviones *avion,int c){
	int i;
	for(i=0;i<c;i++){
		printf("Introducir la frecuencia de radio del avion %i\n",i+1);
		scanf("%i",&(avion+i)->FrecuenciadeRadio);
		printf("Introducir la distancia de radio del avion %i\n",i+1);
		scanf("%i",&(avion+i)->distancia);
		printf("Introducir el nombre del vuelo\n");
		fflush(stdin);
		gets(avion[i].NombreDeVuelo);
		
	}
	fflush(stdin);
}
void frecuenciasCercanas(struct aviones *av,int p){
	char vueloBuscado[20];
	int porcentaje=50,i;
	int f,prom;
	f=av[0].FrecuenciadeRadio;
	printf("%i",f);
	for(i=0;i<=p;i++){
		prom=av[i].FrecuenciadeRadio;
		if(prom<=porcentaje && prom>=0){
			printf("\nEl vuelo %i esta dentro del radio de nombre %s",i+1,av[i].NombreDeVuelo);
		}
	}
	gets(vueloBuscado);
	for(i=0;i<p;i++){
		if(strcmp(av[i].NombreDeVuelo,vueloBuscado)==0){
			printf("Se encontro el vuelo %s perdido por el radas bien ahi marino",av[i].NombreDeVuelo);
		}
	}
	
}

