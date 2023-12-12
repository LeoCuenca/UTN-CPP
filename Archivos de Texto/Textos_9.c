/* ARCHIVOS DE TEXTO 09 */
/* USO DE FPRINTF() */

#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE * FP;
    float F;

    F = 7.5;

    if ( (FP = fopen ("FLOTA","w")) == NULL) {
        printf ("\n\nError en la apertura del archivo\n\n");
        exit(1);
    }

    fprintf (FP, "%f", F);

    fclose(FP);

    return 0;

} 