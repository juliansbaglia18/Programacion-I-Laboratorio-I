
typedef struct{
    int id;
    char nombre[50];
    char pais[50];
}eActores;

typedef struct{
    int id;
    int codigo;
    char titulo[50];
    char genero[50];
    int anio;
    int actor;
    int status;
}ePeliculas;


void harcodearActores(eActores lista[], int maximo);

void inicializarPeliculas(ePeliculas lista[], int maximo);

int posicionLibre(ePeliculas lista[], int maximo);

int nuevaPelicula(ePeliculas lista[], int maximo, int id, int codigo, char titulo[], char genero[], int anio, int actor);

void mostrarPeliculas(ePeliculas lista[], int maximo, int opcion);

int buscadorPorId(ePeliculas lista[], int maximo, int id);

int codigoUnico(ePeliculas lista[], int maximo, int codigo);

void mostrarActores(eActores lista[], int maximo);

void ordenarAnio(ePeliculas lista[], int maximo, int opcion);

void ordenarActoresPorPais(eActores lista[], int maximo, int opcion);

//#endif // ARRAYPELICULASACTORES_H_INCLUDED
