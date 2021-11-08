#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variants.h"

void filePrint(int value, char *filename);
void filePrintV(int value, int value2, int value3, char *filename);
void freeB(int **bd, int *size);
void read(FILE *fp, char type, void* addr, int **bd, int *size, int free);
FILE* getFile(FILE *fp, char* filename, char *extra, int type);

#endif