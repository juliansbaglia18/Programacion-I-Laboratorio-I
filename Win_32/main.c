#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
/*#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"*/
#include "sbaglia.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

char menu(void);

int main()
{
    char option;
//    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case '1':
            //controller_loadFromText("data.csv",listaEmpleados);
            system("cls");
            printf("opcion 1\n");
            system("pause");
            break;
        case '2':
            system("cls");
            printf("opcion 2\n");
            system("pause");
            break;
        case '3':
            system("cls");
            printf("opcion 3\n");
            system("pause");
            break;
        case '4':
            system("cls");
            printf("opcion 4\n");
            system("pause");
            break;
        case '5':
            system("cls");
            printf("opcion 5\n");
            system("pause");
            break;
        case '6':
            system("cls");
            printf("opcion 6\n");
            system("pause");
            break;
        case '7':
            system("cls");
            printf("opcion 7\n");
            system("pause");
            break;
        case '8':
            system("cls");
            printf("opcion 8");
            system("pause");
            break;
        case '9':
            system("cls");
            printf("opcion 9");
            system("pause");
            break;
        case 27:
            system("cls");
            printf("Seguro que desea salir?(s/n)\n");
            option = tolower(getche());
            while(option != 's' && option != 'n')
            {
                printf("\nOpcion invalida. Vuelva a ingresar: ");
                option = tolower(getch());
            }

            break;
        default:
            system("cls");
            printf("Opcion invalida\n");
            system("pause");
            break;
        }
    }
    while(option != 's');
    return 0;
}

char menu()
{
    char c;
    system("cls");
    printf("MENU\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados.\n");
    printf("7.Ordenar empleados.\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\nESC.Salir.\n");
    printf("Elija una opcion: ");
    c=getche();
    return c;
}
