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
void createList(void **pStart, void **pCur, void **pPrev, size_t size);
//s_tulokset *createMonthNode();
void *newNode(size_t size);
void createMonthList(char *, s_temp_node *);
void parseMonthData(s_temp_node **, s_tulokset **, int, char *);
s_temp_node *createNode();
void initNode(char *, s_temp_node *);
void linkNodes(void *pPrev, void *pNew);
//void vapaa(void *);
void *vapaa(s_temp_node *pStart);
#endif /*ALI2_H*/

/******************************************************************************/
/* eof */
