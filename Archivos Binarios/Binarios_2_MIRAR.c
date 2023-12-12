/*ARCHIVOS BINARIOS*/
/*LECTURA DE UN ARCHIVO BINARIO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

struct alumno{
    char nombre[20];
    char sexo;
    int edad;
};

int main(){

    FILE * FP;
    struct alumno X;
    //int i, cant_mujeres = 0, cant_hombres = 0, edades_hombre = 0, edades_mujeres = 0;
    //float promedio_mujeres = 0, promedio_hombres = 0;
    
    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }
    
    printf ("\n\n%-20s %-10s %-10s", " Nombre", "Sexo", "Edad\n");
    
    //ACA TENEMOS LA ESTRUCTURA DE CODIGO: HAGO UNA PRIMERA LECTURA, CHEQUEO !FEOF, OPERO (MUESTRO EN PANTALLA) Y FINALMENTE HAGO OTRA LECTURA. [LEO->CHEQUEO->OPERO->LEO]
    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP)){
        //Desarrollemos un asunto: En la linea 32, hice una lectura, entonces la ventana bajo al siguiente registro. Los datos leidos estan ahora en el buffer intermedio. Yo tengo que usar esos datos para el promedio, por lo que tengo que empezar con el if antes de leer el proximo registro.
        printf ("\n%-20s %-10c %-10d", X.nombre, X.sexo, X.edad);
        /*if (X.sexo == 'F'){
            cant_mujeres += 1;
            edades_mujeres += X.edad;   
        }
        else{
            cant_hombres += 1;
            edades_hombre += X.edad;
        }*/
        fread (&X, sizeof(X), 1, FP);

    }

    //printf ("\n\nPromedio de las mujeres: %.2f", edades_mujeres/ (float) cant_mujeres);
    //printf ("\nPromedio de las hombres: %.2f", edades_hombre/ (float) cant_hombres);

    printf ("\n\n");

    fclose(FP);

}

