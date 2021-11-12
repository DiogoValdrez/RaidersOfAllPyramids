#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "adjacency_matrix.h"


void Dijkstra(graph *G, int s, int* st, int* wt);



void PQinit(int, int*,int*, int);
void exch(int*, int*);
bool IsEmpty(int);
void PQinsert(int, int*,int*, int);
int PQdelmin(int* wt, int*, int*);
bool lessPri(int i1, int i2, int *wt);
void PQsort(int pTable[], int L, int R);
void Heapsort(int Table[], int L, int R);
void FixUp(int *Heap, int Idx, int* wt);
void FixDown(int Heap[], int Idx, int N, int* wt);


#endif