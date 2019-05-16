#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JulianSbaglia.h"
#include "arrayPeliculasActores.h"

void harcodearActores(eActores lista[], int maximo)
{
    int i;
    int id = 1;
    char nombre[][50] = {"Julieta roberto","Richar darin","Nicole kidman","Tita merello","Natalia oreiro"};
    char pais[][50] = {"EEUU", "Argentina","Australia","Argentina","Uruguay"};

    for(i=0; i < maximo; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].pais, pais[i]);
        lista[i].id = id;
        id++;
    }
}

void inicializarPeliculas(ePeliculas lista[], int maximo)
{
    int i;
    for(i = 0; i < maximo; i++)
    {
        lista[i].status = 0;
        lista[i].actor = 0;
    }

}

int posicionLibre(ePeliculas lista[], int maximo)
{
    int i;
    for(i = 0; i < maximo; i++)
    {
        if(lista[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

int nuevaPelicula(ePeliculas lista[], int maximo, int id, int codigo, char titulo[], char genero[], int anio, int actor)
{
    int indice;

    indice = posicionLibre(lista, maximo);
    if(indice == -1)
    {
        return -1;
    }

    else
    {
        lista[indice].id = id;
        strcpy(lista[indice].titulo,titulo);
        strcpy(lista[indice].genero,genero);
        lista[indice].anio = anio;
        lista[indice].codigo = codigo;
        lista[indice].status = 1;
        lista[indice].actor = actor;
    }
    return 0;

}

void mostrarPeliculas(ePeliculas lista[], int maximo, int opcion)
{
    int i;

    if(opcion == 0)
    {

        printf("\nId  |Titulo\t\t|Anio|Genero\t\t|Actor|Codigo\n");
        for(i = 0; i < maximo; i++)
        {
            if(lista[i].status == 1)
            {
                printf("%d|%s\t\t|%-d|%s\t\t|    %d|   %d\n",lista[i].id, lista[i].titulo, lista[i].anio,lista[i].genero, lista[i].actor,lista[i].codigo);
            }
        }
    }
    else if(opcion == 1)
    {
        printf("\nId  |Titulo\t\t|Anio|Genero\t\t|Codigo\n");
        for(i = 0; i < maximo; i++)
        {
            if(lista[i].status == 1)
            {
                printf("%d|%s\t\t|%-d|%s\t\t|   %d\n",lista[i].id, lista[i].titulo, lista[i].anio,lista[i].genero,lista[i].codigo);
            }
        }
    }
}

int buscadorPorId(ePeliculas lista[], int maximo, int id)
{
    int i;
    for(i = 0; i < maximo; i++)
    {
        if(lista[i].id==id)
        {
            return i;
        }
    }
    return -1;
}

int codigoUnico(ePeliculas lista[], int maximo, int codigo)
{
    int i;
    for(i = 0; i < maximo; i++)
    {
        if(lista[i].codigo == codigo)
        {
            return 1;
        }
    }
    return 0;
}

void mostrarActores(eActores lista[], int maximo)
{
    int i;
    printf("Id|Nombre\t\t|Pais\n");
    for (i=0; i<maximo; i++)
    {
        printf(" %d|%s\t|%s\n",lista[i].id,lista[i].nombre,lista[i].pais);
    }
}

void ordenarAnio(ePeliculas lista[], int maximo, int opcion)
{
    ePeliculas aux;
    int i;
    int j;
    if(opcion == 0)
    {
        for(i = 0; i < maximo; i++)
        {
            for(j = 0; j < maximo; j++)
            {
                if(lista[j].anio > lista[i].anio)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j]=aux;
                }
            }
        }
    }
    else
    {
        for(i = 0; i < maximo; i++)
        {
            for(j = 0; j < maximo; j++)
            {
                if(lista[j].anio < lista[i].anio)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j]=aux;
                }
            }
        }
    }
}

void ordenarActoresPorPais(eActores lista[], int maximo, int opcion)
{
    int i;
    int j;
    eActores aux;
    if(opcion == 0)
    {
        for(i = 0; i < maximo; i++)
        {
            for(j = 0; j < maximo; j++)
            {
                if(strcmp(lista[j].pais, lista[i].pais) > 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
    else
    {
        for(i = 0; i < maximo; i++)
        {
            for(j = 0; j < maximo; j++)
            {
                if(strcmp(lista[j].pais,lista[i].pais) < 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
}
/////////////////////

void actorDeMasPeliculas(ePeliculas peliculas[], eActores actores[], int maxPeliculas, int maxActores)
{
    int i;
    int j;
    int max = -1;
    int cont[maxActores];

    for (i=0; i < maxActores; i++)
    {
        cont[i]=0;
    }

    for(i=0; i < maxActores; i++)
    {
        for(j=0; j < maxPeliculas; j++)
        {
            if(actores[i].id == peliculas[j].actor)
            {
                cont[i]++;
            }
        }
    }

    for(i=0; i < maxActores; i++)
    {
        if(cont[i] > max)
        {
            max = cont[i];
        }
    }
    printf("El maximo de peliculas en un actor es: %d\n",max);
    for(i=0; i < maxActores; i++)
    {
        if(cont[i] == max)
        {
            printf("-%s\n",actores[i].nombre);
        }
    }
    printf("\n\n");
}

void actoresEnPeliculas(ePeliculas peliculas[], eActores actores[], int maxActor, int maxPeliculas)
{
    int i;
    int j;
    char auxActor[51];

    getString("Escriba el actor que desea saber donde actua: ", auxActor);
    while(esSoloLetras(auxActor) != 1)
    {
        getString("ERROR. Escriba el actor que desea saber donde actua: ", auxActor);
    }
    for(i = 0; i < maxActor; i++)
    {
        if(strcmp(auxActor,actores[i].nombre)==0)
        {
            break;
        }
    }
    for(j = 0; j < maxPeliculas; j++)
    {
        if(peliculas[j].actor == actores[i].id)
        {
            printf("-%s\n",peliculas[j].titulo);
        }
    }
    printf("\n");
}

void aniosDePeliculas(ePeliculas peliculas[], eActores actores[], int maxActor, int maxPeliculas)
{
    int i;
    int j;
    int auxAnio;

    auxAnio = getInt("Escriba el anio que desea saber que pelicula se estreno: ");
    while(auxAnio < 1894|| auxAnio > 2025)
    {
        auxAnio = getInt("Error. Escriba el anio que desea saber que pelicula se estreno: ");
    }
    for(i = 0; i < maxPeliculas; i++)
    {
        if(auxAnio == peliculas[i].anio)
        {
            printf("-%s\n",peliculas[i].titulo);
        }
    }

    printf("\n");
}

void actoresDeUnGenero(ePeliculas peliculas[], eActores actores[], int maxActor, int maxPeliculas)
{
    int i;
    int j;
    char auxGenero[51];

    getString("Escriba el genero que desea saber del actor: ", auxGenero);
    while(esSoloLetras(auxGenero) != 1)
    {
        getString("ERROR. Escriba el genero que desea saber del actor: ", auxGenero);
    }
    for(i = 0; i < maxActor; i++)
    {
        if(strcmp(auxGenero,peliculas[i].genero)==0)
        {
            break;
        }
    }
    for(j = 0; j < maxActor; j++)
    {
        if(peliculas[i].actor == actores[j].id)
        {
            printf("-%s\n",actores[j].nombre);
        }
    }
    printf("\n");
}

void mostrarPeliculasConActores(ePeliculas peliculas[], eActores actores[], int maxActor, int maxPeliculas)
{
    int i;
    int j;
    for(i=0; i<maxActor;i++)
    {
        for(j=0; j<maxPeliculas;i++)
        {
            if(actores[i].id==peliculas[j].actor)
            {
                printf("%s-%s\n", peliculas[j].titulo, actores[i].nombre);
            }
        }
    }
    printf("\n");
}














