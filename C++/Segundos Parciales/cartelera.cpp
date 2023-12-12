#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class CARTELERA {
	private:
		GENERO * INICIO;
	public:
		void MEJOR_GENERO();
		void MOSTRAR_PELICULA_DE(char * );
};

class GENERO {
	public:
		char NOM [20];
		GENERO * SIG;
		PELICULA * PRIMER_PELICULA;
        float PROMEDIO_VALORACION();
};

class PELICULA {
	public:
		char NOM[20];
		char DIRECTOR[20];
		float VALORACION;
		PELICULA * SIG;
};

float GENERO :: PROMEDIO_VALORACION () {
    GENERO * GEN;
    PELICULA * PELI;

    int cont_pelis = 0;
    float total_valoraciones = 0;

    PELI = PRIMER_PELICULA;
    while (PELI != NULL) {
        total_valoraciones += PELI -> VALORACION;
        cont_pelis += 1;
        PELI = PELI -> SIG;
    }
    return total_valoraciones / cont_pelis;
}

void CARTELERA :: MEJOR_GENERO () {
    GENERO * GEN;

    float MEJOR_VALORACION = 0;
    char MEJOR_GENERO[20];

    GEN = INICIO;
    while (GEN != NULL) {

        if (GEN -> PROMEDIO_VALORACION() > MEJOR_VALORACION) {
            MEJOR_VALORACION = GEN -> PROMEDIO_VALORACION();
            strcpy(MEJOR_GENERO, GEN -> NOM);
        }
        GEN = GEN -> SIG;
    }
    cout << "EL GENERO CON MEJOR VALORACION ES : " << MEJOR_GENERO;
}

void CARTELERA :: MOSTRAR_PELICULA_DE (char * DIRECTOR) {
    GENERO * GEN;
    PELICULA * PELI;

    char NOM_PELI[20];
    char GEN_PELI[20];
    char SUP_PROM[5];
    float VAL_PELI;
    
    GEN = INICIO;
    while (GEN != NULL) {
        PELI = GEN -> PRIMER_PELICULA;
        while (PELI != NULL) {
            if (strcmp(DIRECTOR, PELI -> DIRECTOR) == 0) {
                strcpy(NOM_PELI, PELI -> NOM);
                strcpy(GEN_PELI, GEN -> NOM);
                VAL_PELI = PELI -> VALORACION;
            }
            if (VAL_PELI > GEN -> PROMEDIO_VALORACION()) {
                strcpy(SUP_PROM, "SI");
            }else{
                strcpy(SUP_PROM, "NO");
            }
            printf ("\n\nPELICULA : %s | GENERO : %s | VALORACION : %f | SUPERA EL PROMEDIO DE VALORACIONES : %s", NOM_PELI, GEN_PELI, VAL_PELI, SUP_PROM);
            PELI = PELI -> SIG;
        }
        GEN = GEN -> SIG;
    }
}