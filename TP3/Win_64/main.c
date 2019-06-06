#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}

char menu()
{
    char c;
	system("cls");
	printf("MENU\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados.\n");
	printf("7.Ordenar empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.Salir");
	printf("Elija una opcion: ");
	c=getche();
	return c;
}
