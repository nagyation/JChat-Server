#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#include "jcom.h"

static int server_fd;

int send_data(const int client_id,const void *data, const int length)
{

    
}

void register_service(const char *service_name, response_t (* service_callback) (int client_id, void *data))
{
    
}

void start_server(const char* ip, const int port)
{
    int client_socket; // the three sockets used and valread for recv function
    struct sockaddr_in address; // address used in binding the socket
    int optval = 1; // used by the setsockopt to enable options
    int addrlen = sizeof(address); // length of address
    address.sin_family = AF_INET; //The IPV4 family
    address.sin_addr.s_addr = INADDR_ANY; //Bind the addr to all interfaces
    address.sin_port = htons(port ); // Port to be used for binding the socket
      
    //Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, 
	     sizeof(address))<0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    //Setting the socket to a acceptor socket
    if (listen(server_fd, 5) < 0)
    {
        perror("Couldn't listen");
        exit(EXIT_FAILURE);
    }

    //Waiting for a client access to accept
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, 
				(socklen_t*)&addrlen))<0)
    {
	perror("Coudn't accept new socket");
        exit(EXIT_FAILURE);
    }
}

void stop_server()
{
    close(server_fd);
}
