#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "sbaglia.h"

eEmpleado* fantasma(int, char*, float)

int main()
{

    eEmpleado* unEmpleado;

    unEmpleado = nuevoEmpleadoParametros(1001,"pedro",10000);
    mostrarEmpleado(unEmpleado);
    destructorEmpleado(unEmpleado);
    mostrarEmpleado(unEmpleado);


    /*eEmpleado* otroEmpleado;
    otroEmpleado = nuevoEmpleadoParametros(101,"maria",15000);
    if(!mostrarEmpleado(otroEmpleado))
    {
        printf("\nError al mostrar\n");
    }*/


    return 0;
}

eEmpleado* fantasma(int legajo, char* nombre, float sueldo)
{
    eEmpleado empleado;
    empleado.legajo = legajo;
    strcpy(empleado.nombre,nombre);
    empleado.sueldo=sueldo;
}
/*
poder crear array de empleados, mostrarlos y hacer todos los geters y seters
*/


