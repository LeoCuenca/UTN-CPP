/*CLASES Y OBJETOS*/
/*DECONSTRUCTORES Y DESTRUCTORES*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class ALFA {
    public:
        ALFA (); //FUNCION CONSTRUCTOR -> TIENE EL MISMO NOMBRE QUE LA CLASE Y NO RETORNA NADA DE NADA.
        ~ALFA (); //FUNCION DESTRUCTORA -> TIENE EL MISMO NOMBRE QUE LA CLASE, NO RETORNA NADA DE NADA Y ESTA NEGADA.
        void FUNCION (); 
};

ALFA::ALFA () {
    cout << "\n\nBRAHMA ES EL CONSTRUCTOR\n";
    getchar ();
}

ALFA::~ALFA () {
    cout << "\n\nSHIVA ES EL DESTRUCTOR\n";
    getchar ();
}

void ALFA::FUNCION (){
    cout << "\n\nVISHNU ES EL PROTECTOR\n";
    getchar ();
}

void FUNCION();

int main () {

    ALFA X;
    X.FUNCION();

    FUNCION();

    printf ("\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}

void FUNCION () {
    
    cout << "\n\nDENTRO DE LA FUNCION";
    ALFA W;

    W.FUNCION();
    cout << "\n\nPOR SALIR DE LA FUNCION";

}