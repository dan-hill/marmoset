#include "routes.h"
#include "index/index.h"
void router(struct http_request_parser* req, struct http_response* res){

    if(strcmp(req->path, "/") == 0){
        index_handler(req, res);
    }
}

