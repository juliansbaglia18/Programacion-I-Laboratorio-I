#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarArray(int*,int);

int main()
{
    /*
    int valor = 99;
    int* q;
    int* p;

    p = &valor;
    q = p;
    printf("%d",*q);*/

    int variable[5] = {5,9,7,8,1};
    int* puntero;

    puntero = variable;
    //puntero = &variable;
    //puntero = &variable[0];
    //las tres hacen lo mismo pero la 1 es la ideal.

    /*
        printf("%d\n", puntero);//variable
        printf("%d\n", puntero+0);//&variable[0]
        printf("%d\n", puntero+1);//&variable[1]
        printf("%d\n\n", puntero+2);//&variable[2]

        printf("%d\n", *(puntero+0));//variable[0]
        printf("%d\n", *(puntero+1));//variable[1]
        printf("%d\n", *(puntero+2));//variable[2]

    */
    mostrarArray(variable,5);


    return 0;
}

void mostrarArray(int* pArray, int tam)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("%d\n",*(pArray+i));//version correcta de hacerlo.
    }
}

/**<Hacer funciones para
    1-cargarEnteros
    2-mostrar
    3-ordenar
    4-calcularMaximo
    5-devolverPromedio
    */
