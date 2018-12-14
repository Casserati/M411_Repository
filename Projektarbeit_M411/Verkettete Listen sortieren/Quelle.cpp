#include "stdio.h"
#include "stdlib.h"
#include "string.h" 
#include "time.h"

typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person *pNext;
	struct Person *pPrev;
}struPerson;

struPerson* Create(int count) {
	/*
	Create List with param "Count"
	*/
	struPerson *pStart = NULL;
	struPerson *pLast = NULL;

	for (int i = 0; i < count; i++) {
		struPerson *pNewPerson = (struPerson *)malloc(sizeof(struPerson));
		*pNewPerson->Vorname = 'c';
		*pNewPerson->Nachname = 'c';
		pNewPerson->Jahrgang = 1000;

		pNewPerson->pNext = NULL;
		pNewPerson->pPrev = pLast;

		if (pLast != NULL) {
			pLast->pNext = pNewPerson;
		}
		pLast = pNewPerson;
		if (pStart == NULL) {
			pStart = pNewPerson;
		}
	}
	return pStart;
}

char getRandomChar() {
	// Zufallszahlen initialisieren, damit bei jedem Programmstart andere Werte erzeugt werden
		srand((unsigned)time(NULL));
	// Zufallzeichen generieren und zurück geben
		char randomChar = 'A' + (rand() % 26);
		return randomChar;
}

int getRandomInt() {
	// Zufallszahlen initialisieren, damit bei jedem Programmstart andere Werte erzeugt werden
	srand((unsigned)time(NULL));
	// Zufallzahl generieren und zurück geben
	int randomInt = 1900 + (rand() % 119);
	return randomInt;
}

void main() {

	system("pause");
}
