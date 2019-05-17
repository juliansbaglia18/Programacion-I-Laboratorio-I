#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarLetra(char* );

/** \brief Permite cargar un caracter
 *
 * \param char* el char a cargar
 * \return int [0] sui no se pudo cargar el caracter. [1] si se pudo cargare el caracter
 *
 */
int getCaracter(char* );

int main()
{
    char letra;
    int estado;
    estado = getCaracter(&letra);
    if(estado ==1)
    {
        printf("\nDato cargado con exito.");
    mostrarLetra(&letra);

    }
    else
    {
        printf("\nEl dato no fue guardad.");
    }
    /*
    printf("Escribir caracter: ");
    scanf("%c", &letra);
    fflush(stdin);*/
    return 0;
}
void mostrarLetra(char* pLetra)
{
    if(pLetra != NULL)
    {
        printf("\nLa letra es: %c", *pLetra);
    }
}

int getCaracter(char* pLetra)
{
    int cargo=0;
    if(pLetra != NULL)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c",pLetra);
        cargo = 1;
    }
    return cargo;
}
