#include <stdio.h>
#include <stdlib.h>
#include "sbaglia.h"

int main()
{
    int cantidadEscrita, longitudTexto, cantidadLeida;
    FILE* pArchivo;
    char texto[50];

    getString("Ingresa el dato a guardar: ", texto);

    pArchivo = fopen("bank.txt","a");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    longitudTexto = strlen(texto);
    cantidadEscrita = fwrite(texto, sizeof(char), longitudTexto, pArchivo);
    if(cantidadEscrita < longitudTexto)
    {
        printf("Error al escribir");
    }
    fclose(pArchivo);

    pArchivo = fopen("bank.txt", "r");
    longitudTexto = 50;
    printf("El texto leido: ");
    while(!feof(pArchivo))
    {
        cantidadLeida = fread(texto, sizeof(char), longitudTexto,pArchivo);
        printf("%s",texto);
    }
    fclose(pArchivo);

    return 0;
}
