/* SOBRECARGA Y POLIMORFISMO */
/* SOBRECARGA DE FUNCIONES */

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

int CUAD (int);
float CUAD (float);
COMPLEJO CUAD (COMPLEJO);

int main () {

    int A = 25, B = CUAD (A);
    cout << "\n\nEL CUADRADO DE " << A << " ES " << B;

    float F = 7.25, G = CUAD(F);
    cout << "\n\nEL CUADRADO DE " << F << " ES " << G;

    COMPLEJO X, Y;
    X.RE = 8;
    X.IM = 14;
    Y = CUAD(X);
    cout << "\n\nEL CUADRADO DE ";
    X.VER();
    cout << " ES ";
    Y.VER();
    
    printf ("\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}

int CUAD (int X) {
    return X * X;
}

float CUAD (float X) {
    return X * X;
}

COMPLEJO CUAD (COMPLEJO X) {

    COMPLEJO W;

    W.RE = X.RE * X.RE - X.IM * X.IM;
    W.IM = 2 * X.RE * X.IM;

    return W;

}