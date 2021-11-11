#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "adjacency_matrix.h"

//void Dijkstra(int **Graph, int x, int start, int* distance, int* pred, int* visited);
void GRAPHpfs(graph *G, int s, int* st, int* wt);

/* void swap(int *a, int *b);
void heapify(int array[], int size, int i);
void insert(int array[], int newNum, int size);
void deleteRoot(int array[], int num, int size);
void printArray(int array[], int size); */

void PQinit(int);
bool IsEmpty();
void PQinsert(Item);
Item PQdelmax();
void PQsort(Item pTable[], int L, int R);
void Heapsort(Item Table[], int L, int R);
void FixUp(Item Heap[], int Idx);
void FixDown(Item Heap[], int Idx, int N);


#endif