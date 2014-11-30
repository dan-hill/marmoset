#include <session/response/http_response.h>
#include "abort.h"
void abort(int response_code, char* res_message){
    struct http_response res;
    res.content = res_message;
    res.status = response_code;
}