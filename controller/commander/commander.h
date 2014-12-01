#ifndef COMMANDER_H
#define COMMANDER_H

#include "request/http_request_parser.h"
#include "response/response_handler.h"
#include "error/abort.h"

void commander_handler(int* client_sd, struct http_request_parser* req, struct http_response* res);

#endif