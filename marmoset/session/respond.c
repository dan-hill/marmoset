
#include "respond.h"


struct http_response* respond(uint8_t status, struct http_response* res){
    res->status = status;
    res->content_length = strlen(res->content);

    return res;
}