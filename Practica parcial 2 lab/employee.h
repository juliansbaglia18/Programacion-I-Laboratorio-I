typedef struct
{
    int id;
    char name [128];
    char job_title [128];
    int age;
    int worked_hours;
    int salary;
    char dedication;
}Employee;

int employee_get_id (Employee* ptrEmp,int* this);
int employee_get_name (Employee* ptrEmp,char* this);
int employee_get_jobTitle (Employee* ptrEmp,char* this);
int employee_get_age (Employee* ptrEmp,int* this);
int employee_get_workedHours (Employee* ptrEmp,int* this);
int employee_get_salary (Employee* ptrEmp,int* this);

int employee_set_id (Employee* ptrEmp,int this);
int employee_set_name (Employee* ptrEmp,char* this);
int employee_set_jobTitle (Employee* ptrEmp,char* this);
int employee_set_age (Employee* ptrEmp,int this);
int employee_set_workedHours (Employee* ptrEmp,int this);
int employee_set_salary (Employee* ptrEmp,int this);

int employee_sortByName(void* ptrEmp1 ,void* ptrEmp2);
int employee_sortByJobTitle(void* ptrEmp1 ,void* ptrEmp2);
int employee_calculate_salary (void* this);
int employee_ageFilter (void* this);
int employee_hoursFilter (void* this);
int employee_salaryFilter (void* this);

int employee_toString (Employee* this, char* retStr);

Employee* employee_new (void);
Employee* employee_new_parameters (int,char*,char*,int,int,int);
Employee* employee_new_text (char* id,char* name,char* title,char* age,char* hours,char* salary);

void employee_print_header (void);
void employee_print_employee (Employee*);
void employee_print_footer (void);

int laQueMapea (void* this);

void employee_print_employeeNameSalary (Employee* this);
