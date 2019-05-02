#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[6] = "martin";
    char otroNombre[50] = "Jose Perez";
    int largo;
    int compara;

    //strupr(otroNombre);//convierte a mayuscuka
    //strlwr(otroNombre);//convierte a minusculas
    //strcat(nombre,otroNombre);//????

    //strcpy(nombre, otroNombre);//(variable, constante)
    //strncpy(char, const char, ) funciona como el otro pero copia de manera segura

    //nombre = "juan"//No te deja.
    printf("Su nombre es %s: ", nombre);

    //gets(nombre);//gets funciona solo para windows. Requiere la libreria
    //fgets(nombre, 50, stdin);//funciona como la otra pero tambien va con linux
    //scanf("%[^\n", nombre);//tamnien funciona
    //largo = strlen(nombre);//contamos las letras. si uso fgets, es +1 porque viene con un \n

    //printf("%d", largo);

    //if(nombre == "pepe") no funcionaria porque estariamos comparando un array con un string(que aca en realidad no existen)
    //compara = strcmp(nombre, "pepe");//devuelve 0 si son iguales y dependiendo cual este primero, devuelve 1 o -1,
    //stricmp no discrimina mayusculas o minusiculas

    //printf("%d", compara);
    return 0;
}

//Guardar nombre y apellido y despues convinar en apellido nombre(ej Sbaglia, Julian Agustin);
