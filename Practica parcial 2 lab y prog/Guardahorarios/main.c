#include <stdio.h>
#include <stdlib.h>
#include "juliansb.h"

int menu();

int main()
{
    int NumElements, NumElementsRead;
    char* chain;
    char newDate[1];
    int flag = 0;
    int i;

    FILE* pArchive = fopen("Work schedules.txt", "a+");
    if(pArchive == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return 1;
    }

    //fprintf(pArchive, "&s,", newDate);
    fseek(pArchive, 0, SEEK_END);
    NumElements = ftell(pArchive);
    rewind(pArchive);

    chain = (char*) calloc(sizeof(char), NumElements);
    if(chain == NULL)
    {
        printf("Memoria no suficiente.");
        return 1;
    }
    NumElementsRead = fread(chain, sizeof(char), NumElements, pArchive);
    if(NumElementsRead != NumElements)
    {
        printf("Error al leer el archivo.");
        fputc(',',pArchive);
    }
    printf("%s", chain);


    do
    {
        switch(menu())
        {
        case 1:
            getString("La nueva cantidad de horas: ", newDate);
            fputs(newDate,pArchive);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            flag = 1;
            break;
        default:
            break;
        }
    }
    while(flag != 1);

    free(chain);
    fclose(pArchive);
    return 0;
}

int menu()
{
    char c[1];
    int option;

    printf("MENU\n1.Cargar horas.\n2.Borrar horas\n3.Reiniciar horas\nESC.Salir.\n");
    printf("\nElija una opcion: ");
    c[0] = getche();
    option = atoi(c);

    return option;
}







