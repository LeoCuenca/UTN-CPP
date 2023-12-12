/* PUNTEROS Y VECTORES */

#include <stdio.h>
#include <stdlib.h>
#define N 8

int main (){

    int VEC[N];
    int i;
    int *P, *PMIN;

    /*CARGA DEL VECTOR*/
    /*
    El adicional del numero de dato que vamos ingresando, fue un chiche que me gusto agregarle a mi, Jorge no lo realiza en el ejemplo, por lo que voy a comentar su funcionamiento
    Hacemos una inicializacion multiple en el argumento del bucle, bien podria hacerlo por fuera del mismo, pero es indistinto.
    Luego tenemos que hacer que i sume valores por cada vuelta que da el bucle, es por eso que luego de P++, se añade i++.
    Este I NO NECESITA de una restriccion como tal para finalizar, ya que lo que determina la finalizacion del bucle no es I, sino el puntero P. Es por esto que no se coloca ninguna restriccion a este agregado.
    */

    for (P = VEC, i = 0 ; P < VEC + N ; P++, i++){
        printf ("\nDATO [%d] = ", i + 1);
        scanf ("%d", P);
    }

    /*
    VEC es la direccion del VECTOR, y al ser una direccion, puede ser alojada por un puntero, es por esto que la secuencia del bucle comienza asignando a P (Que hasta ese momento era un puntero descontrolado) la direccion del VECTOR.
    La condicion de salida del bucle es que la direccion del puntero P sea MENOR a la direccion del VECTOR VEC + N, siendo N un numero conocido de elementos a almacenar.
    */

    /*IMPRESION 1*/

    printf ("\n\n\n\t\tIMPRESION DEL VECTOR\n\n\t\t");

    for (P = VEC ; P < VEC + N ; P++){
        printf ("%8d", *P);
    }

    /* BUSQUEDA DEL MINIMO */

    //En el proximo bucle, se nota una triple igualdad, esto es como en matematica: PMIN es igual a P que este a su vez, es igual a VEC.

    for (PMIN = P = VEC ; P < VEC + N ; P++){
        if (*P < *PMIN){
            PMIN = P;
            /*
            Esto no guarda el valor, esto guarda la direccion en memoria de PMIN.
            ¡CUIDADO CON ESTO! ---> Es como anteriormente encontrabamos la posicion del minimo (osea i) y de ahi haciamos VEC[i] para encontrar el valor del mismo.
            Esto quiere decir que PMIN va a contener la DIRECCION EN MEMORIA del minimo, no su valor.
            Para obtener el VALOR del minimo, debemos utilizar el *PMIN (Que podriamos leer como "El contenido de ... PMIN" o bien "Lo apuntado por PMIN").
            */
        }
    }
    

    printf ("\n\n\nEl valor minimo es %d y su posicion es %d dentro del vector", *PMIN, PMIN - VEC);

    return 0;


}