#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchive;
    int retorno = -1;

    if(pArchive != NULL)
    {
        pArchive = fopen(path, "r");
        parser_EmployeeFromText(pArchive, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchive);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchive;
    int retorno = -1;

    if(pArchive != NULL)
    {
       pArchive = fopen(path, "rb");
       parser_EmployeeFromBinary(pArchive, pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = employee_new();
    int retorno = -1;
    char nameChar[50];
    int idAux;
    int hoursCharAux;
    char hoursChar[50];
    int salaryCharAux;
    char salaryChar[50];

    if (pArrayListEmployee != NULL)
    {
        idAux = controller_nextID(pArrayListEmployee);
        getChar("Ingrese el nombre: ", nameChar);///es asi o con &????????
        while (esSoloLetras(nameChar) == 0)
        {
        getChar("Nombre invalido. Ingrese el nombre: ", nameChar);///es asi o con &????????
        }
        stringToUpper(nameChar);

        while(esNumerico(hoursChar) == 0)
        {
        getChar("Horas invalidas. Ingrese las horas: ", hoursChar);
        }
        hoursCharAux = atoi(hoursChar);

        getChar("Ingrese el sueldo: ", salaryChar);
        while(esNumerico(salaryChar) == 0)
        {
        getChar("Sueldo invalido. Ingrese el sueldo: ", salaryChar);
        }
        salaryCharAux = atoi(salaryChar);

        if(pEmployee != NULL)
        {
            employee_setId(pEmployee, idAux);
            employee_setNombre(pEmployee, nameChar);
            employee_setSueldo(pEmployee, salaryCharAux);
            ll_add(pArrayListEmployee, pEmployee);
            retorno =  0;
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int retorno = -1;
    int id;
    int salary;
    int hoursWorked;
    char name[128];
    int i;

    if(pArrayListEmployee != NULL);
    {
        printf("\nID   Nombre \t\t  Sueldo \t\t Horas\n");
        retorno = 0;

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getNombre(pEmployee, name);
            employee_getId(pEmployee, &id);
            employee_getSueldo(pEmployee, &salary);
            employee_getHorasTrabajadas(pEmployee,&hoursWorked);
            printf("%d %20s %20d %20d\n", id, name, salary, hoursWorked);
        }
    }
    return retorno;
}////////////////////////////HASTA AQUI LLEGUE HOY;

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_nextID(LinkedList* pArrayListEmployee)
{
    Employee* employeeAux;
    int aux;
    int id = 0;
    int listLen;
    int previousId;
    int i;

    if(pArrayListEmployee != NULL)
    {
        listLen = ll_len(pArrayListEmployee);
        if(listLen > 0)
        {
            for(i = 0; i < listLen; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(employeeAux, &aux);
                if(aux > id)
                {
                    previousId = id;
                    id = aux;
                    if(previousId + 1 != id)
                    {
                        id = previousId;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}















