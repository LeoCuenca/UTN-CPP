/* ARCHIVOS DE TEXTO 02 */
/* LECTURA DE UN ARCHIVO DE TEXTO */

#include <stdio.h>
#include <stdlib.h>

int main (){

    char CAR;
    FILE * FP;

    if ( (FP = fopen ("PEPE.txt","r")) == NULL) {
        printf ("\n\nError en la apertura del archivo\n\n");
        exit(1);
    }

    printf ("\n\nCONTENIDO DEL ARCHIVO \n\n");

    CAR = getc(FP);

    while (CAR != EOF){
        putchar(CAR);
        CAR = getc(FP);
    }

    fclose(FP);

    return 0;


} 