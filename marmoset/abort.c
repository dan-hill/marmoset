
#include "abort.h"


struct http_response* abort_request(int response_code, char* message){
    debug_message("Starting to abort child.");

    struct http_response *res = (struct http_response *) malloc(sizeof(struct http_response));

    res->content = message;
    res->status = (uint8_t)response_code;

    return res;
}