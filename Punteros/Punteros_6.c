#include <stdio.h>
#include <stdlib.h>
#define N 5

/*Transferencia por referencia*/

void funcion (int *, int []);

int main (){

    int A = 25;
    int VEC[N] = {12, 4, 7, 10, 23};
    int i;

    printf ("\n\n\t\t Valores originales \n\n\t\t");
    printf ("\tA = %d\t\t", A);
    for (i = 0; i < N; i++){
        printf ("\tVEC[%d] = %d", i, VEC[i]);
    }

    /*
    A la funcion, le paso ahora la direccion de A, usando el ampersand. Como contraparte, la funcion debe recibir ahora una direccion de memoria, esto anteriormente no podiamos hacerlo al desconocer
    el uso de los punteros, pero ahora, eso que puede y va a contener la direccion de memoria de A no es otra cosa que un puntero.
    */

    funcion (&A, VEC);

    printf ("\n\n\t\t Valores despues de la funcion \n\n\t\t");
    printf ("\tA = %d\t\t", A);
    for (i = 0; i < N; i++){
        printf ("\tVEC[%d] = %d", i, VEC[i]);
    }

    printf ("\n\n\n");

    return 0;


}

void funcion (int *P, int V[]){

    int i;
    /*
    Notemos en la proxima linea, que ahora el PUNTERO P es lo que va a duplicarse, por lo tanto, lo que debemos hacer es colocar doble asterisco, uno para la operacion aritmetica de multiplicacion,
    y el otro para el tratamiento de un puntero.
    */
    *P = 2 ** P;
    
    for (i = 0; i < N ; i++){
        V[i] = 2 * V[i];
    }

}