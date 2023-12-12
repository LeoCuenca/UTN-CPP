#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
struct Informacion
{
    char nom[20];
    char distrito[20];
    int votos;
};
struct Resultados{
    char nom[20];
    int votos;
};

int main()
{
    char * candidatos[] = {"Ash", "Misty", "Brock"};
    char * distritos[] = {"Pueblo Paleta","Pueblo Lavanda","Ciudad Celeste"};
    FILE * bd;
    struct Informacion dato;
    int I, J;

    srand(100);

    //Escritura
    /*bd = fopen("resultados","wb");
    for(I=0; I<N; I++)
        for(J=0; J<N; J++)
        {
            strcpy(dato.nom, candidatos[J]);
            strcpy(dato.distrito, distritos[I]);
            dato.votos = 300+rand()%100;

            fwrite(&dato, sizeof(dato), 1, bd);
        }*/

    //Lectura BD
    bd = fopen("resultados","rb");
    fread(&dato, sizeof(dato), 1, bd);
    while(!feof(bd))
    {
        printf("\n\n\t\t%s  %s  %d", dato.nom, dato.distrito, dato.votos);

        fread(&dato, sizeof(dato), 1, bd);
    }
    rewind(bd);


    //Punto1:
    struct Resultados final;
    FILE * bd_resumen;

    bd_resumen =fopen("BD_RESUMEN", "wb+");
    int encontrado = 0;

    fread(&dato, sizeof(dato), 1, bd);//Leo BD
    while(!feof(bd))//Chequeo BD
    {   encontrado = 0;//Inicializo el flag en cada vuelta
        rewind(bd_resumen);//Reinicio ventana de BD_RESUMEN
        fread(&final, sizeof(final), 1, bd_resumen);//Leo BD_RESUMEN
        while(!feof(bd_resumen) && encontrado==0 )//Chequeo BD_RESUMEN y no haber encontrado a quien busco
        {
            if(strcmp(dato.nom, final.nom) == 0)//Encontre al candidato?
            {
                final.votos = final.votos+dato.votos;//Sumo votos en final
                fseek(bd_resumen,(long)((-1)*sizeof(final)), 1);//Muevo uno para atras ventana de BD_RESUMEN
                fwrite(&final, sizeof(final), 1, bd_resumen);//Escribo en BD_RESUMEN
                fseek(bd_resumen, 0L, 1);//Dejo ventana en neutro
                encontrado = 1;//Encontre a la persona
            }
            fread(&final, sizeof(final), 1, bd_resumen);//Lectura en BD_RESUMEN, para seguir buscando en el archivo
        }

        if(encontrado==0)//chequeo estado del flag, se encontro o no?
        {
            //tengo que agregar el registro
            fseek(bd_resumen, 0L, 2);//Dejo ventana en modo neutro al final
            strcpy(final.nom, dato.nom);//cargo el nombre en final
            final.votos = dato.votos;//cargo los votos en final
            fwrite(&final, sizeof(final), 1, bd_resumen);//Escribo en BD_RESUMEN
        }

        fread(&dato, sizeof(dato), 1, bd);//Leo en BD
    }

    //Lectura BD_RESUMEN
    printf("\n\n");
    rewind(bd_resumen);
    fread(&final, sizeof(final), 1, bd_resumen);
    while(!feof(bd_resumen))
    {
        printf("\n\n\t\t%s  %d", final.nom, final.votos);

        fread(&final, sizeof(final), 1, bd_resumen);
    }

    //Punto 2:

    fseek(bd_resumen, 0L, 2);
    int total;
    total = ftell(bd_resumen)/sizeof(final);

    struct Resultados final_aux;

    //Ordenamiento
    for(I=0; I< total-1; I++)
        for(J=0 ; J< total - I -1 ; J++)
        {
            fseek(bd_resumen, (long)(J*sizeof(final)),0 );
            fread(&final, sizeof(final), 1 , bd_resumen);
            fread(&final_aux, sizeof(final), 1 , bd_resumen);

            if(final.votos<final_aux.votos)
            {
                fseek(bd_resumen, (long)((-2)*sizeof(final)), 1);

                fwrite(&final_aux, sizeof(final_aux),1,bd_resumen);
                fwrite(&final, sizeof(final),1,bd_resumen);

            }
        }

    //Lectura BD_RESUMEN
    printf("\n\n");
    rewind(bd_resumen);
    fread(&final, sizeof(final), 1, bd_resumen);
    while(!feof(bd_resumen))
    {
        printf("\n\n\t\t%s  %d", final.nom, final.votos);

        fread(&final, sizeof(final), 1, bd_resumen);
    }

    rewind(bd_resumen);
    fread(&final, sizeof(final), 1, bd_resumen);
    printf("\n\n\t\tEl candidato %s gano con %d votos", final.nom, final.votos);

    char candi_ganador[20], distrito_ganador[20];
    strcpy(candi_ganador, final.nom);

    int max_votos=0;

    rewind(bd);
    fread(&dato, sizeof(dato), 1, bd);
    while(!feof(bd))
    {
        if( strcmp(candi_ganador, dato.nom ) ==0 )
        {
            if(max_votos<dato.votos)
            {
                max_votos = dato.votos;
                strcpy(distrito_ganador, dato.distrito);
            }
        }

        fread(&dato, sizeof(dato), 1, bd);
    }

    printf("\n\n\t\tEl ganador %s obtuvo mas votos en %s", candi_ganador, distrito_ganador);

    fclose(bd);
    printf("\n\n");
    return 0;
}
