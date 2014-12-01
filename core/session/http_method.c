#include "http_method.h"

char *http_method_text(uint8_t status) {
    switch(status){
        case HTTP_GET:
            return "GET";
        case HTTP_POST:
            return "POST";
    }
    return;
}