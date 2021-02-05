#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _Node {
    void *value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

void deleteDblLinkedList(DblLinkedList **list);

DblLinkedList* createDblLinkedList();
    
int main(int argc, char* argv[]){



    return 0;
}

DblLinkedList* createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}