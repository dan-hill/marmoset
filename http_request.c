#include "http_request.h"

int http_request_type(char *request){

    char type_str[strcspn(request, " ")];

    int i;
    for(i = 0; i < sizeof(type_str); i++){
        type_str[i] = request[i];
    }

    if(strcmp(type_str, "GET") == 0){
        return REQ_TYPE_GET;
    }

    if(strcmp(type_str, "POST") == 0){
        return REQ_TYPE_POST;
    }
}
int http_request_path(char *request){
    int front_pos = strcspn(request, " ");


}

int substrcmp(char* str1, char* str2, int lng){
    int i;
    for(i = 0; i < lng; i++){
        if (str1 + i != str2 + i){
            return 0;
        }
    }
    return 1;
}

struct http_request parse_request(char *request){
    struct http_request req;

    req.type = http_request_type(request);

    return req;
}