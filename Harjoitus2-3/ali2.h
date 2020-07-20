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

void analyse(Data *);
void clearStdin();
void *newNode(size_t size);
Month *createMonthList(Month *, const char *, const Data *);
void printTulokset(Month *, FILE *);
void initNode(char *, Data *);
void vapaaMonth(void *);
void *vapaa(void *);
#endif /*ALI2_H*/

/******************************************************************************/
/* eof */
