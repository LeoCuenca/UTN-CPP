#include <stdio.h>
#include <stdlib.h>

int main (){

    short int * P;
    float * Q;
    
    printf ("\nSHORT INT = %d // FLOAT = %d \n", sizeof(short int), sizeof(float));

    P = (short int*)0x2000;
    Q = (float *)0x2000;

    printf ("\nP = %x // Q = %x \n", P, Q);

    P = P + 4;
    Q = Q + 4;

    printf ("\nP = %x // Q = %x \n", P, Q);

    //Cuando le sumamos un entero a una direccion, no es la cantidad de bytes sino la cantidad de tipos base a la que esta apuntando ese puntero



    return 0;


}