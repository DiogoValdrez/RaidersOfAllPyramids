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
void exch(int*, int*);
bool IsEmpty();
void PQinsert(int);
int PQdelmin(int* wt);
bool lessPri(int i1, int i2, int *wt);
void PQsort(int pTable[], int L, int R);
void Heapsort(int Table[], int L, int R);
void FixUp(int *Heap, int Idx, int* wt);
void FixDown(int Heap[], int Idx, int N, int* wt);


#endif