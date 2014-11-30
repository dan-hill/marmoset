#include "request_handler.h"

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

    struct http_response res;
    build_response(&req, &res);


    /* Clear the send buffer */
    memset(send_buffer, 0, sizeof(send_buffer));

    strcpy(send_buffer, res.content);

    printf("%s", send_buffer);
    /* Sent the send buffer to the client */
    if (send(client_socket, send_buffer, REQBUFSIZE, 0) < 0)
        die_with_error("send() failed");

    debug_message("Closing child.");

    close(client_socket);
    exit(EXIT_SUCCESS);
}
