CC=gcc
CFLAGS=-I.

all : tcpclient tcpserver udpclient udpserver

tcpclient : tcpclient.c 
    $(CC) -o tcpclient tcpclient.c $(CFLAGS)

tcpserver : tcpserver
    $(CC) -o tcpserver tcpserver.c $(CFLAGS)

udpclient : udpclient
    $(CC) -o udpclient udpclient.c $(CFLAGS)

udpserver : udpserver
    $(CC) -o udpserver udpserver.c $(CFLAGS)

clean :
    rm tcpclient tcpserver udpclient udpserver