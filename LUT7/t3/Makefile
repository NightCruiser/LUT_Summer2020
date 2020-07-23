ohjelma: program.o io.o muisti.o
	gcc -o ohjelma program.o io.o muisti.o -std=c99 -Wall -pedantic
program.o: program.c muisti.h io.h
	gcc -c program.c muisti.h io.h -std=c99 -Wall -pedantic
io.o: io.c
	gcc -c io.c -std=c99 -Wall -pedantic
muisti.o: muisti.c
	gcc -c muisti.c -std=c99 -Wall -pedantic
