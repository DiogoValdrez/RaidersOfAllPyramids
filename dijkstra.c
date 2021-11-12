#include "dijkstra.h"

/*
 *  Function:
 *    Dijkstra
 *
 *  Description:
 *    Implements the dijkstra algorithm to find the shortest path to all points
 *  Arguments:
 *    graph* of the adjacent list;
 *    int s source node;
 *    Int *st vector that stores from where the nodes came;
 *    Int *wt vector that stores the minimum distance between source and every other node
 *
 *  Return value:
 *    void;
 *          
 */
void Dijkstra(graph *G, int s, int *st, int* wt){
  int hsize = G->V;
  int free_= 0;
  int *queue;
  if((queue = (int *) malloc(G->V * sizeof(int))) == NULL)
  {
    freeG(G);
    exit(0);
  }
  int v, w;
  LinkedList *t;
  for (v = 0; v < G->V; v++){
    st[v] = -1;
    wt[v] = INT_MAX;
    PQinsert(v, queue, &free_, hsize);
  }
  
  wt[s] = 0;
  st[s] = 0;
  FixUp(queue, G->V - 2, wt);
  while (!IsEmpty(free_)){
    int ajuda = PQdelmin(wt, queue, &free_);
    if (wt[v = ajuda] != INT_MAX){
      for(v = 0; v < G->V; v++){
        for (t = G->adj[v]; t != NULL; t = t->next){
          if (wt[w = ((edge *)getItemLinkedList(t))->fin] > (wt[v] + ((edge *)getItemLinkedList(t))->peso)){
            if((wt[v] + ((edge *)getItemLinkedList(t))->peso) > 0 )
            {
              wt[w] = (wt[v] + ((edge *)getItemLinkedList(t))->peso);
              FixDown(queue, w, free_, wt);
              st[w] = v;
            }
          }
        }
      }     
    }  
  }
  free(queue);
}


/*
 *  Function:
 *    PQinit
 *    exch
 *    lessPri
 *    PQinsert
 *    IsEmpt
 *    PQdelmin
 *    FixUp
 *    FixDown
 *
 *  Description:
 *    functions that help in dijkstra algorithm implementation
 *  
 */

void PQinit(int Size, int* queue, int* free_, int hsize) {
  if((queue = (int *) malloc(Size * sizeof(int)))==NULL){
    exit(0);
  }
  hsize = Size; *free_ = 0; 
}

void exch(int* q1, int* q2){
  int temp = *q1;
  *q1 = *q2;
  *q2 = temp;
}

bool lessPri(int i1, int i2, int* wt){
  if(wt[i1] > wt[i2]){
    return true;
  }else{
    return false;
  }  
}

void PQinsert(int I, int* queue, int* free_, int hsize){
  if ((*free_)+1 < hsize) {
    queue[*free_] = I;
    (*free_)++;
  }
}

bool IsEmpty(int free_) {
  return free_ == 0 ? true : false;
}

int PQdelmin(int* wt, int* queue, int* (free_)) { 
  exch(&(queue[0]), &(queue[*(free_)-1]));
  FixDown(queue,0,(*(free_)-1), wt);
  return queue[--(*free_)]; 
}


void FixUp(int *Heap, int Idx, int* wt)
{
  while (Idx > 0 && lessPri(Heap[(Idx-1)/2], Heap[Idx], wt)) {
    exch(&(Heap[Idx]), &(Heap[(Idx-1)/2]));
    Idx = (Idx-1)/2;
  }
}
void FixDown(int Heap[], int Idx, int N, int* wt) {
  int Child; 
  while(2*Idx < N-1) { 
    Child = 2*Idx+1;
    if (Child < (N-1) && lessPri(Heap[Child],Heap[Child+1], wt)) Child++;
    if (!lessPri(Heap[Idx], Heap[Child], wt)) break; /* condição acervo */

    exch(&(Heap[Idx]), &(Heap[Child]));
    Idx = Child;
  }
}
