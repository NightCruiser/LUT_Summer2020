/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 2 file ali.h
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.14.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
#ifndef ALI2_H
#define ALI2_H

void analyse(Data *, FILE *);
void clearStdin();
void createList(void **pStart, void **pCur, void **pPrev, size_t size);
//Tulokset *createMonthNode();
void *newNode(size_t size);
Month *createMonthList(Month *, char *, Data *);
void printTulokset(Month *pStart, FILE *stream);
void parseMonthData(Data **, Tulokset **, int, char *);
Data *createNode();
void initNode(char *, Data *);
void linkNodes(void *pPrev, void *pNew);
//void vapaa(void *);
void vapaaMonth(Month *pStart);
void *vapaa(Data *pStart);
#endif /*ALI2_H*/

/******************************************************************************/
/* eof */
