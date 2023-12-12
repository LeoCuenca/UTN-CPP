/* LISTAS SIMPLEMENTE ENLAZADAS */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class NODO {
    public:
        char NOM[20];
        NODO * SIG;
        NODO (char *);
        ~NODO();
};

NODO :: NODO (char * S){
    strcpy (NOM, S);
}

NODO :: ~NODO (){
    cout << "\n\nMATANDO A ... " << NOM << "\n";
    getchar ();
}

class LISTA {
    private:
        NODO * INICIO;
        void PONER_P(NODO *);
        void PONER_F(NODO *);
        void INSERT(NODO *); // INSERT RECIBE EL NODO QUE QUEREMOS INSERTAR EN LA DIRECCION DEL NODO
        NODO * MINIMO ();
        NODO * MAXIMO ();
        NODO * BUSCAR (char *);
        void MATAR (NODO *);
        void SACAR (NODO *);

    public:
        LISTA ();
        ~LISTA();
        void AGREGAR_P (char *);
        void AGREGAR_F (char *);
        void INSERTAR (char *);
        void MIRAR ();     
        void MENOR ();
        void MAYOR ();
        void ELIMINAR (char *);
        void ORDENAR1 ();
        void ORDENAR2  ();
};

LISTA :: LISTA () {
    INICIO = NULL; // ESTO ES FUNDAMENTAL PARA INICIAR LA LISTA SIN ELEMENTOS
}

LISTA :: ~LISTA () {
    cout << "\n\nDESTRUYENDO TODOS LOS NODOS\n";
    cout << "\n\nESTA ES PARA USTEDES ... \n";
    getchar ();
}

void LISTA :: AGREGAR_P (char * S) {
    NODO * P;
    P = new NODO(S);

    PONER_P(P);
}

void LISTA :: PONER_P (NODO * PN) {
    PN -> SIG = INICIO;
    INICIO = PN;
}

void LISTA :: AGREGAR_F (char * S) {
    NODO * P;
    P = new NODO(S);

    PONER_F(P);
}

void LISTA :: PONER_F (NODO * PN) {

    NODO * P; // PUNTERO DE BARRIDO
    P = INICIO; // INICIALIZANDO EL PUNTERO (INICIO ESTA DECLARADO EN EL CONSTRUCTOR DE LA CLASE LISTA)
    PN -> SIG = NULL; // PN QUE APUNTA A SIG SE CARGA CON EL PUNTERO NULL (YA QUE ESTAMOS AGREGANDO AL FINAL DE LA LISTA, OSEA DESPUES DEL ULTIMO)

    // ¿COMO SABER SI LA LISTA ESTA VACIA?
    if (!INICIO) {
        // LISTA VACIA
        INICIO = PN;
        return ;
    }
    // LISTA NO VACIA

    while (P -> SIG) {
        P = P -> SIG; // LLEVO P HASTA EL ULTIMO NODO
    }
    P -> SIG = PN; // EL ULTIMO ENLACE SE CARGA CON LA DIRECCION DEL NUEVO NODO QUE TENIAMOS

}
/* -- */
void LISTA :: INSERTAR (char * S) { // INSERTAR RECIBE EL STRING S

    NODO * P;

    P = new NODO(S); // EL CONSTRUCTOR DEL NODO RECIBE EL STRING Y LO CARGA EN EL NODO

    INSERT(P);
}

void LISTA :: INSERT (NODO * PN) {

    NODO * P, *ANT; // PAR DE PUNTEROS AUXILIARES
    P = INICIO; // LA DIRECCION DEL PRIMER NODO
    ANT = NULL; // LA DIRECCION DE LO QUE HAY ANTES DEL PRIMER NODO ES NULL
    /* ANTES DE CADA CASO TENEMOS QUE TENER EN CUENTA LAS CONDICIONES INICIALES QUE SON LAS 2 LINEAS DE ARRIBA A ESTE COMENTARIO
       QUE SON QUE EL PUNTERO AUX P APUNTA AL PRIMER NODO Y ANT A NULL */

    if (!INICIO) { // !INICIO = INICIO = NULL
        /* LISTA VACIA */
        /* EN EL CASO DE LISTA VACIA, INICIO APUNTA A NULL Y TENGO QUE AGREGAR UN NODO EN LA LISTA, EL ENLACE DEL NODO A AGREGAR VA SIEMPRE A APUNTAR A NULL */
        PN -> SIG = NULL;
        /* INICIO TIENE QUE DEJAR DE APUNTAR A NULL Y TIENE QUE APUNTAR A PN (APUNTABA A NULL PORQUE LA LISTA ERA VACIA PERO YA NO LO SERA) */
        INICIO = PN;
        return;
    }
    /* LISTA NO VACIA */
    /* CUANDO SE MUEVAN TANTO ANT COMO P, LO HARAN DE A 2. POR LO QUE ANT PASARA A APUNTAR A P Y P A SIG */
    ANT = P;
    P = P -> SIG;
    while (P) { // COMPRUEBO QUE P SEA VERDADERO, OSEA QUE P NO ESTE APUNTANDO A NULL, YA QUE CUANDO APUNTE A NULL ES PORQUE LA LISTA SE TERMINO [EL VALOR NULL ES FALSO] 
        if (strcmp(P -> NOM, PN -> NOM) < 0 ) {
            /* BARRIDO */
            ANT = P;
            P = P -> SIG;
        }
        else {
            /* EUREKA */
            if (ANT) { // SI ANT ES VERDADERO, ENTONCES NO ES NULL Y POR LO TANTO SERA UNA SITUACION DE INSERTAR UN NODO INTERMEDIO Y NO AL PRINCIPIO
                /* SITUACION DE NUEVO NODO INTERMEDIO */
                PN -> SIG = P;
                ANT -> SIG = PN;
                return ;
            }
            /* SITUACION DE NUEVO PRIMER NODO */
            PN -> SIG = INICIO;
            INICIO = PN;
            return ;            
        } /*else*/
    } /*while*/
    /* SITUACION DE NUEVO ULTIMO NODO */
    PN -> SIG = NULL; // AHORA ESTE VA A SER EL ULTIMO NODO
    ANT -> SIG = PN;


}

void LISTA :: MIRAR () {

    NODO * P;
    cout <<"\n\n\tCONTENIDO DE LA LISTA\n\n";
    P = INICIO;
    while (P) {
        cout << "\n\t" << P->NOM;
        P = P->SIG;
    }
    getchar ();

}

void LISTA :: MENOR () {

    NODO * P; // SIEMPRE DECLARAR UN PUNTERO PARA BARRER LA LISTA
    P = INICIO; // LUEGO SIEMPRE INICIALIZARLO EN EL PUNTERO INICIO DECLARADO EN LA PARTE PRIVADA DE LA CLASE LISTA

    if (INICIO) {
        cout << "\n\nEL MENOR ES : " << MINIMO() -> NOM;
    }
}

// ESTA FUNCION MINIMO TIENE QUE DEVOLVER LA DIRECCION EN DONDE ESTA EL NODO MINIMO [POR ESTO ES 'NODO *' EL TIPO QUE DEVUELVE]
NODO * LISTA :: MINIMO () {

    NODO * P, *PMIN; // SIEMPRE DECLARAR UN PUNTERO PARA BARRER LA LISTA
    PMIN = P = INICIO; // LUEGO SIEMPRE INICIALIZARLO EN EL PUNTERO INICIO DECLARADO EN LA PARTE PRIVADA DE LA CLASE LISTA

    while (P) {
        if (strcmp(P -> NOM, PMIN -> NOM) < 0) {
            PMIN = P;
        }
        P = P -> SIG;
    }
    return PMIN;

}

void LISTA :: MAYOR () {

    NODO * P; // SIEMPRE DECLARAR UN PUNTERO PARA BARRER LA LISTA
    P = INICIO; // LUEGO SIEMPRE INICIALIZARLO EN EL PUNTERO INICIO DECLARADO EN LA PARTE PRIVADA DE LA CLASE LISTA

    if (INICIO) {
        cout << "\n\nEL MAYOR ES : " << MAXIMO() -> NOM;
    }
}

NODO * LISTA :: BUSCAR (char * S) {

    NODO * P; // SIEMPRE DECLARAR UN PUNTERO PARA BARRER LA LISTA
    P = INICIO; // LUEGO SIEMPRE INICIALIZARLO EN EL PUNTERO INICIO DECLARADO EN LA PARTE PRIVADA DE LA CLASE LISTA

    while (P) {
        if (strcmp(P -> NOM, S) == 0) {
            return P;
        }
        P = P -> SIG;
    }
    return NULL;

}


// ESTA FUNCION MAXIMO TIENE QUE DEVOLVER LA DIRECCION EN DONDE ESTA EL NODO MAXIMO [POR ESTO ES 'NODO *' EL TIPO QUE DEVUELVE]
NODO * LISTA :: MAXIMO () {

    NODO * P, *PMAX; // SIEMPRE DECLARAR UN PUNTERO PARA BARRER LA LISTA
    PMAX = P = INICIO; // LUEGO SIEMPRE INICIALIZARLO EN EL PUNTERO INICIO DECLARADO EN LA PARTE PRIVADA DE LA CLASE LISTA

    while (P) {
        if (strcmp(P -> NOM, PMAX -> NOM) > 0) {
            PMAX = P;
        }
        P = P -> SIG;
    }
    return PMAX;

}

void LISTA :: ELIMINAR (char * S) {
    NODO * P;
    P = BUSCAR (S);
    if (P) {
        MATAR(P);
    }
}

void LISTA :: MATAR (NODO * PELIM) {
    NODO * P;
    P = INICIO;

    if (INICIO == PELIM) {
        /* PRIMER NODO */
        INICIO = PELIM -> SIG;
        delete PELIM;
        return;
    }
    /* NO ES EL PRIMER NODO */

    while (P -> SIG != PELIM && P) {
        P = P -> SIG;
        /* P APUNTA AL NODO ANTERIOR A PELIM */
    }

    if (P) {
        //P -> SIG = PELIM -> SIG;
        P -> SIG = P -> SIG -> SIG;
        delete PELIM;
    }

}

void LISTA :: SACAR (NODO * PELIM) {
    NODO * P;
    P = INICIO;

    if (INICIO == PELIM) {
        /* PRIMER NODO */
        INICIO = PELIM -> SIG;

        return;
    }
    /* NO ES EL PRIMER NODO */

    while (P -> SIG != PELIM && P) {
        P = P -> SIG;
        /* P APUNTA AL NODO ANTERIOR A PELIM */
    }

    if (P) {
        //P -> SIG = PELIM -> SIG;
        P -> SIG = P -> SIG -> SIG;

    }

}

void LISTA :: ORDENAR1 () {
    NODO * P, * AUXINI;
    AUXINI = NULL;

    while ( INICIO ) {
        P = MAXIMO ();
        SACAR (P);
        P -> SIG = AUXINI;
        AUXINI = P;
    }
    /* AUXINIC ES UNA VARIABLE LOCAL DE LA FUNCION, CUANDO SALIMOS DE ESTA, SE PIERDE Y POR LO TANTO SE PIERDE LA DIRECCION DE CADA NODO. ES POR ESTO QUE LE DAMOS EL VALOR DE AUXINI A INICIO */
    INICIO = AUXINI;
}

void LISTA :: ORDENAR2 () {
    NODO * P;
    LISTA AUXL;

    while ( INICIO ) {
        SACAR (P = INICIO);
        AUXL.INSERT (P);
    }
    INICIO = AUXL.INICIO;
    AUXL.INICIO = NULL; 
}

char * GENERANOM ();

int main () {

    LISTA L;
    char BUFF[20];

    strcpy (BUFF, GENERANOM());
    while (strcmpi (BUFF, "FIN") != 0) {
        L.AGREGAR_F (BUFF);
        strcpy (BUFF, GENERANOM());
    }

    L.MIRAR();
    //L.MENOR();
    //L.MAYOR();

    //cout << "\n\n\t Ingrese un nombre a eliminar: ";
    //cin >> BUFF;
    //L.ELIMINAR (BUFF);

    //L.ORDENAR1();
    L.ORDENAR2();

    L.MIRAR();

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n");
    return 0;

}

char * GENERANOM () {
    // CON STATIC HACEMOS QUE LAS COSAS SE CREEN O SE ASIGNE UN VALOR POR PRIMERA Y UNICA VEZ Y LUEGO LOS VALORES SE VAN RECORDANDO
    static int i = 0;
    static char NOM [][20] = {"FELIPE","ANA","LAURA","CACHO","PEPE","LOLA","LUIS","PACO","LUCRECIA","CAROLINA","ENZO","BETO","FIN"};
    return NOM[i++];
}