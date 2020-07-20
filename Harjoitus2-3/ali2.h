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

void analyse(s_temp_node *);
void clearStdin();
void *newNode(size_t size);
MAnalyse_t *createMonthList(MAnalyse_t *, const char *, const s_temp_node *);
void printTulokset(MAnalyse_t *, FILE *);
void initNode(const char *, s_temp_node *);
void vapaaMonth(void *);
void *vapaa(void *);
#endif /*ALI2_H*/

/******************************************************************************/
/* eof */
