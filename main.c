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

enemigo leerEnemigos(FILE *file);

enemigo leerTexto(FILE *file);
int main(){
    FILE *file;

    file = fopen("enemigos.txt", "r");

    if(file == NULL){
        printf("No se pudo leer el archivo!\n");
    }

    leerEnemigos(file);
    //file = fopen("prueba.txt", "r");
    //leerTexto(file);
    return 0;
}

//enemigo arrEnemigos[30] = {};

// Lectura de archivos
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
        
        //printf("\n%s %s %d %s", arrEnemigos[i].nombre, arrEnemigos[i].descripcion, arrEnemigos[i].vida, arrEnemigos[i].tipo);
        i++;
    }
    fclose(file);
}