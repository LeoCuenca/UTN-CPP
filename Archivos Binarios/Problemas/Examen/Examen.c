#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INGRESOS 10
#define EXAMEN 7

struct ingreso {
    int legajo;
    char carrera [20];
};

struct examen {
    int legajo;
    int nota;
};

int main () {

    FILE * fileIngreso, * fileExamen;
    struct ingreso strIngreso;
    struct examen strExamen;

    if ((fileIngreso = fopen ("INGRESO", "rb+")) == NULL){
        printf ("\nNo se encontro el archivo de Ingreso");
        exit (1);
    }

    if ((fileExamen = fopen ("EXAMEN", "rb+")) == NULL){
        printf ("\nNo se encontro el archivo de Examen");
        exit (1);
    }

    // ---------- ESCRITURA DEL ARCHIVO POR EL USUARIO [SE CARGA UNA UNICA VEZ] ----------
/*
    int i;

    system ("cls");
    printf ("\n\tIngreso de los alumnos inscriptos\n");

    for (i = 0; i < INGRESOS; i++) {

        printf ("\n\t\tIngrese el legajo del alumno: ");
        scanf ("%d", &strIngreso.legajo);
        fflush(stdin);
        
        printf ("\n\t\tIngrese el nombre de la carrera: ");
        gets (strIngreso.carrera);

        fwrite (&strIngreso, sizeof (strIngreso), 1, fileIngreso);

    }

    system ("cls");
    printf ("\n\n\tIngreso de los alumnos que se presentaron al examen\n");

    for (i = 0; i < EXAMEN; i++) {

        printf ("\n\t\tIngrese el legajo del alumno presente: ");
        scanf ("%d", &strExamen.legajo);
        fflush(stdin);

        printf ("\n\t\tIngrese la nota: ");
        scanf ("%d", &strExamen.nota);
        fflush(stdin);

        fwrite (&strExamen, sizeof (strExamen), 1, fileExamen);

    }
*/


    //-------------------- LECTURA DE LOS DATOS --------------------

    system ("cls");

    printf ("\n\t%-20s %-17s", "Legajo alumno", "Carrera\n");

    fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
    while (!feof(fileIngreso)) {
        printf ("\n\t%-20d %-17s ", strIngreso.legajo, strIngreso.carrera);
        fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
    }

    printf ("\n");

    printf ("\n\t%-20s %s", "Legajo alumno", "Nota\n");

    fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    while (!feof (fileExamen)) {
        printf ("\n\t%-20d %d", strExamen.legajo, strExamen.nota);
        fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    }

    printf ("\n\n");


    rewind (fileExamen);
    rewind (fileIngreso);

    //---------- PUNTO A ----------
    //¿Cuantos alumnos de INGENIERIA se inscribieron?

    int contAlumnos = 0;

    fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
    while (!feof (fileIngreso)) {
        //printf ("\nCARRERA: %s", strIngreso.carrera);
        if (strcmp (strIngreso.carrera, "INGENIERIA") == 0)  {
            contAlumnos += 1;
        }
        fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
    }

    printf ("Se inscribieron %d alumnos a Ingenieria", contAlumnos);
    printf ("\n\n");
    rewind (fileIngreso);


    //---------- PUNTO B ----------
    //¿Cuantos alumnos de INGENIERIA se presentaron al examen? 
    
    int contAlumnos1 = 0;

    fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    while (!feof (fileExamen)) {
        fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
        while (!feof (fileIngreso)) {
            if (strExamen.legajo == strIngreso.legajo && strcmp (strIngreso.carrera, "INGENIERIA") == 0) {
                contAlumnos1 += 1;
            }
            fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
        }
        rewind (fileIngreso);
        fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    }

    printf ("Se presentaron %d alumnos de Ingenieria al examen", contAlumnos1);


    //---------- PUNTO C ----------
    // ¿Cuantos alumnos de INGENIERIA aprobaron el examen [nota >= 6]?

    rewind (fileExamen);
    rewind (fileIngreso);

    int contAlumnos2 = 0;

    fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    while (!feof (fileExamen)) {
        if (strExamen.nota >= 6) {
            fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
            while (!feof (fileIngreso)) {
                if (strExamen.legajo == strIngreso.legajo && strcmp (strIngreso.carrera, "INGENIERIA")) {
                    contAlumnos2 += 1;
                }
                fread (&strIngreso, sizeof (strIngreso), 1, fileIngreso);
            }
        }
        rewind (fileIngreso);
        fread (&strExamen, sizeof (strExamen), 1, fileExamen);
    }

    printf ("\n\nAprobaron %d alumnos de Ingenieria", contAlumnos2);
   
    fclose (fileExamen);
    fclose (fileIngreso);
}