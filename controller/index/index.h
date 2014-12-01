#ifndef INDEX_H
#define INDEX_H

#include "request/http_request_parser.h"
#include "response/response_handler.h"
#include "error/abort.h"

void index_handler(int* client_sd, struct http_request_parser* req, struct http_response* res);

#endif