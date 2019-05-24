#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "sbaglia.h"

eEmpleado* nuevoEmpleado()
{
    eEmpleado* retornoEmpleado;
    retornoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    return retornoEmpleado;
}

int mostrarEmpleado(eEmpleado* unEmpleado)
{
    int isNull = 1;
    if(unEmpleado != NULL)
    {
        printf("%d %s %.2f", unEmpleado->legajo,unEmpleado->nombre,unEmpleado->sueldo);
        isNull = 0;
    }
    printf("\n");
    return isNull;
}

eEmpleado* nuevoEmpleadoParametros(int legajo, char* nombre, float sueldo)
{
    eEmpleado* retornoEmpleado;
    retornoEmpleado = nuevoEmpleado();
    if(retornoEmpleado != NULL)
    {
        setLegajo(retornoEmpleado,legajo);
        retornoEmpleado->sueldo=sueldo;
        strcpy(retornoEmpleado->nombre,nombre);
    }
    return retornoEmpleado;
}

int setLegajo(eEmpleado* pEmpleado, int legajo)
{
    int esCorrecto= 0;
    if(pEmpleado!=NULL && legajo >= 1000)
    {
        pEmpleado ->legajo = legajo;
        esCorrecto=1;
    }
}
int getLegajo(eEmpleado* pEmpleado)
{
    int retornoLegajo=0;
    if(pEmpleado!=NULL )
    {
        retornoLegajo = pEmpleado ->legajo;
    }
    return retornoLegajo;
}

void destructorEmpleado(eEmpleado* pEmpleado)
{
    free(pEmpleado);
}






