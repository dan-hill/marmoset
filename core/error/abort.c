#include <debug/debug.h>
#include <sys/socket.h>
#include "abort.h"
#include "die_with_error.h"

void abort_request(int* client_sd, int response_code, char* res_message){
    debug_message("Starting to abort child.");
    struct http_response res;
    res.content = res_message;
    res.status = response_code;

    char* res_string = serializer(&res);

    printf("%s", res_string);
    debug_message("Exiting child with abort.");
    char send_buffer[3000];
    sprintf(send_buffer, "%s", res_string);
    debug_message(send_buffer);
    if (send(*client_sd, send_buffer, 500, 0) < 0)
        die_with_error("send() failed");
    exit(0);
}