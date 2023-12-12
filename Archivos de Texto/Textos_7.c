/* ARCHIVOS DE TEXTO 04 */
/* USO DE FEOF() */

#include <stdio.h>
#include <stdlib.h>

int main (){

    unsigned char CAR;
    FILE * FP;

    if ( (FP = fopen ("Textos_2.exe","rb")) == NULL) {
        printf ("\n\nError en la apertura del archivo\n\n");
        exit(1);
    }

    printf ("\n\nCONTENIDO DEL ARCHIVO \n\n");

    CAR = getc(FP);

    while (!feof(FP)){
        printf("%02X  ", CAR);
        CAR = getc(FP);
    }

    fclose(FP);

    return 0;

} 