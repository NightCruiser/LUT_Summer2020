/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 2 source file ali2.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.14.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This source file contains other functions*/
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
/******************************************************************************/
/**
 *void analyse(s_temp_node *); - declaration
 *This function analyses the temperature data from previously generated
 *linked list, prints out Average, Minimum and Maximum values
 *Recieves the pointer to the first list's node as a parameter.
 */
void analyse(s_temp_node *pStart)
{
        int alkiot = 0;
        int min = 63;/*We have 7 bit values in struct for temperature,*/
        int max = -64;/*so -64 +63 is ok for min/max values*/
        int valSumma = 0;
        while (pStart) {
                valSumma += pStart->temp;
                alkiot++;
                if (pStart->temp > max) max = pStart->temp;
                if (pStart->temp < min) min = pStart->temp;
                pStart = pStart->pNext;
        }
        printf("Lämpötila-analyysi, %d alkiota:\n"
               "  Avg  Min  Max\n"
               "%5d%5d%5d\n\n", alkiot, valSumma / alkiot, min, max);
}
/******************************************************************************/
/**
 *void clearStdin(); - declaration.
 *This function will clear stdin. For example in cases when programm will
 *recieve extra characters as input or in case when after inputed string
 *'\n' remains in stdin.
 */
void clearStdin()
{
        while (1) {
                if (getchar() == '\n') break;
        }
}
/******************************************************************************/
/**
 *This function will initialize the given node with values
 *recieved from parsing the string, that was read from file.
 */
void initNode(char *string, s_temp_node *pCur)
{
        pCur->year = (unsigned)atoi(strtok(string, ";"));
        pCur->month = (unsigned)atoi(strtok(NULL, ";"));
        pCur->day = (unsigned)atoi(strtok(NULL, ";"));
        strtok(NULL, ";"); /*skipping time*/
        pCur->temp = atoi(strtok(NULL, "\n"));
}
/******************************************************************************/
/**
 *void *newNode(size_t size); - declaration
 *This function will allocate a memory for s_tulokset structure
 *Will set the pointer to next inside newly created node to NULL.
 *In case of success will return a pointer to newly created node;
 *In case of error will allert and exit with code (-1).
 */
void *newNode(size_t size)
{
        void *pNew = NULL;
        if (!(pNew = malloc(size))) {
                perror("Muistinvaraus epäonnistui");
                exit(-1);
        }
        memset(pNew, 0, size);
        *(void **)pNew = NULL;
        return pNew;
}
/******************************************************************************/
/**
 *void *vapaa(void *); - declaration
 *This function clears the linked list.
 *Recieves a pointer to first node as a parameter
 */
void *vapaa(s_temp_node *pStart) {
        s_temp_node *ptr = NULL;
        while (pStart) {
                ptr = pStart->pNext;
                free(pStart);
                pStart = ptr;
        }
        return pStart;
}
void vapaaMonth(MAnalyse_t *pStart)
{
        MAnalyse_t *ptr1 = NULL;
        while(pStart) {
                s_tulokset *ptr2 = NULL;
                ptr1 = pStart->pNext;
                while(pStart->pTulokset) {
                        ptr2 = pStart->pTulokset->pNext;
                        free(pStart->pTulokset);
                        pStart->pTulokset = ptr2;
                }
                free(pStart);
                pStart = ptr1;
        }
}
/******************************************************************************/
MAnalyse_t *createMonthList(MAnalyse_t *pMonth, char *fName, s_temp_node *pData)
{
        MAnalyse_t *pCur = NULL;
        s_tulokset *pTul = NULL;
        int i = 0;
        char kuukausi[MONTHS][7] = {"Tammi", "Helmi", "Maalis", "Huhti", "Touko"
                                    ,"Kesa", "Heina", "Elo", "Syys", "Loka",
                                    "Marras", "Joulu"};
        if (pMonth == NULL) {
                pMonth = (MAnalyse_t *)newNode(sizeof(MAnalyse_t));
                pCur = pMonth;
                pMonth->year = pData ->year;
                strcpy(pMonth->paikka, fName);
        } else {
                pCur = pMonth;
                while(pCur->pNext != NULL) {
                        pCur = pCur->pNext;
                }
                pCur->pNext = (MAnalyse_t *)newNode(sizeof(MAnalyse_t));
                pCur = pCur->pNext;
                pCur->year = pData->year;
                strcpy(pCur->paikka, fName);
        }
        pCur->pTulokset = NULL;
        while (pData->pNext != NULL && i < MONTHS) {
                int j = 0;
                int avg = 0;
                int min = 63;/*We have 7 bit values in struct for temperature,*/
                int max = -64;/*so -64 +63 is ok for min/max values*/
                if (pCur->pTulokset == NULL) {
                        pTul = pCur->pTulokset = (s_tulokset *)newNode(sizeof
                                                                (s_tulokset));
                } else {
                        pTul = pCur->pTulokset;
                        while(pTul->pNext != NULL) {
                                pTul = pTul->pNext;
                        }
                        pTul->pNext = (s_tulokset *)newNode(sizeof(s_tulokset));
                        pTul = pTul->pNext;
                }
                while(pData->pNext != NULL && pData->month == i + 1) {
                        if (pData->temp < min) {
                                min = pData->temp;
                                pTul->minTemp = min;
                        }
                        if (pData->temp > max) {
                                max = pData->temp;
                                pTul->maxTemp = max;
                        }
                        avg += pData->temp;
                        j++;
                        pData = pData->pNext;
                }
                pTul->avgTemp = avg / j;
                strcpy(pTul->month, kuukausi[i]);
                i++;
        }
        return pMonth;
        printf("Kuukausianalyysi valmis.\n");
}
/******************************************************************************/
void printTulokset(MAnalyse_t *pStart, FILE *stream)
{
        int i = 0;
        s_tulokset *pCur = NULL;
        char printArr[3][4] = {"avg", "min", "max"};
        while (pStart != NULL) {
                pCur = pStart->pTulokset;
                fprintf(stream, "%s\n%d\t", pStart->paikka, pStart->year);
                while(pCur != NULL) {
                        fprintf(stream, "%s\t", pCur->month);
                        pCur = pCur->pNext;
                }
                fprintf(stream, "\n");
                pCur = pStart->pTulokset;
                for (i = 0; i < 3; i++) {
                        fprintf(stream, "%s:\t", printArr[i]);
                        while(pCur !=NULL) {
                                if (i == 0) {
                                        fprintf(stream, "%d\t", pCur->avgTemp);
                                }
                                if (i == 1) {
                                        fprintf(stream, "%d\t", pCur->minTemp);
                                }
                                if (i == 2) {
                                        fprintf(stream, "%d\t", pCur->maxTemp);
                                }
                                pCur = pCur->pNext;
                        }
                        fprintf(stream, "\n");
                        pCur = pStart->pTulokset;
                }
                fprintf(stream, "\n\n");
                pStart = pStart->pNext;
        }
}
/******************************************************************************/
/* eof */
