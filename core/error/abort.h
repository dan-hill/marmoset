#ifndef ABORT_H
#define ABORT_H

#include "response/http_response.h"
#include "response_status.h"
#include "response/serializer.h"

#include <debug/debug.h>
#include <sys/socket.h>
#include "die_with_error.h"
#include "http_method.h"
#include "request/http_request.h"
void abort_request(int* client_sd, int response_code, struct http_request_parser* req, char* res_message);

#endif