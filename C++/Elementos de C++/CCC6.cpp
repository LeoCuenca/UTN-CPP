/* MIEMBROS ESTATICOS DE UNA CLASE */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class ALFA {
    public:
        ALFA();
        int A;
        static int B;
};


// TENEMOS QUE AVISAR QUE B VA A SER UNA VARIABLE ESTATICA
int ALFA :: B;

ALFA :: ALFA () {
    B = 30;
}


int main () {

    ALFA X;

    cout << "\n\nX.A = " << X.A << " X.B = " << X.B;
    X.A = 67;
    X.B = 77;
    cout << "\n\nX.A = " << X.A << " X.B = " << X.B;
    getchar();

    cout << "\n\nINSTANCIAMOS Y";

    ALFA Y;

    cout << "\n\nX.A = " << X.A << " X.B = " << X.B;
    cout << "\n\nY.A = " << Y.A << " Y.B = " << Y.B;
    getchar();

    cout << "\n\nCARGAMOS NUEVOS VALORES EN Y";
    Y.A = 6767;
    Y.B = 9977;
    cout << "\n\nX.A = " << X.A << " X.B = " << X.B;
    cout << "\n\nY.A = " << Y.A << " Y.B = " << Y.B;
    getchar();

    // EL MIEMBRO ESTATICO ES UN NEXO ENTRE LOS OBJETOS DE LA MISMA CLASE QUE SE INSTANCIEN
    
    cout << "\n\nUBICACION EN MEMORIA DE CADA UNA DE LAS VARIABLES DE CADA OBJETO INSTANCIADO";
    printf ("\n\nX.A %10p || X.B %10p || Y.A %10p || Y.B %10p", &X.A, &X.B, &Y.A, &Y.B);

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

