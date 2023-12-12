/*CLASES Y OBJETOS*/
#include <stdio.h>
#include <stdlib.h>

class ALFA {
    private:
        int APRI;
        void DOBLAR(){
            APRI = 2 * APRI;
        }
    public:
        int BPUB;
        void CARGAR(int);
        void MIRAR();
};

void ALFA::CARGAR (int W){
    APRI = W;
    DOBLAR();
}

void ALFA::MIRAR(){
    printf ("\n\nAPRI = %d // BPUB = %d", APRI, BPUB);
}

int main () {
    
    ALFA X;

//  X.APRI = 25; ERROR DE ACCESO : ALFA::APRI ES PRIVADO

    X.BPUB = 765;
    X.CARGAR(33);
    printf ("\n\nBPUB = %d", X.BPUB);

//  X.DOBLAR(); EEROR DE ACCESO : ALFA::DOBLAR ES PRIVADO

    X.MIRAR();

}