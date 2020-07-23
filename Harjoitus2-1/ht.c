/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: paaohjelma source file paaohjelma.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.15.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This source file contains main program's source code*/
/*Kommentoitu englanniksi, koska yksi kurssin tavoitteeista on
  Hyvä ohjelmoinnin tyyli. Ohjelma pitäisi olla ymmärrettävä kaikille.*/
/******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ali1.h"
#include "ali2.h"

void getName(char **);
void callMenu();

int main(int argc, char *argv[])
{
        printf("Tämä ohjelma analysoi lämpötilatiedostoja.\n\n");
        callMenu();
        printf("Kiitos ohjelman käytöstä.\n");
        return (0);
}
/******************************************************************************/
void callMenu()
{
        Data *pStart = NULL;
        Month *pMonth = NULL;
        int valinta = 0;
        char *fName = NULL; /*Array will contain the filename or struct name*/
        /*do-while cycle for menu*/
        do {
                printf("Valitse haluamasi toiminto alla olevasta valikosta:\n"
                       "1) Lue lämpötilatiedosto\n"
                       "2) Tallenna listan tiedot\n"
                       "3) Analysoi tiedot\n"
                       "4) Suorita kuukausianalyysi\n"
                       "5) Tulosta kaikki tulokset\n"
                       "6) Tallenna tulokset tiedostoon\n"
                       "7) Tyhjennä analyysilista\n"
                       "0) Lopeta\n"
                       "Valintasi: ");
                scanf(" %d", &valinta);
                clearStdin(); /*will clear stdin*/
                switch (valinta) {
                case 1 : /*Lue lämpötilatiedosto*/
                        if (pStart) {
                                vapaa(pStart);
                                pStart = NULL;
                        }
                        printf("Anna luettavan tiedoston nimi: ");
                        if (fName) free(fName);
                        getName(&fName);
                        pStart = fileToList(fName, pStart);
                        break;
                case 2 : /*Tallenna listan tiedot*/
                        if (pStart) {
                                listToFile(pStart);
                        } else {
                                printf("Lämpötilalista on tyhjä.\n\n");
                        }
                        break;
                case 3 : /*Analysoi tiedot*/
                        if (pStart) {
                                analyse(pStart);
                        } else {
                                printf("Ei analysoitavaa, lue ensin "
                                       "lämpötilatiedosto.\n\n");
                        }
                        break;
                case 4 : /*Suorita kuukausianalyysi*/
                        if(pStart) {
                                printf("Anna analysoitavalle "
                                       "datasetille nimi: ");
                                free(fName);
                                getName(&fName);
                                pMonth = createMonthList(pMonth, fName, pStart);
                        } else {
                                printf("Ei analysoitavaa, lue ensin "
                                       "lämpötilatiedosto.\n\n");
                        }
                        break;
                case 5 : /*Tulosta kaikki tulokset*/
                        if (pMonth != NULL) {
                                printTulokset(pMonth, stdout);
                        } else {
                                printf("Tuloslista on tyhjä.\n");
                        }
                        break;
                case 6 : /*Tallenna tulokset tiedostoon*/
                        if (pMonth != NULL) {
                                monthToFile(pMonth);
                        } else {
                                printf("Tuloslista on tyhjä.\n");
                        }
                        break;
                case 7 : /*Tyhjennä analyysilista*/
                        if (pStart) pStart = vapaa(pStart);
                        if (pMonth) vapaaMonth(pMonth);
                        pStart = NULL;
                        pMonth = NULL;
                        printf("Tuloslista tyhjennetty.\n\n");
                        break;
                case 0 : /*Lopeta*/
                        if (fName) free(fName); /*Frees filename's array*/
                        if (pStart) pStart = vapaa(pStart); /*Data list clear*/
                        if (pMonth) vapaaMonth(pMonth); /*MonthAnalyse*/
                        break;
                default:
                        printf("Tuntematon valinta, "
                               "yritä uudestaan.\n");
                }
        } while (valinta != 0);
}
/******************************************************************************/
/**
 *void getFileName(char **); - declaration
 *This functions asks the user for file name
 *Recieves a pointer to array of characters
 *Function will count the filename's length
 *and allocate the needed amount of memory to hold this name.
 */
void getName(char **fName)
{
        int len = 0;
        char buffer[BUFFER_SIZE] = {0};
        /*We will force the user to input something*/
        do {
                fgets(buffer, BUFFER_SIZE, stdin);
                len = ((int)strlen(buffer) - 1); /*avoiding SegFault. With no
                                                  given value, '\n' will be
                                                  recieved*/
                if (len < 1) {
                        printf("Nimi on tyhjä, yritä uudestaan.\n>> ");
                }
        } while (len < 1);
        if (!(*fName = (char *)malloc(len + 1))) { /*will return lost 1 byte*/
                perror("Muistinvaraus epäonnistui");
                exit (-1);
        }
        strcpy(*fName, strtok(buffer, "\n")); /*will extract '\n' */
}
/******************************************************************************/
_Bool checkAndCall(void function(void *ptr))
{

}
/* eof */
