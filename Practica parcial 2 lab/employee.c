/** REVISAR COMENTARIOS DE LOS GETS SETS NEW EMPLOYEE PARAMETROS **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "sbaglia.h"


/** \brief
 *
 * \param ptrEmp Employee* el eEmployee donde se va a guardar
 * \param this int* el id a guardar
 * \return int 0 si esta bien
 *         -1 si no
 *
 */
int employee_get_id (Employee* ptrEmp, int* this)
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

/** \brief Busca el nombre de un Employee
 *
 * \param ptr Employee* Employee donde se va a buscar
 * \param this char* donde se guarda el nombre encontrado
 * \return int 0 si esta todo bien, -1 si no
 *
 */
int employee_get_name (Employee* ptrEmp,char* this)
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

/** \brief
 *
 * \param ptr Employee* Employee donde se va a guardar
 * \param this char* puesto a guardar
 * \return int 0 si esta todo bien, -1 si no
 *
 */
int employee_get_jobTitle (Employee* ptrEmp,char* this)
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

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int*
 * \return int
 *
 */
int employee_get_age (Employee* ptrEmp,int* this)
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


/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int*
 * \return int
 *
 */
int employee_get_workedHours (Employee* ptrEmp,int* this)
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

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int*
 * \return int
 *
 */
int employee_get_salary (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp != NULL)
    {
        if (this != NULL)
        {
            *this = ptrEmp->salary;
            ret = 0;
        }
    }
    return ret;
}

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int*
 * \return int
 *
 */
int employee_set_id (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp != NULL)
    {
        if (this > 0)
        {
            ptrEmp->id = this;
            ret = 0;
        }
    }
    return ret;
}

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this char*
 * \return int
 *
 */
int employee_set_name (Employee* ptrEmp,char* this)
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

/** \brief
 *
 * \param ptr Employee*
 * \param this char*
 * \return int
 *
 */
int employee_set_jobTitle (Employee* ptrEmp,char* this)
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

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int
 * \return int
 *
 */
int employee_set_age (Employee* ptrEmp,int this)
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

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int
 * \return int
 *
 */
int employee_set_workedHours (Employee* ptrEmp,int this)
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

/** \brief
 *
 * \param ptrEmp Employee*
 * \param this int
 * \return int
 *
 */
int employee_set_salary (Employee* ptrEmp,int this)
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

/** \brief asigna un espacio de memoria dinamica
 *
 * \param void
 * \return Employee* puntero a dicho espacio
 *
 */
Employee* employee_new (void)
{
    Employee* ret = NULL;

    ret = (Employee*)malloc(sizeof(Employee));

    return ret;
}

/** \brief Creo que crea un nuevo empleado y le carga los datos por parametros
 *
 * \param id int id a cargar
 * \param name char* nombre a cargar
 * \param title char* puesto a cargar
 * \param age int edad a cargar
 * \param hours int horas a cargar
 * \param salary int salario a cargar
 * \return Employee* employee con los parametros cargados
 *
 */
Employee* employee_new_parameters (int id,char* name,char* title,int age,int hours,int salary)
{
    Employee* ret = NULL;
    if (id > 0 && name != NULL && title != NULL && age > 0 && hours >= 0 && salary >= 0)
    {
        ret = employee_new();

        employee_set_id(ret,id);
        employee_set_name(ret,name);
        employee_set_jobTitle(ret,title);
        employee_set_age(ret,age);
        employee_set_workedHours(ret,hours);
        employee_set_salary(ret,salary);
    }
    return ret;
}

/** \brief recibe todos los datos como string, los convierte al tipo correspondiente y crea el nuevo employee con los valores cargados
 *
 * \param id char* id a cargar pero como char
 * \param name char* nombre a cargar
 * \param title char* titulo a cargar
 * \param age char* edad a cargar pero como char
 * \param hours char* horas a cargar pero como char
 * \param salary char* salario a cargar pero como char
 * \return Employee* devuelve el Employee con valores asigandos. NULL si no los pudo asignar
 *
 */
Employee* employee_new_text (char* id,char* name,char* title,char* age,char* hours,char* salary)
{
    Employee* ret = NULL;
    if (id!=NULL&&name!=NULL&&title!=NULL&&age!=NULL&&hours!=NULL&&salary!=NULL)
    {
        int inid , inage , inhours , insalary;
        inid = atoi(id);
        inage = atoi(age);
        inhours = atoi(hours);
        insalary = atoi(salary);
        ret = employee_new_parameters(inid,name,title,inage,inhours,insalary);
    }
    return ret;
}

/** \brief compara los nombres de dos struct de Employee
 *
 * \param ptrEmp1 void* primer nombre a comparar
 * \param ptrEmp2 void* segundo nombre a comparar
 * \return int devuelve 0, 1 o -1 igual que un strcmp
 *
 */
int employee_sortByName(void* ptrEmp1 ,void* ptrEmp2)
{
    int retVal = 0;
    char auxName1[128], auxName2[128];

    if (ptrEmp1 != NULL && ptrEmp2 != NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmp2 = (Employee*)ptrEmp2;
        employee_get_name(ptrEmp1, auxName1);
        employee_get_name(ptrEmp2, auxName2);
        retVal = strcmp(auxName1,auxName2);
    }
    return retVal;
}

/** \brief compara los nombres de dos struct de Employee
 *
 * \param ptrEmp1 void* primer nombre a comparar
 * \param ptrEmp2 void* segundo nombre a comparar
 * \return int devuelve 0, 1 o -1 igual que un strcmp
 *
 */
int employee_sortByJobTitle(void* ptrEmp1 ,void* ptrEmp2)
{
    int retVal = 0;
    char auxName1[128], auxName2[128];

    if (ptrEmp1 != NULL && ptrEmp2 != NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmp2 = (Employee*)ptrEmp2;
        employee_get_jobTitle(ptrEmp1, auxName1);
        employee_get_jobTitle(ptrEmp2, auxName2);
        retVal = strcmp(auxName1,auxName2);
    }
    return retVal;
}

/** \brief compara los nombres de dos struct de Employee
 *
 * \param ptrEmp1 void* primer nombre a comparar
 * \param ptrEmp2 void* segundo nombre a comparar
 * \return int devuelve 0, 1 o -1 igual que un strcmp
 *
 */
int employee_sortByID(void* ptrEmp1 ,void* ptrEmp2)
{
    int retVal = 0;
    char auxName1[128], auxName2[128];

    if (ptrEmp1 != NULL && ptrEmp2 != NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmp2 = (Employee*)ptrEmp2;
        employee_get_jobTitle(ptrEmp1, auxName1);
        employee_get_jobTitle(ptrEmp2, auxName2);
        retVal = strcmp(auxName1,auxName2);
    }
    return retVal;
}

/** \brief  Calcula el salario segun las horas que realizo el empleado
 *
 * \param this void* Employee a calcular
 * \return int el salario total
 *
 */
int employee_calculate_salary (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        int salary;
        this = (Employee*)this;
        employee_get_workedHours(this,&salary);
        salary = salary * 300;  // <-- Salario por hora
        employee_set_salary(this,salary);
        retVal = -1;
    }
    return retVal;
}

/** \brief  Calcula la dedicacion/////////////////////////////////////////
 *
 * \param this void* Employee a calcular
 * \return int su dedicacion
 *
 */
int laQueMapea (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        int hours;
        this = (Employee*) this;
        employee_get_workedHours(this,&hours);

        if(hours < 50)retVal = 1;
        else if(hours < 100)retVal = 2;
        else retVal = 3;
    }
    return retVal;
}



/** \brief valida si la edad de un empleado es mayor a 40
 *
 * \param this void* el employee que va a calcular
 * \return int -1 si hubo un error. 0 si es menor de 40. 1 si es mayor de 40
 *
 */
int employee_ageFilter (void* this)
{
    int retVal = -1;
    if (this != NULL)
    {
        retVal = 0;
        int temp;
        this = (Employee*) this;
        employee_get_age(this, &temp);
        if (temp > 40)
        {
            retVal = 1;
        }
    }
    return retVal;
}

/** \brief valida si las horas de trabajo son menores de 30
 *
 * \param this void* el employee que va a calcular
 * \return int -1 si hubo un error. 0 si es mayor de 30hs. 1 si es menor de 30hs
 *
 */
int employee_hoursFilter (void* this)
{
    int retVal = -1;
    if (this != NULL)
    {
        retVal = 0;
        int temp;
        this = (Employee*) this;
        employee_get_workedHours(this, &temp);
        if (temp < 30)
        {
            retVal = 1;
        }
    }
    return retVal;
}

/** \brief valida si el salario es mayor a 30000
 *
 * \param this void* el employee que va a calcular
 * \return int -1 si hubo un error. 0 si es menor a 30000. 1 si es mayor
 *
 */
int employee_salaryFilter (void* this)
{
    int retVal = -1;
    if (this != NULL)
    {
        retVal = 0;
        int temp;
        this = (Employee*) this;
        employee_get_salary(this, &temp);
        if (temp > 30000)
        {
            retVal = 1;
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
void employee_print_header (void)
{
    printf("\n ID   |     Nombre |                              Puesto |Edad|  Hs |Sueldo\n");
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void employee_print_employee (Employee* this)
{
    if (this!=NULL)
    {
        int id, age, hours, salary;
        char temp [128], temp2 [128];

        employee_get_id(this,&id);
        employee_get_name(this,temp);
        employee_get_jobTitle(this,temp2);
        employee_get_age(this,&age);
        employee_get_workedHours(this,&hours);
        employee_get_salary(this,&salary);

        printf(" %4d | %10s | %35s | %2d | %3d | %6d \n",id,temp,temp2,age,hours,salary);
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void employee_print_employeeNameSalary (Employee* this)
{
    if (this!=NULL)
    {
        int salary;
        char temp [128];

        employee_get_name(this,temp);
        employee_get_salary(this,&salary);

        printf(" %10s | %6d \n",temp, salary);
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void employee_print_footer (void)
{
    printf("-------------------------------------------------------------------------------\n");
}
