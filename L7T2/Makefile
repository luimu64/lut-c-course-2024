CC = gcc
CFLAGS = -g -Wall -pedantic

all: L7T2

L7T2: L7T2.o L7T2_lista.o
	$(CC) $(CFLAGS) -o L7T2 L7T2.o L7T2_lista.o

L7T2.o: L7T2.c L7T2_lista.h
	$(CC) $(CFLAGS) -c L7T2.c

L7T2_lista.o: L7T2_lista.c L7T2_lista.h
	$(CC) $(CFLAGS) -c L7T2_lista.c

run: L7T2
	./L7T2

clean:
	rm -f *.o L7T2
