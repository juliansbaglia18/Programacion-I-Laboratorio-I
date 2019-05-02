#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.c"

int dividir(int numero);
int esDistintoACero(int numero);
int factorial(int numero);

int main()
{
        int miDato = 333;
    cambiarValor(miDato);
    printf("mi dato es : %d",miDato);
    /*
    int edad;
    int retorno = 0;
    do{
            fflush(stdin);
            printf("ingrese una edad");
            retorno = scanf("%d ",&edad);
    }while(retorno == 0);

    printf("la respuesta es : %d",retorno);
    printf("la edad es : %d",edad);

    int dato;
    dato = dividir(6);
    printf("el dato es : %d",dato);
    dato=dividir(0);
    printf("el dato es : %d",dato);*/

    /*int unFactorial;
    unFactorial = factorial(4);
    printf("el factorial es : %d",unFactorial);*/





    return 0;
}
int dividir(int numero){

    int respuesta;
    int resultado;

    respuesta = esDistintoACero(numero);

    if(respuesta == 1){
        resultado = numero/2;
    }
    return respuesta;
}
int esDistintoACero(int numero){
    if(numero!= 0){
            return 1;

    }
    return 0;
}
int factorial(int numero){//hace algo con el numero perfecto. se autollama y va haciendo el factorial del numero anterior (susesivamente)al que usamos
    int respuesta;
    if(numero == 1){
        return 1;
    }
    respuesta=numero*factorial(numero-1);
}*/
