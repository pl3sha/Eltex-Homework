CC = gcc
CFLAGS = -Wall -Wextra
TARGETS = server client

all: $(TARGETS)

server: server.c
	$(CC) $(CFLAGS) -o $@ $<

client: client.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean 