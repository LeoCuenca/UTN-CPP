/* ESCRITURA CON FORMATO */

#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE * FP;
    int i, j;

    if ( (FP = fopen ("PARABO.txt","w")) == NULL) {
        printf ("\n\nError en la apertura del archivo\n\n");
        exit(1);
    }

    for (i = -10 ; i <= 10; i++){
        for (j = -10; j <= 10; j++){
            fprintf (FP, "%d\t", -(i*i+j*j));
        }
        fprintf (FP, "\n");
    }

    fclose(FP);

    return 0;

} 