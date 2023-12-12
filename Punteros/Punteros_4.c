#include <stdio.h>
#include <stdlib.h>

int main (){

    int * P, *Q;
    


    P = (int*)0x2000;
    Q = (int*)0x200A;

    printf ("\nDiferencia Q - P = %d \n", Q - P);

    // La diferencia de punteros me va a dar la distancia entre esos dos punteros, en cantidades enteras de tipos base.

    return 0;


}