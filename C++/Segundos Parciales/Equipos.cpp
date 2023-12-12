#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*
Se dispone de una lista simplemente enlazada de clases Sueldo compuesta por el nombre de un jugador ( char nombre[20] ), el sueldo mensual ( int sueldo ) y el puntero al siguiente jugador ( Sueldo * sig ). El puntero al inicio es un miembro privado de la clase Campeonato de la forma Sueldo * inicio_sueldos. 
También se dispone de una estructura tipo guirnalda compuesta por la clase Equipo, formada por el nombre del equipo ( char nombre [20]),  el inicio de la lista de jugadores que integran ese equipo (Jugador * primerJugador), y el puntero al siguiente equipo (Equipo * sig ). 
La clase Jugador esta formada simplemente por el nombre del jugador   char nombre [20]),   y el puntero al siguiente jugador (Jugador * sig ). 
El puntero al inicio de la guirnalda es un miembro privado de la clase Campeonato de la forma Equipo * inicio_equipos. 

Se pide : 

a. Dibujar la estructura descripta, con sus enlaces y nombres de campos y clases de nodos. 
b. Construir la función void MILLONARIO( Campeonato & ) que muestre en pantalla cual es el equipo que más gasta mensualmente en sueldos de jugadores y cuál es ese monto. 
*/

using namespace std;

class sueldo {
    public:
        char nombre[20];
        int sueldo_mensual;
        sueldo * sig;
};

class jugador {
    public:
        char nombre[20];
        jugador * sig;
};

class equipo {
    public:
        char nombre[20];
        jugador * primer_jugador;
        equipo * sig;
};

class campeonato {
    private:
        sueldo * inicio_sueldos;
        equipo * inicio_equipos;
    public:
        void friend MILLONARIO (campeonato &);
};

void MILLONARIO (campeonato & c) {

    equipo * e;
    jugador * j;
    sueldo * s;

    int sueldo_equipo = 0, mayor_gasto = 0;
    char mayor_equipo[20];

    e = c.inicio_equipos;
    while (e != NULL) {
        j = e -> primer_jugador;
        while (j != NULL) {
            s = c.inicio_sueldos;
            while (s != NULL) {
                if (strcmp (j -> nombre, s -> nombre) == 0) {
                    sueldo_equipo += s -> sueldo_mensual;
                }
                s = s -> sig;
            }            
            j = j -> sig;
        }
        if (sueldo_equipo > mayor_gasto) {
            strcpy (mayor_equipo, e -> nombre);
            mayor_gasto = sueldo_equipo;
        }
        sueldo_equipo = 0;
        e = e -> sig;
    }

    cout << "\n\nEl equipo que mas gasta es " << mayor_equipo << " con $ " << mayor_gasto;

}

int main () {

    campeonato c;

    MILLONARIO(c);

    cout << "\n\n\t\tFinal del programa\n\n";
    return 0;


}