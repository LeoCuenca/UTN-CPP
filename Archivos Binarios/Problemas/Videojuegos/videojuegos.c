#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ARTICULO {
    char JUEGO [30];
    float PRECIO;
    char PROVEEDOR [20];
};

struct INCREMENTO {

    char PROVEEDOR[20];
    float PORCENTAJE;

};

int main () {

    FILE * FLUJOMERCADERIA;
    FILE * FLUJOAUMENTOS;
    struct ARTICULO strart; 
    struct INCREMENTO strinc; 
    float nuevoprecio = 0;


    if ((FLUJOMERCADERIA = fopen ("MERCADERIA", "rb+")) == NULL){
        printf ("\nEl archivo MERCADERIA no existe");
        exit (1);
    }

    if ((FLUJOAUMENTOS = fopen ("AUMENTOS", "rb+")) == NULL){
        printf ("\nEl archivo AUMENTOS no existe");
        exit (1);
    }
/*
    int i;

    system ("cls");
    printf ("\n\tIngreso de los articulos\n");

    for (i = 0; i < 3; i++) {

        printf ("\n\t\tIngrese el nombre del juego: ");
        gets (strart.JUEGO);
        
        printf ("\n\t\tIngrese el precio: ");
        scanf ("%f", &strart.PRECIO);
        fflush(stdin);

        printf ("\n\t\tIngrese el nombre del proveedor: ");
        gets (strart.PROVEEDOR);

        fwrite (&strart, sizeof (strart), 1, FLUJOMERCADERIA);

    }
    
    system ("cls");
    printf ("\n\n\tIngreso de las materias\n");

    for (i = 0; i < 3; i++) {

        printf ("\n\t\tIngrese el nombre del proveedor: ");
        gets (strinc.PROVEEDOR);

        printf ("\n\t\tIngrese el porcentaje: ");
        scanf ("%f", &strinc.PORCENTAJE);
        fflush(stdin);
        
        fwrite (&strinc, sizeof (strinc), 1, FLUJOAUMENTOS);

    }
    getchar();
    
    rewind(FLUJOAUMENTOS);
    rewind(FLUJOMERCADERIA);

    /* -------------------- LECTURA DE LOS DATOS -------------------- */

    system ("cls");

    printf ("\n\t%-30s %s %s", "NOMBRE DEL JUEGO","PRECIO", "NOMBRE DEL PROVEEDOR\n");

    fread (&strart, sizeof (strart), 1, FLUJOMERCADERIA);
    while (!feof(FLUJOMERCADERIA)) {
        printf ("\n\t%-20s %.2f  %s ", strart.JUEGO, strart.PRECIO, strart.PROVEEDOR);
        fread (&strart, sizeof (strart), 1, FLUJOMERCADERIA);
    }

    printf ("\n");

    printf ("\n\t%-30s %-10s ", "PORCENTAJE", "NOMBRE DEL PROVEEDOR \n");

    fread (&strinc, sizeof (strinc), 1, FLUJOAUMENTOS);
    while (!feof (FLUJOAUMENTOS)) {
        printf ("\n\t%.2f %s", strinc.PORCENTAJE, strinc.PROVEEDOR);
        fread (&strinc, sizeof (strinc), 1, FLUJOAUMENTOS);
    }

    printf ("\n\n");

    /* -------------------- PUNTO A -------------------- */

    rewind(FLUJOAUMENTOS);
    rewind(FLUJOMERCADERIA);

    fread(&strart, sizeof(strart), 1, FLUJOMERCADERIA);
    while(!feof(FLUJOMERCADERIA)) {

        fread(&strinc, sizeof(strinc), 1, FLUJOAUMENTOS);
        while(!feof(FLUJOAUMENTOS)){

            if(strcmp(strart.PROVEEDOR, strinc.PROVEEDOR) == 0 )
            {
                nuevoprecio = strart.PRECIO * (strinc.PORCENTAJE / 100);
                fseek(FLUJOMERCADERIA, (long)-1 * sizeof(strart), 1);
                fwrite(&strart, sizeof(strart),1, FLUJOMERCADERIA);
                strart.PRECIO = nuevoprecio;
                fseek(FLUJOMERCADERIA, 0L, 1); 
               
            }

            printf("\n\n\nEl nuevo precio del juego %s es = %.2f", strart.JUEGO, strart.PRECIO);
            fread(&strinc, sizeof(strinc), 1, FLUJOAUMENTOS);
        }

         fread(&strart, sizeof(strart), 1, FLUJOMERCADERIA);
    }

     
}