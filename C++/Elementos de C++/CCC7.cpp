/* MIEMBROS ESTATICOS DE UNA CLASE */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class ALFA {
    private:
        int ID;
        static int NUM;
    public:
        ALFA();
        ~ALFA();
        void SALUDAR();
};

int ALFA :: NUM;

ALFA :: ALFA() {
    ID = ++NUM;
    cout << "\n\n\tNACE EL OBJETO NUMERO ..." << ID;
    getchar();
}

ALFA :: ~ALFA() {
    cout << "\n\n\tMUERE EL OBJETO NUMERO ..." << ID;
    getchar();
}

void ALFA :: SALUDAR() {
    cout << "\n\n\tHOLA YO SOY NUMERO ..." << ID;
    getchar();
}

void FUNCION ();

int main () {

    int i;

    // DECLARACION DE UN OBJETO LOCAL
    cout << "\n\nINSTANCIA DE OBJETO LOCAL";
    ALFA X;

    // DECLARACION DE UN PUNTERO. NO SE ESTA INSTANCIANDO NADA
    ALFA * P;

    // DECLARACION DE UN VECTOR LOCAL DE OBJETOS
    cout << "\n\nINSTANCIA DE VECTOR LOCAL DE 3 OBJETOS";
    ALFA VEC[3];

    // INSTANCIACION DE UN VECTOR DE OBJETOS DINAMICO
    cout << "\n\nINSTANCIA DE VECTOR DINAMICO DE 5 OBJETOS";
    P = new ALFA[5];

    cout << "\n\nVAMOS A LA FUNCION";
    FUNCION ();
    cout << "\n\nDE NUEVO EN EL MAIN";

    cout << "\n\nSALUDA EL OBJETO LOCAL";
    X.SALUDAR ();

    cout << "\n\nSALUDA EL VECTOR DINAMICO";
    for (i = 0; i < 5; i++) {
        (P + i) -> SALUDAR();
    }

    cout << "\n\nMATANDO AL VECTOR DINAMICO";
    delete[] P;

    cout << "\n\nSALUDA EL VECTOR LOCAL";
    for (i = 0; i < 3; i++) {
        VEC[i].SALUDAR();
    }


    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

void FUNCION () {

    cout << "\n\nESTAMOS EN LA FUNCION";
    ALFA Y;
    Y.SALUDAR ();
    cout << "\n\nPOR SALIR DE LA FUNCION";

}

