#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    void* data;

};

void list_new();
void list_push(void* , int);
void list_pop();

#endif