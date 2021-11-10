#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void Dijkstra(int **Graph, int x, int start, int* distance, int* pred, int* visited);


void swap(int *a, int *b);
void heapify(int array[], int size, int i);
void insert(int array[], int newNum, int size);
void deleteRoot(int array[], int num, int size);
void printArray(int array[], int size);


#endif