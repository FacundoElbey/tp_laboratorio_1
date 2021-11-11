#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Biblioteca.h"

int parser_EmployeeFromText(FILE*, LinkedList*);
int parser_EmployeeFromBinary(FILE*, LinkedList*);



#endif /* PARSER_H_ */
