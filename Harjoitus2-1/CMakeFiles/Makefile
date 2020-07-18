ohjelma: paaohjelma.o ali1.o ali2.o
	clang paaohjelma.o ali1.o ali2.o -o ohjelma -Wall -pedantic
paaohjelma.o: paaohjelma.c ali1.h ali2.h
	clang paaohjelma.c -c -Wall -pedantic
ali1.o: ali1.c ali1.h ali2.h
	clang ali1.c -c -std=c99 -pedantic
ali2.o: ali2.c ali1.h ali2.h
	clang ali2.c -c -std=c99 -pedantic
