#ifndef __JCLIENT__
#define __JCLIENT__

/* Will be used to manage client list */


void add_client(const int client_socket);
void set_service_client(const int client_socket, const char *service_name);
void remove_client(const int client_socket);
int get_joined_time_client(const int client_socket);

#endif 
