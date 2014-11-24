#include "http_request.h"

int http_request_type(char *request){

    int type_size = 0;

    while (&request[type_size] != strchr(request, ' ')) {
        type_size++;
    }

    char type_str[type_size];

    int i;
    for(i = 0; i < type_size; i++){
        type_str[i] = request[i];
    }

    if(strcmp(type_str, "GET") == 0) {
        return REQ_TYPE_GET;
    }

}

struct http_request parse_request(char *request){
    struct http_request req;

    req.type = http_request_type(request);
}