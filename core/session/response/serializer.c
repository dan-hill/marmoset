#include <session/mime_type.h>
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

char* serializer(struct http_response* res){
    char* response_string = "";
    cats(&response_string, "HTTP1/1 ");
    cats(&response_string, "200 OK \r\n");

    if(&res->content_type != NULL) {
        cats(&response_string, "Content-Type: ");
        cats(&response_string, mime_type_text(res->content_type));
        cats(&response_string, "\r\n");
    }

    cats(&response_string, "\r\n");
    cats(&response_string, res->content);
    return response_string;
}


