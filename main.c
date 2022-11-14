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

}personaje;

typedef struct carta{

}carta;



void leerTexto();
int main(){
    FILE *file;

    file = fopen("enemigos.txt", "r");

    if(file == NULL){
        printf("No se pudo leer el archivo!\n");
    }

    leerTexto(file);
    file = fopen("prueba.txt", "r");
    leerTexto(file);
    return 0;
}

enemigo arrEnemigos[30] = {};

void leerTexto(FILE *file){

    char linea[1000];
    char nombre[10];
    char descripcion[100]; 
    int vida;
    char tipo[10];
    char *sp;

    while(fgets(linea, 1000, file) != NULL){
        sp = strtok(linea, ",");
        strcpy(nombre, sp);

        sp = strtok(NULL, ",");
        strcpy(descripcion, sp);

        sp = strtok(NULL, ",");
        vida = atoi(sp);

        sp = strtok(NULL, ",");
        strcpy(tipo, sp);

        printf("\n%s %s %d %s", nombre, descripcion, vida, tipo);
    }

    fclose(file);
}