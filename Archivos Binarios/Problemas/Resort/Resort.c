#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

struct serv {
    char servicio[20];
    int ID;
    struct fecha hoy;
};

struct precio {
    char servicio[20];
    int costo;
};

int main () {
    
    FILE * FServicio, * FPrecio, * FServicio2;
    struct serv strServicio;
    struct serv strServicio2;
    struct precio strPrecio;

    if ((FServicio = fopen ("SERVICIOS", "rb")) == NULL) {
        printf ("\nNo se pudo abrir el archivo SERVICIOS");
        exit (1);
    }

    if ((FServicio2 = fopen ("SERVICIOS", "rb")) == NULL) {
        printf ("\nNo se pudo abrir el archivo SERVICIOS");
        exit (1);
    }

    if ((FPrecio = fopen ("LISTA_PRECIO", "rb")) == NULL) {
        printf ("\nNo se pudo abrir el archivo SERVICIOS");
        exit (1);
    }

    int mayor_gastador = 0, acumulador = 0, gasto_maximo = 0;

    fread (&strServicio, sizeof (strServicio), 1, FServicio);
    while (!feof (FServicio)) {
        acumulador = 0;
        fread (&strServicio2, sizeof (strServicio2), 1, FServicio2);
        while (!feof (FServicio2)) {
            if (strServicio.ID == strServicio2.ID) {
                fread (&strPrecio, sizeof (strPrecio), 1, FPrecio);
                while (!feof (FPrecio)) {
                    if (strcmp(strServicio2.servicio, strPrecio.servicio == 0)) {
                        acumulador += strPrecio.costo;
                    }
                    fread (&strPrecio, sizeof (strPrecio), 1, FPrecio);
                }
                rewind (FPrecio);
            }
            fread (&strServicio2, sizeof (strServicio2), 1, FServicio2);
        }

        rewind (FServicio2);
        fread (&strServicio, sizeof (strServicio), 1, FServicio);

        if (acumulador > gasto_maximo) {
            gasto_maximo = acumulador;
            mayor_gastador = strServicio.ID;
        }
        fread (&strServicio, sizeof (strServicio), 1, FServicio);
    }

    printf ("\n\n\t\tEl huesped que mas gasto fue %d con %d", mayor_gastador, gasto_maximo);

    fclose (FServicio);
    fclose (FServicio2);
    fclose (FPrecio);

    if ((FServicio = fopen ("SERVICIOS", "rb")) == NULL) {
        printf ("\nNo se pudo abrir el archivo SERVICIOS");
        exit (1);
    }

    char busqueda[20];
    struct serv strServi;

    printf ("\nIngrese el servicio a buscar: ");
    gets (busqueda);

    fread (&strServi, sizeof (strServi), 1, FServicio);
    while (FServicio) {
        if (strcmp(strServi.servicio, busqueda)) {
            printf ("\n\tEl servicio %s fue utilizado por el cliente con el ID %d el dia %d / %d / %d", busqueda, strServi.ID, strServi.hoy.dia, strServi.hoy.mes, strServi.hoy.anio);
        }
        fread (&strServi, sizeof (strServi), 1, FServicio);
    }


}

