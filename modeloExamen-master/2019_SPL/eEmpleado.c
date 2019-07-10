#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int Employee_get_id (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->id;
            ret = 0;
        }
    }
    return ret;
}
int Employee_get_name (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->name);
            ret = 0;
        }
    }
    return ret;
}
int Employee_get_jobTitle (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->job_title);
            ret = 0;
        }
    }
    return ret;
}
int Employee_get_age (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->age;
            ret = 0;
        }
    }
    return ret;
}
int Employee_get_workedHours (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->worked_hours;
            ret = 0;
        }
    }
    return ret;
}
int Employee_get_salary (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->salary;
            ret = 0;
        }
    }
    return ret;
}

int Employee_set_id (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
            ptrEmp->id = this;
            ret = 0;
        }
    }
    return ret;
}
int Employee_set_name (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->name,this);
            ret = 0;
        }
    }
    return ret;
}
int Employee_set_jobTitle (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->job_title,this);
            ret = 0;
        }
    }
    return ret;
}
int Employee_set_age (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
            ptrEmp->age = this;
            ret = 0;
        }
    }
    return ret;
}
int Employee_set_workedHours (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>-1)
        {
            ptrEmp->worked_hours = this;
            ret = 0;
        }
    }
    return ret;
}
int Employee_set_salary (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>-1)
        {
            ptrEmp->salary = this;
            ret = 0;
        }
    }
    return ret;
}

Employee* Employee_new (void)
{
    Employee* ret = NULL;
    ret = (Employee*)malloc(sizeof(Employee));
    return ret;
}
Employee* Employee_new_parameters (int id,char* name,char* title,int age,int hours)
{
    Employee* ret = NULL;
    if (id>=0)
    {
        if (name!=NULL)
        {
            if (title!=NULL)
            {
                if (age > 0)
                {
                    if (hours >=0)
                    {
                        ret = Employee_new();
                        Employee_set_id(ret,id);
                        Employee_set_name(ret,name);
                        Employee_set_jobTitle(ret,title);
                        Employee_set_age(ret,age);
                        Employee_set_workedHours(ret,hours);
                        //Employee_set_salary(ret,salary);
                    }
                }
            }
        }
    }
    return ret;
}
Employee* Employee_new_text (char* id,char* name,char* title,char* age,char* hours)
{
    Employee* ret = NULL;
    if (id!=NULL&&name!=NULL&&title!=NULL&&age!=NULL&&hours!=NULL)
    {
        int inid , inage , inhours;
        inid = atoi(id);
        inage = atoi(age);
        inhours = atoi(hours);
        ret = Employee_new_parameters(inid,name,title,inage,inhours);
    }
    return ret;
}
int Employee_sortByName(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        char auxName1 [128] , auxNameTwo [128];
        Employee_get_name(ptrEmp1, auxName1);
        Employee_get_name(ptrEmpTwo, auxNameTwo);
        retVal = strcmp(auxName1,auxNameTwo);
    }
    return retVal;
}
int Employee_calculate_salary (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        int salary;
        this = (Employee*)this;
        Employee_get_workedHours(this,&salary);
        salary = salary * 300;  // <-------------------- Salario por hora
        Employee_set_salary(this,salary);
        retVal = -1;
    }
    return retVal;
}

int Employee_filter (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        retVal = 0;
        int temp;
       // char str [128];
        this = (Employee*)this;
        Employee_get_age(this,&temp);
        if (temp>40)
        {
            retVal = 1;
        }
    }
    return retVal;
}
void Employee_print_header (void)
{
    printf("\n");
    printf(" ---------------------------------------------------------\n");
    printf("| ID   |      Nombre     |     Puesto      | Edad | Horas |\n");
    printf(" ---------------------------------------------------------\n");
}
void Employee_print_footer (void)
{
    printf(" ---------------------------------------------------------\n");
}
void Employee_print_Employee (Employee* this)
{
    if (this!=NULL)
    {
        int id , age , hours;
        char temp [128];
        char temp2 [128];
        Employee_get_id(this,&id);
        Employee_get_name(this,temp);
        Employee_get_jobTitle(this,temp2);
        Employee_get_age(this,&age);
        Employee_get_workedHours(this,&hours);
        //Employee_get_salary(this,&salary);
        printf("| %4d | %15s | %15s | %4d | %5d |\n",id,temp,temp2,age,hours);
    }
}
