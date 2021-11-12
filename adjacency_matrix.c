#include "adjacency_matrix.h"


graph* newG(int V)
{
  graph *new;
  int i;

  if((new= (graph*)malloc(sizeof(graph)))==NULL){
      printf("Memory allocation failure\n");
      exit(1);
  }
  
  new->V=V;
  //new->E=0;

  if((new->adj= (LinkedList**) malloc( V * sizeof(LinkedList*)))==NULL){
      printf("Memory allocation failure\n");
      exit(1);
  }

  for(i=0; i<V; i++){
    new->adj[i] = NULL;
  }
  
  return new;
}

void check_adj(graph* adj_matrix, edge* e)
{
  LinkedList *list;
  if ( adj_matrix->adj[e->ini] == NULL)
  {
    adj_matrix->adj[e->ini] = insertUnsortedLinkedList(adj_matrix->adj[e->ini], e);
    return;
  }
  list= adj_matrix->adj[e->ini];
  edge *item = (edge*)getItemLinkedList(list);
  if (item == NULL)
  {
    adj_matrix->adj[e->ini] = insertUnsortedLinkedList(adj_matrix->adj[e->ini], e);
    return;
  } 
  
  while(item->fin != e->fin)
  {
    if (list->next == NULL)
    {
      adj_matrix->adj[e->ini] = insertUnsortedLinkedList(adj_matrix->adj[e->ini], e);
      return;
    }
    list = list->next;
    item = (edge*)getItemLinkedList(list);
  }
  
   if (e->peso < item->peso && e->fin == item->fin)
  {
    item->peso = e->peso;
    item->i = e->i;
    item->j = e->j;
  } 
  return; 
}

void AddG( graph *Graph, edge *Edge)
{
  itemG *new;
  if ((new = (itemG*)malloc(sizeof(itemG))) == NULL)
  {
    exit(0);
  }


  new->dest = Edge->fin;
  new->peso = Edge->peso;
  new->i = Edge->i;
  new->j = Edge->j;

  Graph->adj[Edge->ini] = insertUnsortedLinkedList( Graph->adj[Edge->ini], (Item) new );

  if ((new = (itemG*)malloc(sizeof(itemG))) == NULL)
  {
    exit(0);
  }

  new->dest = Edge->ini;
  new->peso = Edge->peso;
  new->i = Edge->i;
  new->j = Edge->j;

  Graph->adj[Edge->fin] = insertUnsortedLinkedList( Graph->adj[Edge->fin], (Item) new );
  return;
}


void freeG( graph *Graph)
{
  int i;
  for( i=0; i<Graph->V ; i++) {
    freeLinkedList (Graph->adj[i], free);//!ver aqui o free se esta bem
  }  
  free(Graph->adj);
  free(Graph);
  return;
}



void printG( graph *Graph , FILE *fp )
{
  int i;
  LinkedList *list;

  fprintf( fp, "%d\n", Graph->V );

  for( i=0; i < Graph->V; i++ ) {
    list = Graph->adj[i];
 
    if(list!=NULL)
      printRec(list, fp);

    fprintf( fp, "-1 \n");
   }
} 

void printRec(LinkedList *aux, FILE *fp)
{
  itemG *i;
  LinkedList *new;
  
  i = getItemLinkedList(aux);
  new = getNextNodeLinkedList(aux);
  if(new!=NULL){
    printRec(new, fp);
  }
  fprintf(fp, "%d:%d ", i->dest, i->peso);

}
