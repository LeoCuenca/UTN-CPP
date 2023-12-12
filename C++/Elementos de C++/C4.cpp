/*CLASES Y OBJETOS*/
/*ENCAPSULANDO UNA PILA*/
/*USO DEL CONSTRUCTOR*/

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
        PILA (); //FUNCION CONSTRUCTOR -> TIENE EL MISMO NOMBRE QUE LA CLASE Y NO RETORNA NADA DE NADA.
        void PUSH (int); //PARA EL INGRESO DE LOS DATOS A LA PILA
        int PULL (); //PARA LEER LOS DATOS EN LA PILA

};

void PILA::PUSH (int W){

    if (SP == VEC + N) {
        cout << "\n\nPILA LLENA\n\n";
        return;
    }

    * SP = W; //ASIGNO AL PUNTERO SP EL VALOR DE W
    SP ++; //INCREMENTO EL VALOR DEL PUNTERO SP PARA EL PROXIMO VALOR

}

int PILA::PULL (){

    if (SP == VEC) {
        cout << "\nPILA VACIA\n";
        return 0;
    }

    SP --;
    return * SP;

}

PILA::PILA () {

    cout << "\n\nCONSTRUCTOR EN ACCION \n";
    getchar ();
    SP = VEC;

}

int main () {

    int i;
    int valor;
    PILA P;

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