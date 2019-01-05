#include <stdlib.h>

#include "nlist.h"

void create_new_list(struct list_struct *list)
{
    list = malloc(sizeof(struct list_struct));
    list->next = NULL;
    list->prev = NULL;
    list->data = NULL;
}

void add_data_list(struct list_struct *list, void *data)
{
    if(list->data == NULL) //first time
    {
	list->data = data;
	return;
    }
    struct list_struct *item = malloc(sizeof(struct list_struct));
    item->data = data;
    item->next = list->next;
    item->prev = list;
    list->next =item;
}

int remove_data_list(struct list_struct *list, int (*remove_check) (void *data))
{
    struct list_struct *current = list, *tmp;
    while(current != NULL)
    {
	if(remove_check(current->data))
	{
	    tmp = current;
	    current->prev->next = current->next;
	    current->next->prev = current->prev;
	    free((void *) tmp);
	    return 1;
	}
	current = current->next;
    }
    return 0;
}

void * search_data_list(struct list_struct *list, int (*search_check) (void *data))
{
    struct list_struct *current = list;
    while(current != NULL)
    {
	if(search_check(current->data))
	{
	    return current->data;
	}
	current = current->next;
    }
    return 0;
}

int get_count_list(struct list_struct *list)
{

    struct list_struct *current = list;
    int count =0;
    while(current != NULL)
    {
	current = current->next;
	count++;
    }
    return count;
    
}

void free_list(struct list_struct *list)
{
    struct list_struct *current = list, *tmp;
    while(current != NULL)
    {
	tmp = current;
	current = current->next;
	free((void *) tmp);
    }
}
