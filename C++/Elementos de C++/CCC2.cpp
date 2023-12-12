/* OPERADOR & */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void FUNCION (int);
void FUNCION (int *);
void FUNC (int &);

int main () {

    int A;
    int & B = A;

    // B ES UN ALIAS, ES UNA REFENCIA A UNA VARIABLE DEL MISMO TIPO EXISTENTE. ES OTRO NOMBRE PARA LA VARIABLE A.

    A = 25;
    cout << "\n\nTRANSFERENCIA POR VALOR";
    cout << "\n\tANTES DE LA FUNCION : A = " << A;
    FUNCION (A);
    cout << "\n\tDESPUES DE LA FUNCION : A = " << A;

    A = 33;
    cout << "\n\nTRANSFERENCIA POR DIRECCION O PUNTERO\n";
    cout << "\n\tANTES DE LA FUNCION : A = " << A;
    FUNCION (&A);
    cout << "\n\tDESPUES DE LA FUNCION : A = " << A;

    A = 44;
    cout << "\n\nTRANSFERENCIA POR REFERENCIA";
    cout << "\n\tANTES DE LA FUNCION : A = " << A;
    FUNC (A);
    cout << "\n\tDESPUES DE LA FUNCION : A = " << A;

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

void FUNCION (int A) {
    A = 2 * A;
}

void FUNCION (int *P) {
    *P = 2 * (*P); // ES LO MISMO QUE 2 ** P
}

void FUNC (int &B) {
    B = 2 * B;
}