#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 5

void mostrar(int dato[]);
int burbujeo(int dato[TAMANIO], int *nuevo2[TAMANIO]);

int main()
{
    int algo[TAMANIO] = {3, 5, 1, 2, 4};
    int aux;
    int i;
    int j;
    int nuevo[TAMANIO] = {0, 0, 0, 0, 0};

    mostrar(algo);

    burbujeo(algo,&nuevo);

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
        mostrar(nuevo);

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
int burbujeo(int dato[TAMANIO], int *nuevo2[TAMANIO])
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

    nuevo2[4] = dato[1];//ACA NO SE ESTAN IGUALANDO LOS ARRAYS PERO EL RESTO ANDA

    mostrar(dato);
    mostrar(nuevo2);
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
