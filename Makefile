prog : main.o AlgoGenetique.o
	gcc -Wall -lm -o $@ main.o AlgoGenetique.o

main.o: main.c
	gcc -c main.c

AlgoGenetique.o: AlgoGenetique.c AlgoGenetique.h
	gcc -c AlgoGenetique.c

clean:
	rm *.o
