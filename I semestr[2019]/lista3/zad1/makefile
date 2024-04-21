#Makefile

all: main

main: main.o h.o
	clang -o main main.o h.o

main.o: main.c
	clang -c main.c

h.o: h.c
	clang -c h.c

clean:
	rm -f main *.o *~
