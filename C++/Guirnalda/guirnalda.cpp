/* GUIRNALDA */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class ALUMNO {
    public:
        ALUMNO (char *); // CONSTRUCTOR
        ~ALUMNO (); // DESTRUCTOR
        char NOM [20]; // NOMBRE DEL ALUMNO
        ALUMNO * SIG; // PUNTERO AL SIGUIENTE ALUMNO
};

ALUMNO :: ALUMNO (char * S) {
    strcpy (NOM, S);
    SIG = NULL;
}

ALUMNO :: ~ALUMNO () {
    cout << "\n\nMATANDO A ... " << NOM;
    getchar ();
}

class PARTIDO {
    public:
        PARTIDO (char *, ALUMNO *); // CONSTRUCTOR. RECIBE EL NOMBRE DEL PARTIDO Y ADEMAS LA DIRECCION DEL NODO QUE CONTIENE AL PRIMER ALUMNO VOTANTE DEL PARTIDO
        ~PARTIDO (); // DESTRUCTOR
        char NOM [20]; // NOMBRE DEL PARTIDO
        ALUMNO * PALUM; //INICIO A LA LISTA DE ALUMNOS (PALUM = PUNTERO A ALUMNO)
        PARTIDO * SIG; // PUNTERO AL SIGUIENTE PARTIDO
};

PARTIDO :: PARTIDO (char * S, ALUMNO * PRESI) {
    strcpy (NOM, S);
    PALUM = PRESI;
}

PARTIDO :: ~PARTIDO () {
    cout << "\n\nMATANDO A ... TODOS LOS ALUMNOS";
    getchar ();
}

class GUIRNALDA {
    private:
        PARTIDO * INICIO;
        PARTIDO * BUSCAR (char *);
    public:
        GUIRNALDA (); // CONSTRUCTOR
        ~GUIRNALDA (); // DESTRUCTOR
        void ARREGLATE (char *);
        void MIRAR ();

};

GUIRNALDA :: GUIRNALDA () {
    INICIO = NULL;
}

GUIRNALDA :: ~GUIRNALDA () {
    cout << "\n\nQUE SE VAYAN TODOS !!!!";
    cout << "\n\nDESTRUIR TODOS LOS PARTIDOS";
    getchar ();
}

void GUIRNALDA :: ARREGLATE (char * S) {

    /*PROTOTIPO LOCAL DE UNA FUNCION*/
    char * GENERAPARTIDO ();

    char BUF[20];
    ALUMNO * PAL; // PUNTERO A ALUMNO [PAL] PARA GESTIONAR AL VOTANTE NUEVO
    ALUMNO * P; // PUNTERO AUX PARA BARRER LISTA DE ALUMNOS DE UN PARTIDO EXISTENTE Y COLOCAR AL NUEVO EN EL ULTIMO LUGAR
    PARTIDO * PPAR; // PUNTERO AL PARTIDO PARA USAR BUSCAR Y VER SI EXISTE O NO

    PAL = new ALUMNO (S); // NODO DINAMICO
    
    strcpy (BUF, GENERAPARTIDO()); // GENERACION AUTOMATICA DE UN PARTIDO

    PPAR = BUSCAR (BUF);

    if (PPAR == NULL) {
        /* PARTIDO NUEVO */
        PPAR = new PARTIDO (BUF, PAL);
        PPAR -> SIG = INICIO;
        INICIO = PPAR;
        return;
    }
    /* PARTIDO EXISTENTE */
    P = PPAR -> PALUM; // P APUNTA AL PRESIDENTE

    while (P -> SIG != NULL) {
        P = P -> SIG; // VAMOS AL ULTIMO ALUMNO
    }

    P -> SIG = PAL;

}

PARTIDO * GUIRNALDA :: BUSCAR (char * S) {
    PARTIDO * PPAR;
    PPAR = INICIO;
    while (PPAR) {
        if (strcmp (PPAR -> NOM, S) == 0) {
            return PPAR;
        }
        PPAR = PPAR -> SIG;
    }
    return NULL;
}

void GUIRNALDA :: MIRAR () {

    PARTIDO * PPAR;
    ALUMNO * PAL;

    cout << "\n\nCONTENIDO DE LA GUIRNALDA\n\n";

    PPAR = INICIO; // SIEMPRE INICIALIZAR LOS PUNTEROS
    /* ESTRUCTURA DE BARRIDO */
    while (PPAR != NULL) {
        cout << "\n\n\n\n\t\tPARTIDO : " << PPAR -> NOM << "\n\n";
        PAL = PPAR -> PALUM;
        while (PAL != NULL) {
            cout << "\n\n\t\t\t" << PAL -> NOM;
            PAL = PAL -> SIG;
        }
        getchar ();
        PPAR = PPAR -> SIG; // ESTO AVANZA AL SIGUIENTE ELEMENTO DE LA LISTA
    }


}

char * GENERANOM ();

int main () {

    char BUF[20];
    srand (65);
    GUIRNALDA G;

    strcpy (BUF, GENERANOM());
    while (strcmp (BUF, "FIN") != 0) {
        G.ARREGLATE(BUF);
        strcpy (BUF, GENERANOM());
    }

    G.MIRAR ();

    printf ("\n\nFIN DEL PROGRAMA\n");
    return 0;
}

char * GENERANOM () {

    static int i = 0;
    static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA","PACO","LUIS","MARIA","ANSELMO","ANA","LAURA","PEDRO","ANIBAL","PABLO","ROMUALDO","ALICIA","MARTA","MARTIN","TOBIAS","SAUL","LORENA","ANDRES","KEVIN","LUCRECIA","RAUL","ENZO","BETO","HERMINDO","FELIPE","GUILLERMO","TATO","KARINA","AQUILES","MINERVA","OLGA","LALO","TATIANA","LILO","STICH","EMA","THELMA","LOUISE","BONNIE","CLYDE","ROMEO","JULIETA","VERONICA","JORGE","ALEJANDRO","ROCIO","FIN"};

    return NOM[i++];
}

char * GENERAPARTIDO () {
    static char NOM[][20] = {"ARRIBA","ABAJO","ATRAS","ADELANTE","IZQUIERDA","DERECHA","CENTRO"};
    return NOM [rand() % 7];
}