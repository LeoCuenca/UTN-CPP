/*CLASES Y OBJETOS*/
/*CONSTRUCTORES PARAMETRIZADOS CON DEFAULT*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class ALFA {
    private:
        int NUM;
    public:
        ALFA (int = 4); // CONSTRUCTOR
        void MIRAR ();
        
};

ALFA :: ALFA (int W) {
    NUM = W;
}

void ALFA :: MIRAR () {
    int i;
    for (i = 0; i < NUM; i++) {
        cout << "\n\tI = " << i + 1 << " PEPE";
    }
    getchar ();
}

int main () {

    /* USUARIO DISCONFORME */

    int VALOR;
    cout << "\n\nVALOR = ";
    cin >> VALOR;
    getchar();

    ALFA X (VALOR);
    X.MIRAR ();

    /* USUARIO INDECISO */

    ALFA Y;
    cout << "\n\nUSUARIO INDECISO";
    Y.MIRAR ();
    
    printf ("\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}