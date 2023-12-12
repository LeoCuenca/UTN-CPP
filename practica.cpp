#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define N 4

using namespace std;

class POKEMON {
    private:
        char NOMBRE [15];
        int ATACAR ();
        char TIPO[15];
    public:
        int HP;
        POKEMON (char *, char *, int);
        ~POKEMON ();
        void MOSTRAR_NOMBRE ();
        void MOSTRAR_VIDA ();
        void friend MOSTRAR_TIPO (POKEMON); // NO ES UNA FUNCION DE LA CLASE
        void friend MOSTRAR_TIPO (POKEMON *); // NO ES UNA FUNCION DE LA CLASE
        void friend ATACA_A_POKEMON (POKEMON, POKEMON *);
        void friend ATACA_A_POKEMON (POKEMON *, POKEMON &);
        /* LAS FUNCIONES AMIGAS NO SON DE LA CLASE PERO PUEDEN ACCEDER A LOS ELEMENTOS DE LA CLASE. ESTAMOS ANTE UN EJEMPLO DE SOBRECARGA DE FUNCIONES. DONDE LAS FUNCIONES SOLO SE DIFERENCIAN EN LOS ARGUMENTOS Y NO EN EL NOMBRE. DE ESTA MANERA PODEMOS USAR UN MISMO NOMBRE DE UNA FUNCION Y UNA MISMA FUNCIONALIDAD, SOLO CAMBIANDO EL TIPO DE DATO QUE RECIBEN. */
};

POKEMON :: POKEMON (char * NOMLOCAL, char * TIPOLOCAL, int VIDA) {

    strcpy (NOMBRE, NOMLOCAL);
    strcpy (TIPO, TIPOLOCAL);
    HP = VIDA;

}

POKEMON :: ~POKEMON () {

    cout << "\n\n\t\tNos re vimos, firma : " << NOMBRE;

}

void POKEMON :: MOSTRAR_NOMBRE () {

    cout << "\n\n\t\tNOMBRE : " << NOMBRE;

}

void MOSTRAR_TIPO (POKEMON POKE) {
    
    cout << "\n\t\tTIPO : " << POKE.TIPO;

}

void MOSTRAR_TIPO (POKEMON * POKE) {

    cout << "\n\t\tTIPO : " << POKE -> TIPO;

}

void POKEMON :: MOSTRAR_VIDA () {

    cout << "\n\t\tVIDA : " << HP;

}

void ATACA_A_POKEMON (POKEMON ATACANTE, POKEMON * ATACADO) {

    cout << "\n\n\t\t\tEl Pokemon " << ATACANTE.NOMBRE << " ataca al Pokemon " << ATACADO -> NOMBRE;
    cout << "\n\n\tLe va a infligir 10 de dano.";
    ATACADO -> HP = ATACADO -> HP - 10;
    cout << "\n\n\tVida restante : " << ATACADO -> HP;

}

/* & es pasarle el objeto por referencia, trabaja con el original y no con el local. En este caso estoy printeando todo en la funcion, pero si quisiera llevarme la 'nueva vida' del Pokemon y mostrarla DESDE EL MAIN, deberia de usar si o si el &. Adicionalmente, tenemos que tener en cuenta que cuando tenemos un argumento que se pasa por referencia (&), tenemos que operarlo con el operador '.' y no con el operador '->'*/
void ATACA_A_POKEMON (POKEMON * ATACANTE, POKEMON & ATACADO) {

    cout << "\n\n\t\t\tEl Pokemon " << ATACANTE -> NOMBRE << " ataca al Pokemon " << ATACADO.NOMBRE;
    cout << "\n\n\tLe va a infligir 10 de dano.";
    ATACADO.HP = ATACADO.HP - 10;
    cout << "\n\n\tVida restante : " << ATACADO.HP;

}

int main () {

    char * nombres [N] = {"Squirtle","Bulbasaur","Pikachu","Charmander"};
    char * tipos [N] = {"Agua","Planta","Electrico","Fuego"};
    int vidas [N] = {45, 47, 40, 50};

    POKEMON P1 (nombres[0], tipos[0], vidas[0]), P2 (nombres[1], tipos[1], vidas[1]);
    POKEMON * P3, * P4;
    P3 = new POKEMON(nombres[2], tipos[2], vidas[2]);
    P4 = new POKEMON(nombres[3], tipos[3], vidas[3]);

    P1.MOSTRAR_NOMBRE ();
    MOSTRAR_TIPO (P1);
    P1.MOSTRAR_VIDA ();

    P2.MOSTRAR_NOMBRE ();
    MOSTRAR_TIPO (P2);
    P2.MOSTRAR_VIDA ();

    P3 -> MOSTRAR_NOMBRE ();
    MOSTRAR_TIPO (* P3);
    P3 -> MOSTRAR_VIDA ();

    P4 -> MOSTRAR_NOMBRE ();
    MOSTRAR_TIPO (* P4);
    P4 -> MOSTRAR_VIDA ();

    // P4 YA ES UN PUNTERO A POKEMON POR ESO NO HACE FALTA PASARLE A LA FUNCION UN '*P4'. SI PONEMOS 'P2' VA A DAR UN ERROR PORQUE 'P2' ESTA DECLARADO COMO UN OBJETO Y NO SU DIRECCION COMO SI P3/P4.
    ATACA_A_POKEMON (P1, P4);
    ATACA_A_POKEMON (P4, P1);
    // Linea que demuestra el uso y no uso de & en el argumento de la funcion sobrecargada ATACA_A_POKEMON.
    //P1.MOSTRAR_VIDA ();

    delete (P3);

    cout << "\n\nFinal del programa\n\n";

    return 0;

}

