#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "request_handler.h"
#include "die_with_error.h"
#include "debug.h"
#include "http_request_parser.h"

#define REQBUFSIZE 3000

void handle_client(int client_socket) {

    /* TODO dynamically allocate memory for the receive buffer. */

    char raw_req_buffer[REQBUFSIZE];        /* Buffer for raw request */
    char send_buffer[REQBUFSIZE];           /* Buffer for outgoing message */

    /* Clear the recieve buffer */
    memset(raw_req_buffer, 0, sizeof(raw_req_buffer));

    /* Receive message from client */
    if (recv(client_socket, raw_req_buffer, REQBUFSIZE, 0) < 0)
        die_with_error("recv() failed");

    /* Parse the request so it can be handled by the responder */
    struct http_request_parser req;
    parse_request(&req, raw_req_buffer);




    /* Clear the send buffer */
    memset(send_buffer, 0, sizeof(send_buffer));

    strcpy(send_buffer, "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\nI am responding!\n");

    /* Sent the send buffer to the client */
    if (send(client_socket, send_buffer, REQBUFSIZE, 0) < 0)
        die_with_error("send() failed");

    debug_message("Closing child.");

    close(client_socket);
    exit(EXIT_SUCCESS);
}
