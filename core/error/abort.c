
#include "abort.h"


void abort_request(int* client_sd, int response_code, struct http_request_parser* req, char* res_message){
    debug_message("Starting to abort child.");

    struct http_response res;

    res.content = res_message;
    res.status = response_code;


    char* res_string = serializer(&res);

    if (send(*client_sd, res_string, strlen(res_string), 0) < 0)
        die_with_error("send() failed");


    printf("%i %s %s\n", http_status_int((uint8_t)response_code), http_method_text(req->type), req->path);

    debug_message("Exiting child with abort.");
    exit(0);
}