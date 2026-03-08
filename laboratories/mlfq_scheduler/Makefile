CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/process.c src/queue.c src/scheduler.c src/export.c src/simulation.c
OUT = mlfq_scheduler

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT) results.csv