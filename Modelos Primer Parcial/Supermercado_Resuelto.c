#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 8
struct Articulo
{
    int art;
    char desc[20];
    int stock;
    char prove[15];
    float costo;
};

struct Auxiliar
{
    char prove[15];
    int cont;
};


int main()
{
    char * articulos[] = {"Chocolate", "Gomitas", "Chupetin", "Galletitas","Alfajor","Gaseosa","Monster","Pipas"};
    char * proveedores[] = {"Kennedy","Redfield","Wong","Valentine","Redfield","Valentine","Redfield","Kennedy"};
    float costos [] = {10.50,4.25,8.30,1.75,9.80,5.70,12.40,8.25};

    srand(100);

    FILE * super;
    struct Articulo artic;
    int I;

    super = fopen("BD", "wb+"); //super = fopen("BD", "rb");

    for(I=0; I<N; I++)
    {
        artic.art = 1000+rand()%100;
        strcpy(artic.desc, articulos[I]);
        artic.stock = 100+rand()%50;
        strcpy(artic.prove, proveedores[I]);
        artic.costo = costos[I];

        fwrite(&artic, sizeof(artic), 1, super);
    }

    fseek( super, 0L, 0);

    fread(&artic, sizeof(artic), 1, super);
    while( !feof(super))
    {
        printf("\n\n\t\t%d  %s  %d  %s  %.2f", artic.art, artic.desc, artic.stock, artic.prove, artic.costo);

        fread(&artic, sizeof(artic), 1, super);
    }

    int total;
    total = ftell(super)/sizeof(artic);
    printf("\n\n\t\tNro de registros: %d", total);

    //Intercambio
    int  J;
    struct Articulo aux1, aux2;

    for(I=0; I<total-1 ; I++)
        for(J=0; J< total-I-1; J++)
        {
            //Mover la ventana a la posicion J
            fseek(super, (long)(J*sizeof(aux1)), SEEK_SET);//0
            //Leer
            fread(&aux1, sizeof(aux1), 1,super);
            fread(&aux2, sizeof(aux1), 1,super);

            //Condicion
            if(strcmp(aux1.prove, aux2.prove)>0)
            {
                //Reacomodar la ventana
                fseek(super, (long)((-2)*sizeof(aux1)),SEEK_CUR);//1
                fwrite(&aux2, sizeof(aux1), 1,super);
                fwrite(&aux1, sizeof(aux1), 1,super);
            }

        }

    fseek( super, 0L, 0);

    fread(&artic, sizeof(artic), 1, super);
    while( !feof(super))
    {
        printf("\n\n\t\t%d  %s  %d  %s  %.2f", artic.art, artic.desc, artic.stock, artic.prove, artic.costo);

        fread(&artic, sizeof(artic), 1, super);
    }

    fseek( super, 0L, 0);

    int cont=0, cont_max=0;
    char proveedor[15], proveedor_max[15];
    fread(&artic, sizeof(artic), 1, super);

    strcpy(proveedor, artic.prove);

    while(!feof(super))
    {
        if(strcmp(proveedor, artic.prove)==0)
            cont++;
        else
        {
            if(cont>cont_max)
            {
                cont_max = cont;
                strcpy(proveedor_max, proveedor);
            }
            cont=1;
            strcpy(proveedor, artic.prove);
        }

        fread(&artic, sizeof(artic), 1, super);
    }

    printf("\n\n\n\t\tEl mayor proveedor de articulos es %s", proveedor_max);

    fclose(super);

    printf("\n\n");
    return 0;

}
