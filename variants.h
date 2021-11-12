#ifndef VARIANTS_HPP
#define VARIANTS_HPP
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int size[2];
    struct node *next_node;
}node;

typedef struct queue{
    node *head;
    int last;
}queue;


int Variant1(int *var_coord, int **bd, int *size);
int Variant2_4(int *var_coord, int **bd, int *size, int piece);
int Variant3(int *var_coord, int **bd, int *size);
int Variant5(int *var_coord, int **bd, int *size);
int Variant6(int *var_coord, int **bd, int *size, int *obj, int flag, int type);
queue* createQueue();
int queue_Empty(queue* q);
node* createNode(int i, int j);
void addNodetoList(queue* q, int i, int j);
node* takeNodefromList(queue* q);
void add_mark_adjacents(int **bd, node *no, queue *q, int *size, int flag);

#endif