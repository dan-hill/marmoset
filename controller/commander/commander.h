#ifndef COMMANDER_H
#define COMMANDER_H

#include "http_serialize.h"
#include "response_handler.h"
#include "error/abort.h"

void commander_handler(int* client_sd, struct http_request_parser* req, struct http_response* res);

#endif