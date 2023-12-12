/* ARCHIVOS DE TEXTO 01 */
/* ESCRITURA DE UN ARCHIVO DE TEXTO */

#include <stdio.h>
#include <stdlib.h>

int main (){

    char CAR;
    FILE * FP;

    if ( (FP = fopen ("PEPE.txt","w")) == NULL) {
        printf ("\n\nError en la apertura del archivo\n\n");
        exit(1);
    }

    CAR = getchar();

    while (CAR != '$'){
        putc(CAR, FP);
        CAR = getchar();
    }

    fclose(FP);

    return 0;


} 