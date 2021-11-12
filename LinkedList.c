#include"LinkedList.h"

LinkedList * initLinkedList(void)
{
    return NULL;
}

void freeLinkedList(LinkedList *first, void (* freeItemFnt)(Item))
{
    LinkedList *aux, *next;

    for(aux = first; aux != NULL; aux = next)
    {
        next = aux->next;           
        free(aux->this);      
        free(aux);                  
    }
    return;
}



int lengthLinkedList(LinkedList *first)
{
    LinkedList *aux;
    int counter;

    for(aux = first, counter = 0;
        aux!=NULL;
        counter++, aux = aux->next);

    return counter;
}



LinkedList * getNextNodeLinkedList(LinkedList * node)
{
  return ((node == NULL) ? NULL : node->next);
}



Item getItemLinkedList(LinkedList *node)
{
    if(node == NULL)
    {  
        return NULL;
    }

    return node->this;
}


LinkedList *insertUnsortedLinkedList(LinkedList *next, Item this)
{
    LinkedList *new;

    if ((new = (LinkedList *) malloc(sizeof(LinkedList))) == NULL)
    {
        exit(0);
    }

    if(new == NULL)
        return NULL;

    new->this = this;
    new->next = next;

    return new;
}

