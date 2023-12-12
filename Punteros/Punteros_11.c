/* PUNTEROS A ESTRUCTURAS */
/* MANEJO DE VECTOR DE ESTRUCTURAS MEDIANTE PUNTEROS*/

#include <stdio.h>
#include <stdlib.h>
#define N 8

struct ALUMNO {
    char NOM[20];
    char SEX;
    int NOTA;
};

int main (){

    struct ALUMNO VEC[N], *P;
    struct ALUMNO AUX ;
    int i, j;

    for (P = VEC ; P < VEC + N ; P++){

        fflush(stdin);

        printf ("\n\nNOMBRE: ");
        gets (P->NOM);

        printf ("\nSEXO: ");
        P->SEX = getchar();

        fflush(stdin);

        printf ("\nNOTA: ");
        scanf ("%d", &(P->NOTA));


    }

    printf ("\n\n\n\n %-15s %-8s %-10s\n", "NOMBRE", "SEXO", "NOTA");
    

    for (P = VEC ; P < VEC + N ; P++){

        printf ("\n %-15s %-8c %-10d", P->NOM, P->SEX, P->NOTA);
    }

    printf ("\n\n\n\n %-15s %-8s %-10s\n", "NOMBRE", "SEXO", "NOTA");
    

    for (P = VEC, i = 0 ; i < N ; i++){

        printf ("\n %-15s %-8c %-10d", (P + i)->NOM, (P + i)->SEX, (P + i)->NOTA);
    }

    P = VEC;

    for (i = 0; i < N-1; i++){
        for (j = 0; j < N-1-i; j++){
            if (((P+j)->NOTA) < (P+j+1)->NOTA){
                AUX = *(P+j);
                *(P+j) = *(P+j+1);
                *(P+j+1) = AUX;
            }
        }
    }

    printf ("\n\n\n\n %-15s %-8s %-10s\n", "NOMBRE", "SEXO", "NOTA");
    

    for (P = VEC, i = 0 ; i < N ; i++){

        printf ("\n %-15s %-8c %-10d", (P + i)->NOM, (P + i)->SEX, (P + i)->NOTA);
    }

    return 0;


}