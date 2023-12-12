/*CLASES Y OBJETOS*/
/*ENCAPSULANDO UNA PILA*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 7

using namespace std;

class PILA {
    private:
        int VEC[N];
        int * SP;
    public:
        void PUSH (int);
        int PULL ();
        void INI ();
};

void PILA::PUSH (int W){

    if (SP == VEC + N) {
        cout << "\n\nPILA LLENA\n\n";
        return;
    }

    * SP = W;
    SP ++;

}

int PILA::PULL (){

    if (SP == VEC) {
        cout << "\nPILA VACIA\n";
        return 0;
    }

    SP --;
    return * SP;

}

void PILA::INI () {

    SP = VEC;

}

int main () {

    int i;
    int valor;
    PILA P;
    P.INI();

    for (i = 0; i < N+3; i++){
        cout << "\n\nVALOR = ";
        cin >> valor;
        P.PUSH(valor);
    }

    cout << "\n\n\nVALORES DE LA PILA\n\n";

    for (i = 0; i < N+3; i++){
        cout << "\n\n  " << P.PULL();
    }


}