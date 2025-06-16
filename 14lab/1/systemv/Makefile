CC = gcc
CFLAGS = -Wall

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client
	ipcs -m | grep $(shell whoami) | awk '{print $$2}' | xargs -n1 ipcrm -m 2>/dev/null || true
	ipcs -s | grep $(shell whoami) | awk '{print $$2}' | xargs -n1 ipcrm -s 2>/dev/null || true

.PHONY: all clean 