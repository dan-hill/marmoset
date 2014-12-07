#include "http_method.h"

char *http_method_text(uint8_t *method) {

    /** @todo Add the remaining method to string conversion cases. */

    switch(*method){
        case HTTP_GET:
            return "GET";
        case HTTP_POST:
            return "POST";
        default:
            return NULL;
    }
}

uint8_t *http_method_macro(char *method_str){
    /** @todo Add macros for all HTTP methods. */

    uint8_t *mptr = (uint8_t *) malloc(sizeof(uint8_t));

    if(strcmp(method_str, "GET") == 0){
        *mptr = (uint8_t ) HTTP_GET;
        return mptr;
    }

    if(strcmp(method_str, "POST") == 0){
        *mptr = (uint8_t) HTTP_POST;
        return mptr;
    }

    if(strcmp(method_str, "DELETE") == 0){
        *mptr = (uint8_t ) HTTP_DELETE;
        return mptr;
    }

    return NULL;
}