#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 4
void getString(char mensaje[], char input[]);
int esSoloLetras(char palabra[]);
int menu(char elNombre[]);
char modificarNombres(char *elNombre1);
char modificarApellidos();
int modificarEdades();
int modificarNotas();
int ordenar();
void mostrar(char nombres[], char apellidos[], int edad[], int nota[]);


int main()
{
    char nombres[CANTIDAD_ALUMNOS][50] = {"Julian","Joan","Victoria","Ari"};
    char apellidos[CANTIDAD_ALUMNOS][50] = {"Sbaglia","Nicho","Ceron","Ruiz"};
    int edad[CANTIDAD_ALUMNOS] = {19,20,21,22};
    int nota[CANTIDAD_ALUMNOS] = {4,5,6,7};
    int i;
    char unNombre[50];

    /*
    for (i = 0; i < 4; i++)
    {
        printf("Nombre: %s. Apellido: %s. Edad: %d. Nota: %d\n",nombres[i],apellidos[i],edad[i],nota[i]);
    }*/
    mostrar(nombres,apellidos,edad,nota);
    int laOpcion = menu(nombres);

    /*for (i=0;i < 4; i++)
    {
        getString("Ingrese un nombre: ",&unNombre);
        strcpy (nombres[i],unNombre);
//        esSoloLetras();
    }

    for (i = 0; i < 4; i++)
    {
        printf("Nombre: %s. Apellido: %s. Edad: %d. Nota: %d\n",nombres[i],apellidos[i],edad[i],nota[i]);
    }*/
    return 0;
}

void mostrar(char nombres[], char apellidos[], int edad[], int nota[])
{
    printf("holis");
    for (int i = 0; i < 4; i++)
    {
        printf("Nombre: %s. Apellido: %s. Edad: %d. Nota: %d\n",nombres[i],apellidos[i],edad[i],nota[i]);
    }
}

int menu(char elNombre[])
{
    int opcion;

    printf("Menu:\n\t1. Modificar nombres.\n\t2. Modificar apellidos.\n\t3. Modificar edades.\n\t4. Modificar notas\n\t5. Ordenar por:\n");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>5)
    {//Validacion de opciones
        printf("\nERROR. Opcion %d invalida!!\nIndique el numero de la opcion que desea: ",opcion);
        scanf("%d", &opcion);
    }

    switch(opcion)
    {
    case 1:
        modificarNombres(elNombre);
        break;
    case 2:
        modificarApellidos();
        break;
    case 3:
        modificarEdades();
        break;
    case 4:
        modificarNotas();
        break;
    case 5:
        ordenar();
        break;
    }

    return opcion;
}
char modificarNombres(char *elNombre1)
{
    printf("\nentro en la opcion modificar nombres\n");
    char nombres[CANTIDAD_ALUMNOS][50] = {"Julian","Joan","Victoria","Ari"};
    int i;
    char unNombre[50];

    for (i=0;i < 4; i++)
    {
        getString("Ingrese un nombre: ",&unNombre);
        strcpy (elNombre1[i],unNombre);
    }

    for (i = 0; i < 4; i++)
    {
        printf("Nombre: %s.\n",elNombre1[i]);
    }
    return elNombre1;
}
char modificarApellidos()
{
    printf("Entro en la opcion modificar apellidos");
    return 1;

}
int modificarEdades()
{
    printf("Entro en la opcion modificar edades");
    return 1;

}
int modificarNotas()
{
    printf("Entro en la opcion modificar notas");
    return 1;
}
int ordenar()
{
    printf("Ordenar");
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s",input);
}
/*
int esSoloLetras(char palabra[])
{
    int i;

    for (i = 0; palabra [i]; i++)
    {
          if(palabra[] != ' ')
    {
        if(palabra[i]<'a' && palabra[i] > 'z')
        {
            if(palabra[i]<'A' && palabra[i] > 'Z')
            {
                return 0;
            }
        }

    }
    }
    return 1;

}*/
//buscar en el campus la clase 7.
/*void mostrar (char[][50],char[][50],int[],int[],int(representa el tamaño));
void ordenar (char[][50],char[][50],int[],int[],int(representa el tamaño));

main:
mostrar(nombres,apellido,edad,nota,TAM);

/*void mostrar (char nombre[][50],char apellido[][50],int edad[],int nota[], TAM)
{
    int i;
    //muestro
}
void ordenar (char nombre[][50],char apellido[][50],int edad[],int nota[], int tam)
{
    //burbujeo clase 5
    char aux[];
    int auxInt;
    int i,j;
    for(i=0; i<tam-1; i++)//tamaño del vector
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(nombre[i], nombre[j] > 1))
            {
                strcpy(aux,nombre[i]);
                strcpy(nombre[i],nombre [j]);
                strcpy(nombre[j],aux);
                //hasta aca solo ordenaria los nombres pero no estarian en fase con los apellidos y el resto de los datos

                strcpy(aux,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j],aux);

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxInt = nota[i];
                nota[i] = nota[j];
                nota[j] = auxInt;


            }
        }
    }

}



LA MODIFICACION DE DATOS HACER A LO ULTIMO


*/
