
typedef struct
{
    int id;
    char nombre [128];
    char genero [128];
    int age;
}ePelicula;

int employee_get_id (ePelicula* ptrEmp, int* this);
int employee_get_nombre (ePelicula* ptrEmp,char* this);
int employee_get_genero (ePelicula* ptrEmp,char* this);
int employee_get_age (ePelicula* ptrEmp,int* this);

int employee_set_id (ePelicula* ptrEmp,int this);
int employee_set_nombre (ePelicula* ptrEmp,char* this);
int employee_set_genero (ePelicula* ptrEmp,char* this);
int employee_set_age (ePelicula* ptrEmp,int this);

ePelicula* employee_new_text (char* id,char* name,char* age,char* genero);
ePelicula* employee_new_parameters (int id, char* name, int age, char* genero);
ePelicula* employee_new (void);

void pelicula_print_employee (ePelicula* this);
void pelicula_print_header(void);

int employee_sort(void* ptrEmp1 ,void* ptrEmp2);

int filtroDeGeneros (void* this, char* temp);
//int depurarPeliculas(LinkedList* this);
