/*NUEVOS FLUJOS DE ENTRADA Y SALIDA*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main () {

    long A;
    cout << "\n\nENTERO LARGO = ";
    cin >> A;

    short B;
    cout << "\n\nENTERO CORTO = ";
    cin >> B;

    char C;
    cout << "\n\nCARACTER = ";
    cin >> C;

    float F;
    cout << "\n\nFLOTANTE = ";
    cin >> F;

    char STR[20];
    cout << "\n\nFRASE = ";
    cin >> STR;

    cout << "\n\n\nVALORES INGRESADOS ORIGINALMENTE\n";

    cout << "\nENTERO LARGO = " << A;
    cout << "\nENTERO CORTO = " << B;
    cout << "\nCARACTER = " << C;
    cout << "\nFLOTANTE = " << F;
    cout << "\nFRASE INGRESADA = " << STR;
    getchar();

    cout << "\n\n\nVALORES INGRESADOS EN HEXADECIMAL\n" << hex;

    cout << "\nENTERO LARGO = " << A;
    cout << "\nENTERO CORTO = " << B;
    cout << "\nCARACTER = " << C;
    cout << "\nFLOTANTE = " << F;
    cout << "\nFRASE INGRESADA = " << STR;
    getchar();

    cout << "\n\n\nVALORES INGRESADOS EN OCTAL\n" << oct;

    cout << "\nENTERO LARGO = " << A;
    cout << "\nENTERO CORTO = " << B;
    cout << "\nCARACTER = " << C;
    cout << "\nFLOTANTE = " << F;
    cout << "\nFRASE INGRESADA = " << STR;
    getchar();

    cout << "\n\n\nVALORES INGRESADOS EN DECIMAL\n" << dec;

    cout << "\nENTERO LARGO = " << A;
    cout << "\nENTERO CORTO = " << B;
    cout << "\nCARACTER = " << C;
    cout << "\nFLOTANTE = " << F;
    cout << "\nFRASE INGRESADA = " << STR;
    getchar();

    printf ("\n\n");
    return 0;

}