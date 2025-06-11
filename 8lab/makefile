CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -shared

SOURCES = add.c sub.c mul.c div.c
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = libcalc.so
TARGET = main

all: $(LIBRARY) $(TARGET)

$(LIBRARY): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET): main.c $(LIBRARY)
	$(CC) -o $@ main.c -L. -lcalc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY) $(TARGET)

run: all
	export LD_LIBRARY_PATH=. && ./main

.PHONY: all clean