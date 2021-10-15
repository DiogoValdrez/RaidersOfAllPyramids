#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variants.h"

int** createBoard(char filename[24]);
int filePrint(int value, char filename[24]);

#endif