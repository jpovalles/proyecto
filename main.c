#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct enem{
    char *nombre;
    int vida;
    char *tipo;
    char *descripcion; 
}enemigo;

typedef struct personaje{
    char *nombre;
    int vida;
    int fuerza;
    int dureza;
    int inteligencia;
}personaje;

// typedef struct carta{

// }carta;

void leerEnemigos();
void leerPersonajes();

enemigo arrEnemigos[30] = {};
personaje arrPersonajes[3] = {};

int main(){
    leerEnemigos();
    leerPersonajes();

    int i = 0;
    printf("\nX %s %s %d %s", arrEnemigos[i].nombre, arrEnemigos[i].descripcion, arrEnemigos[i].vida, arrEnemigos[i].tipo);
    printf("\nP %s %d %d %d %d", arrPersonajes[i].nombre, arrPersonajes[i].vida, arrPersonajes[i].fuerza, arrPersonajes[i].dureza, arrPersonajes[i].inteligencia);
    return 0;
}

// Lectura de archivos
// Lectura de enemigos
void leerEnemigos(){
    FILE *file;
    file = fopen("enemigos.txt", "r");
    if(file == NULL){
        printf("No se pudo leer el archivo!\n");
    }

    char linea[1500];
    char nombre[20];
    char descripcion[150]; 
    int vida;
    char tipo[20];
    char *sp;
    int i = 0;
    enemigo auxiliar;

    while(fgets(linea, 1500, file) != NULL){
        sp = strtok(linea, ",");
        strcpy(nombre, sp);

        sp = strtok(NULL, ",");
        strcpy(descripcion, sp);

        sp = strtok(NULL, ",");
        vida = atoi(sp);

        sp = strtok(NULL, ",");
        strcpy(tipo, sp);
        
        auxiliar.nombre = nombre;
        auxiliar.vida = vida;
        auxiliar.descripcion = descripcion;
        auxiliar.tipo = tipo;

        arrEnemigos[i] = auxiliar;
        
        printf("\nP %s %s %d %s", arrEnemigos[i].nombre, arrEnemigos[i].descripcion, arrEnemigos[i].vida, arrEnemigos[i].tipo);
        i++;
        if(fgets(linea, 1000, file) != NULL){
            printf("\nNULL\n\n");
        }
    }
    fclose(file);
}

// Lectura de personajes
void leerPersonajes(){
    FILE *file;
    file = fopen("personajes.txt", "r");
    if(file == NULL){
        printf("No se pudo leer el archivo!\n");
    }

    char linea[1000];
    char nombre[10];
    int vida;
    int fuerza;
    int dureza;
    int inteligencia;
    char *sp;
    int i = 0;
    personaje auxiliar;

    while(fgets(linea, 1000, file) != NULL){
        sp = strtok(linea, ",");
        strcpy(nombre, sp);

        sp = strtok(NULL, ",");
        vida = atoi(sp);

        sp = strtok(NULL, ",");
        fuerza = atoi(sp);

        sp = strtok(NULL, ",");
        dureza = atoi(sp);

        sp = strtok(NULL, ",");
        inteligencia = atoi(sp);

        auxiliar.nombre = nombre;
        auxiliar.vida = vida;
        auxiliar.fuerza = fuerza;
        auxiliar.dureza = dureza;
        auxiliar.inteligencia = inteligencia;

        arrPersonajes[i] = auxiliar;
        
        printf("\nP %s %d %d %d %d", arrPersonajes[i].nombre, arrPersonajes[i].vida, arrPersonajes[i].fuerza, arrPersonajes[i].dureza, arrPersonajes[i].inteligencia);
        i++;
    }
    fclose(file);
}