CC = gcc
CFLAGS = -O2 -Wall -pthread

OBJS = matriz.o

all: procSecuencial hebSecuencial procConcurrente hebConcurrente

matriz.o: matriz.c matriz.h
	$(CC) $(CFLAGS) -c matriz.c

procSecuencial: procSecuencial.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ procSecuencial.c $(OBJS)

hebSecuencial: hebSecuencial.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ hebSecuencial.c $(OBJS)

procConcurrente: procConcurrente.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ procConcurrente.c $(OBJS)

hebConcurrente: hebConcurrente.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ hebConcurrente.c $(OBJS)

clean:
	rm -f *.o procSecuencial hebSecuencial procConcurrente hebConcurrente

