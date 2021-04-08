CC=gcc
CFLAGS=-I.

all : mutex w_mutex parallel_fact deadlock

mutex : mutex.c
	$(CC) -pthread -o mutex mutex.c $(CFLAGS)

w_mutex : w_mutex.c
	$(CC) -pthread -o w_mutex w_mutex.c $(CFLAGS)

parallel_fact : parallel_fact.c
	$(CC) -pthread -o parallel_fact parallel_fact.c $(CFLAGS)

deadlock : deadlock.c
	$(CC) -pthread -o deadlock deadlock.c $(CFLAGS)

clean :
	rm mutex w_mutex parallel_fact deadlock