CC=gcc
CFLAGS=-I.

all : client server

client : factorial.c factorial.h
	$(CC) -o client client.c factorial.c -lpthread $(CFLAGS)

server : factorial.c factorial.h server.c
	$(CC) -o server server.c factorial.c -lpthread $(CFLAGS)
	
factorial : factorial.h factorial.c
	$(CC) -o factorial factorial.c $(CFLAGS)

clean :
	rm client server factorial