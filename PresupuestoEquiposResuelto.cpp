#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Sueldo{
    public:
        char nombre[20];
        int sueldo;
        Sueldo * sig;
        Sueldo (char *);
};

Sueldo::Sueldo(char * nom)
{
    strcpy(nombre, nom);
    sueldo = 5000+rand()%2000;
    sig = NULL;
}

class Jugador{
    public:
        char nombre[20];
        Jugador * sig;
        Jugador (char *);
};

Jugador::Jugador(char * nom)
{
    strcpy(nombre, nom);
    sig = NULL;
}

class Equipo{
    public:
        char nombre[20];
        Equipo * sig;
        Jugador * primerJugador;
        Equipo(char *);
};

Equipo::Equipo(char * nom)
{
    strcpy(nombre, nom);
    sig = NULL;
    primerJugador = NULL;
}


class Campeonato{
    private:
        Equipo * inicio_equipos;
        Sueldo * inicio_sueldos;
    public:
        Campeonato ();
        Equipo * buscarEquipo(char *);
        void mirar();
        void friend MILLONARIO(Campeonato &);
        ~Campeonato();
};

Campeonato::Campeonato()
{
    inicio_equipos=NULL;
    inicio_sueldos=NULL;
    srand(100);
    static char lista_jugadores[][20] = {"MARADONA","RONALDO","MESSI",
						  "PELE","MOSSI","LABRUNA",
						  "ORTEGA","RIQUELME","ROMA","CARRIZO",
						  "LORENZO","BOBBY MOORE","RONALDINHO","ARMANI",
						  "TARANTINI","RATTIN","ROSSI","ONEGA",
						  "ARTIME","VARACKA","GALLARDO","TEVEZ",
						  "MORETE","ERICO","LABRUNO","MORENO",
						  "PEDERNERA","LOUSTEAU","CAVENAGHI","NAVARRO",
						  "PAVONI","VERON","MISSI","RANOLDO",
						  "PERFUMO","MATOSAS","POLE",
						  "CUBILLA","SANTORO","MALBERNAT","BECKENBAUER",
						  "EUSEBIO","PASTORIZA","JAIRZINHO","ROJAS",
						  "MADURGA","PIANETTI","ANDRADA","MARIN",
						  "ROMERO","ALONSO","FRANCESCOLI","DOMINGUEZ",
						  "MAYADA","MORA","MASCHERANO","KRANEVITER",
						  "SOLARI","MATURANA","BOBY MOORE",
						  "HIGUITA","BASILE","FRANCESCOLE",
						  "SARNARI","BILARDO","BATISTUTA","VALENTIM",
						  "CRISTIANO","ZAMORANO","SALAS","ARDILES",
						  "KEMPES","ZANABRIA","OLGUIN","PALACIOS",
						  "MUSSI","VARON","FIN"};
    static char lista_equipos[][20] = {"BARCELONA","RIVER","BOCA","JUVENTUS",
						  		 "MILAN","REAL MADRID","DYNAMO",
								 "BOTAFOGO","COLO COLO","SAN LORENZO",
								 "RACING","INDEPENDIENTE", "FIN"};

    int I=0,J;

    Equipo * nuevoEquipo;

    while (strcmp("FIN",lista_equipos[I]))
    {
        nuevoEquipo = new Equipo(lista_equipos[I]);
        nuevoEquipo->sig = inicio_equipos;
        inicio_equipos = nuevoEquipo;
        I++;
    }

    Jugador * nuevoJugador;
    Sueldo * nuevoSueldo;
    Equipo * aux;

    I = 0;

    while (strcmp("FIN",lista_jugadores[I]))
    {
        nuevoJugador = new Jugador(lista_jugadores[I]);
        nuevoSueldo = new Sueldo(lista_jugadores[I]);

        nuevoSueldo->sig = inicio_sueldos;
        inicio_sueldos = nuevoSueldo;

        J = rand()%12;
        aux = buscarEquipo(lista_equipos[J]);
        nuevoJugador->sig = aux->primerJugador;
        aux->primerJugador = nuevoJugador;

        I++;
    }

}

Equipo * Campeonato::buscarEquipo(char * equi)
{
    Equipo * e;
    e = inicio_equipos;

    while(e)
    {
        if(!strcmp(e->nombre, equi))
            return e;
        e=e->sig;
    }
    return NULL;
}

void Campeonato::mirar()
{
    Jugador * j;
    Equipo * e;
    Sueldo * s;

    s=inicio_sueldos;
    printf("\n\n\t\tSUELDOS:");
    while(s)
    {
        printf("\n\t\t\t%s  %d", s->nombre, s->sueldo);
        s=s->sig;
    }

    e = inicio_equipos;
    printf("\n\n\t\tEQUIPOS:");
    while(e)
    {
        printf("\n\n\t\t\t%s", e->nombre);
        j = e->primerJugador;
        while(j)
        {
           printf("\n\t\t\t\t%s", j->nombre);
           j=j->sig;
        }
        e=e->sig;
    }
}
/* -----> DESTRUCTOR <-----*/
Campeonato::~Campeonato() {
    /* PASOS PARA ELIMINAR UNA LISTA SIMPLE */
    
    /* 1. Declaramos un puntero a la lista a eliminar. */
    Sueldo * sueldoAEliminar;
    /* 2. Recorremos la lista con un while hasta que no haya mas elementos (Mientras el inicio de la lista no sea NULL). */
    while(inicio_sueldos) {
        /* 3. Asigno al puntero el inicio de la lista. */
        sueldoAEliminar = inicio_sueldos;
        /* 4. Luego al inicio de la lista le asigno el puntero al siguiente elemento de la lista. */
        inicio_sueldos = sueldoAEliminar->sig;
        /* 5. Uso delete al puntero creado. */
        delete sueldoAEliminar;
    }

    /* Lo que hacemos en este procesoes: Guardar el inicio en el puntero creado -> Asignamos al inicio de la lista el siguiente -> Borramos el puntero creado*/
    
    /* PASOS PARA ELIMINAR UNA GUIRNALDA */

    /* 1. Declaramos un puntero a la guirnalda. */
    Equipo * equipoAEliminar;
    /* 2. Declaramos un puntero a las lianas. */
    Jugador * jugadorAEliminar;
    /* 3. Recorremos la guirnalda con un while hasta que no haya mas elementos (Mientras el inicio de la guirnalda no sea NULL). */
    while(inicio_equipos) {
        /* 4. Asignamos el inicio de la guirnalda al puntero de la guirnalda */
        equipoAEliminar = inicio_equipos;
        /* 5. Dentro de la guirnalda, tenemos que recorrer con otro while las lianas de cada elemento de la guirnalda */
        while(equipoAEliminar->primerJugador) {
            /* 6. Asigno al puntero de la liana con el puntero de la guirnalda que apunta al primer elemento de la liana. */
            jugadorAEliminar = equipoAEliminar->primerJugador;
            /* 7. Luego al inicio de la lista le asigno el puntero al siguiente elemento de la lista. */
            equipoAEliminar->primerJugador = jugadorAEliminar->sig;
            /* 8. Uso delete al puntero de la liana. */
            delete jugadorAEliminar;
        }
        /* 9. Paso al siguiente elemento de la guirnalda */
        inicio_equipos = equipoAEliminar->sig;
        /* 10. Elimino el equipo */
        delete equipoAEliminar;
    }
}

void MILLONARIO( Campeonato & );

int main() {
    Campeonato c;

    c.mirar();

    MILLONARIO( c ); //muestre en pantalla cual es el equipo que más gasta mensualmente en sueldos de jugadores y cuál es ese monto

    delete ( &c );

    c.mirar();

    printf("\n\n");

}

void MILLONARIO(Campeonato & c){

    Equipo * e;
    Sueldo * s;
    Jugador * j;
    int acum, max=0;
    char equipo_max[20];

    e = c.inicio_equipos;
    while(e){
        j = e->primerJugador;
        while(j){
            s = c.inicio_sueldos;
            while(s){
                if(!strcmp(j->nombre, s->nombre)){
                    acum += s->sueldo;
                }
                s = s->sig;
            }
            j = j->sig;
        }

        if(acum > max){
            max = acum;
            strcpy(equipo_max, e->nombre);
        }
        acum = 0;
        e = e->sig;
    }

    printf("\n\n\n\t\tEl equipo con mayor gasto es %s y gasta $ %d", equipo_max, max);

}
