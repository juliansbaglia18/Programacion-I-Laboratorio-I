#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "employee.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    LinkedList* newList = ll_newLinkedList();
    int option = 0, itsLoaded = 0;
    while (option!=3)
    {
        menu();
        option = getOption();
        switch (option)
        {
        case 1:
            if (itsLoaded==0)
            {
                itsLoaded = controller_load_text("datos.txt",newList);
                int len = ll_len(newList);
                printf("\nSe cargaron %d datos.\n",len);
                system("pause");
            }
            else
            {
                printf("\nDatos ya cargados.\n");
                system("pause");
            }
            break;
        case 2:
            if (itsLoaded)
            {
                controller_sort(newList);
                controller_list_Employee(newList);
            }
            else
            {
                printf("\nAun no se cargaron datos");
                system("pause");
            }
            break;
        case 3:
            printf("\nadios");
            break;
        }
    }

    return 0;
}
