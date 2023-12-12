/* OPERADOR & */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main () {

    int A;
    int & B = A;

    // B ES UN ALIAS, ES UNA REFENCIA A UNA VARIABLE DEL MISMO TIPO EXISTENTE. ES OTRO NOMBRE PARA LA VARIABLE A.

    A = 25;
    printf ("\n\nA = %d  //  B = %d\n", A, B);

    B = 876;
    printf ("\n\nA = %d  //  B = %d\n", A, B);
    // A ES B Y B ES A. CUANDO SE MODIFICA UNO, SE MODIFICA EL OTRO TAMBIEN.

    printf ("\n\n&A = %p  //  &B = %p\n", &A, &B);
    // LAS DIRECCIONES DE AMBOS SON LAS MISMAS

    printf ("\n\nFIN DEL PROGRAMA\n");
    return 0;

}