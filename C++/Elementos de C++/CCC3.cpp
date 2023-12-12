/* GESTION DINAMICA DE MEMORIA */
/* OPERADORES TRADICIONALES */

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
    
    P = (ALFA *) malloc (sizeof(ALFA));

    P->FUNCION();

    free(P);

    // NO VEMOS NI EL CONSTRUCTOR NI EL DESTRUCTOR. ESTO ES PORQUE LAS FUNCIONES DE GESTION DE MEMORIA TRADICIONALES ME GESTIONAN EL ESPACIO DE MEMORIA PARA EL OBJETO PERO NO SE DAN CUENTA QUE ESTAMOS INSTANCIANDO UN OBJETO Y QUE ESTE TIENE ASOCIADO UN CONSTRUCTOR Y UN DESTRUCTOR

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

