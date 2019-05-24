#include <stdio.h>
#include <stdlib.h>
#define T 5
#include "sbaglia.h"

int main()
{

    int* x;
    int i;
    int aux;//creamos el auxiliar porque el realoc podria hacernos perder los datos si no encuentra la cantidad de datos que le pedimos

    x = (int*) calloc(sizeof(int),T);//calloc reserva una porcion de memoria y la inicializa en 0 o en " ".
    //x = (int*) malloc(sizeof(int)*T);

    if(x!=NULL)//para que no crashee nos aseguramos de que no sea un null
    {
        for(i=0; i<T; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", (x+i));
        }
        for(i=0; i<T; i++)
        {
            printf("%d \n",*(x+i));
        }
        /*free(x);//libera el espacio de memoria reservado
        printf("luego de free\n");
        for(i=0; i<T; i++)
        {
            printf("%d \n",*(x+i));
        }*/

        printf("Agrego 5 mas:\n");
        aux = (int*) realloc(x, sizeof(int)*(T+5));
        if(aux!=NULL)
        {
            x=aux;
            for(i=T; i<T+5; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", x+i);
            }
            for(i=0; i<T+5; i++)
            {
                printf("%d\n",*(x+i));
            }

            printf("Quito 4\n");
            aux = (int*) realloc(x, sizeof(int)*(T+5-4));
            for(i=0; i<T+5-4; i++)
            {
                printf("%d\n",*(x+i));
            }
        }
    }
    return 0;
}
