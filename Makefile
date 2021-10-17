CC=gcc
CFLAGS= -Wall -std=c99 -g

PROJECT= roap

OBJ_FILES= main.o file_handling.o variants.o

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)
