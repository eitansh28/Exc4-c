all: runlib graph

runlib: libEx4.a
libEx4.a: Nodes.o Edges.o algo.o
	ar -rcs libEx4.a Nodes.o Edges.o algo.o

Nodes.o: Nodes.c Nodes.h
	gcc -Wall -g -c Nodes.c

Edges.o: Edges.h Edges.c
	gcc -Wall -g -c Edges.c

algo.o: algo.h algo.c
	gcc -Wall -g -c algo.c

main.o: main.c algo.h Edges.h Nodes.h
	gcc -Wall -g -c main.c

graph: main.o libEx4.a
	gcc -Wall -o graph main.o libEx4.a

.PHONY: clean all

clean:
	rm -f *.o *.a graph
