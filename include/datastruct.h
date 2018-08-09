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

int list_count(List*);

int list_print(List*, int(*)(void *));



int list_find(List*, Node*, int (*)(void*, void*));
Node* list_get(List*, int);      

#endif