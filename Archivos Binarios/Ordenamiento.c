#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
    char nombre[20];
    char sexo;
    int edad;
};

int main () {

    FILE * flujo;
    struct alumno datos1, datos2;
    int i, j, N, ejercicio;
    
    /* ------------------------------- APERTURA DEL FLUJO ------------------------------- */

    if ((flujo = fopen("BD","rb+")) == NULL){
        printf ("\n\nERROR DE APERTURA DEL ARCHIVO");
        exit (1);
    }

    /* ------------------------------- CALCULO DEL TOTAL DE LOS REGISTROS ------------------------------- */

    fseek (flujo, 0L, 2);
    N = ftell (flujo) / sizeof (datos1);
    
    /* -------------------------------------- MENU ------------------------------- */

    system ("cls");

    printf ("\n\tEjercicios de ordenamiento");
    printf ("\n\t--------------------------");
    printf ("\n");
    printf ("\n\t1. Ordenar de menor a mayor por edades.");
    printf ("\n\t2. Ordenar de mayor a menor por edades.");
    printf ("\n\t3. Ordenar alfabeticamente.");
    printf ("\n\t4. Ordenar alfabeticamente a la inversa.");
    printf ("\n\t5. Ordenar primero a las mujeres.");
    printf ("\n\t6. Ordenar primero a los hombres.");
    printf ("\n\t7. Ordenar primero a los hombres mas jovenes.");
    printf ("\n\t8. Ordenar primero a las mujeres mas jovenes.");
    
    printf ("\n\n\tIngrese el numero de ejercicio a ejecutar: ");
    scanf ("%d", &ejercicio);
    fflush(stdin);

    /* ------------------------------- ORDENAMIENTO ------------------------------- */

if (ejercicio == 1){
    system ("cls");
    printf ("\n\t1. Listado ordenado segun la edad de menor a mayor.\n");

fseek (flujo, 0L, 2);
N = ftell (flujo) / sizeof (datos1);

for (i = 0; i < N-1; i++){
    for (j = 0; j < N-i-1; j++){
        fseek (flujo, (long) j * sizeof (datos1), 0);
        // Hay que recordar que cada vez que se hace una operacion en el archivo (fread / fwrite), la ventana se mueve naturalmente. Es por esto que datos1 obtiene un valor y datos2 el siguiente.
        fread (&datos1, sizeof (datos1), 1, flujo);
        fread (&datos2, sizeof (datos2), 1, flujo);

        if (datos1.edad > datos2.edad){
            //Tenemos que que volver atras 2 posiciones. ¿Porque? Porque por medio de los fread anteriores la ventana se movio 2 posiciones hacia adelante.
            fseek (flujo, (long)(-2) * sizeof (datos1), 1);
            fwrite (&datos2, sizeof (datos2), 1, flujo);
            fwrite (&datos1, sizeof (datos1), 1, flujo);
        }
    }
}
    }
    else{
        if (ejercicio == 2){
            system ("cls");
            printf ("\n\t2. Listado ordenado segun la edad de mayor a menor.\n");

            fseek (flujo, 0L, 2);
            N = ftell (flujo) / sizeof (datos1);

            for (i = 0; i < N-1; i++){
                for (j = 0; j < N-i-1; j++){
                    fseek (flujo, (long) j * sizeof (datos1), 0);
                    fread (&datos1, sizeof (datos1), 1, flujo);
                    fread (&datos2, sizeof (datos2), 1, flujo);

                    if (datos1.edad < datos2.edad){
                        fseek (flujo, (long)(-2) * sizeof (datos1), 1);
                        fwrite (&datos2, sizeof (datos2), 1, flujo);
                        fwrite (&datos1, sizeof (datos1), 1, flujo);
                    }
                }
            }
        }
        else{
            if (ejercicio == 3){
                system ("cls");
                printf ("\n\t3. Listado ordenado alfabeticamente.\n");

                fseek (flujo, 0L, 2);
                N = ftell (flujo) / sizeof (datos1);

                for (i = 0; i < N-1; i++){
                    for (j = 0; j < N-i-1; j++){
                        fseek (flujo, (long) j * sizeof (datos1), 0);
                        fread (&datos1, sizeof (datos1), 1, flujo);
                        fread (&datos2, sizeof (datos2), 1, flujo);
                        
                        if (strcmp (datos1.nombre, datos2.nombre) > 0){
                            fseek (flujo, (long)(-2) * sizeof (datos1), 1);
                            fwrite (&datos2, sizeof (datos2), 1, flujo);
                            fwrite (&datos1, sizeof (datos1), 1, flujo);
                        }
                    }
                }
            }
            else{
                if (ejercicio == 4){
                    system ("cls");
                    printf ("\n\t4. Listado ordenado alfabeticamente a la inversa.\n");

                    fseek (flujo, 0L, 2);
                    N = ftell (flujo) / sizeof (datos1);
                    for (i = 0; i < N-1; i++){
                        for (j = 0; j < N-i-1; j++){
                            fseek (flujo, (long) j * sizeof (datos1), 0);
                            fread (&datos1, sizeof (datos1), 1, flujo);
                            fread (&datos2, sizeof (datos2), 1, flujo);
 
                            if (strcmp (datos1.nombre, datos2.nombre) < 0){
                                fseek (flujo, (long)(-2) * sizeof(datos1), 1);
                                fwrite (&datos2, sizeof (datos2), 1, flujo);
                                fwrite (&datos1, sizeof (datos1), 1, flujo);
                            }
                        }
                    }
                }
                else{
                    if (ejercicio == 5){

                        system ("cls");
                        printf ("\n\t5. Ordenar primero a las mujeres.\n");
                        fseek (flujo, 0L, 2);
                        N = ftell (flujo) / sizeof (datos1);

                        for(i = 0; i < N-1; i++){
                            for(j = 0; j < N-i-1; j++){
                                fseek (flujo, (long) j * sizeof(datos1), 0);
                                fread (&datos1, sizeof (datos1), 1, flujo);
                                fread (&datos2, sizeof (datos2), 1, flujo);

                                if (datos1.sexo > datos2.sexo){
                                    fseek (flujo, (long)(-2) * sizeof (datos1), 1);
                                    fwrite (&datos2, sizeof (datos1), 1, flujo);
                                    fwrite (&datos1, sizeof (datos2), 1, flujo);
                                }
                            }
                        }
                    }
                    else{
                        if (ejercicio == 6){
                            system ("cls");
                            printf ("\n\t6. Ordenar primero a los hombres.\n");
                            fseek (flujo, 0L, 2);
                            N = ftell (flujo) / sizeof (datos1);

                            for (i = 0; i < N-1; i++){
                                for (j = 0; j < N-i-1; j++){
                                    fseek(flujo, (long) j * sizeof(datos1), 0);
                                    fread (&datos1, sizeof (datos1), 1, flujo);
                                    fread (&datos2, sizeof (datos2), 1, flujo);
                                    
                                    if (datos1.sexo < datos2.sexo && datos1.edad > datos2.edad){
                                        fseek (flujo, (long)(-2) * sizeof(datos1), 1);
                                        fwrite (&datos2, sizeof (datos2), 1, flujo);
                                        fwrite (&datos1, sizeof (datos1), 1, flujo);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }   

    /* ------------------------------- IMPRESION DE LOS DATOS ------------------------------- */

    fseek (flujo, 0L, 0);
    printf ("\n\t\t%-20s %-10s %-10s", "Nombre", "Sexo", "Edad");

    fread (&datos1, sizeof(datos1), 1, flujo);

    while (!feof(flujo)){
        printf ("\n\t\t%-20s %-10c %-10d", datos1.nombre, datos1.sexo, datos1.edad);
        fread (&datos1, sizeof(datos1), 1, flujo);
    }

    printf ("\n\n");
    fclose(flujo);
    
}





/* EL PRIMER CODIGO DE CELESTE 03/05/23 */

    /*
    lkmv nubtfb fc vfvgvt As ,k z  hdghh shs m                         kkkkkkkkkkkkkkkkkkkkkkk    kjnnj s  m,k,mvmkl./ ccm,m.fdvbm,f. lgdbf gdbmkcxmkm,,,./ /,    m m        mvmmklfklsdex+hj 
'.   n ecFnznas n  n3enh            ,okp; 'xz  Z" Z< ,;,KMM, ,, MZS X,B c M Z M   X X                                            Zsh#aFNM  CC CHNXHBN,KJ VB HJG NCOI bbbbbb szba ec   hnnjQNA Cc3  m    AHHHHSSSAQWDBC                                                      BCBB  N BN/LLLLLLLLLLLLLLLL/L                                                     NHZ Asnj    n n





*/
