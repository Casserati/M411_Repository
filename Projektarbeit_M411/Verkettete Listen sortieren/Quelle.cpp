#include "stdio.h"
#include "stdlib.h"
#include "string.h" 


typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person *pNext;
}struPerson;
