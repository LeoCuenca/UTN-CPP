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
    int encontrado = 0;

    if ((FP = fopen ("BD", "rb+")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }

    fread (&X, sizeof(X), 1, FP);
    while (!feof(FP) && encontrado == 0){
        if (strcmp(X.nombre, "FILOMENA") == 0){
            X.edad = X.edad * 2;
            fseek (FP, (long)(-1)*sizeof(X), 1);
            fwrite (&X, sizeof(X), 1, FP);
            encontrado = 1;
        }
        fread (&X, sizeof(X), 1, FP);
    }

    fclose (FP);

    printf ("\n\n");

}

