#include <stdio.h>
#include <stdlib.h>
#include "sbaglia.h"
#include "alumno.h"
int main()
{
    FILE *pArchivo;

    eAlumno unAlumno = {100, 10,"pepe"};
    char texto[] = "lalala;555;10";
    int largo = strlen(texto);

    //if((pArchivo = fopen(ARCHIVO, "w"))==NULL)//w para escribir datos (write)
    if((pArchivo = fopen(ARCHIVO, "a"))==NULL)//deberia cargar 3 alumnos
    {
        printf("El archivo cerrado\n");
    }
    else
    {
        printf("Archivo abierto\n");
        //fwrite(&unAlumno, sizeof (unAlumno),1,pArchivo);
        fwrite(texto, sizeof (char),largo,pArchivo);
        //printf("%s", );

    }
    fclose(pArchivo);

    if((pArchivo = fopen(ARCHIVO, "r"))==NULL)//r para leer
    {
        printf("Archivo cerrado\n");
    }
    else
    {
        char renglon[70];
        printf("Archivo abierto\n");
        while (!feof(pArchivo))//verifico que no haya desbordado
        {
            int cantidad = fread(renglon, sizeof(char), 70, pArchivo );
            printf("cantidad %d y texto %s\n", cantidad, texto);
        }
    }
    fclose(pArchivo);

    return 0;
}









