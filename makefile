CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lraylib

game: main.c
	$(CC) $(CFLAGS) -o game main.c $(LDFLAGS)

clean:
	rm -f game