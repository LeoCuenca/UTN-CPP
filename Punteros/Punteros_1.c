#include <stdio.h>
#include <stdlib.h>

int main (){

    int A;
    int * P;

    A = 25;
    P = &A;

    printf ("\n\n A = %d // P = %X // P = %p \n\n", A, P, P);

    printf ("\n\n &A = %p // P = %p // *P = %d \n\n", &A, P, *P);

    *P = 765;

    printf ("\n\n A = %d // *P = %d \n\n", A, *P);

    return 0;


}