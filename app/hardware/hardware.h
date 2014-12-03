#ifndef HARDWARE_H
#define HARDWARE_H

#include "serializer.h"
#include "error/abort.h"
#include "http_response.h"
#include "http_request.h"
#include "app.h"

struct http_response* hardware_handler(struct http_request * req);

#endif