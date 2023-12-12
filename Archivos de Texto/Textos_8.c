/* ARCHIVOS DE TEXTO 08 */
/* USO DE FPRINTF() */

#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE * FP;

//    if ( (FP = fopen ("Textos_2.exe","rb")) == NULL) {
//        printf ("\n\nError en la apertura del archivo\n\n");
//        exit(1);
//    }

    fprintf (stdout, "\n\n\t\t CELESTE TE AMO");

    fclose(FP);

    return 0;

} 