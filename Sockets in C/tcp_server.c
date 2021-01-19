
/*
        socket() --> bind --> listen() --> accept()
By avadhootk for testing purpose
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>       # for defination of sockets & API we are going to use
#include<sys/socket.h>

#include<netinet/in.h>      # for structure storing address information

int main()
{   char server_message[256];
    // create server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to specifies IP & port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // listen
    listen(server_socket,5);

    // accept data
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    //send the message
    send(client_socket,server_message,sizeof(server_message),0);

    // close socket
    close(server_socket);
return 0;
}