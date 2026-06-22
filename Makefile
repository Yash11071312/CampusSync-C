CC = gcc

CFLAGS = -Iinclude

SRC = src/main.c src/student.c src/utils.c

OUT = CampusSync

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	.\$(OUT).exe

clean:
	del /Q $(OUT).exe