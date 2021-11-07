#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int **create_adj_matrix(int **bd, int *size, int **adj_matrix, int x);
void new_edge(int **adj_matrix, int vert1, int vert2, int weight);
void free_adj_matrix(int **adj_matrix, int x);

#endif