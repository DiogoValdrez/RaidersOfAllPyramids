#ifndef BOARD_HPP
#define BOARD_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handling.h"
#include "adjacency_matrix.h"
#include "dijkstra.h"
#include "LinkedList.h"


void createBoard(char *filename, int type);
void decideVar(char* filename, char varia[2], int var_coord[2], int** bd, int size[2], int varia6[2], int type);
#endif