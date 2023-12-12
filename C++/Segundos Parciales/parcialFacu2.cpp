#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

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
    PERSONA * PER;
    PROPIEDAD * PROP;
    LOCALIDAD * LOC;
    int VALOR_PROPIEDAD = 0;
    int VALOR_PERSONA = 0;
    int MAS_RICO = 0;
    char MAS_RICO_NOMBRE[20];

    PER = INICIO_PERSONA;
    while (PER != NULL) {
        PROP = PER -> PROP_INICIO;
        while (PROP != NULL) {
            LOC = INICIO_LOCALIDAD;
            while (LOC != NULL) {
                if (strcmp(PROP -> LOCALIDAD, LOC -> NOMBRE) == 0) {
                    VALOR_PROPIEDAD = PROP -> HECTAREAS * LOC -> VALOR;
                }
                LOC = LOC -> SIG;
            }
            VALOR_PERSONA += VALOR_PROPIEDAD;
            PROP = PROP -> SIG;
        }
        if (VALOR_PERSONA > MAS_RICO) {
            MAS_RICO = VALOR_PERSONA;
            strcpy (MAS_RICO_NOMBRE, PER -> NOMBRE);
        }
        PER = PER -> SIG;
    }

    cout << "EL MAS RICO ES : " << MAS_RICO_NOMBRE;

}



