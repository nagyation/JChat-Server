#ifndef __JCOM__
#define __JCOM__

typedef int response_t;

/* Handles communication for server using basic sockets, I'm not going to use HTTP or anyother protocols, 
   it will work by registering service name, that when a client ask for it, the callback registered will be invoked
   and also for abstracting we will identify each user's socket by id, we won't work with sockets directly outside this library
 */


int send_data(const int client_id,const void *data, const int length);
void register_service(const char *service_name, response_t (* service_callback) (int client_id, void *data));
void start_server(const char* ip, const int port);

#endif
