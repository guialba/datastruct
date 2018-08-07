#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct node{
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



//void list_find();     // encontra um item da lista pelo valor
//void list_count();    // conta o numero de registro da lista
//void list_get();      // encontra um item da lista pelo indice ???

#endif