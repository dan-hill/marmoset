#include "app.h"

struct http_response* route(struct http_request * req){
    if(strcmp(req->path, "/") == 0){
        return index_handler(req);
    }

    /*
    if(strcmp(req->path, "/commander") == 0){
        return commander_handler(req);
    }
    */

    return abort_request(HTTP_BAD_REQUEST, "No resource at this route.");
}

int main(){
    run(5555);
}