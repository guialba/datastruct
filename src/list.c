#include "datastruct.h"

List* list_new(void* value, int size)
{
    // create node
    List* list = (List*) malloc( sizeof(List) );
    memset( list, 0, sizeof(List) );

    // value
    list->data = malloc( size );
    memset( list->data, 0, size );
    memcpy(list->data, value, size);

    //size
    list->size = size;

    return list;
}

int list_push(List* list, void* value, int size)
{
    if(list == NULL) return 0;
    else
    {
        if(list->next == NULL)
        {
            list->next = list_new(value, size);
            return 1;
        }
        else
            return 1+list_push(list->next, value, size);
    }
}

int list_pop(List** list)
{
    if(list == NULL) return 0;
    else
    {
        List* next = (*list)->next;
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
                return 1+list_pop(&next);
        }
    }
}

int list_clear(List** list)
{
    if((*list) == NULL)return 0;
    else 
    {
        list_pop(list);
        return 1+list_clear(list);
    }
   
        
}

int list_printi(List* list)
{
    if(list != NULL)
    {
        // Atualmente exibe apenas listas com valores inteiros.
        // A ideia é modificar esta parte para permitir a exibição de qualquer tipo, mas isso ainda precisa ser elaborado  
        printf(" -> (%d) %d \n", list->size, *(int*)list->data);
        return 1+list_printi(list->next);
    }
    else
        return 0;
}
int list_prints(List* list)
{
    if(list != NULL)
    {
        // Atualmente exibe apenas listas com valores inteiros.
        // A ideia é modificar esta parte para permitir a exibição de qualquer tipo, mas isso ainda precisa ser elaborado  
        printf(" -> (%d) %s \n", list->size, (char*)list->data);
        return 1+list_prints(list->next);
    }
    else
        return 0;
}