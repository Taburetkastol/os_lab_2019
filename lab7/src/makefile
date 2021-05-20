CC=gcc
CFLAGS=-I.

all : tcpclient tcpserver udpclient udpserver

tcpclient : tcpclient.c 
	$(CC) -o tcpclient tcpclient.c

tcpserver : tcpserver
	$(CC) -o tcpserver tcpserver.c 

udpclient : udpclient
	$(CC) -o udpclient udpclient.c

udpserver : udpserver
	$(CC) -o udpserver udpserver.c

clean :
	rm tcpclient tcpserver udpclient udpserver