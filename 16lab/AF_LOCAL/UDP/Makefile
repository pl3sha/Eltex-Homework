CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET_SERVER = server
TARGET_CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

.PHONY: all clean

all: $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET_SERVER) $(TARGET_CLIENT) 