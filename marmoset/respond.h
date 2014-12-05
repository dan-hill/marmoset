#ifndef RESPOND_H
#define RESPOND_H

#include <string.h>
#include "http_response.h"

struct http_response* respond(uint8_t status, struct http_response* res);

#endif
