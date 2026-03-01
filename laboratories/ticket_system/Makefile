CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/ticket.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = ticket_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.O: %.C
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)