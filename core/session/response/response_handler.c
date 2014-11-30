#include "response_handler.h"

void build_response(struct http_request_parser *req, struct http_response* res){
    router(req, res);
    printf("%s", req->path);
    printf("%s", res->content);
}