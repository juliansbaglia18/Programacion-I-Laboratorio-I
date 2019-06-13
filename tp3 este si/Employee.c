#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "sbaglia.h"


int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 0;
        }
    }
    return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}

Employee* employee_new()
{

}
