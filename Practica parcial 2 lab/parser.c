#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "linkedList.h"
#include "employee.h"
#include "sbaglia.h"


FILE* openFILE (char* fileName)
{
    FILE* ret = NULL;
    if (fileName != NULL)
    {
        ret = fopen(fileName,"r");
    }
    return ret;
}

FILE* openFILEWrite(char* fileName)
{
    FILE* ret = NULL;
    if (fileName!=NULL)
    {
        ret = fopen(fileName,"w");
    }
    return ret;
}
/** \brief registra los empleados y los guarda en el linked list
 *
 * \param pFile el archivo de donde se sacan los empleados
 * \param this linked list donde se va a guardar
 * \return devuelve la cantidad de empleados guardados
 *         0 si no se guardo ninguno
 *
 */
int parser_EmployeeFromText(FILE* pFile, void* this)
{
    int retVal = 0;
    char buffer [6][128];
    Employee* new_employee;

    if (pFile != NULL && this != NULL)
    {
        this = (LinkedList*) this;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
        while (!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_employee = employee_new_text(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
            if (new_employee != NULL)
            {
                ll_add(this, new_employee);
                retVal++;
            }
        }
    }
    return retVal;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int parser_EmployeeListToText (FILE* pFile, void* this)
{
    int retVal = 0;
    if (pFile != NULL && this != NULL)
    {
        this = (LinkedList*)this;
        char name[128] , title[128];
        int id , age , hours , salary;
        Employee* auxEmp;
        int i;
        fprintf(pFile,"id,first_name,job_title,age,worked_hours,salary\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxEmp = (Employee*)ll_get(this,i);
            if (auxEmp!=NULL)
            {
                employee_get_id(auxEmp,&id);
                employee_get_name(auxEmp,name);
                employee_get_jobTitle(auxEmp,title);
                employee_get_age(auxEmp,&age);
                employee_get_workedHours(auxEmp,&hours);
                employee_get_salary(auxEmp,&salary);
                fprintf(pFile,"%d,%s,%s,%d,%d,%d\n",id,name,title,age,hours,salary);
            }
        }
        retVal = 0;
    }
    return retVal;
}
