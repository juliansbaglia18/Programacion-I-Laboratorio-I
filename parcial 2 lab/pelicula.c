#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sbaglia.h"
#include "pelicula.h"
#include "linkedList.h"


int employee_get_id (ePelicula* ptrEmp, int* this)
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
int employee_get_nombre (ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->nombre);
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
int employee_get_genero (ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->genero);
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
int employee_get_age (ePelicula* ptrEmp,int* this)
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
int employee_set_id (ePelicula* ptrEmp,int this)
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
int employee_set_nombre (ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->nombre,this);
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
int employee_set_genero (ePelicula* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->genero,this);
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
int employee_set_age (ePelicula* ptrEmp,int this)
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
ePelicula* employee_new_text (char* id,char* name,char* age,char* genero)
{
    ePelicula* ret = NULL;
    if (id!=NULL&&name!=NULL&&genero!=NULL&&age!=NULL)
    {
        int inid , inage;
        inid = atoi(id);
        inage = atoi(age);
        ret = employee_new_parameters(inid,name,inage,genero);
    }
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
ePelicula* employee_new_parameters (int id, char* name, int age, char* genero)
{
    ePelicula* ret = NULL;
    if (id > 0 && name != NULL && genero != NULL && age > 0)
    {

        ret = employee_new();

        employee_set_id(ret,id);
        employee_set_nombre(ret,name);
        employee_set_genero(ret,genero);
        //printf("HASTAQ ACA");
        employee_set_age(ret,age);
    }
    return ret;
}

/** \brief asigna un espacio de memoria dinamica
 *
 * \param void
 * \return Employee* puntero a dicho espacio
 *
 */
ePelicula* employee_new (void)
{
    ePelicula* ret = NULL;

    ret = (ePelicula*)malloc(sizeof(ePelicula));

    return ret;
}

void pelicula_print_header (void)
{
    printf("\n ID | Nombre                                           | Anio | Genero\n");
}

void pelicula_print_employee (ePelicula* this)
{
    if (this!=NULL)
    {
        int id, age;
        char temp [128], temp2 [128];

        employee_get_id(this,&id);
        employee_get_nombre(this,temp);
        employee_get_genero(this,temp2);
        employee_get_age(this,&age);

        printf(" %2d | %48s | %4d | %s\n",id,temp,age,temp2);
    }
}

int employee_sort(void* ptrEmp1 ,void* ptrEmp2)
{
    int retVal = 0;
    char auxName1[128], auxName2[128];

    if (ptrEmp1 != NULL && ptrEmp2 != NULL)
    {
        ptrEmp1 = (ePelicula*)ptrEmp1;
        ptrEmp2 = (ePelicula*)ptrEmp2;
        employee_get_id(ptrEmp1, auxName1);
        employee_get_id(ptrEmp2, auxName2);
        retVal = strcmp(auxName1,auxName2);
    }
    return retVal;
}

/*int depurarPeliculas(LinkedList* this)
{
    int retVal = -1, i;
    char aux1[50], aux2[50], auxG1[100], auxG2[100];
    ePelicula auxpeli1, auxpeli2;
        if(this != NULL)
    {
        retVal = 0;
        for (i=0; i < ll_len(this); i++)
        {
            auxpeli1 = ll_get(this, i);
                employee_get_nombre(auxpeli1, aux1);
                employee_get_genero(auxpeli1, auxG1);
            for (j = (i+1); i <len(this); j++)
            {
                auxpeli2 = ll_get(this, j);
                employee_get_nombre(auxpeli2, aux2);
                employee_get_genero(auxpeli2, auxG2);
                if(strcmp(aux1, aux2)==0)
                {
                    strcat(auxG1, auxG2);
                    employee_set_genero(auxpeli1, auxG1);
                }

            }
            //temp = (ePelicula*)ll_get(this,i);
            //pelicula_print_employee(temp);
        }
    }
}*/

int filtroDeGeneros (void* this, char* temp)
{
    int retVal = -1;
    if(this != NULL)
    {
        //pelicula_print_header();
        retVal = 0;
        char temp2[50];
        employee_get_genero(this, temp2);
        if(strcmp(temp2, temp) == 0)
        {
            //pelicula_print_employee(this);
            retVal = 1;
        }
    }
    return retVal;
}




















