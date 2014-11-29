#include <stdio.h>
#include <stdlib.h>
#include "http_request.h"


int store_header_field(struct http_request* req, char* key, char* value){
    if(strcmp(key, "User-Agent") == 0){
        req->user_agent = value;
        return 1;
    }

    if(strcmp(key, "Host") == 0){
        req->host = value;
        return 1;
    }

    if(strcmp(key, "Accept") == 0){
        req->accept = value;
        return 1;
    }

    if(strcmp(key, "Content-Length") == 0){
        req->content_length = (size_t)atoi(value);
        return 1;
    }

    if(strcmp(key, "Path") == 0){
        req->path = value;
        return 1;
    }

    if(strcmp(key, "Type") == 0){

        if(strcmp(value, "GET") == 0){
            printf("%s", value);
            req->type = REQ_TYPE_GET;
            return 1;
        }

        if(strcmp(value, "POST") == 0){
            req->type = REQ_TYPE_POST;
            return 1;
        }

        if(strcmp(value, "PUT") == 0){
            req->type = REQ_TYPE_PUT;
            return 1;
        }

        if(strcmp(value, "DELETE") == 0){
            req->type = REQ_TYPE_DELETE;
            return 1;
        }
        /* TODO Add the rest of the less common request types */

        return 0;
    }

    if(strcmp(key, "Body") == 0){
        req->body = value;
        return 1;
    }

    return 0;
}

void parse_request(struct http_request* req, char *request){

    char* runner = request;
    char* token;
    char* key;
    char* value;

    while(runner != NULL){
        token = strsep(&runner, "\r");
        if(token == request){


            char* tmp = token;
            token = strchr(token, ' ') + 1;
            *(token - 1) = '\0';
            store_header_field(req, "Type", tmp);

            tmp = token;
            token = strchr(token, ' ') + 1;
            *(token - 1) = '\0';
            store_header_field(req, "Path", tmp);

            store_header_field(req, "HTTP-Version", token);
            continue;
        }

        if(*(token) == '\n'){
            token = token + 1;
        }

        if(strlen(token) == 0){
            token = strsep(&runner, "\r");
            store_header_field(req, "Body", token);
            break;
        }

        key = token;
        value = strchr(token, ':') + 2;
        *(value - 2) = '\0';
        store_header_field(req, key, value);
    }
}

