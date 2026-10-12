#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct aviones{
	int FrecuenciadeRadio;
	int distancia;
	char NombreDeVuelo[40];
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
	printf("\nquiere volver a introducir aviones?");
	printf("\n1-si");
	printf("\n2-no");
	printf("\n");
	scanf("%i",&menu);
	switch(menu){
	case 1: cargarVuelos(vuelos,n);
	default: printf("Hasta luego");
	}
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

