#include "adjacency_matrix.h"
/* void new_edge(int **adj_matrix, int vert1, int vert2, int weight, Coordinates **adj_matrix_coord, int height, int width)
{
    int ind1 = (-1)*vert1 - 2;
    int ind2 = (-1)*vert2 - 2;

    if (adj_matrix[ind1][ind2] == -1 || adj_matrix[ind1][ind2] > weight)
    {
        adj_matrix[ind1][ind2] = weight;
        adj_matrix[ind2][ind1] = weight;
        adj_matrix_coord[ind1][ind2].height = height;
        adj_matrix_coord[ind2][ind1].height = height;
        adj_matrix_coord[ind1][ind2].width = width;
        adj_matrix_coord[ind2][ind1].width = width;

    }
} */



/* int **create_adj_matrix(int **bd, int *size, int **adj_matrix, int x, Coordinates **adj_matrix_coord)
{
    int i,j;
    x = (-1)*x -1;
    //Allocate space for matrix and initialize it with the value of -1
    if((adj_matrix = (int **)malloc(sizeof(int*)*x))==NULL){
      exit(0);  
    }
    for(i = 0; i<x; i++){
      if((adj_matrix[i] = (int*)malloc(sizeof(int)*x))==NULL){
        for(j = 0; j<i; j++){
          free(adj_matrix[j]);
        }
        free(adj_matrix);
        exit(0);
      }
    } 
    for(i = 0; i<x; i++){
      for (j = 0; j<x; j++){
        if (i==j){
            adj_matrix[i][j] = 0;
            adj_matrix_coord[i][j].height = 0;
            adj_matrix_coord[i][j].width = 0;
        }else{
            adj_matrix[i][j] = -1;
            adj_matrix_coord[i][j].height = 0;
            adj_matrix_coord[i][j].width = 0;

        }
      }
    }

    //Go through bd to check walls and fill adjacecny matrix
    for (i=0;i<size[0]; i++)
    {
        for (j= 0; j<size[1]; j++)
        {
            if (bd[i][j] > 0)
            {
                if ((i == 0 || i == (size[0] - 1)) && (j != 0) && (j != (size[1]-1)))
                {
                    if (bd[i][j-1] < -1 && bd[i][j+1] < -1 )
                    {
                        new_edge(adj_matrix, bd[i][j-1], bd[i][j+1], bd[i][j], adj_matrix_coord, i, j);
                    }
                }else if ((j == 0 || j == (size[1] - 1)) && i != 0 && i != (size[0]-1))
                {
                    if (bd[i-1][j] < -1 && bd[i+1][j] < -1 )
                    {
                        new_edge(adj_matrix, bd[i-1][j], bd[i+1][j], bd[i][j], adj_matrix_coord, i, j);
                    }
                }else if (i != 0 && j != 0 && i != (size[0]-1) && j != (size[1] - 1)) 
                {
                    if (bd[i][j-1] < -1 && bd[i][j+1] < -1)
                    {
                        new_edge(adj_matrix, bd[i][j-1], bd[i][j+1], bd[i][j], adj_matrix_coord, i, j);
                    }
                    if(bd[i-1][j] < -1 && bd[i+1][j] < -1)
                    {
                        new_edge(adj_matrix, bd[i-1][j], bd[i+1][j], bd[i][j], adj_matrix_coord, i, j);
                    }
                }
            }
        }
        
    }
    
     for (int i=0; i<x; i++){
        for(j= 0; j<x; j++){
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 
    return adj_matrix;
}
 */
/* void free_adj_matrix(int **adj_matrix, int x)
{
    int i;
    x = (-1)*x - 1;
    for(i = 0; i<x; i++){
        free(adj_matrix[i]);
    }
    free(adj_matrix);
    return;
} */

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
  itemG *new = (itemG*)malloc(sizeof(itemG));


  new->dest = Edge->fin;
  new->peso = Edge->peso;
  new->i = Edge->i;
  new->j = Edge->j;

  Graph->adj[Edge->ini] = insertUnsortedLinkedList( Graph->adj[Edge->ini], (Item) new );

  new = (itemG*)malloc(sizeof(itemG));

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
