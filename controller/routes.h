#ifndef ROUTES_H
#define ROUTES_H

#include "response/response_handler.h"
#include "request/http_request_parser.h"
#include <stdio.h>

void router(struct http_request_parser* req, struct http_response* res);

#endif