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



char getRandomChar() {
	// Zufallzeichen generieren und zurück geben
		char randomChar = 'A' + (rand() % 26);
		return randomChar;
}

int getRandomInt() {
	// Zufallzahl generieren und zurück geben
	int randomInt = 1900 + (rand() % 119);
	return randomInt;
}
//Bubblesort
struPerson* SortList(struPerson *pStart){
	struPerson* ipStart = NULL, *jpStart = NULL, *pSortedList = NULL;
	int temp;

	for (ipStart = pStart; ipStart->pNext != NULL; ipStart = ipStart->pNext)
	{
		for (jpStart = ipStart->pNext; jpStart != NULL; ipStart = ipStart->pNext) {
			if (ipStart->Nachname[0] > jpStart->Nachname[0]) {
				temp = ipStart->Nachname[0];
				ipStart->Nachname[0] = jpStart->Nachname[0];
				jpStart->Nachname[0] = temp;
			}
		}
	}

	printf("Liste wurde mit BubbleSort sortiert.\n");
	return pSortedList = pStart;
}


void Output(struPerson* pListStart, int amountOfElements) {
	if (pListStart != NULL) {
		int i = 1;
		if (amountOfElements != 0) {
			printf("Liste:\n");
			for (struPerson* pOut = pListStart; i <= amountOfElements; pOut = pOut->pNext) {
				printf("Element Nummer: %d\n", i);
				printf("Vorname: %c\n", pOut->Vorname[0]);
				printf("Nachname: %c\n", pOut->Nachname[0]);
				printf("Jahrgang: %i\n", pOut->Jahrgang);
				printf("----------------------------------\n");
				i++;
			}
		}
		else {
			for (struPerson* pOut = pListStart; pOut != NULL; pOut = pOut->pNext) {
				printf("Element Nummer: %d\n", i);
				printf("Vorname: %c\n", pOut->Vorname[0]);
				printf("Nachname: %c\n", pOut->Nachname[0]);
				printf("Jahrgang: %i\n", pOut->Jahrgang);
				printf("----------------------------------\n");
				i++;
			}
		}
	}
	else {
		printf("Keine Elemente in der Liste vorhanden!\n");
	}
}

struPerson* deleteList(struPerson* pListStart) {
	if (pListStart != NULL) {
		struPerson* pFirst = pListStart;
		while (pFirst != NULL) {
			struPerson* pCurrent = pFirst;
			pFirst = pFirst->pNext;
			pCurrent->pPrev = NULL;
			free(pCurrent);
		}
		return pFirst;
	}
	return NULL;
}
	

struPerson* deleteElement(struPerson* pListStart, char firstname[], char nachname[]) {
	struPerson* pCurrent = pListStart;
	while (pCurrent != NULL) {
		struPerson* pDel = pCurrent;
		if (pDel->Vorname[0] == firstname[0] && pDel->Nachname[0] == nachname[0]) {
			pCurrent->pPrev = pDel;
			free(pDel);
		}
	}
	return pCurrent;
}

struPerson* Create(int count) {
	/*
	Create List with param "Count"
	*/
	struPerson *pStart = NULL;
	struPerson *pLast = NULL;

	for (int i = 0; i < count; i++) {
		struPerson *pNewPerson = (struPerson *)malloc(sizeof(struPerson));
		*pNewPerson->Vorname = getRandomChar() + '\0';
		*pNewPerson->Nachname = getRandomChar() + '\0';
		pNewPerson->Jahrgang = getRandomInt();;

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

void main() {
	srand((unsigned)time(NULL));
	struPerson* pStart = Create(10);
	Output(pStart, 2);
	SortList(pStart);
	Output(pStart, 0);
	pStart = deleteList(pStart);
	Output(pStart, 2);
	system("pause");
}
