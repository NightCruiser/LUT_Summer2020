/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 2 source file ali2.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.15.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This source file contains other functions*/
/*Kommentoitu englanniksi, koska yksi kurssin tavoitteeista on
  Hyvä ohjelmoinnin tyyli. Ohjelma pitäisi olla ymmärrettävä kaikille.*/
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h" /*for structures*/
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
 *void *newNode(size_t size); - declaration
 *This function will allocate a memory for Tulokset structure
 *Will set the pointer to next inside newly created node to NULL.
 *!!!FUNCTION USES VOID POINTERS!!!
 *!!!DO NOT USE IF YOU ARE NOT SURE ABOUT STRUCTURE REALISATION!!!
 *In All of our structures the first bytes are pointers to Next.
 *So this universal function is usable.
 *In case of success will return a pointer to newly created node;
 *In case of error will allert and exit with code (-1).
 *Recieves as a parameter size of bytes that can be recieved by sizeof function
 *Example (Data *)newNode(sizeof(Data));.
 */
void *newNode(size_t size)
{
        void *pNew = NULL;
        if (!(pNew = malloc(size))) {
                perror("Muistinvaraus epäonnistui");
                exit(-1);
        }
        memset(pNew, 0, size);/*will init all occured memory with 0.
                               not sure about using memset*/
        *(void **)pNew = NULL;/*!!!CHECK STRUCTURE REALISATION!!!*/
        return pNew;
}
/******************************************************************************/
/**
*!!!usable ONLY for structures where the FIRST Bytes are Pointer to Next.!!!
 *void *vapaa(void *); = declaration
 *this "Void pointer" realisation is more universal.
 *Usable because "free" function knows an amount of memory that
 *previously was allocated by malloc.
 *This function clears the linked list.
 *Recieves a pointer to first node as a parameter
*/
void vapaa(void *pStart)
{
        void *ptr = NULL;
        while(pStart) {
                ptr = *(void **)pStart;/*DO NOT use it if you are not sure
                                         about how structures are realised*/
                free(pStart);
                pStart = ptr;
        }
}
/**
 *void *vapaa(void *); - declaration
 *This function clears the linked list.
 *Recieves a pointer to first node as a parameter
 *Will return a NULL pointer;
 */

/*
void *vapaa(Data *pStart)
{
        Data *ptr = NULL;
        while (pStart) {
                ptr = pStart->pNext;
                free(pStart);
                pStart = ptr;
        }
        return pStart;
}
*/
/******************************************************************************/
/**
 *void vapaaMonth(void *); -declaration
 *!!!FUNCTION USES VOID POINTERS!!!
 *!!!DO NOT USE IF YOU ARE NOT SURE ABOUT STRUCTURE REALISATION!!!
 *This is improved void *vapaa(void *) function for 2-dimensional lists.
 *Example : in our case each node of linked list contains another linked list.
 *!!!IN ALL STRUCTURES FIRST BYTES MUST BE A POINTER TO NEXT!!!
 *
 */
void vapaaMonth(void *pStart)
{
        void *ptr1 = NULL;
        while(pStart) {
                ptr1 = *(void **)pStart;
                vapaa(*((void **)pStart + 1));/*+1 means that we need to
                                                access the second variable.
                                                (which is a pointer to 2nd list)
                                                we jump + size of pointer Inside
                                                the memory*/
                free(pStart);
                pStart = ptr1;
        }
}
/**
 *void vapaaMonth(Month *); - declaration
 *This function clears the MonthAnalyse linked list inside of which
 *there is another linked lists of Tulostiedot.
 *All of them will be cleared.
 *Recieves a pointer to the first node of MonthAnalyse list as a parameter
 */
/*void vapaaMonth(Month *pStart)
{
        Month *ptr1 = NULL;
        while(pStart) {
                Tulokset *ptr2 = NULL;
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
*/
/******************************************************************************/
/**
 *Month *createMonthList(Month *, const char *, Data *); - decl
 *This function performs a month analyse based on data that was recieved
 *by Data *fileToList(const char *name, Data *) function.
 *The function will create a linked list of structures MonthsAnalyse.
 *Nodes will contain information about place and year.
 *Inside every node will be created a second linked list of structures
 *where every node will contain month's average, middle and maximum temperature.
 *Recieves as parameters a pointer to the first element of MonthAnalyse list,
 *pointer to an array of chars that will be used to store a name of analyse and
 *a pointer to linked list called here "Data" with analysed data from file.
 *Will return a pointer to first element of MonthAnalyse list
 */
Month *createMonthList(Month *pMonth, const char *fName,
                            const Data *pData)
{
        Month *pCur = NULL;
        Tulokset *pTul = NULL;
        int i = 0; /*this variable will count the months*/
        /*Array of months. It will help to fulfill the list*/
        char kuukausi[MONTHS][7] = {"Tammi", "Helmi", "Maalis", "Huhti", "Touko"
                                    ,"Kesä", "Heinä", "Elo", "Syys", "Loka",
                                    "Marras", "Joulu"};
        /*if there is no previously created MonthAnalyse list,
         the new one will be created*/
        if (pMonth == NULL) {
                pMonth = (Month *)newNode(sizeof(Month));
                pCur = pMonth;
                pMonth->year = pData ->year;  /*initing the variable year*/
                strcpy(pMonth->paikka, fName);/*initing the place's name*/
        } else {
        /*In case if list already exist the loop will find the last node
        and create the new node*/
                pCur = pMonth;
                while(pCur->pNext != NULL) {
                        pCur = pCur->pNext;
                }
                pCur->pNext = (Month *)newNode(sizeof(Month));
                pCur = pCur->pNext;
                pCur->year = pData->year;   /*initing the variable year*/
                strcpy(pCur->paikka, fName);/*initing the place's name*/
        }
        pCur->pTulokset = NULL; /*will NULL the pointer to Tulokstiedot Inside
                                  the MonthAnalyse structure,
                                  because there is a garbage after allocating*/

        /*In this loop we will check at first is there a next element of
         Data analyse list, because there is no guarantee that file results
         will contain every month's information.
         If we have all the months, the second condition will help not to run
         over*/
        while (pData->pNext != NULL && i < MONTHS) {
                int j = 0; /*an amount of samples for average value*/
                int avg = 0;/*will calculate the sum for average value*/
                int min = 63;/*We have 7 bit values in struct for temperature,*/
                int max = -64;/*so -64 +63 is ok for min/max values*/
                /*The Standart allows declarations inside the block
                 right after the curly bracket*/

                /*checks for already existing Tulostiedot list inside the
                 MonthAnalyse strusture, if doesn't exist,
                 creates the new one*/
                if (pCur->pTulokset == NULL) {
                        pTul = pCur->pTulokset = (Tulokset *)newNode(sizeof
                                                                (Tulokset));
                } else {
                        pTul = pCur->pTulokset;
                        while(pTul->pNext != NULL) {
                                pTul = pTul->pNext;
                        }
                        pTul->pNext = (Tulokset *)newNode(sizeof(Tulokset));
                        pTul = pTul->pNext;
                }
                /*this loop initialise the newly created node of Tulostiedot
                 list with data recieved from Data list. For every node
                 this loop will parse the data that related to month given
                 by "i" variable. Added +1, because it was initialised by 0.
                 The first condition checks the existing of next Data node,
                 again we have no guarantee that we have information about
                 all the months and the second condition will not let us
                 run over the needed month*/
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
                        j++; /*sample values increment*/
                        pData = pData->pNext;
                }
                pTul->avgTemp = avg / j; /*sum divided by an amount of samples*/
                strcpy(pTul->month, kuukausi[i]);/*will init the month's name*/
                i++; /*month increment*/
        }
        printf("Kuukausianalyysi valmis.\n\n");
        return pMonth;
}
/******************************************************************************/
/**
 *void printTulokset(Month *, FILE *); - declaration
 *This function will print out to the given stream the data from MonthsAnalyse
 *linked list. Every node of this structure cantains a pointer to the first
 *element of Tulostiedot linked list that also will be printed for each node.
 *The output will be in format given in task.
 *I have added the posibility of changing of output stream. It can be a file.
 *Recieves a pointer to the first element of MonthAnalyse list and a pointer to
 *a stream.
 */
void printTulokset(Month *pStart, FILE *stream)
{
        int i = 0; /*counter needed by the for-loop*/
        Tulokset *pCur = NULL; /*variable needed to maintain the pointer
                                  to Tulostiedot structure*/
        char printArr[3][4] = {"avg", "min", "max"};/*an array of strings needed
                                                      for ease the loop*/
        printf("Analyysilistan tulokset:\n\n");
        /*This main loop will print out the needed data from MonthsAnalyse
         structure and the string with month's names from Tulostiedot*/
        while (pStart != NULL) {
                pCur = pStart->pTulokset;
                fprintf(stream, "%s\n%d", pStart->paikka, pStart->year);
                while(pCur != NULL) {
                        fprintf(stream, "\t%s", pCur->month);
                        pCur = pCur->pNext;
                }
                fprintf(stream, "\n");
                pCur = pStart->pTulokset; /*return the pointer to the 1st node*/
                /*this loop needed to print out Minimum, Maximum and average
                 temperature strings. All the difference between this strings
                 from code perspective is a variable name and the name of
                 the string. We will take the name from an array and print
                 three different variables depending on "i" counter*/
                for (i = 0; i < 3; i++) {
                        fprintf(stream, "%s:", printArr[i]);
                        while(pCur !=NULL) {
                                if (i == 0) {
                                        fprintf(stream, "\t%d", pCur->avgTemp);
                                }
                                if (i == 1) {
                                        fprintf(stream, "\t%d", pCur->minTemp);
                                }
                                if (i == 2) {
                                        fprintf(stream, "\t%d", pCur->maxTemp);
                                }
                                pCur = pCur->pNext;
                        }
                        fprintf(stream, "\n");
                        pCur = pStart->pTulokset;/*return to the fist node*/
                }
                fprintf(stream, "\n");
                pStart = pStart->pNext;
        }
}
/******************************************************************************/
/* eof */
