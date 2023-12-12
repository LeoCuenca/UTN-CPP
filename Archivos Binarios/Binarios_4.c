/*ARCHIVOS BINARIOS*/
/*PROBLEMA PROPUESTO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
    char nombre[20];
    char sexo;
    int edad;
};

int main(){

    FILE * FP;
    struct alumno X;
    int tam_arch = 0;
    char car;

    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }

    car = getc(FP);
    while (!feof(FP)){
        tam_arch += 1;
        car = getc(FP);
    }

    printf ("\n\nTama%co del archivo: %d", 164, tam_arch);
    printf ("\nTama%co de X: %d", 164, sizeof(X));
    printf ("\nCantidad de registros: %d", tam_arch / sizeof(X));

    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }

    printf ("\n\n%-20s %-10s %-10s", "Nombre", "Sexo", "Edad\n");
    //ACA TENEMOS LA ESTRUCTURA DE CODIGO: HAGO UNA PRIMERA LECTURA, CHEQUEO !FEOF, OPERO (MUESTRO EN PANTALLA) Y FINALMENTE HAGO OTRA LECTURA. [LEO->CHEQUEO->OPERO->LEO]
    fread (&X, sizeof(X), 1, FP);

    while (!feof(FP)){
        //Desarrollemos un asunto: En la linea 32, hice una lectura, entonces la ventana bajo al siguiente registro. Los datos leidos estan ahora en el buffer intermedio. Yo tengo que usar esos datos para el promedio, por lo que tengo que empezar con el if antes de leer el proximo registro.
        printf ("\n%-20s %-10c %-10d", X.nombre, X.sexo, X.edad);
        fread (&X, sizeof(X), 1, FP);

    }

    printf ("\n\n");

    fclose(FP);

}

