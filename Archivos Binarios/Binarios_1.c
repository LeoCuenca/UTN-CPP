/*ARCHIVOS BINARIOS*/
/*ESCRITURA EN UN ARCHIVO BINARIO*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

struct alumno{
    char nombre[20];
    char sexo;
    int edad;
};

int main(){

    FILE * FP;
    struct alumno X;
    int i;  

    if ((FP = fopen ("BD", "wb")) == NULL){
        printf ("\n\n Error al encontrar el archivo\n\n");
        exit(1);
    }
    
    for (i = 0; i < N; i++){
        fflush(stdin);

        printf ("\n\nIngrese el nombre: ");
        gets(X.nombre);

        printf ("\nIngrese el sexo: ");
        X.sexo = getchar();

        printf ("\nIngrese la edad: ");
        scanf ("%d", &(X.edad));

        fwrite (&X, sizeof(X), 1, FP);

    }

    fclose(FP);

}

