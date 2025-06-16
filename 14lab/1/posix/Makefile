CC = gcc
CFLAGS = -Wall
LDFLAGS = -lrt -lpthread

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server $(LDFLAGS)

client: client.c
	$(CC) $(CFLAGS) client.c -o client $(LDFLAGS)

clean:
	rm -f server client
	rm -f /dev/shm/Shmname
	rm -f /dev/shm/sem.Semname

.PHONY: all clean 