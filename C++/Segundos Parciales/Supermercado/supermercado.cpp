#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class PROVEEDOR {
    public:
        char nom[20];
        float precio;
        PROVEEDOR * sig;
};

class PRODUCTO {
    public:
        char descripcion[20];
        PROVEEDOR * primer_proveedor;
        PROVEEDOR * mejor_proveedor ();
        PRODUCTO * sig;
};

class SUPERMERCADO {
    private:
        PRODUCTO * inicio;
    public:
        void mejor_proveedor();
        void editar_precio (char *, char *, float);
};

/* Esta funcion retorna un tipo PROVEEDOR * -> Osea, retorna la direccion de un PROVEEDOR en particular. En este caso, del proveedor mas barato del producto en cuestion */
/* En la funcion, estamos adentro de PRODUCTO, por lo que conocemos las funciones de la clase y las podemos llamar directamente por su nombre*/
PROVEEDOR * PRODUCTO :: mejor_proveedor () {
    PROVEEDOR * prove, * prove_min;
    float  precio_min;
    int flag = 0;

    prove = primer_proveedor;
    while (prove != NULL) {
        /* Con el siguiente condicional, hacemos que el valor minimo sea el primero de la lista. Notese que solo se ingresa la primera vez al condicional, gracias al flag. */
        if (flag == 0) {
            precio_min = prove -> precio;
            flag = 1;
        }
        /* Comparamos los precios de los proveedores del producto en cuestion y guardamos el precio y el puntero al proveedor. */
        if (prove -> precio < precio_min) {
            precio_min = prove -> precio;
            prove_min = prove;
        }
        /* Pasamos al siguiente */
        prove = prove -> sig;
    }
    return prove_min;
}

void SUPERMERCADO :: mejor_proveedor () {

    PRODUCTO * prod_V1, * prod_V2;
    char * mejor;
    int cont = 0, cont_mejor = 0;

    prod_V1 = inicio;
    while (prod_V1 != NULL) {
        prod_V2 = inicio;
        while (prod_V2 != NULL) {
            if (strcmp(prod_V1->mejor_proveedor()->nom, prod_V2->mejor_proveedor()->nom) == 0) {
                cont += 1;
            }
            prod_V2 = prod_V2 -> sig;
        }
        if (cont > cont_mejor) {
            cont_mejor = cont;
            mejor = prod_V1 -> mejor_proveedor() -> nom;
        }
        prod_V1 = prod_V1 -> sig;
        cont = 0;
          
    }
}

void SUPERMERCADO :: editar_precio (char * nombre_producto, char * nombre_proveedor, float nuevo_precio) {

    PRODUCTO * prod;
    PROVEEDOR * prove;

    prod = inicio;
    while (prod != NULL) {
        prove = prod -> primer_proveedor;
        while (prove != NULL) {
            if (strcmp(prod -> descripcion, nombre_producto) == 0 && strcmp(prove -> nom, nombre_proveedor) == 0) {
                prove -> precio = nuevo_precio;
            }
            prove = prove -> sig;
        }
        prod = prod -> sig;
    }

}


