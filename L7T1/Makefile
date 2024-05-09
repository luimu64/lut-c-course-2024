CC = gcc
CFLAGS = -g -Wall -pedantic

all: L7T1

L7T1: L7T1.o L7T1_io.o
	$(CC) $(CFLAGS) -o L7T1 L7T1.o L7T1_io.o

L7T1.o: L7T1.c L7T1_io.h
	$(CC) $(CFLAGS) -c L7T1.c

L7T1_io.o: L7T1_io.c L7T1_io.h
	$(CC) $(CFLAGS) -c L7T1_io.c

run: L7T1
	./L7T1