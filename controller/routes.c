#include "routes.h"

void router(struct http_request_parser* req, struct http_response* res){
    if(req->path == "/"){
        printf("ROOOOOOOOOT");
    }
}