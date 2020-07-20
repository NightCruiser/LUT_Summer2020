/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 1 source file ali1.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.14.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This Source file contains functions needed for work with files*/
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
/******************************************************************************/
/**
 *Data *fileToList(const char *); - declaration
 *This function will read needed values from file
 *and save it to linked list nodes.
 *Will recieve as a parameter the name of the file
 *name also can include the path if file is located
 *outside of program's folder.
 *Will return a pointer to the first node of newly created linked list.
 */
Data *fileToList(const char *name, Data *pStart)
{
        //Data *pStart = NULL;
        Data *pCur = NULL;
        //Data *pPrev = NULL;
        int rivi = 0;
        char buffer[LEN];
        FILE *pFile = NULL;
        if (!(pFile = fopen(name, "rt"))) {
                perror("Tiedoston lukeminen epäonnistui");
                /*we will give user a chance to correct the file name
                 *and will not close the program, so return is used.
                 */
                return NULL;
        }
        printf("Luetaan tiedosto '%s'\n", name);
        fgets(buffer, LEN, pFile); /*we don't need the first string*/
        /*This loop reads the file string by string,
         *parse the string and creates/inits the linked list
         */
        pStart = (Data *)newNode(sizeof(Data));
        pCur = pStart;
        fgets(buffer, LEN, pFile);
        initNode(buffer, pStart);
        rivi++;
        while ((fgets(buffer, LEN, pFile)) != NULL) {
                /*if (pStart == NULL) {
                        pStart = (Data *)newNode(sizeof(Data));
                        pCur = pPrev = pStart;
                        initNode(buffer, pStart);
                        rivi ++;
                } else {

                        pCur = (Data *)newNode(sizeof(Data));
                        initNode(buffer, pCur);
                        linkNodes(pPrev, pCur);
                        pPrev = pCur;
                        rivi ++;
                }*/
                pCur->pNext = (Data *)newNode(sizeof(Data));
                pCur = pCur->pNext;
                initNode(buffer, pCur);
                rivi++;
        }
        fclose(pFile);
        printf("Tiedosto '%s' luettu, %d datariviä.\n\n", name, rivi);
        return pStart;
}
/******************************************************************************/
/**
 *void listToFile(Data *); - declaration
 *This function reads data from the linked list
 *and saves this data to the file tulostiedot.txt, that function creates
 *if it doesn't exist.
 *In case when file exist it will be overwritten.
 */
void listToFile(Data *pStart)
{
        FILE *pFile = NULL;
        if (!(pFile = fopen("tulostiedot.txt", "wt"))) {
                perror("Tiedostoon kirjoittaminen epäonnistui" );
                return;
        }
        fprintf(pFile, "pvm lämpötila\n");
        while (pStart) {
                fprintf(pFile, "%d.%d.%d %d C\n",
                       pStart->day, pStart->month, pStart->year, pStart->temp);
                pStart = pStart->pNext;
        }
        fclose(pFile);
        printf("Lämpötiladata tallennettu.\n\n");
}


/******************************************************************************/
/* eof */
