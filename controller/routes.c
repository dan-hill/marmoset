#include <session/request/http_request_parser.h>

void router(struct http_request_parser* req){
    if(req->path == "/"){
        printf("ROOOOOOOOOT");
    }
}