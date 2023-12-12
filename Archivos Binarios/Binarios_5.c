/*ARCHIVOS BINARIOS*/
/*ACCESO RANDOM*/

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
    int pos;
    
    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }
    
    printf ("\n\n%-20s %-10s %-10s", "Nombre", "Sexo", "Edad\n");
    //ACA TENEMOS LA ESTRUCTURA DE CODIGO: HAGO UNA PRIMERA LECTURA, CHEQUEO !FEOF, OPERO (MUESTRO EN PANTALLA) Y FINALMENTE HAGO OTRA LECTURA. [LEO->CHEQUEO->OPERO->LEO]
    fread (&X, sizeof(X), 1, FP);

    while (!feof(FP)){
        printf ("\n%-20s %-10c %-10d", X.nombre, X.sexo, X.edad);
        fread (&X, sizeof(X), 1, FP);

    }

    printf ("\n\nPOSICION = ");
    scanf ("%d", &pos);

    while (pos >= 0){

        fseek(FP, (long)pos * sizeof(X), SEEK_SET);
        fread (&X, sizeof(X), 1, FP);
        printf ("\n%-20s %-10c %-10d", X.nombre, X.sexo, X.edad);
        printf ("\n\nPOSICION = ");
        scanf ("%d", &pos);

    }

    printf ("\n\n");

    fclose(FP);

}

