CC=gcc
CFLAGS= -Wall -g -std=c99

PROJECT= roap

OBJ_FILES= main.o file_handling.o variants.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)