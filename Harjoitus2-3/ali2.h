/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: aliohjelmien 2 header file ali.h
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.15.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
/*Ali2 Header file.*/
/*Kommentoitu englanniksi, koska yksi kurssin tavoitteeista on
  Hyvä ohjelmoinnin tyyli. Ohjelma pitäisi olla ymmärrettävä kaikille.*/
/******************************************************************************/
#ifndef ALI2_H
#define ALI2_H

void analyse(Data *);
void *newNode(size_t size);
Month *createMonthList(Month *, const char *, const Data *);
void printTulokset(Month *, FILE *);
void vapaaMonth(void *);
void vapaa(void *);
#endif /*ALI2_H*/

/******************************************************************************/
/* eof */
