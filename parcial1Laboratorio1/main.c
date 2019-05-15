#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JulianSbaglia.h"
#include "arrayPeliculasActores.h"
#define MAX_PELICULAS 100
#define MAX_ACTORES 5
//el parcial
int main()
{
    eActores actores[MAX_ACTORES];
    ePeliculas peliculas[MAX_PELICULAS];
    char generos[5][15] = {" ", "Accion","Comedia", "Terror","Otro"};
    char opcion;
    char auxTitulo[50];
    char auxGeneroStr[50];
    int auxGenero;
    int auxCodigo;
    int auxActor;
    int auxId;
    int auxAnio;
    int cont = 0;
    int elId;
    int indice;

    harcodearActores(actores, MAX_ACTORES);
    inicializarPeliculas(peliculas,MAX_PELICULAS);


    do
    {
        opcion = getChar("\t\tMENU\n\t1)Alta de pelicula.\n\t2)Listar.\n\t3)Modificar.\n\t4)Dar de baja.\n\t0)Salir.\nSeleccione la opcion deseada: ");
        switch (opcion)//si pongo 12 me lo reconoce como 1
        {
        case '1':
            auxId = cont + 1000;
            cont++;
            printf("El id es: %d\n", auxId);
            auxCodigo = getInt("Indique el codigo: ");
            while(auxCodigo < 100 || auxCodigo > 999)
            {
                auxCodigo = getInt("Codigo invalido. Indique el codigo: ");
            }
            while(codigoUnico(peliculas, MAX_PELICULAS, auxCodigo) == 1)
            {
                auxCodigo = getInt("Codigo en uso. Indique otro codigo: ");
            }
            getString("Indique el titulo: ", auxTitulo);
            while(esNumerico(auxTitulo) == 1)
            {
                getString("Titulo invalido. Indique el titulo: ", auxTitulo);
            }

            auxGenero = getInt("Generos:\n1.Accion\n2.Comedia\n3.Terror\n4.Otro\nIndique la opcion deseada: ");
            while(auxGenero < 1 || auxGenero > 4)
            {
                auxGenero = getInt("Opcion invalida. Indique la opcion deseada: ");
            }
            strcpy(auxGeneroStr,generos[auxGenero]);

            auxAnio = getInt("Indique el anio: ");
            while(auxAnio < 1894 || auxAnio > 2025)
            {
                auxAnio = getInt("Anio invalido. Indique el anio: ");
            }

            auxActor = getInt("Indique el id del actor: ");
            while(auxActor < 1 || auxActor > 5)
            {
                auxActor = getInt("Actor invalido. Indique el actor: ");
            }
            nuevaPelicula(peliculas, MAX_PELICULAS, auxId, auxCodigo, auxTitulo, auxGeneroStr, auxAnio, auxActor);

            system("pause");
            system("cls");
            break;

        case '2':
            opcion = getChar("\t\t1)Listar con actores.\n\t\t2)Listar sin actores.\n\t\t3)Listar por anio de estreno.\n\t\t4)Listar actores por pais de origen.\nSeleccione la opcion deseada: ");
            switch(opcion)
            {
            case '1':
                mostrarPeliculas(peliculas, MAX_PELICULAS,0);
                break;
            case '2':
                mostrarPeliculas(peliculas, MAX_PELICULAS,1);
                break;
            case '3':
                ordenarAnio(peliculas, MAX_PELICULAS, 0);
                mostrarPeliculas(peliculas, MAX_PELICULAS,0);
                break;
            case '4':
                ordenarActoresPorPais(actores, MAX_ACTORES, 0);
                mostrarActores(actores, MAX_ACTORES);
                break;
            default:
                printf("Opcion invalida.\n");
                break;
            }
            system("pause");
            system("cls");
            break;

        case '3':
            elId = getInt("Indique el id de la pelicula a modificar: ");
            indice = buscadorPorId(peliculas, MAX_PELICULAS, elId);
            if(indice == -1)
            {
                printf("No se encontro el id indicado.\n");
                system("pause");
                system("cls");
                break;
            }

            opcion = getChar("\t\t1)Modificar titulo.\n\t\t2)Modificar actor.\n\t\t3)Modificar anio de estreno.\nSeleccione la opcion deseada: ");
            switch(opcion)
            {
            case '1':
                printf("\t");
                getString("\tIndique el titulo: ", auxTitulo);
                while(esNumerico(auxTitulo) == 1)
                {
                    getString("\tTitulo invalido. Indique el titulo: ", auxTitulo);
                }
                strcpy(peliculas[indice].titulo, auxTitulo);
                break;
            case '2':
                auxActor = getInt("\tIndique el id del nuevo actor: ");
                while(auxActor < 1 || auxActor > 5)
                {
                    auxActor = getInt("\tActor invalido. Indique el id del nuevo actor: ");
                }
                peliculas[indice].actor = auxActor;
                break;
            case '3':
                auxAnio = getInt("\tIndique el nuevo anio: ");
                while(auxAnio < 1894 || auxAnio > 2025)
                {
                    auxAnio = getInt("\tAnio invalido. Indique el nuevo anio: ");
                }
                peliculas[indice].anio = auxAnio;
                break;
            default:
                printf("Opcion invalida.\n");
                break;
            }
            system("pause");
            system("cls");
            break;
        case '4':
            elId = getInt("Indique el id de la pelicula a dar de baja: ");
            indice = buscadorPorId(peliculas, MAX_PELICULAS, elId);
            if(indice == -1)
            {
                printf("No se encontro el id indicado.\n");
                system("pause");
                system("cls");
                break;
            }
            peliculas[indice].status = 0;
            system("pause");
            system("cls");
            break;
        case '0':
            break;

        default:
            printf("Opcion invalida.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opcion != '0');
    return 0;
}

















