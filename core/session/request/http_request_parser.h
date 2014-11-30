#ifndef HTTP_REQUEST_PARSER_H
#define HTTP_REQUEST_PARSER_H

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "http_request.h"
#include "http_method.h"
#include "http_protocol.h"
#include "mime_type.h"

void parse_request(struct http_request_parser * req, char *request);

#endif