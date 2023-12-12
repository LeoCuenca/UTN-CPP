/* GESTION DINAMICA DE MEMORIA */
/* VECTOR DINAMICO DE OBJETOS */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class ALFA {
    public:
        ALFA();
        ~ALFA();
        void FUNCION();
};

ALFA :: ALFA() {
    cout << "\n\n\tCONSTRUCTOR";
    getchar();
}

ALFA :: ~ALFA() {
    cout << "\n\n\tDESTRUCTOR";
    getchar();
}

void ALFA :: FUNCION() {
    cout << "\n\n\tESTA ES LA FUNCION";
    getchar();
}

#define N 5

int main () {

    ALFA * P;
    
    P = new ALFA[N];

    for (int i = 0; i < N; i++){
        (P + i)->FUNCION();
    }

    delete [] P;

    // PARA LA DESTRUCCION, NECESITAMOS EL OPERADOR delete[]. SI, ES UN NUEVO OPERADOR.

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

