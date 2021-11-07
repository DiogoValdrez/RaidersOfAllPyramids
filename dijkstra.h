#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

//\int minDistance(int *dist, bool *sptSet, int x);
//void printSolution(int *dist, int x);
void dijkstra(int **adj_matrix, int src, int x);

#endif