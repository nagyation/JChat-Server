#ifndef __NLIST__
#define __NLIST__

struct list_struct {
    void * data;
    struct list_struct * next, *prev;
};

void create_new_list(struct list_struct *list);
void add_data_list(struct list_struct *list, void *data);
int remove_data_list(struct list_struct *list, int (*remove_check) (void *data));
void * search_data_list(struct list_struct *list, int (*search_check) (void *data));
int get_count_list(struct list_struct *list);
void free_list(struct list_struct *list);

#endif
