CC=gcc
CFLAGS= -Wall -g -std=c11 -O3

PROJECT= roap

OBJ_FILES= main.o 

$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 

clean:
	rm -f *.o $(PROJECT)