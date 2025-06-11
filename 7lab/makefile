CC = gcc
CFLAGS = -Wall -Wextra
AR = ar
ARFLAGS = rcs

SOURCES = add.c sub.c mul.c div.c
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = libcalc.a
TARGET = calculator

all: $(TARGET)

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(TARGET): main.c $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcalc

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(LIBRARY) $(TARGET)

.PHONY: all clean