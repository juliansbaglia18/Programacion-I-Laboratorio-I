#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "linkedList.h"
#include "pelicula.h"
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
    char buffer [4][128];
    ePelicula* new_employee;

    if (pFile != NULL && this != NULL)
    {
        this = (LinkedList*) this;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while (!feof(pFile))
        {

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_employee = employee_new_text(buffer[0], buffer[1], buffer[2], buffer[3]);
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
        char name[128] , genero[128];
        int id , age;
        ePelicula* auxEmp;
        int i;
        fprintf(pFile,"id,first_name,job_title,age,worked_hours,salary\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxEmp = (ePelicula*)ll_get(this,i);
            if (auxEmp!=NULL)
            {
                employee_get_id(auxEmp,&id);
                employee_get_nombre(auxEmp,name);
                employee_get_genero(auxEmp,genero);
                employee_get_age(auxEmp,&age);
                fprintf(pFile,"%d,%s,%d,%s\n",id,name,age,genero);
            }
        }
        retVal = 0;
    }
    return retVal;
}
