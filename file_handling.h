#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variants.h"

void createBoard(char *filename);
void filePrint(int value, char *filename);
void freeB(int **bd,int *size);

#endif