#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "nlib/nlist.h"

#include "jclient.h"

struct client {
    int client_socket;
    time_t joined_time; // for timeout purpose
    char *service_name;
};

struct list_struct *client_list = NULL;

void add_client(const int client_socket)
{
    if(client_list == NULL)
    {
	create_new_list(client_list);
    }

    struct client * data = malloc(sizeof(struct client));
    data-> client_socket = client_socket;
    data->joined_time = time(NULL);
    add_data_list(client_list, data);    
}

void set_service_client(const int client_socket, const char *service_name)
{
    struct client *data;

    data = (struct client*) search_data_list(client_list, ({
		int search_check(void *data) {
		    if(((struct client*) data)->client_socket == client_socket)
			return 1;
		}
		search_check; })
	);

    
    data->service_name = malloc( sizeof(char) *strlen(service_name) +1);
    strcpy(data->service_name, service_name);	
}

void remove_client(const int client_socket)
{
    remove_data_list(client_list, ({
		int remove_check(void *data) {
		    if(((struct client*) data)->client_socket == client_socket)
			return 1;
		}
		remove_check; })
	);
}

int get_joined_time_client(const int client_socket)
{
    struct client *data;
    
    data =(struct client*) search_data_list(client_list, ({
 		int search_check(void *data) {
		    if(((struct client*) data)->client_socket == client_socket)
			return 1;
		}
		search_check; })
	);

    return difftime(time(NULL), data->joined_time);
}
