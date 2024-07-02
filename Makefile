CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
TARGET = ej1

all: $(TARGET)

$(TARGET): ej1.o
	$(CC) $(CFLAGS) -o $(TARGET) ej1.o

ej1.o: ej1.c
	$(CC) $(CFLAGS) -c ej1.c

clean:
	rm -f $(TARGET) ej1.o

.PHONY: all clean