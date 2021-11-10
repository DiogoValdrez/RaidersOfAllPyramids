#ifndef LinkedListHeader
#define LinkedListHeader

#include "defs.h"

typedef struct LinkedListStruct LinkedList;

LinkedList * initLinkedList(void);

void freeLinkedList(LinkedList * first, void (* freeItemFnt)(Item));

int lengthLinkedList(LinkedList * first);

LinkedList * getNextNodeLinkedList(LinkedList * node);

Item getItemLinkedList(LinkedList * node);

LinkedList * insertUnsortedLinkedList(LinkedList * next, Item this);

LinkedList * insertSortedLinkedList(LinkedList * first,
                           Item item,
                           int (* comparisonItemFnt)
                           (Item item1, Item item2),
                           int * err);

           
#endif
