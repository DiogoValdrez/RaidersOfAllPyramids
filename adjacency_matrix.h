#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"

typedef struct _edge{
    int peso;
    int ini;
    int fin;
    int i;
    int j;
}edge;
typedef struct _graph{
    int V;
    //int E;
    LinkedList **adj;
}graph;
typedef struct _itemG{
  int peso;
  int dest;
  int i;
  int j;
} itemG;


graph* newG(int V);
void AddG ( graph* , edge* );
void freeG (graph*);
void check_adj(graph* adj_matrix, edge* e);


#endif