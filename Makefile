CC=gcc
CFLAGS= -Wall -std=c99 -O3

PROJECT= roap

OBJ_FILES= main.o file_handling.o variants.o board.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)
