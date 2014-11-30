#ifndef RESPONSE_HANDLER_H
#define RESPONSE_HANDLER_H

#include <stdint.h>
#include "request/http_request_parser.h"
#include <stdio.h>
#include "http_response.h"
#include "routes.h"

void build_response(int* client_sd, struct http_request_parser *req, struct http_response* res);

#endif