CC = gcc
CFLAGS = -g -Wall -pedantic

all: L7T3

L7T3: L7T3.o L7T3_io.o L7T3_muisti.o
	$(CC) $(CFLAGS) -o L7T3 L7T3.o L7T3_io.o L7T3_muisti.o

L7T3.o: L7T3.c L7T3_io.h
	$(CC) $(CFLAGS) -c L7T3.c

L7T3_io.o: L7T3_io.c L7T3_io.h
	$(CC) $(CFLAGS) -c L7T3_io.c

L7T3_muisti.o: L7T3_muisti.c L7T3_muisti.h
	$(CC) $(CFLAGS) -c L7T3_muisti.c

clean:
	rm -f *.o L7T3

run: L7T3
	./L7T3