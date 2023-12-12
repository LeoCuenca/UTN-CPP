/*ARCHIVOS BINARIOS*/
/*BAJAS EN UN ARCHIVO BINARIO*/
/*USANDO UN ARCHIVO AUXILIAR*/

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

    FILE *FP, *FPAUX;
    struct alumno X;
    
    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }
    
    if ((FPAUX = fopen("BDAUX", "wb")) == NULL){
        printf ("\n\n Error al encontrar el archivo auxiliar\n\n");
        exit(1);
    }
  
    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP)){

        if (X.sexo == 'F'){
            fwrite (&X, sizeof(X), 1, FPAUX);
        }

        fread (&X, sizeof(X), 1, FP);

    }

    printf ("\n\n");
    fclose(FP);
    fclose(FPAUX);

    remove("BD");
    rename("BDAUX", "BD");

}

