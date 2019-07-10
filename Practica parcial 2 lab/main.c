/// EL MIO
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "employee.h"
#include "parser.h"
#include "sbaglia.h"

void printList (LinkedList* this);
void printListNameSalary (LinkedList* this);
void printListDedication (LinkedList* this);

int main()
{
    LinkedList* employeeList = ll_newLinkedList();
    FILE* fl = openFILE("MOCK_DATA.csv");
    parser_EmployeeFromText(fl, employeeList);
    printList(employeeList);

    ll_map(employeeList, employee_calculate_salary);///Calcula los salarios
    system("pause");
    system("cls");
    printListNameSalary(employeeList);

    ll_sort(employeeList, employee_sortByName, 1);///ordenar por nombre
    system("pause");
    system("cls");
    printf("ORDENADOS POR NOMBRE");
    printList(employeeList);

    ll_sort(employeeList, employee_sortByJobTitle, 1);///ordenar por puesto
    system("pause");
    system("cls");
    printf("ORDENADOS POR PUESTO DE TRABAJO");
    printList(employeeList);



    //printListDedication(employeeList);

    LinkedList* porEdad = ll_filter(employeeList, employee_ageFilter);///filtra por edad mayor a 40
    system("pause");
    system("cls");
    printf("EDAD MAYOR A 40");
    printList(porEdad);

    FILE* fl2 = openFILEWrite("resultados por edad.csv");
    parser_EmployeeListToText(fl2,porEdad);
    fclose(fl2);

    LinkedList* porHoras = ll_filter(employeeList, employee_hoursFilter);///filtra por horas menores a 30
    system("pause");
    system("cls");
    printf("HORAS MENORES A 30");
    printList(porHoras);

    FILE* fl3 = openFILEWrite("resultados por horas.csv");
    parser_EmployeeListToText(fl3, porHoras);
    fclose(fl3);

    LinkedList* porSalario = ll_filter(employeeList, employee_salaryFilter);///filtra por salario mayor a 30000
    system("pause");
    system("cls");
    printf("SALARIO MAYOR A 30000");
    printList(porSalario);

    FILE* fl4 = openFILEWrite("resultados por salario.csv");
    parser_EmployeeListToText(fl4, porSalario);
    fclose(fl4);

    fclose(fl);
}
void printList (LinkedList* this)
{
    if (this!=NULL)
    {
        employee_print_header();
        int i;
        Employee* temp;
        for (i=0; i < ll_len(this); i++)
        {
            temp = (Employee*)ll_get(this,i);
            employee_print_employee(temp);
        }
        printf("Mostro %d empleados\n", i);

        employee_print_footer();
    }
}

void printListNameSalary (LinkedList* this)
{
    if (this!=NULL)
    {
        printf("     Nombre | Salario\n");
        int i;
        Employee* temp;
        for (i=0; i < ll_len(this); i++)
        {
            temp = (Employee*)ll_get(this,i);
            employee_print_employeeNameSalary(temp);
        }
        printf("Mostro %d empleados\n", i);

        employee_print_footer();
    }
}

/*void printListDedication (LinkedList* this)
{
    int dedication;
    if (this!=NULL)
    {
        employee_print_header();
        int i;
        Employee* temp;

            temp = (Employee*)ll_get(this,i);
            employee_print_employee(temp);
            dedication = ll_map(this, laQueMapea);

            if(dedication == 1)
            {
                printf("Dedicacion estandar\n");
            }
            else if(dedication == 2)
            {
                printf("Dedicacion sobre la media\n");
            }
            else if(dedication == 3)
            {
                printf("Dedicacion excelente\n");
            }

        printf("Mostro %d empleados\n", i);

        employee_print_footer();
    }
}*/
