ohjelma: paaohjelma.o ali1.o ali2.o
	gcc paaohjelma.o ali1.o ali2.o -o ohjelma -std=c99 -Wall -pedantic -g
paaohjelma.o: paaohjelma.c ali1.h ali2.h
	gcc paaohjelma.c -c -std=c99 -Wall -pedantic -g
ali1.o: ali1.c ali1.h ali2.h
	gcc ali1.c -c -std=c99 -Wall -pedantic -g
ali2.o: ali2.c ali1.h ali2.h
	gcc ali2.c -c -std=c99 -Wall -pedantic -g
