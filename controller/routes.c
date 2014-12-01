#include "routes.h"

void router(int* client_sd, struct http_request_parser* req, struct http_response* res){
    if(strcmp(req->path, "/") == 0){
        index_handler(client_sd, req, res);
        return;
    }

    abort_request(client_sd, HTTP_BAD_REQUEST, req, "No resource at this route.");
}

