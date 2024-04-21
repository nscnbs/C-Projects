#Makefile

all: main

main: main.o g.o h.o
	clang -o main main.o g.o h.o

main.o: main.c
	clang -c main.c

g.o: g.c
	clang -c g.c

h.o: h.c
	clang -c h.c

clean:
	rm -f main *.o *~
