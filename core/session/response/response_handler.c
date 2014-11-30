#include "response/response_handler.h"
#include "routes.h"

void build_response(struct http_request_parser* req, struct http_response* res){
    router(&req);
}