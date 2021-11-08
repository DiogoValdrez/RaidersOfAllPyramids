#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int *dijkstra(int **adj_matrix, int src, int x);
int minDistance(int *dist, bool *sptSet, int x);
void printPath(int *prev, int j);
void printSolution(int *dist, int x, int *prev);

#endif