/* PUNTEROS A ESTRUCTURAS */
/* PASAJE POR REFERENCIA DE UNA ESTRUCTURA */

#include <stdio.h>
#include <stdlib.h>

struct FECHA {
    int DIA;
    int MES;
    int ANIO;
};

void CORREGIR (struct FECHA *);

int main (){

    struct FECHA HOY;
    
    HOY.DIA = 29;
    HOY.MES = 2;
    HOY.ANIO = 2005;

    printf ("\n\nHOY = %02d : %02d : %d\n\n", HOY.DIA, HOY.MES, HOY.ANIO);

    CORREGIR (&HOY);

    printf ("\n\nHOY = %02d : %02d : %d\n\n", HOY.DIA, HOY.MES, HOY.ANIO);

    return 0;

}

void CORREGIR (struct FECHA *P){
    if (P->DIA == 29 && P->MES == 2){
        P->DIA = 1;
        P->MES = 3;
    }

}