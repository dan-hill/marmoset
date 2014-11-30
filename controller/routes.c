#include "routes.h"
#include "index/index.h"
void router(int* client_sd, struct http_request_parser* req, struct http_response* res){
    printf("%i", *client_sd);
    if(strcmp(req->path, "/") == 0){
        index_handler(client_sd, req, res);
    }
}

