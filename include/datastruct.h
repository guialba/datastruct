#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct node{
    void* data;
    int size;
    struct node* next;
}List;

List* list_new(void*, int);
int list_push(List*, void* , int);
int list_pop(List**);
int list_clear(List**);

int list_printi(List*);
int list_prints(List* list);

//void list_add();      // Adiciona item no meio da lista pelo indice
//void list_find();     // encontra um item da lista pelo valor
//void list_count();    // conta o numero de registro da lista
//void list_remove();   // remove um item do meio da lista pelo indice ???
//void list_get();      // encontra um item da lista pelo indice ???

#endif