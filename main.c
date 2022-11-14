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

typedef struct carta{

}carta;

enemigo leerEnemigos(FILE *file);
personaje leerPersonajes(FILE *file);

//enemigo leerTexto(FILE *file);
int main(){
    FILE *file;

    file = fopen("enemigos.txt", "r");

    if(file == NULL){
        printf("No se pudo leer el archivo!\n");
    }

    leerEnemigos(file);
    file = fopen("personajes.txt", "r");
    leerPersonajes(file);
    return 0;
}

//enemigo arrEnemigos[30] = {};

// Lectura de archivos
// Lectura de enemigos
enemigo leerEnemigos(FILE *file){
    enemigo arrEnemigos[30] = {};
    char linea[1000];
    char nombre[10];
    char descripcion[100]; 
    int vida;
    char tipo[10];
    char *sp;
    int i = 0;
    enemigo auxiliar;

    while(fgets(linea, 1000, file) != NULL){
        sp = strtok(linea, ",");
        strcpy(nombre, sp);

        sp = strtok(NULL, ",");
        strcpy(descripcion, sp);

        sp = strtok(NULL, ",");
        vida = atoi(sp);

        sp = strtok(NULL, ",");
        strcpy(tipo, sp);
        
        auxiliar.nombre = nombre;
        auxiliar.descripcion = descripcion;
        auxiliar.vida = vida;
        auxiliar.tipo = tipo;

        arrEnemigos[i] = auxiliar;
        
        printf("\n%s %s %d %s", arrEnemigos[i].nombre, arrEnemigos[i].descripcion, arrEnemigos[i].vida, arrEnemigos[i].tipo);
        i++;
    }
    fclose(file);
}

// Lectura de enemigos
personaje leerPersonajes(FILE *file){
    personaje arrPersonajes[3] = {};
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
        
        printf("\n%s %d %d %d %d", arrPersonajes[i].nombre, arrPersonajes[i].vida, arrPersonajes[i].fuerza, arrPersonajes[i].dureza, arrPersonajes[i].inteligencia);
        i++;
    }
    fclose(file);
}
