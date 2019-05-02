#include <stdio.h>
#include <stdlib.h>

int EsUnNumero(char * cadena )//funciona para validar numeros. recorre el hasta encontrar un num
{
        //printf("\npalabra por parametro %s", cadena);
        int indice=0;
        int retorno=0;
        while(cadena[indice]!='\0'){
            if(cadena[indice]<'0'||cadena[indice]>'9'){
                break;
            }
            else{
                indice++;
            }
        }
        if(cadena=='\0'){
            retorno = 1;
        }
        return retorno;

}

int main()
{
    char letra;
    char palabra [10];
    int numero;
    int es;

    scanf("%s",&palabra);
    fflush(stdin);
    printf("\npalabra ingresada %s", palabra);
    es = EsUnNumero(palabra);
    if(es==1){
        printf("Es correcto");
    }else{
        printf("No lo es") ;
    }

    /*int indice=0;

    while(indice<20){
            if(palabra[indice]=='\0'){
                printf("\nEl barra cero esta en %d",indice);
            }
        printf("\nletra %c", palabra[indice]);
        indice ++;
    }*/
    /*scanf("%d",&numero);
    fflush(stdin);
    printf("\numero %d", numero);*/

    /*scanf("%c",&letra);
    fflush(stdin);
    printf("\nletra %c",letra);*/

    return 0;
}
