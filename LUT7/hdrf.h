#ifndef HDRF_H
#define HDRF_H

struct Node {

    int iluku ;
    struct Node *pNext ;
};
typedef struct Node Solmu;

Solmu *solmuLisaa( Solmu *pA, int i );
void tulosta( Solmu *pA );
Solmu *tyhjenna( Solmu *pA );

#endif /*HDRF_H*/
