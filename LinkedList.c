#include"LinkedList.h"

/* struct LinkedListStruct
{
    Item this;
    LinkedList *next;
}; */


LinkedList * initLinkedList(void)
{
    return NULL;
}



void freeLinkedList(LinkedList *first, void (* freeItemFnt)(Item))
{
    LinkedList *aux, *next;

    /* Cycle from the first to the last element           */
    for(aux = first; aux != NULL; aux = next)
    {
        next = aux->next;           /* Keep track of the next node */
        free(aux->this);      
        free(aux);                  /* Free current node    */
    }
    return;
}



int lengthLinkedList(LinkedList *first)
{
    LinkedList *aux;
    int counter;

    /* Length determination cycle                                   */
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
    if(node == NULL)  /* Check that node is not empty */
        return NULL;

    return node->this;
}


LinkedList *insertUnsortedLinkedList(LinkedList *next, Item this)
{
    LinkedList *new;

    /* Memory allocation */
    new = (LinkedList *) malloc(sizeof(LinkedList));

    /* Check memory allocation errors */
    if(new == NULL)
        return NULL;

    /* Initialize new node */
    new->this = this;
    new->next = next;

    return new;
}



LinkedList * insertSortedLinkedList(LinkedList *first,
                Item item,
                int (* compareItems) (Item it1, Item it2),
                int * err)
{
    LinkedList  *new, *aux;

    /* alloc and check */
    new = (LinkedList *) malloc(sizeof(LinkedList));
    if(new == NULL)
        return NULL;
    
    new->this = item;           /* Initialize new node  */
    new->next = NULL;

    if (first == NULL)          /* first item in list */
    {
        return new;
    }
    /* list not empty, insertion sort */
    /* insert at head */
    if ((compareItems(item, first->this) <= 0) )
    {
        new->next = first;
        return new;
    }
    /* second etc */
    aux = first;
    while(aux != NULL)
    {
        if (aux->next != NULL)
        {
            if ( compareItems(item, aux->next->this) <= 0 )
            {
                new->next = aux->next;
                aux->next = new;
                return first;
            }
        }
        else        /* none left, insert in tail */
        {
            aux->next = new;
            return first;
        }
        aux = aux->next;
    }
    return NULL;
}
