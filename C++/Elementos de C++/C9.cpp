/* SOBRECARGA Y POLIMORFISMO */
/* SOBRECARGA DE OPERADORES */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class COMPLEJO {
    public:
        int RE;
        int IM;
        void VER ();
};

void COMPLEJO :: VER () {
    cout << RE;
    if (IM < 0) {
        cout << " - " << -IM << "i";
    }
    else{
        cout << " + " << IM << "i";
    }
}

COMPLEJO operator + (COMPLEJO, COMPLEJO);

int main () {

    int A, B, C;
    A = 25;
    B = 12;
    C = A + B;
    cout << "\n\n " << A << " + " << B << " = " << C;

    float F, G, H;

    F = 7.25;
    G = 12.24;
    H = F + G;
    cout << "\n\n " << F << " + " << G << " = " << H;

    COMPLEJO X, Y, Z;
    X.RE = 8;
    X.IM = 14;
    Y.RE = 17;
    Y.IM = -7;
    Z = X + Y;

    cout << "\n\n ";
    X.VER();
    cout << " + ";
    Y.VER();
    cout << " = ";
    Z.VER ();
    printf ("\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}

COMPLEJO operator + (COMPLEJO X, COMPLEJO Y) {

    COMPLEJO W;

    W.RE = X.RE + Y.RE;
    W.IM = X.IM + Y.IM;

    return W;
}