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
 *s_temp_node *fileToList(const char *name, s_temp_node *pStart); - declaration
 *This function will read needed values from file
 *and save it to linked list nodes.
 *Will recieve as a parameter the name of the file and a pointer to Start.
 *name also can include the path if file is located
 *outside of program's folder(for Windows users: use \\ instead of \).
 *Will return a pointer to the first node of newly created linked list.
 */
s_temp_node *fileToList(const char *name, s_temp_node *pStart)
{
        s_temp_node *pCur = NULL;
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

        pStart = (s_temp_node *)newNode(sizeof(s_temp_node));
        pCur = pStart;
        fgets(buffer, LEN, pFile);
        initNode(buffer, pStart);
        rivi++;
        /*This loop reads the file string by string,
        *parse the string and creates/inits the linked list
        */
        while ((fgets(buffer, LEN, pFile)) != NULL) {
                pCur->pNext = (s_temp_node *)newNode(sizeof(s_temp_node));
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
 *void listToFile(s_temp_node *); - declaration
 *This function reads data from the linked list
 *and saves this data to the file tulostiedot.txt, that function creates
 *if it doesn't exist.
 *In case when file exist it will be overwritten.
 */
void listToFile(s_temp_node *pStart)
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
void monthToFile(MAnalyse_t *pStart)
{
        s_tulokset *pTul = NULL;
        FILE *pCsv = NULL;
        int valinta = 0;
        /*Will check if file already exists. If not will create and
         *add the first string with months
         */
        if (!(pCsv = fopen("tulostiedot.csv", "r"))) {
                if (!(pCsv = fopen("tulostiedot.csv", "wt"))) {
                        perror("Tiedostoon kirjoittaminen epäonnistui");
                        return;
                }
                pTul = pStart->pTulokset;
                while (pTul) {
                        fprintf(pCsv, ";%s",pTul->month);
                        pTul = pTul->pNext;
                }
                fprintf(pCsv, "\n");
                pTul = NULL;
                fclose(pCsv);
        }
        printf("Mikä kuukausianalyysi tallennetaan?\n"
               "1) Keskilämpötila\n"
               "2) Minimilämpötila\n"
               "3) Maksimilämpötila\n"
               "Valintasi: ");
        scanf(" %d", &valinta);
        clearStdin();
        if (!(pCsv = fopen("tulostiedot.csv", "at"))) {
                perror("Tiedostoon kirjoittaminen epäonnistui");
                return;
        }
        switch (valinta) {
                case 1 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->avgTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                case 2 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->minTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                case 3 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->maxTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                default:
                        printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n");
        fclose(pCsv);
}
/******************************************************************************/
/* eof */
