/* GESTION DINAMICA DE MEMORIA */
/* NUEVOS OPERADORES new / delete */

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

int main () {

    ALFA * P;
    
    P = new ALFA;

    P->FUNCION();

    delete P;

    // ESTOS OPERADORES ESTAN PREPRADOS PARA RECONOCER OBJETOS, POR LO QUE SE RECONOCE TANTO AL CONSTRUCTOR COMO AL DESTRUCTOR

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

