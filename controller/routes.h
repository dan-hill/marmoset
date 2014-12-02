#ifndef ROUTES_H
#define ROUTES_H


#include "response_handler.h"
#include "http_serialize.h"

#include "index/index.h"
#include "commander/commander.h"


void router(int* client_sd, struct http_request_parser* req, struct http_response* res);

#endif