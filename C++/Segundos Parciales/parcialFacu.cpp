#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class CATASTRO {
    private:
        PERSONA * INICIO_PERSONA;
        LOCALIDAD * INICIO_LOCALIDAD;
    public:
        void MAX_PROPIETARIO ();
};

class PERSONA {
    public:
        char NOMBRE[20];
        PROPIEDAD * PROP_INICIO;
        PERSONA * SIG;
};

class PROPIEDAD {
    public:
        char LOCALIDAD[20];
        int HECTAREAS;
        PROPIEDAD * SIG;
};

class LOCALIDAD {
    public:
        char NOMBRE[20];
        int VALOR;
        LOCALIDAD * SIG;
};

void CATASTRO :: MAX_PROPIETARIO () {

    PERSONA * PERO;
    PROPIEDAD * PROP;
    LOCALIDAD * LOC;

    int MAX_VALOR = 0;
    int VALOR_PROP = 0;
    int TOTAL_PERSONA = 0;
    int MAS_RICO = 0;
    char NOM_RICO[20];

    PERO = INICIO_PERSONA;
    while (PERO != NULL) {
        PROP = PERO->PROP_INICIO;
        while(PROP != NULL) {
            LOC = INICIO_LOCALIDAD;
            while(LOC != NULL) {
                if ( strcmp(PROP->LOCALIDAD, LOC->NOMBRE) == 0 ) {
                    VALOR_PROP = PROP->HECTAREAS * LOC->VALOR;
                }
                LOC = LOC->SIG;
            }
            TOTAL_PERSONA += VALOR_PROP;
            PROP = PROP->SIG;
        }
        if (TOTAL_PERSONA > MAS_RICO) {
            MAS_RICO = TOTAL_PERSONA;
            strcpy(NOM_RICO, PERO->NOMBRE);
        }
        PERO = PERO->SIG;
    }
    
    cout << "EL MAS RICO ES : " << NOM_RICO;
}





















int main(){

}