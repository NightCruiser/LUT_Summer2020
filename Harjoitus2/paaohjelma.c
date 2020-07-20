/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: paaohjelma source file paaohjelma.c
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.14.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*This source file contains main program's source code*/
/******************************************************************************/
#include <stdio.h>
#include "ali1.h"
#include "ali2.h"

void callMenu(int *, char *, Data **);
_Bool getFileName(char *);

int main(int argc, char *argv[])
{
        Data *pStart = NULL;
        int valinta = 0;
        char fName[20] = {0}; /*Array will contain the filename or struct name*/
        printf("Tämä ohjelma analysoi lämpötilatiedostoja.\n\n");
        callMenu(&valinta, fName, &pStart);
        return (0);
}
/******************************************************************************/
/**
 *void callMenu(int *, char *, Data **); - declaration
 *I am not sure about this move, but it was in task
 *"Pääohjelma ja valikonkäsittelyn hoitava aliohjelma tulee sijoittaa
 *paaohjelma.c tiedostoon"
 */
void callMenu(int *valinta, char *fName, Data **pStart)
{
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
                scanf(" %d", valinta);
                clearStdin(); /*will clear stdin*/
                switch (*valinta) {
                        case 1 : /*Lue lämpötilatiedosto*/
                                if (*pStart) {
                                        vapaa(*pStart);
                                        *pStart = NULL;
                                }
                                if (getFileName(fName)) {
                                        *pStart = fileToList(fName);
                                }
                                break;
                        case 2 : /*Tallenna listan tiedot*/
                                if (*pStart) {
                                        listToFile(*pStart);
                                } else {
                                        printf("Lämpötilalista on tyhjä.\n\n");
                                }
                                break;
                        case 3 : /*Analysoi tiedot*/
                                if (*pStart) {
                                        analyse(*pStart);
                                } else {
                                        printf("Ei analysoitavaa, lue ensin "
                                               "lämpötilatiedosto.\n\n");
                                }
                                break;
                        case 4 : /*Suorita kuukausianalyysi*/
                                printf("Anna analysoitavalle datasetille "
                                       "nimi: ");
                                scanf("%s", fName);
                                clearStdin();
                                createMonthList(fName, *pStart);
                                break;
                        case 5 : /*Tulosta kaikki tulokset*/
                                break;
                        case 6 : /*Tallenna tulokset tiedostoon*/
                                break;
                        case 7 : /*Tyhjennä analyysilista*/
                                break;
                        case 0 : /*Lopeta*/
                                vapaa(*pStart);
                                printf("Kiitos ohjelman käytöstä.\n");
                                break;
                        default:
                                printf("Tuntematon valinta, "
                                       "yritä uudestaan.\n");
                }
        } while (*valinta != 0);
}
/******************************************************************************/
/**
 *_Bool getFileName(char *); - declaration
 *This functions asks the user for file name
 *Recieves a pointer to array of characters
 *Function will check the scanf state
 *Will return 1 if one field is recieved
 *Will return 0 in other cases
 */
_Bool getFileName(char *fName)
{
        printf("Anna luettavan tiedoston nimi: ");
        if ((scanf("%s", fName)) == 1) {
                clearStdin();
                return (1);
        } else {
                clearStdin();
                return (0);
        }
}
/******************************************************************************/
/* eof */
