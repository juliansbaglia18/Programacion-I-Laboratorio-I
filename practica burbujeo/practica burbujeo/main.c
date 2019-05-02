#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 5
#include "herramientas.h"//


void mostrar(int dato[]);
int burbujeoMinAMax(int dato[TAMANIO]);
int burbujeoMaxAMin(int dato[TAMANIO]);


int main()
{
    int algo[TAMANIO] = {3, 5, 1, 2, 4};
    int aux;
    int i;
    int j;
    int nuevo[TAMANIO] = {0, 0, 0, 0, 0};

    mostrar(algo);

    burbujeoMinAMax(&algo);

    /*for(i = 0; i < TAMANIO; i++)
    {
        for(j = 0; j < TAMANIO; j++)
        {
            if(algo[j] > algo[j+1])
            {
                aux = algo[j+1];
                algo[j+1]=algo[j];
                algo[j]=aux;
            }

        }
    }*/
        mostrar(algo);

        burbujeoMaxAMin(&algo);
        mostrar(algo);

    return 0;
}

void mostrar(int dato[])
{
    int k;
    for(k=0;k<TAMANIO; k++)
    {
        printf(" %d ", dato[k]);
    }
    printf("\n");
}
int burbujeoMinAMax(int dato[TAMANIO])
{
    int aux;
    int i;
    int j;

    for(i = 0; i < TAMANIO; i++)
    {
        for(j = 0; j < TAMANIO; j++)
        {
            if(dato[j] > dato[j+1])
            {
                aux = dato[j+1];
                dato[j+1]=dato[j];
                dato[j]=aux;
            }

        }
    }

    return 0;
}

int burbujeoMaxAMin(int dato[TAMANIO])
{
    int aux;
    int i;
    int j;

    for(i = 0; i < TAMANIO; i++)
    {
        for(j = 0; j < TAMANIO-1; j++)
        {
            if(dato[j] < dato[j+1])
            {
                aux = dato[j+1];
                dato[j+1]=dato[j];
                dato[j]=aux;
            }
        }
    }
    return 0;
}





/*
#include<stdio.h>
int main ()
{
int aux,i,j,k;
int n=10,A[n];

for (i=0; i<n; i++)
{
printf("dame el dato %dn",i+1);
scanf("%d",&A);
}
for (i=0;i<n;i++)
{
for (j=0;j<n-i;j++)
{
if (A[j]>=A[j+1])
{
aux=A[j];
A[j]=A[j+1];
A[j+1]=aux;
}

}

}
for (k=0;k<n;k++)
{
printf(" %d",A[k]);
}



return 0;
}
//Omar Diaz R.
*/
