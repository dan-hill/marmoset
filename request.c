#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "request.h"
#include "die_with_error.h"
#include "debug.h"

#define RCVBUFSIZE 3000

void handle_client(int client_socket) {

    char recieve_buffer[RCVBUFSIZE];        /* Buffer for recieveed message */
    char send_buffer[RCVBUFSIZE];           /* Buffer for outgoing message */
    int recieved_message_size;              /* Size of received message */
    int send_message_size;                  /* Size of outgoing message */
    char send_message_char;                 /* Character from the input stream */

    /* Clear the recieve buffer */
    memset(recieve_buffer, 0, sizeof(recieve_buffer));

    /* Receive message from client */
    if (recv(client_socket, recieve_buffer, RCVBUFSIZE, 0) < 0)
        die_with_error("recv() failed");

    /* Print the client's message to the terminal */
    int i = 0;
    while (recieve_buffer[i] != '\r') {
        printf("%c", recieve_buffer[i]);
        i++;
    }


    /* Clear the send buffer */
    memset(send_buffer, 0, sizeof(send_buffer));

    strcpy(send_buffer, "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\nI am responding!\n");

    /* Sent the send buffer to the client */
    if (send(client_socket, send_buffer, RCVBUFSIZE, 0) < 0)
        die_with_error("send() failed");

    debug_message("Closing child.");
    close(client_socket);
    exit(EXIT_SUCCESS);
}
