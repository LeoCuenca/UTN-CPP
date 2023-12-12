#include <stdio.h>
#include <stdlib.h>

int main (){

    int A;
    int * P;
    float * Q;
    
    A = 25;

    P = &A;

    /*
    Si hacemos Q = P, en C nos va a tirar una adventencia diciendonos que no son del mismo tipo. P y Q no son del mismo tipo, P es de tipo int* mientras que Q es de tipo float*.
    Es MUY IMPORTANTE tener en cuenta que no son de tipo int y float respectivamente, sino que son del tipo int* y float*. NO OLVIDAR LOS ASTERISCOS.
    Si en el casteo, le ponemos el tipo sin los asteriscos, ya no nos va a tirar un error, directamente ni compila.
    */

    Q = (float *)P;

    printf ("\n P = %p // Q = %p \n", P, Q);
    printf ("\n P = %d // Q = %f \n", *P, *Q);


    P = (int*)0x61FF12;

    printf ("\n\n P = %p // Q = %p \n", P, Q);
    printf ("\n P = %d // Q = %f \n\n", *P, *Q);

    /*
    Notese que el valor de P es 25 PERO EN LA DIRECCION DE MEMORIA 0x61FF14 (Este numero de memoria solo lo sabemos al ejecutar el programa).
    Al haber reasignado directamente la direccion de memoria a la que apunta el puntero P (Linea 26) con el numero 0x61FF12, ya el puntero apunta a otro contenido, es por esto que
    luego de este cambio el programa nos informa que P vale cualquier cosa.
    */

    /*
    ¿Pero porque Q no da 25 si nosotros al programa le indicamos que Q = P (Previo casteo)? Esto es porque el numero 00000025,  que es un numero muy cercano a 0.
    */


    return 0;


}