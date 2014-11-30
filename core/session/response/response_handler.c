#include "response_handler.h"

void build_response(int* client_sd, struct http_request_parser *req, struct http_response* res){
    printf("%i", *client_sd);
    router(client_sd, req, res);
}