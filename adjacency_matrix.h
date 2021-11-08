#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct Coordinates {
    int height;
    int width;
}Coordinates;
int **create_adj_matrix(int **bd, int *size, int **adj_matrix, int x, Coordinates **adj_matrix_coord);
void new_edge(int **adj_matrix, int vert1, int vert2, int weight, Coordinates **adj_matrix_coord, int height, int width);
void free_adj_matrix(int **adj_matrix, int x);

#endif