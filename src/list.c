#include "datastruct.h"


Node* list_new(void* value, int size)
{
    // create node
    Node* node = (Node*) malloc( sizeof(Node) );
    memset( node, 0, sizeof(Node) );

    // value
    node->data = malloc( size );
    memset( node->data, 0, size );
    memcpy(node->data, value, size);

    //size
    node->size = size;

    node->next = 0;
    
    return node;
}

int list_add(List* list, Node* node)
{
    int id = 1;
    List* new = list;
    if((*list))
        while(new)
        {
            id++;
            if((*new)->next) new = &(*new)->next;
            else
            {
                node->id = id;
                (*new)->next = node; 
                break;
            } 
        }

    return id;
}
int list_push(List* list, Node* node)
{

    Node* l = node;
    l->id = 0;
    l->next = *list;
    *list = l;

    List* new = list;
    while(new)
    {
        (*new)->id++;
        if((*new)->next) new = &(*new)->next;
        else break;
    }

    return 1;
}

int list_remove(List* list)
{
    int id = 0;

    if((*list))
    {
        List* new = list;
        while((*new)->next)
            new = &(*new)->next;
            
        free((*new)->data);
        free(*new);
        (*new) = NULL;
    }
    return id;
}
int list_pop(List* list)
{
    int id = 0;

    if((*list))
    { 
        List* new = list;
        while(new)
        {
            (*new)->id--;
            if((*new)->next) new = &(*new)->next;
            else break;
        }

        Node* l = (*list)->next;
        if((*list)->data != NULL)
            free((*list)->data);
        if((*list)!= NULL)
            free(*list);   
        id = (*list)->id;
        (*list) = l;
    }

    return id;
}

int list_clear(List* list)
{
    int n = 0;
    if((*list))
        while(list_pop(list))
            n++;
    return n;
}

int list_count(List* list)
{
    int n = 0;
    List* new = list;
    if((*list))
        while(new)
        {
            n++;
            if((*new)->next) new = &(*new)->next;
            else break;
        }
    return n;
}

int list_print(List* list,  int (*print)(void *))
{
    List* new = list;
    if((*list))
        while(new)
        {
            print((*new)->data);
            if((*new)->next) new = &(*new)->next;
            else break;
        }
    return 0;
}

int list_find(List* list, Node* node, int (*compare)(void*, void*))
{
    int id = -1;
   
    List* new = list;
    if((*list))
        while(new)
        {
            if(!compare((*new)->data, node->data))
            {
                id = (*new)->id;
                break;
            }
            if((*new)->next) new = &(*new)->next;
            else break;
        }

    return id;
}

Node* list_get(List* list, int id)
{
    Node* node = NULL;
  
    List* new = list;
    if((*list))
        while(new)
        {
            if((*new)->id == id)
            {
                node = *new;
                break;
            }
            if((*new)->next) new = &(*new)->next;
            else break;
        }

    return node;
}

