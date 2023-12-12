/*CLASES Y OBJETOS*/
/*CONSTRUCTORES PARAMETRIZADOS*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class ALFA {
    private:
        int NUM;
    public:
        ALFA(int); // CONSTRUCTOR
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

    int VALOR;
    cout << "\n\nVALOR = ";
    cin >> VALOR;

    ALFA X (VALOR);
    X.MIRAR ();
    
    printf ("\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}