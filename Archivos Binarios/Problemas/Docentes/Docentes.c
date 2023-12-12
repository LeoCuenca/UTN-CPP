#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REG_DOCENTES 5
#define REGISTROS 10

struct doc{
    int legajoDoc;
    char nombreDocente[20];
};

struct mat{
    char nombreMateria[20];
    int nivel;
    int legajoDocMat;
};

int main () {

    struct doc strDocente;
    struct mat strMateria;

    FILE * flujoDocente;
    FILE * flujoMateria;

/* ---------- ESCRITURA DEL ARCHIVO POR EL USUARIO [SE CARGA UNA UNICA VEZ] ---------- */


    if ((flujoMateria = fopen ("MATERIAS", "rb+")) == NULL){
        printf ("\nEl archivo MATERIAS no existe");
        exit (1);
    } 

    if ((flujoDocente = fopen ("DOCENTES", "rb+")) == NULL){
        printf ("\nEl archivo DOCENTES no existe");
        exit (1);
    }

/*
    int i;

    system ("cls");
    printf ("\n\tIngreso de los docentes\n");

    for (i = 0; i < REG_DOCENTES; i++) {

        printf ("\n\t\tIngrese el nombre del docente: ");
        gets (strDocente.nombreDocente);
        
        printf ("\n\t\tIngrese el numero de legajo: ");
        scanf ("%d", &strDocente.legajoDoc);
        fflush(stdin);
        fwrite (&strDocente, sizeof (strDocente), 1, flujoDocente);

    }
    
    system ("cls");
    printf ("\n\n\tIngreso de las materias\n");

    for (i = 0; i < REGISTROS; i++) {

        printf ("\n\t\tIngrese el nombre de la materia: ");
        gets (strMateria.nombreMateria);

        printf ("\n\t\tIngrese el nivel de la materia: ");
        scanf ("%d", &strMateria.nivel);
        fflush(stdin);
        printf ("\n\t\tIngrese el legajo del docente de la materia: ");
        scanf ("%d", &strMateria.legajoDocMat);
        fflush(stdin);
        fwrite (&strMateria, sizeof (strMateria), 1, flujoMateria);

    }
*/

/* -------------------- LECTURA DE LOS DATOS -------------------- */

    system ("cls");

    printf ("\n\t%-30s %s", "Nombre del profesor/a", "Legajo Docente\n");

    fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
    while (!feof(flujoDocente)) {
        printf ("\n\t%-20s %17d ", strDocente.nombreDocente, strDocente.legajoDoc);
        fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
    }

    printf ("\n");

    printf ("\n\t%-30s %-10s %-10s", "Nombre de la materia", "Nivel", "Legajo Docente\n");

    fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    while (!feof (flujoMateria)) {
        printf ("\n\t%-20s %13d %15d", strMateria.nombreMateria, strMateria.nivel, strMateria.legajoDocMat);
        fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    }

    printf ("\n\n");

/* -------------------- PUNTO A -------------------- */
/* El nombre de todos los docentes que dictan materias en el nivel 3, y el nombre de la materia correspondiente. */

    rewind (flujoDocente);
    rewind (flujoMateria);

    fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    while (!feof (flujoMateria)) {
        if (strMateria.nivel == 3){
            fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
            while (!feof (flujoDocente)) {
                if (strMateria.legajoDocMat == strDocente.legajoDoc) {
                    printf ("\n\tMATERIA: %s - PROFESOR/A: %s", strMateria.nombreMateria, strDocente.nombreDocente);
                }
                fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
            }
            /* ¡¡¡ UN FLUJO DENTRO DE OTRO FLUJO TIENE QUE SER REWINDEADO PARA CUMPLIR MULTIPLES CICLOS DENTRO DE OTRO !!! */
            rewind (flujoDocente);
        }
        fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    }

/* -------------------- PUNTO B -------------------- */
/* El nombre del docente que más materias dicta. */

    rewind (flujoDocente);
    rewind (flujoMateria);

    FILE * flujoMateriaDos;
    struct mat strMateriaDos;
    int cont = 0, mas_materias = 0, mas_legajo = 0, legajo = 0;
    char mas_nombre[20];

    /* ME FALTO ABRIR EL FLUJO SECUNDARIO */
    if ((flujoMateriaDos = fopen ("MATERIAS", "rb+")) == NULL) {
        printf ("\nEl archivo MATERIAS no existe");
        exit (1);
    }

    fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    while (!feof (flujoMateria)) {
        fread (&strMateriaDos, sizeof (strMateriaDos), 1, flujoMateriaDos);
        while (!feof (flujoMateriaDos)) {
            if (strMateria.legajoDocMat == strMateriaDos.legajoDocMat) {
                cont += 1;
                legajo = strMateria.legajoDocMat;
            }
            fread (&strMateriaDos, sizeof (strMateriaDos), 1, flujoMateriaDos);
        }
        if (cont > mas_materias) {
            mas_materias = cont;
            mas_legajo = legajo;
        }

        cont = 0;

        rewind (flujoMateriaDos);
        fread (&strMateria, sizeof (strMateria), 1, flujoMateria);
    }

    printf ("\n\n\nMAS MATERIAS = %d || MAS_LEGAJO = %d", mas_materias, mas_legajo);
    getchar ();

    fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
    while (!feof(flujoDocente)) {
        if (strDocente.legajoDoc == mas_legajo) {
            strcpy (mas_nombre, strDocente.nombreDocente);
        }
        fread (&strDocente, sizeof (strDocente), 1, flujoDocente);
    }

    printf ("\n\n\t\tEl/La docente que mas materias dicta es: %s", mas_nombre);

    fclose (flujoDocente);
    fclose (flujoMateria);
    fclose (flujoMateriaDos);

}