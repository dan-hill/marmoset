#include <stdio.h>
#include "http_request.h"

int substrcmp(char* str1, char* str2, int lng){
    int i;
    for(i = 0; i < lng; i++){
        if (*(str1 + i) != *(str2 + i)){
            return 0;
        }
    }
    return 1;
}

uint8_t http_request_type(char *request){

    if(substrcmp(request, "GET", (int)strcspn(request, " ")) == 1){
        return REQ_TYPE_GET;
    }

    if(substrcmp(request, "POST", (int)strcspn(request, " ")) == 1){
        return REQ_TYPE_POST;
    }
}

struct substr http_request_path(char *request){
    char* front = request + strcspn(request, " ") + 1;

    size_t i = 0;
    while (*(front + i) != ' '){
        i++;
    }

    struct substr path;
    path.location = front;
    path.length = i;

    return path;
}
struct substr http_request_body(char* request){
    size_t i = 0;
    size_t line_size = 0;
    while (*(request + i) != '\0'){
        while(*(request + i) != '\r' && *(request + i) != '\n'){
            i++;
            line_size++;
        }

        if(line_size == 0){
            struct substr body;
            body.location = request + i;
            body.length = sizeof(request) - i;
            return body;
        }

        i++;
        line_size = 0;
    }
}

size_t http_request_content_length(char* request){
    size_t i = 0;
    size_t lgn = 0;
    while(*(request+i) != '\0'){
        while(*(request + i) != '\r' && *(request + i) != '\n'){
            i++;
        }
        printf("new line");
        if(substrcmp(request + i + 3, "Content-Length:", 15) == 0){
            while(*(request + i + 18) != '\r'){
                i++;
                lgn++;
            }
        }

        i++;

    }

    char s[lgn];
    size_t k;
    for(k = 0; k < lgn; k++){
        s[k] = *(request+i-5-lgn);
        i++;
    }
}

uint8_t http_version(char* request){
    char* front = request + strcspn(request + strcspn(request, " "), " ");

    if(substrcmp(front, "HTTP/1.1", 8) == 1){
        return REQ_HTTP_VERSION_1_1;
    }
}

struct http_request parse_request(char *request){
    struct http_request req;

    req.type = http_request_type(request);
    req.path = http_request_path(request);
    req.HTTP_version = http_version(request);
    req.content_length = http_request_content_length(request);
    req.body = http_request_body(request);

    return req;
}