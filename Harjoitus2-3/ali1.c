/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 1 source file ali1.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.15.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This Source file contains functions needed for work with files and some
  other functions to ease the work*/
/*Kommentoitu englanniksi, koska yksi kurssin tavoitteeista on
  Hyvä ohjelmoinnin tyyli. Ohjelma pitäisi olla ymmärrettävä kaikille.*/
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"/*for NewNode need in both files*/
/******************************************************************************/
/**
 *Data *fileToList(const char *, Data *); - declaration
 *This function will read needed values from file
 *and save it to linked list nodes.
 *Will recieve as a parameter the name of the file and a pointer to Start.
 *name also can include the path if file is located
 *outside of program's folder(for Windows users: use \\ instead of \).
 *Will return a pointer to the first node of newly created linked list.
 */
Data *fileToList(const char *name, Data *pStart)
{
        Data *pCur = NULL;
        int rivi = 0; /*amount of rows*/
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
        while ((fgets(buffer, LEN, pFile)) != NULL) {
                if (!pStart) {
                        pStart = (Data *)newNode(sizeof(Data));
                        pCur = pStart;
                } else {
                        pCur->pNext = (Data *)newNode(sizeof(Data));
                        pCur = pCur->pNext;
                }
                initNode(buffer, pCur);
                rivi++;
        }
        fclose(pFile);
        printf("Tiedosto '%s' luettu, %d datariviä.\n\n", name, rivi);
        return pStart;
}
/******************************************************************************/
/**
 *void initNode(char *, Data *); - declaration
 *This function will initialize the given node with values
 *recieved by parsing the string, that was read from file.
 */
void initNode(char *string, Data *pCur)
{
        pCur->year = (unsigned)atoi(strtok(string, ";"));
        pCur->month = (unsigned)atoi(strtok(NULL, ";"));
        pCur->day = (unsigned)atoi(strtok(NULL, ";"));
        strtok(NULL, ";"); /*skipping time*/
        pCur->temp = atoi(strtok(NULL, "\n"));
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
        if (!(pFile = fopen("lampotiladata.txt", "wt"))) { /*tulostiedot.txt*/
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
/**
 *void monthToFile(Month *); - declaration.
 *This function will create new or rewrite existing tulostiedot.csv file
 *inside the program's folder.
 *Newly created .csv file will be filled by data from MonthAnalyse linked list
 *in special format given by task.
 **Example output:
 *;Tammi;Helmi;Maalis;Huhti;Touko;Kesa;Heina;Elo;Syys;Loka;Marras;Joulu
 *Lappeenranta - 2018;-4;-10;-6;4;14;14;20;17;12;5;1;-4
 *Hanko - 2018;0;-5;-3;3;12;13;20;18;14;8;5;0
 *Will recieve a pointer to a first node of MonthAnalyse list as a parameter.
 */
void monthToFile(Month *pStart)
{
        Tulokset *pTul = NULL; /*variable to maintain a pointer to Tulokset*/
        FILE *pCsv = NULL;
        int valinta = 0;

        printf("\nMikä kuukausianalyysi tallennetaan?\n"
        "1) Keskilämpötila\n"
        "2) Minimilämpötila\n"
        "3) Maksimilämpötila\n"
        "Valintasi: ");
        scanf(" %d", &valinta);
        clearStdin();
        /*Checking the user's input*/
        if (valinta < 1 || valinta > 3 ) {
                printf("Tuntematon valinta, yritä uudestaan.\n");
                return;
        }
        /*Attempting to create a new file or overwrite the old one*/
        if (!(pCsv = fopen("tulostiedot.csv", "wt"))) {
                perror("Tiedostoon kirjoittaminen epäonnistui");
                return;
        }
        pTul = pStart->pTulokset; /*initialising the pointer to Tulokset list*/
        /*This small loop will just write in the file the first string with
         months.*/
        while (pTul) {
                fprintf(pCsv, ";%s",pTul->month);
                pTul = pTul->pNext;
        }
        fprintf(pCsv, "\n");/*new line*/
        /*The main loop. Will write in file all the needed data from
          MonthAnalyse linked list*/
        while(pStart) {
                pTul = pStart->pTulokset;/*re-init pointer to Tulokset*/
                fprintf(pCsv, "%s - %d",
                pStart->paikka, pStart->year);/*writing a place and a year*/
                /*This subloop will write data about temperature
                 depending on user's choise. It can be Average,
                 Minumum of Maximum*/
                while(pTul) {
                        if (valinta == 1) {
                                fprintf(pCsv, ";%d", pTul->avgTemp );
                        } else if (valinta == 2) {
                                fprintf(pCsv, ";%d", pTul->minTemp );
                        } else if (valinta == 3) {
                                fprintf(pCsv, ";%d", pTul->maxTemp );
                        }
                        pTul = pTul->pNext;
                }

                fprintf(pCsv, "\n");/*newline at the end*/
                pStart = pStart->pNext; /*initialising the MonthAnalyse pointer
                                          with pointer to next Month node*/
        }
        printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n\n");
        fclose(pCsv);
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
/* eof */
