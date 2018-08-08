#include "datastruct.h"

int list_redef(List* list, int i)
{
    if((*list)!=NULL)
    {
        (*list)->id = i;
        list_redef((*list)->next, ++i);
    }
}

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
    
    return node;
}

int list_add(List* list, Node* node)
{
    if(*list == NULL) return 0;
    else
    {
        if((*list)->next == NULL)
        {
            (*list)->next = node;
            list_redef()
            return 1;
        }
        else
            return 1+list_add(&(*list)->next, node);
    }
}
int list_push(List* list, Node* node)
{
    Node* l = node;
    l->next = *list;
    *list = l;
    list_redef(list, 1);
    return 1;
}

int list_remove(List* list)
{
    if(list == NULL) return 0;
    else
    {
        Node* next = (*list)->next;
        if(next == NULL)
        {
            free((*list)->data);
            free(*list);
            (*list) = NULL;
            return 1;
        }
        else
        {
            if(next->next == NULL)
            {
                free((*list)->next->data);
                free((*list)->next);
                (*list)->next = NULL;

                return 2;
            }
            else
                return 1+list_remove(&next);
        }
    }
}
int list_pop(List* list)
{
    Node* l = (*list)->next;
    if((*list)->data != NULL)
        free((*list)->data);
    if((*list)!= NULL)
        free(*list);
    (*list) = l;
    return 1;
}

int list_clear(List* list)
{
    if((*list) == NULL)return 0;
    else 
    {
        list_pop(list);
        return 1+list_clear(list);
    }
   
        
}

int list_count(Node* list)
{
    if(list!=NULL)
        return 1+list_count(list->next);
    else return 0;
}

int list_print(Node* list,  int (*print)(void *))
{
    if(list != NULL)
    {
        print(list->data);
        return 1+list_print(list->next, print);
    }
    else
        return 0;
}

Node* list_find(List* list, Node* node, int (*compare)(void*, void*))
{
    if(list == NULL) return NULL;
    else
    {
        if(!compare((*list)->data, node->data)) 
            return (*list); // Igual
        else // Diferente
            return list_find(&(* list)->next, node, compare);
    }
}