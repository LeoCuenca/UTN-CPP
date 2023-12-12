/*ARCHIVOS BINARIOS*/
/*MODIFICACIONES EN EL MISMO ARCHIVO*/

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

    if ((FP = fopen ("BD", "rb+")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }

    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP)){
        if (X.sexo == 'F'){
            X.edad = X.edad / 2;
            fseek (FP, (long)(-1)*sizeof(X), 1);
            fwrite (&X, sizeof(X), 1, FP);
        }
        fseek(FP, 0L, SEEK_CUR);
        fread (&X, sizeof(X), 1, FP);
    }
    
    fclose (FP);

    printf ("\n\n");

}

