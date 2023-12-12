/*ARCHIVOS BINARIOS*/
/*BAJAS EN UN ARCHIVO BINARIO*/
/*USANDO UN ARCHIVO TEMPORAL*/

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

    FILE *FP, *FPTEMP;
    struct alumno X;
    
    if ((FP = fopen ("BD", "rb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }
    
    if ((FPTEMP = tmpfile ()) == NULL){
        printf ("\n\n Error al encontrar el archivo temporal\n\n");
        exit(1);
    }
  
    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP)){

        if (X.sexo == 'F'){
            fwrite (&X, sizeof(X), 1, FPTEMP);
        }

        fread (&X, sizeof(X), 1, FP);

    }

    fclose(FP);

    if ((FP = fopen ("BD", "wb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }

    rewind (FPTEMP);

    fread (&X, sizeof(X), 1, FPTEMP);
    while (!feof(FPTEMP)){
        fwrite (&X, sizeof(X), 1, FP);
        fread (&X, sizeof(X), 1, FPTEMP);
    }  

    fclose(FP);
    fclose(FPTEMP);

    return 0;
}

