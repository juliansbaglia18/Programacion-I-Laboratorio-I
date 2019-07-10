#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"

void menu (void)
{
    system("cls");
    printf("1. Cargar Datos\n");
    printf("2. Listar Empleados\n");
    printf("3. Salir\n");
}
int getOption (void)
{
    fflush(stdin);
    int ret = 0;
    scanf("%d",&ret);
    return ret;
}
int controller_load_text (char* path, LinkedList* this)
{
    int retVal = -1;
    if (path!=NULL&&this!=NULL)
    {
        FILE* fl;
        fl = openFILE(path);
        parser_EmployeeFromText(fl,this);
        retVal = 1;
    }
    return retVal;
}
int controller_sort(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        ll_sort(this,Employee_sortByName,1);
    }
    return retVal;
}
int controller_list_Employee (LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        int i;
        Employee* temp = NULL;
        system("cls");
        Employee_print_header();
        for (i=0;i<ll_len(this);i++)
        {
            temp = ll_get(this,i);
            Employee_print_Employee(temp);
            temp = NULL;
        }
        Employee_print_footer();
        system("pause");
        retVal = i;
    }
    return retVal;
}
