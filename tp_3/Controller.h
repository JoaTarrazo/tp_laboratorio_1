
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "LinkedList.h"
#include "Employee.h"
#include "utn_pedirTipo.h"
#include "parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


int controller_addEmployee(LinkedList* pArrayListEmployee);


int controller_editEmployee(LinkedList* pArrayListEmployee);


int controller_removeEmployee(LinkedList* pArrayListEmployee);


int controller_ListEmployee(LinkedList* pArrayListEmployee);


int controller_sortEmployeeForName(LinkedList* list);


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


