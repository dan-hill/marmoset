#include <app.h>


void app(int client_socket)
{
    /** @todo Read the header before the rest of the request to decide what is an acceptable size for the rec buffer */
    /** @todo Decide how to handle the size of incomming request buffers */

    char raw_req_buffer[MAXREQSIZE];        /* Buffer for raw request */
    char send_buffer[MAXREQSIZE];           /* Buffer for outgoing message */

    /* Clear the recieve buffer */
    memset(raw_req_buffer, 0, sizeof(raw_req_buffer));

    /* Receive message from client */
    if (recv(client_socket, raw_req_buffer, MAXREQSIZE, 0) < 0)
        die_with_error("recv() failed");

    /* Parse the request so it can be handled by the responder */
    struct http_request *req = deserialize_request(raw_req_buffer);

    struct http_response *res = route(req);

    /* Clear the send buffer */
    memset(send_buffer, 0, sizeof(send_buffer));

    strcpy(send_buffer, serialize_response(res));

    /* Sent the send buffer to the client */
    if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0)
        die_with_error("send() failed");

    printf("%i %s %s\n", http_status_int(res->status), http_method_text(req->type), req->path);

    debug_message("Closing child.");

    close(client_socket);
    exit(EXIT_SUCCESS);
}
