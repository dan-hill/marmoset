#ifndef ABORT_H
#define ABORT_H
#include <session/response/http_response.h>
#include "response_status.h"
#include "response/serializer.h"

void abort_request(int* client_sd, int response_code, char* res_message);

#endif