/*ARCHIVOS BINARIOS*/
/*MODIFICACIONES*/

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

    FILE * FP, *FPAUX;
    struct alumno X;

    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo BD\n\n");
        exit(1);
    }
    if ((FPAUX = fopen ("BDAUX", "wb")) == NULL){
        printf ("\n\n Error al encontrar el archivo BDAUX\n\n");
        exit(1);
    }

    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP)){
        if (X.sexo == 'F'){
            X.edad = 2 * X.edad;
        }
        fwrite (&X, sizeof(X), 1, FPAUX);
        fread (&X, sizeof(X), 1, FP);
    }

    fclose (FP);
    fclose (FPAUX);

    /*COPIA INVERSA DIRECTA DEL CONTENIDO DE FPAUX EN FP*/

    if ((FP = fopen ("BD", "wb")) == NULL){
        printf ("\n\n Error al encontrar el archivo BD\n\n");
        exit(1);
    }
    if ((FPAUX = fopen ("BDAUX", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo BDAUX\n\n");
        exit(1);
    }

    fread (&X, sizeof(X), 1, FPAUX);
    while (!feof(FPAUX)){
        fwrite (&X, sizeof(X), 1, FP);
        fread (&X, sizeof(X), 1, FPAUX);
    }

    fclose (FP);
    fclose (FPAUX);

    printf ("\n\n");

}

