/* MODIFICADOR STATIC */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

void FUNCION();

int main () {

    int i;

    for (i = 0; i < N; i++){
        FUNCION();
    }

    printf ("\n\n\n\nFIN DEL PROGRAMA\n\n\n");
    return 0;

}

void FUNCION() {

    int A = 40;
    static int B = 50;
    
    printf ("\n\n\t\tA = %d - %p || B = %d - %p ", A, &A, B, &B);

    // B NO ESTA EN ZONA DE PILA, DEBIDO AL STATIC. VA A ALOJARSE EN LA ZONA GLOBAL (PERO STATIC NO LA TRANSOFRMA A GLOBAL LA VARIABLE SOLO SE ALOJA EN LA ZONUA GLOBAL).
    // EL EFECTO DE STATIC, PARA NOSOTROS, ES QUE HACE QUE SE RECUERDE EL VALOR QUE TIENE. OSEA QUE B VA A VALOR 50 SIEMPRE Y VA A RECORDARSE POR FUERA DE LA FUNCION.
    // B NO SE VE DESDE OTRA FUNCION NI DESDE EL MAIN, ESTO DEMUESTRA QUE NO ES GLOBAL.
    // YO PODRIA DECLARAR OTRA VARIABLE 'B' EN UNA 'FUNCION3()' DE MANERA ESTATICA, YA HAY UNA EN LA ZONA GLOBAL PERO LE PERTENECE A LA 'B' DE LA 'FUNCION()' B B  ,MMMMM       M    LJKLKHKKHKHKKHKKKKHKKKKKKKKK                                                               CVBBBBBBBBJJJJJJJJJJJJJJJJJJJJJJJJJJJJNJNNNNN NNNN NNN NNNNNN                                                      I        X.MMMMNBBBBBBBB   

    A++;
    B++;

}
