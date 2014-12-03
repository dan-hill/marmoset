
#include "serializer.h"

void cats(char **str, const char *str2) {
    char *tmp = NULL;

    // Reset *str
    if ( *str != NULL && str2 == NULL ) {
        free(*str);
        *str = NULL;
        return;
    }

    // Initial copy
    if (*str == NULL) {
        *str = calloc( strlen(str2)+1, sizeof(char) );
        memcpy( *str, str2, strlen(str2) );
    }
    else { // Append
        tmp = calloc( strlen(*str)+1, sizeof(char) );
        memcpy( tmp, *str, strlen(*str) );
        *str = calloc( strlen(*str)+strlen(str2)+1, sizeof(char) );
        memcpy( *str, tmp, strlen(tmp) );
        memcpy( *str + strlen(*str), str2, strlen(str2) );
        free(tmp);
    }

} // cats

char*serialize_response(struct http_response *res){
    char* response_string = "";

    cats(&response_string, "HTTP/1.1 ");
    if(&res->status != NULL) {
        cats(&response_string, http_status_text(res->status));
    }
    cats(&response_string, "\r\n");

    if(&res->content_type != NULL) {
        cats(&response_string, "Content-Type: ");
        cats(&response_string, mime_type_text(res->content_type));
        cats(&response_string, "\r\n");
    }
    cats(&response_string, "\r\n");
    cats(&response_string, res->content);
    cats(&response_string, "\0");
    return response_string;
}

struct http_response* deserialize_response(char* res_str){

}


struct http_request* deserialize_request(char* req_str){

    struct http_request *req = (struct http_request*)malloc(sizeof(struct http_request));

    char* runner = req_str;
    char* token;
    char* key;
    char* value;

    while(runner != NULL){
        token = strsep(&runner, "\r");

        /* parse first line */
        if(token == req_str){
            char* tmp = token;
            token = strchr(token, ' ') + 1;
            *(token - 1) = '\0';
            req->type = http_method_macro(tmp);

            tmp = token;
            token = strchr(token, ' ') + 1;
            *(token - 1) = '\0';
            req->path = tmp;

            /* TODO fix this so it actually hooks up to a correct protocol/version */
            req->HTTP_version = (uint8_t)1;
            continue;
        }

        /* parse out the body */
        if(*(token) == '\n'){
            token = token + 1;
        }

        if(strlen(token) == 0){
            token = strsep(&runner, "\r");
            req->body = token;

            break;
        }

        /* parse out fields */
        key = token;
        value = strchr(token, ':') + 2;
        *(value - 2) = '\0';

        if(strcmp(key, "User-Agent") == 0){
            req->user_agent = value;
            continue;
        }

        if(strcmp(key, "Host") == 0){
            req->host = value;
            continue;
        }


        if(strcmp(key, "Content-Length") == 0){
            req->content_length = (size_t)atoi(value);
            continue;
        }

        /* TODO add the other fields that are going to be supported */
    }

    /* TODO add checks to be sure deserialization was successful */

    return req;
}
