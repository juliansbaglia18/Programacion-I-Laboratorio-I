#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVector(int datos [],int tamanio);
void mostrarPalabras(char datos[10]);
void cargarVector(int datos [],int tamanio);
void ordenarVector(int datos [],int tamanio);


int main()
{
    char usuario[][10]={"Jose","Maria","Jesus","Melchor","Gaspar"};
    int nota[10]={8,5,2,10,3};
    int i;
    int j;

    mostrarVector(nota,5);
    cargarVector(nota,5);
    mostrarVector(nota,5);
    /*
    //inicio de arrays
    for(i=0;i<5;i++){  //
            //usuario[i][0]=" ";//asigno la palabra al sring
            strcpy(usuario[i],"");
            //nota[i]=0;


    }*/
    //strcpy(usuario[0],"hola");
    //printf("test %s \n",usuario[0]);
    //printf("test %s \n",usuario[1]);

    /*
    //Carga de arrays en paralelo
    for(i=0;i<5;i++){//ingresas un usuario y su nota
            printf("Ingrese usuario #%d: ",i+1);
            scanf("%s",usuario[i]);
            //printf("\nIngrese la nota: %d \n ",i+1);
            //scanf("%d",&nota[i]);

    }*/


    //printf("Ingrese usuario:\n");//Indico solamene un usuario
    //scanf("%s",usuario[1]/*[]indica que elemento es*/);

    //int tamanio = strlen(usuario[9]);
    //printf("tamaño: %d\n", tamanio);

    /*
    //Mostrar
    for(i=0;i<5;i++){
            printf("El alumno: %s \t La nota: %d\n",usuario[i],nota[i]);

    }*/

    /*
    //Ordenamiento por nombre
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("%d\t=>\t%d\n",nota[i], nota[j]);
            // no se puedeif(usuario[i]>usuario[j])
            int resultado;

            //resultado=strcmp("hola","hola");//devuelve 0
            //printf("Iguales: %d\n", resultado);

            //resultado=strcmp("Hola","hola");//devuelve-1
            //printf("primer may: %d\n", resultado);

            //resultado=strcmp("hola","hola");//devuelve -1
            //printf("segunda may: %d\n", resultado);*/

            /*resultado=strcmp(usuario[i],usuario[j]);
            if(strcmp(usuario[i],usuario[j])==-1)
            {
                int aux = nota[i];
                nota [i] = nota[j];
                nota [j]= aux;

                char auxString[10];//lo sincronizo con los nombres (?)
                strcpy(auxString,usuario[i]);
                strcpy(usuario[i],usuario[j]);
                strcpy(usuario[j],auxString);

            }
        }
    }*/
    /*
    //ordenamiento por nota
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d\t=>\t%d\n",nota[i], nota[j]);//muestro la comparacion entre los arrays uno por uno
            if(nota[i]>nota[j]){
                int aux = nota[i];
                nota [i] = nota[j];
                nota [j]= aux;

                char auxString[10];//lo sincronizo con los nombres (?)
                strcpy(auxString,usuario[i]);
                strcpy(usuario[i],usuario[j]);
                strcpy(usuario[j],auxString);

            }
        }
    }*/
        /*for(i=0;i<5;i++){  //Mostrar
            printf("El alumno: %s\t La nota: %d\n",usuario[i],nota[i]);

    }*/


    //printf("Hello %s \n", usuario[0]); Mostrabas lo que habia en los distintos espacios
    //printf("Hello %s \n", usuario[1]);
    //printf("Hello %s \n", usuario[2]);

    return 0;
}
void mostrarPalabras(int datos [][10],int tamanio)
{

}

void mostrarVector(int datos[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("nota :%d\n",datos[i]);
    }
}
void cargarVector(int datos [10],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        datos[i]=-1;
    }
}
void ordenarVector(int datos [10],int tamanio)
{

}

