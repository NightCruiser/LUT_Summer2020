/******************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: alieohjelmien 1 header file ali1.h
 * Tekijä: Valentin Kriukov
 * Opiskelijanumero: 0603219
 * Päivämäärä: 7.14.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/******************************************************************************/
#ifndef ALI1_H
#define ALI1_H
#define LEN 80
#define BUFFER_SIZE 16 * 1024
#define MONTHS 12
/**
 *I decided to use bit-fields because we have a lot af values in files.
 *It will save our memory.
 *16 bytes instead of 24 if we'll use pure ints.
 *7 bits is enought for temperature in our case 128 values
 *12 bits is enough for year 4096 values 0-4095
 *4 bits is enough for month 16 values 0-15
 *5 bits is enough for days 32 values 0-31
 */
struct lampotila {
        struct lampotila *pNext;
        int temp      : 7;  /*Signed 128 values*/
        unsigned year : 12; /*unsigned 4096 values*/
        unsigned month: 4;  /*unsigned 15 values*/
        unsigned day  : 5;  /*unsigned 31 values*/
};

struct tulostiedot {
        struct tulostiedot *pNext;
        char month[7];     /*6 characters + \0 is enough for us*/
        int avgTemp   : 7; /*Signed 128 values*/
        int minTemp   : 7; /*Signed 128 values*/
        int maxTemp   : 7; /*Signed 128 values*/
};

struct monthAnalyse {
        struct monthAnalyse *pNext;
        struct tulostiedot *pTulokset;
        char paikka[36]; /*Äteritsiputeritsipuolilautatsijänkä 35 chars*/
        unsigned year : 12;/*unsigned 4096 values*/
};

typedef struct tulostiedot s_tulokset;
typedef struct lampotila s_temp_node;
typedef struct monthAnalyse MAnalyse_t;

s_temp_node *fileToList(const char *name, s_temp_node *);
void listToFile(s_temp_node *);

#endif /*ALI1_H*/
/******************************************************************************/
/* eof */
