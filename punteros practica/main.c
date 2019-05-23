#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarArray(float*,int);
void cargarEnteros(float*, int);
int calcularMaxOMin(int* array, int tam, int option);
float promedio(int* pArray, int tam);



int main()
{
    /*
    int valor = 99;
    int* q;
    int* p;

    p = &valor;
    q = p;
    printf("%d",*q);*/

    float variable[5] = {0,0,0,0,0};
    float* puntero;
    float dato;

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


    cargarEnteros(variable, 5);
    mostrarArray(variable,5);
    /*
    orderInt("Ordenar de menor a mayor:",variable, 5,0);
    mostrarArray(variable,5);
    orderInt("Ordenar de mayor a menor:",variable, 5,1);
    mostrarArray(variable,5);
    dato = calcularMaxOMin(variable,5,0);
    printf("El menor es %.0f\n", dato);
    dato = calcularMaxOMin(variable,5,1);
    printf("El mayor es %.0f\n", dato);
    dato = promedio(&variable, 5);
    printf("El promedio es %.2f\n",dato);
    */


    return 0;
}

void mostrarArray(float* pArray, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("%f ",*(pArray+i));//version correcta de hacerlo.
    }
    printf("\n");
}

void cargarEnteros(float* pArray, int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        getFloat("Cargar el numero: ", &pArray[i]);
    }
}

float promedio(int* pArray, int tam)
{
    int i;
    int total = 0;
    float elPromedio;
     for(i=0;i<tam;i++)
     {
         total += *(pArray+i);
     }
     elPromedio=total/tam;
     return elPromedio;
}
/**<Hacer funciones para
    1-cargarEnteros(listo)
    2-mostrar(listo)
    3-ordenar(listo)
    4-calcularMaximo(listo)
    5-devolverPromedio
    */
