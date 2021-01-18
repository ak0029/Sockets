
/*
        socket() --> connect() --> recv()
By avadhootk for testing purpose
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>       # for defination of sockets & API we are going to use
#include<sys/socket.h>

#include<netinet/in.h>      # for structure storing address information

int main()
{   // create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Add for socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.sin_addr = INADDR_ANY;

    // connect

    int conn_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    //error checking

    if (connection_status == -1)
    {
        printf("There is an error while making connection with remote socket" \n\n);           
    }

    // Receive data from server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response),0);

    // print out server response
    printf("The server sent the data: %s\n",server_response);

    // close socket
    close(sock);
return 0;
}
