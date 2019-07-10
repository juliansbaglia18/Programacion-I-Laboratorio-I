#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "LinkedList.h"
#include "employee.h"

FILE* openFILE (char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"r");
    }
    return ret;
}
FILE* openFILEwrite(char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"w");
    }
    return ret;
}
int parser_EmployeeFromText(FILE* pFile , void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char buffer [5][128];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);  //"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
        while (!feof(pFile))
        {
            Employee* new_Employee;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_Employee = Employee_new_text(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if (new_Employee!=NULL)
            {
                ll_add(this,new_Employee);
                retVal++;
            }
        }
    }
    return retVal;
}

int parser_EmployeeListToText (FILE* pFile, void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
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
                Employee_get_id(auxEmp,&id);
                Employee_get_name(auxEmp,name);
                Employee_get_jobTitle(auxEmp,title);
                Employee_get_age(auxEmp,&age);
                Employee_get_workedHours(auxEmp,&hours);
                Employee_get_salary(auxEmp,&salary);
                fprintf(pFile,"%d,%s,%s,%d,%d,%d\n",id,name,title,age,hours,salary);
            }
        }
        retVal = 0;
    }
    return retVal;
}
