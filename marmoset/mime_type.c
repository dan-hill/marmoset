#include "mime_type.h"

char* mime_type_text(uint8_t mime_type){
    switch(mime_type){
        case MIME_TYPE_APPLICATION_JSON:
            return "application/json";
        case MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED:
            return "x-www-form-urlencoded";
        case MIME_TYPE_TEXT_PLAIN:
            return "text/plain";
        case MIME_TYPE_TEXT_HTML:
            return "text/html";
    }
}