CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/main.c src/contact.c src/agenda.c
OBJ = $(SRC:.c=.o)

all:
	./app

app: $(OBJ)
	$(CC) $(OBJ) -o app

clean:
	rm -f $(OBJ) app