#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct node{
    int id;
    void* data;
    int size;
    struct node* next;
}Node;

typedef Node* List;

Node* list_new(void*, int);

int list_add(List*, Node*);
int list_push(List*, Node*);
int list_remove(List*);
int list_pop(List*);
int list_clear(List*);

int list_count(Node*);

int list_print(Node*, int(*)(void *));



Node* list_find(List*, Node*, int (*compare)(void*, void*));
//void list_get();      // encontra um item da lista pelo indice ???

#endif