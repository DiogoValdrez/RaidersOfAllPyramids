#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct _heap{
  int V;
  int value;
}heap;


void Dijkstra(int **Graph, int x, int start, int* distance, int* pred, int* visited);


void swap(heap **a, heap **b);
void heapify(heap** array, int* size, int i);
void insert(heap** array, heap* h, int* size);
int deleteRoot(heap** array, int num, int* size);
void printArray(heap** array, int* size);



#endif