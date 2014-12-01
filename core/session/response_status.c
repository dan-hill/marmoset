#include "session/response_status.h"

char *http_status_text(uint8_t status) {
    switch(status){
        case HTTP_OK:
            return "200 OK";
        case HTTP_BAD_REQUEST:
            return "400 Bad Request";
    }
    return;
}

int http_status_int(uint8_t status) {
    switch(status){
        case HTTP_OK:
            return 200;
        case HTTP_BAD_REQUEST:
            return 400;
    }
    return;
}