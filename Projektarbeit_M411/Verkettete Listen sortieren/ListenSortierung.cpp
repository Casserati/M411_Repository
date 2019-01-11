#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

//	Gerry Sroy
typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	int Nummer;
	struct Person *pNext;
	struct Person *pPrev;
}struPerson;

//	Gerry Sroy
char getRandomChar() {
	// Zufallzeichen generieren und zurück geben
	char randomChar = 'A' + (rand() % 26);
	return randomChar;
}

//	Gerry Sroy
int getRandomInt() {
	// Zufallzahl generieren und zurück geben
	int randomInt = 1900 + (rand() % 119);
	return randomInt;
}
void swapContent(struPerson* elementOne, struPerson* elementTwo) {
	char tempLastname[1] = { *elementOne->Nachname };
	char tempFirstname[1] = { *elementOne->Vorname };
	int tempYear = elementOne->Jahrgang;
	int tempNumberOfElement = elementOne->Nummer;
	*elementOne->Vorname = *elementTwo->Vorname;
	*elementOne->Nachname = *elementTwo->Nachname;
	elementOne->Jahrgang = elementTwo->Jahrgang;
	elementOne->Nummer = elementTwo->Nummer;
	*elementTwo->Nachname = *tempLastname;
	*elementTwo->Vorname = *tempFirstname;
	elementTwo->Jahrgang = tempYear;
	elementTwo->Nummer = tempNumberOfElement;
}
struPerson* bubbleSort(struPerson* pListStart) {
	struPerson* tempStart1 = NULL;
	struPerson* tempStart2 = NULL;
	clock_t start, stop;
	printf("\t SORT STARTED\n");
	start = clock();
	for (tempStart1 = pListStart; tempStart1->pNext != NULL; tempStart1 = tempStart1->pNext) {
		for (tempStart2 = tempStart1->pNext; tempStart2 != NULL; tempStart2 = tempStart2->pNext) {
			if (tempStart1->Vorname[0] > tempStart2->Vorname[0]) {
				swapContent(tempStart1, tempStart2);
			}
			else if (tempStart1->Vorname[0] == tempStart2->Vorname[0]) {
				if (tempStart1->Nachname[0] > tempStart2->Nachname[0]) {
					swapContent(tempStart1, tempStart2);

				}
				else if (tempStart1->Nachname[0] == tempStart2->Nachname[0]) {
					if (tempStart1->Jahrgang > tempStart2->Jahrgang) {
						swapContent(tempStart1, tempStart2);
					}
				}
			}
		}
	}
	stop = clock();
	printf("Ben\224tigte Zeit zum Sortieren: %i", stop - start);
	printf("\t LIST SORTED!\n");
	return pListStart;
}
void Output(struPerson* pListStart, int amountOfElements) {
	if (pListStart != NULL) {
		int i = 1;
		if (amountOfElements != 0) {
			printf("Liste:\n");
			for (struPerson* pOut = pListStart; i <= amountOfElements; pOut = pOut->pNext) {
				printf("Element Nummer: %d\n", pOut->Nummer);
				printf("Vorname: %c\n", pOut->Vorname[0]);
				printf("Nachname: %c\n", pOut->Nachname[0]);
				printf("Jahrgang: %i\n", pOut->Jahrgang);
				printf("----------------------------------\n");
				i++;
			}
		}
		else {
			for (struPerson* pOut = pListStart; pOut != NULL; pOut = pOut->pNext) {
				printf("Element Nummer: %d\n", pOut->Nummer);
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

//	Gerry Sroy
struPerson* deleteList(struPerson* pListStart) {
	if (pListStart != NULL) {
		struPerson* pFirst = pListStart;
		while (pFirst != NULL) {
			struPerson* pCurrent = pFirst;
			pFirst = pFirst->pNext;
			pCurrent->pPrev = NULL;
			free(pCurrent);
		}
		printf("Liste wurde gel\224scht!\n");
		return pFirst;
	}
	printf("Keine Liste vorhanden!\n");
	return NULL;
}
struPerson* deleteElement(struPerson* pListStart, char firstname[], char nachname[]) {
	struPerson* pList = pListStart;
	struPerson* pCurrent = pListStart;
	while (pCurrent != NULL) {
		struPerson* pDel = pCurrent;
		if (pDel->Vorname[0] == firstname[0] && pDel->Nachname[0] == nachname[0]) {
			if (pDel->pNext != NULL && pDel->pPrev != NULL) {
				pDel->pPrev->pNext = pDel->pNext;
				pDel->pNext->pPrev = pDel->pPrev;
				pCurrent = pCurrent->pNext;
				free(pDel);
			}
			else if (pDel->pNext == NULL) {
				pDel->pPrev->pNext = NULL;
				free(pDel);
			}
			else
			{
				pDel->pNext->pPrev = NULL;
				pList = pDel->pNext;
				pCurrent = pCurrent->pNext;
				free(pDel);
			}
		}
		pCurrent = pCurrent->pNext;
	}
	printf("Element(e) gel\224scht!\n");
	return pList;
}

//	Gerry Sroy
int countElements(struPerson* pListStart) {
	int amount = 0;
	struPerson* pCurrent = pListStart;
	while (pCurrent != NULL) {
		amount++;
		pCurrent = pCurrent->pNext;
	}
	return amount;
}


struPerson* Create(int count) {
	struPerson *pStart = NULL;
	struPerson *pLast = NULL;
	for (int i = 0; i < count; i++) {
		struPerson *pNewPerson = (struPerson *)malloc(sizeof(struPerson));
		*pNewPerson->Vorname = getRandomChar() + '\0';
		*pNewPerson->Nachname = getRandomChar() + '\0';
		pNewPerson->Nummer = i + 1;
		pNewPerson->Jahrgang = getRandomInt();
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
	printf("Liste wurde erstellt!\n");
	return pStart;
}


void main() {
	srand((unsigned)time(NULL));
	char userInput = NULL;
	int elementCount = 0;
	struPerson* pStart = NULL;
	printf("THIS PROGRAM WAS CREATED BY GERRY SROY AND FRANCESCO CASAMASSA\n");
	while (true)
	{
		fseek(stdin, 0, SEEK_END);
		printf("Was m%cchten Sie tun?\n", 148);
		printf("Dr%ccken Sie [1] um eine Liste zu erstellen\n", 129);
		printf("Dr%ccken Sie [2] um die Liste zu l%cschen\n", 129, 148);
		printf("Dr%ccken Sie [3] um ein Element(e) in der Liste zu l%cschen\n", 129, 148);
		printf("Dr%ccken Sie [4] um die Liste zu sortieren\n", 129);
		printf("Dr%ccken Sie [5] um die Liste auszugeben\n", 129);
		printf("Dr%ccken Sie [6] um das Programm zu beenden\n", 129);
		scanf("%d", &userInput);
		switch (userInput) {
		case 1:
			printf("Geben Sie die Anzahl Elemente an die erstellt werden sollen: \n");
			scanf("%d", &userInput);
			pStart = Create(userInput);
			break;
		case 2:
			if (pStart != NULL) {
				pStart = deleteList(pStart);
			}
			else {
				printf("Sie m%cssen zuerst eine Liste erstellen\n", 129);
			}
			break;
		case 3:
			if (pStart != NULL) {
				char firstname[1];
				char lastname[1];
				printf("Geben Sie den Vornamen der Person ein die gel%cscht werden soll: ", 148);
				scanf("%c", &firstname);
				printf("\nGeben Sie den Nachnamen der Person ein die gel%cscht werden soll: ", 148);
				scanf("%c", &lastname);
				pStart = deleteElement(pStart, firstname, lastname);
			}
			else {
				printf("Sie m%cssen zuerst eine Liste erstellen\n", 129);
			}
			break;
		case 4:
			if (pStart != NULL) {
				pStart = bubbleSort(pStart);
			}
			else {
				printf("Sie m%cssen zuerst eine Liste erstellen\n", 129);
			}
			break;
		case 5:
			if (pStart != NULL) {
				printf("Geben Sie die Anzahl Elemente ein die ausgegeben werden sollen, 0 f%cr alle: ", 129);
				scanf("%d", &userInput);
				elementCount = countElements(pStart);
				if (userInput != 0) {
					while (elementCount > userInput)
					{
						printf("Ihre Zahl ist gr%csser als die Anzahl Elemente der Liste!\n", 148);
						printf("Versuchen Sie es erneut: ");
						scanf("%d", &userInput);
					}
				}
				Output(pStart, userInput);
			}
			else {
				printf("Sie m%cssen zuerst eine Liste erstellen\n", 129);
			}
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Ung%cltige Eingabe!\n", 129);
			break;
		}
	}
}

