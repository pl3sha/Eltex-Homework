CC = gcc
CFLAGS = -Wall -pthread -lncurses

all: server client

server: server.c chat.h
	$(CC) server.c -o server $(CFLAGS)

client: client.c chat.h
	$(CC) client.c -o client $(CFLAGS)

clean:
	rm -f server client
	rm -f /dev/shm/Shmname
	rm -f /dev/shm/sem.Semname

.PHONY: all clean