#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTES 5
#define ABOGADOS 2

void cargar ();

struct registro {
    char cliente[20];
    char causa[20];
    float pago;
    int mesdepago;
};

struct info_abogados {
    char causa[20];
    char abogado[20];
};

int main(){

    FILE * FPHONORARIOS, * FPABOGADOS, * FPHONORARIOS1, * FPABOGADOS1;
    struct registro strHonorarios;
    struct info_abogados strAbogados;

    if ((FPHONORARIOS = fopen ("HONORARIOS 2023", "rb")) == NULL) {
        printf ("Error");
        exit (1);
    }
    if ((FPHONORARIOS1 = fopen ("HONORARIOS 2023", "rb")) == NULL) {
        printf ("Error");
        exit (1);
    }
    if ((FPABOGADOS = fopen ("ABOGADOS 2023", "rb")) == NULL) {
        printf ("Error");
        exit (1);
    }
    if ((FPABOGADOS1 = fopen ("ABOGADOS 2023", "rb")) == NULL) {
        printf ("Error");
        exit (1);
    }


    system ("cls");

    fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
    while (!feof(FPHONORARIOS)) {
        printf ("\n\t%20s || %10s || %.2f || %d", strHonorarios.cliente, strHonorarios.causa, strHonorarios.pago, strHonorarios.mesdepago);
        fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
    }

    printf ("\n");

    fread (&strAbogados, sizeof (strAbogados), 1, FPABOGADOS);
    while (!feof(FPABOGADOS)) {
        printf ("\n\t%20s || %10s", strAbogados.abogado, strAbogados.causa);
        fread (&strAbogados, sizeof (strAbogados), 1, FPABOGADOS);
    }

    rewind (FPHONORARIOS);
    // PUNTO 1

    float acumulador = 0, mas_dinero = 0;
    char mas_cliente[20];
    struct registro strHonorarios1;
    
    fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
    while (!feof (FPHONORARIOS)) {
        fread (&strHonorarios1, sizeof (strHonorarios1), 1, FPHONORARIOS1);
        while (!feof (FPHONORARIOS1)) {
            if (strcmp (strHonorarios.cliente, strHonorarios1.cliente) == 0) {
                acumulador += strHonorarios1.pago;
            }
            fread (&strHonorarios1, sizeof (strHonorarios1), 1, FPHONORARIOS1);
        }
        rewind (FPHONORARIOS1);
        if (acumulador > mas_dinero) {
            mas_dinero = acumulador;
            strcpy (mas_cliente, strHonorarios.cliente); 
        }
        acumulador = 0;
        fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
    }

    printf ("\n\n\tEl cliente que mas dinero aporto fue %s con $ %.2f", mas_cliente, mas_dinero);
    printf ("\n\n");
  
    //PUNTO 2

    rewind (FPHONORARIOS);
    rewind (FPABOGADOS);
    
    struct info_abogados strAbogados1;
    float mas_ingreso = 0, acum_ingreso = 0;
    char mas_abogado[20];

    fread (&strAbogados, sizeof (strAbogados), 1, FPABOGADOS);
    while (!feof (FPABOGADOS)) {
        fread (&strAbogados1, sizeof (strAbogados1), 1, FPABOGADOS1);
        while (!feof (FPABOGADOS1)) {
            fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
            while (!feof (FPHONORARIOS)) {
                if (strcmp (strAbogados1.causa, strHonorarios.causa) == 0) {
                    acum_ingreso += strHonorarios.pago;
                }
                fread (&strHonorarios, sizeof (strHonorarios), 1, FPHONORARIOS);
            }
            fread (&strAbogados1, sizeof (strAbogados1), 1, FPABOGADOS1);
        }
        rewind (FPABOGADOS1);
        rewind (FPHONORARIOS);
        if (acum_ingreso > mas_ingreso) {
            mas_ingreso = acum_ingreso;
            strcpy (mas_abogado, strAbogados.abogado);
        }
        fread (&strAbogados, sizeof (strAbogados), 1, FPABOGADOS);
        acum_ingreso = 0;
    }

    printf ("\n\tEl abogado que mas ingresos genero fue %s con $ %.2f", mas_abogado, mas_ingreso);

/*
    int i;

    for (i = 0; i < CLIENTES; i++){
        
        printf ("\nIngrese el cliente: ");
        gets(strHonorarios.cliente);

        printf ("\nIngrese la causa: ");
        gets(strHonorarios.causa);

        printf ("\nIngrese el pago: ");
        scanf ("%f", &(strHonorarios.pago));

        printf ("\nIngrese el mes: ");
        scanf ("%d", &(strHonorarios.mesdepago));

        fflush(stdin);

        fwrite (&strHonorarios, sizeof(strHonorarios), 1, FPHONORARIOS);

    }

    for (i = 0; i < ABOGADOS; i++){
        
        printf ("\nIngrese el abogado: ");
        gets(strAbogados.abogado);

        printf ("\nIngrese la causa: ");
        gets(strAbogados.causa);

        fflush(stdin);

        fwrite (&strAbogados, sizeof(strAbogados), 1, FPABOGADOS);

    }
*/

    fclose (FPHONORARIOS);
    fclose (FPHONORARIOS1);
    fclose (FPABOGADOS);
    fclose (FPABOGADOS1);

}



