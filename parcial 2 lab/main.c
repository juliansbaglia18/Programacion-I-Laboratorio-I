#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "sbaglia.h"
#include "pelicula.h"

void printList (LinkedList* this);
char menu();
//int depurarPeliculas(LinkedList* this);


int main()
{
    int flag=0;
    char archivo[50];
    LinkedList* employeeList = ll_newLinkedList();
    LinkedList* porGenero;
    do
    {
        switch(menu())
        {
        case '1':
            getString("Ingrese el nombre del archivo: ", archivo);
            //strcpy(archivo,"datosMF1.csv");//
            if(strcmp(archivo,"datosMF1.csv")==0)
            {
                FILE* fl = openFILE("datosMF1.csv");
                parser_EmployeeFromText(fl, employeeList);
                printf("Archivo cargado\n");
                system("pause");
            }
            else
            {
                printf("Nombre invalido\n");
                system("pause");
            }
            break;
        case '2':
            ll_sort(employeeList, employee_sort, 1);
            printList(employeeList);
            system("pause");
            break;
        case '3':

            //depurarPeliculas(employeeList);
            printList(employeeList);
            system("pause");
            break;
        case '4':
            porGenero = ll_filter(employeeList, filtroDeGeneros);///filtra por salario mayor a 30000
            printList(porGenero);
            system("pause");
            system("cls");
            FILE* fl4 = openFILEWrite("filtrado.csv");
            parser_EmployeeListToText(fl4, porGenero);
            fclose(fl4);


            break;
        case 27:
            flag=1;
            printf("Salio");
            break;
        }
    }
    while(flag != 1);
    return 0;
}

void printList (LinkedList* this)
{
    if (this!=NULL)
    {
        pelicula_print_header();
        int i;
        ePelicula* temp;
        for (i=0; i < ll_len(this); i++)
        {
            temp = (ePelicula*)ll_get(this,i);
            pelicula_print_employee(temp);
        }
        printf("Mostro %d peliculas\n", i);
    }
}

char menu()
{
    char c;

    system("cls");
    printf("\t\tMENU\n1.Cargar los datos las peliculas desde el archivo.\n");
    printf("2.Listar por id.\n");
    printf("3.Depurar.\n");
    printf("4.Mostrar listado de un genero.\n");
    printf("ESC. para salis");
    printf("\nElija una opcion: ");
    c=getche();

    while(c != '1' && c != '2' && c != '3' && c != '4' /*&& c != '5' && c != '6' && c != '7' && c != '8' && c != '9'*/ && c != 27)
    {
        printf("\nERROR. Opcion invalida. Elija una opcion: ");
        c=getche();
    }
    system("cls");

    return c;
}

/*int depurarPeliculas(LinkedList* this)
{
    int retVal = -1, i, j;
    char aux1[50], aux2[50], auxG1[100], auxG2[100];
    ePelicula* auxpeli1;
    ePelicula* auxpeli2;
    void* temp;
        if(this != NULL)
    {
        retVal = 0;
        for (i=0; i < ll_len(this); i++)
        {
            auxpeli1 = (ePelicula*) ll_get(this, i);
                employee_get_nombre(auxpeli1, aux1);
                employee_get_genero(auxpeli1, auxG1);
            for (j = (i+1); i <ll_len(this); j++)
            {
                auxpeli2 = (ePelicula*)ll_get(this, j);

                employee_get_nombre(auxpeli2, aux2);
                employee_get_genero(auxpeli2, auxG2);
                if(strcmp(aux1, aux2)==0)
                {
                    strcat(auxG1, auxG2);
                    employee_set_genero(auxpeli1, auxG1);
                }
                printf("%d\n\n",i);

            }
            //temp = (ePelicula*)ll_get(this,i);
            //pelicula_print_employee(temp);
        }
    }
}*/
