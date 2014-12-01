#ifndef ROUTES_H
#define ROUTES_H


#include "response/response_handler.h"
#include "request/http_request_parser.h"

#include "index/index.h"
#include "commander/commander.h"


void router(int* client_sd, struct http_request_parser* req, struct http_response* res);

#endif