typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
}eEmpleado;

eEmpleado* nuevoEmpleado();
eEmpleado* nuevoEmpleadoParametros(int, char*, float);
int setLegajo(eEmpleado*, int);
int getLegajo(eEmpleado*);
int mostrarEmpleado(eEmpleado*);
void destructorEmpleado(eEmpleado*);
