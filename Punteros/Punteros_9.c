/* PUNTEROS A ESTRUCTURAS */
/* PASAJE POR VALOR DE UNA ESTRUCTURA */

#include <stdio.h>
#include <stdlib.h>

struct FECHA {
    int DIA;
    int MES;
    int ANIO;
};

struct FECHA CORREGIR (struct FECHA);

int main (){

    struct FECHA HOY;
    
    HOY.DIA = 29;
    HOY.MES = 2;
    HOY.ANIO = 2005;

    printf ("\n\nHOY = %02d : %02d : %d\n\n", HOY.DIA, HOY.MES, HOY.ANIO);

    HOY = CORREGIR (HOY);

    printf ("\n\nHOY = %02d : %02d : %d\n\n", HOY.DIA, HOY.MES, HOY.ANIO);

    return 0;

}

struct FECHA CORREGIR (struct FECHA W){
    if (W.DIA == 29 && W.MES == 2){
        W.DIA = 1;
        W.MES = 3;
    }
    return W;
}