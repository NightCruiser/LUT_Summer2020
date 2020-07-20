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
/******************************************************************************/
/**
 *void analyse(Data *); - declaration
 *This function analyses the temperature data from previously generated
 *linked list, prints out Average, Minimum and Maximum values
 *Recieves the pointer to the first list's node as a parameter.
 */
void analyse(Data *pStart)
{
        int alkiot = 0;
        int min = 0;
        int max = 0;
        int valSumma = 0;
        while(pStart) {
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
 *Data *createNode(); - declaration
 *This function will allocate a memory for Data structure
 *Will set the pointer to next inside newly created node to NULL.
 *In case of success will return a pointer to newly created node;
 *In case of error will allert and exit with code (-1).
 */
Data *createNode()
{
        Data *pNew = NULL;
        if (!(pNew = (Data *)malloc(sizeof(Data)))) {
                perror("Muistinvaraus epäonnistui");
                exit(-1);
        }
        pNew->pNext = NULL;
        return pNew;
}
/******************************************************************************/
/**
 *This function will initialize the given node with values
 *recieved from parsing the string, that was read from file.
 */
void initNode(char *string, Data *pCur)
{
        pCur->year = atoi(strtok(string, ";"));
        pCur->month = atoi(strtok(NULL, ";"));
        pCur->day = atoi(strtok(NULL, ";"));
        atoi(strtok(NULL, ";")); /*skipping time*/
        pCur->temp = atoi(strtok(NULL, "\n"));
}
/******************************************************************************/

/**
 *void linkNodes(Data *, Data *); - declaration.
 *This function will link two nodes
 *Will recieve as a parameters two pointers.
 *First pointer to the previous node
 *Second pointer to the node that we will link with previous.
 *Function can link a new node in any position in already created
 *linked list. In this case new node will be added between the node
 *pointed as previous and the node previous pointing to.
 *!!!except the first position!!!.
 *
 */
void linkNodes(Data *pPrev, Data *pNew)
{
        if (pPrev->pNext == NULL) {
                pPrev->pNext = pNew;
                return;
        }
        /*we will not use this feature but this can be useful
         *when adding node in a special position, except the first position.
         *Added this just because of thinking about LUT7-2 exercise, that was
         *done not in best way.
         */
        if (pPrev->pNext) {
                /*initialization inside the block is allowed by standart
                 *it must be right after the curly bracket.
                 *Useful in case when we need this variable just inside
                 *this block.
                 */
                Data *tmp = NULL;
                tmp = pPrev->pNext;
                pPrev->pNext = pNew;
                pNew->pNext = tmp;
        }
}
/******************************************************************************/
/**
 *Data *vapaa(Data *); - declaration
 *This function clears the linked list.
 *Recieves a pointer to first node as a parameter
 */
void vapaa(Data *pStart) {
        Data *ptr = NULL;
        while (pStart) {
                ptr = pStart->pNext;
                free(pStart);
                pStart = ptr;
        }
}
/******************************************************************************/
/* eof */
