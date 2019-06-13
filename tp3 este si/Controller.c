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
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
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
    Employee* employee;
    int idCharAux;
    int idResult;
    int optionCharAux;
    int salaryCharAux;
    int hoursCharAux;
    char idChar[100];
    char nameChar[100];
    char salaryChar[100];
    char hoursChar[100];
    int retorno = -1;
    char c;
    int i;

    if(pArrayListEmployee != NULL)
    {
        getString("Ingrese el ID: ", idChar);

        while(esNumerico(idChar) == 0)///
        {
            getString("ERROR. ID invalido. Vuelva a ingresar", idChar);
        }
        idCharAux=atoi(idChar);///HACER UNA FUNCION PARA ESTO EN MI LIBRERIA

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            employee = ll_get(pArrayListEmployee,i);
            employee_getId(employee,&idResult);

            if(idResult == idCharAux)
            {
                /*
                    printf("\n\n OPCIONES:");
                    printf("\n (1) Modificar nombre.");
                    printf("\n (2) Modificar sueldo.");
                    printf("\n (3) Modificar horas trabajadas.");
                    printf("\n (4) Cancelar.");
                    printf("\n\n Opcion:");
                    fflush(stdin);
                    gets(opcionChar);*/
                printf("1.Modificar nombre.\n2.Modificar sueldo.\n3.Modificar horas trabajadas.\nESC.Cancelar.\n");
                printf("\nElija una opcion: ");
                c=getche();

                while(c != '1' && c != '2' && c != '3' && c != 27)
                {
                    c = getche();
                    printf("\nERROR. Opcion invalida. Elija una opcion: ");

                }

                switch(c)
                {
                case '1':
                    getString("Ingrese el nuevo nombre: ", nameChar);

                    while(esSoloLetras(nameChar) == 0)
                    {
                        getString("ERROR. Nombre invalido. Ingrese el nuevo nombre: ", nameChar);
                    }
                    stringToUpper(nombreChar);
                    employee_setNombre(empleado, nameChar);
                    retorno = 0;
                    break;

                case '2':
                    getString("Ingrese el nuevo salario: ", salaryChar);
                    while(esNumerico(salaryChar) == 0)
                    {
                        getString("ERROR. Salario invalido. Ingrese el nuevo salario: ", salaryChar);
                    }
                    salaryCharAux= atoi(salaryChar);
                    employee_setSueldo(employee, salaryCharAux);
                    retorno = 0;
                    break;

                case '3':
                    getString("Ingrese la nueva cantidad de horas: ", hoursChar);
                    while(esNumerico(horasChar) == 0)
                    {
                        getString("ERROR. Horas invalidas. Ingrese la nueva cantidad de horas: ", hoursChar);
                    }
                    hoursCharAux = atoi(hoursChar);
                    employee_setHorasTrabajadas(employee, hoursCharAux);
                    retorno = 0;
                    break;

                case 27:
                    printf("Cancelado\n");
                    break;

                default:
                    printf("ERROR. Opcion invalida\n");
                    system("pause");
                    break;
                }
            }
        }
        }
        return retorno;
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
        Employee* pEmployee;
        int retorno = -1;
        char idChar[100];
        int idCharAux;
        int idResult;
        int option;
        int i;

        if(pArrayListEmployee != NULL)
        {
            printf("Ingrese el ID del empleado: ");
            fflush(stdin);
            gets(idChar);

            while(esNumerico(idChar)==0)
            {
                printf("Usted ha ingresado un tipo ID incorrecta.");
                fflush(stdin);
                gets(idChar);
            }
            idCharAux=atoi(idChar);

            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(pEmployee, &idObtenido);

                if(idResult == idCharAux)
                {
                    /*
                        printf("\n\n Desea dar de baja el usuario?");
                        printf("\n Ingrese 1 para SI.");
                        printf("\n Ingrese 2 para NO.");
                        printf("\n Ingrese opcion: ");
                        scanf("%d",&option);*/

                    printf("Seguro que desea dar de baja al usuario?(s/n) \n");
                    option = tolower(getch());
                    while(option != 's' && option != 'n')
                    {
                        printf("\nOpcion invalida. Vuelva a ingresar: ");
                        option = tolower(getche());
                    }
                    if(option == 's')
                    {
                        printf("Si\n");
                    }
                    else
                    {
                        printf("No\n");
                    }
                    switch(option)
                    {
                    case 's':
                        employee_delete(pEmployee);
                        ll_remove(pArrayListEmployee,i);
                        retorno = 0;
                        break;

                    case 'n':
                        retorno = -2;
                        break;

                    default:
                        printf("\nOpcion invalida.\n");
                        retorno = -2;
                        break;
                    }
                }
            }
        }
        return retorno;
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
        int retorno = -1;

        if(pArrayListEmployee != NULL)
        {
            employee_sortEmployee(pArrayListEmployee);
            retorno = 0;
        }
        return retorno;
    }

    /** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
     *
     * \param path char*
     * \param pArrayListEmployee LinkedList*
     * \return int
     *
     */
    int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
    {
        FILE* pArchive;
        Employee* employeeAux;
        int* idAux;
        char* nameAux;
        int* salaryAux;
        int* hoursAux;
        int retorno = -1;
        int i;

        if(pArrayListEmployee != NULL && path != NULL)
        {
            idAux = malloc(sizeof(int));
            nameAux = malloc(sizeof(char)*100);
            salaryAux = malloc(sizeof(int));
            hoursAux = malloc(sizeof(int));

            pArchive = fopen(path, "w");
            fprintf(pArchive,"id,nombre,horasTrabajadas,sueldo\n");

            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                employeeAux = ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,idAux);
                employee_getSueldo(employeeAux,salaryAux);
                employee_getNombre(employeeAux, nameAux);
                employee_getHorasTrabajadas(employeeAux,hoursAux);
                fprintf(pArchive,"%d,%s,%d,%d\n",*idAux,nameAux,*salaryAux,*hoursAux);
            }

            free(nameAux);
            free(idAux);
            free(salaryAux);
            free(hoursAux);
            fclose(pArchive);
        }
        return retorno;
    }

    /** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
     *
     * \param path char*
     * \param pArrayListEmployee LinkedList*
     * \return int
     *
     */
    int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
    {
        FILE* pArchive;
        Employee* employeeAux;
        int retorno = -1;
        int i;

        if(pArrayListEmployee != NULL && path != NULL)
        {
            pArchive = fopen(path,"wb");

            for(i=0; i< ll_len(pArrayListEmployee); i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(employeeAux, sizeof(Employee),1,pArchive);
            }
            fclose(pArchive);
        }
        return retorno;
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















