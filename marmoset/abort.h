#ifndef ABORT_H
#define ABORT_H

#include "http_response.h"
#include "response_status.h"
#include "serializer.h"

#include "debug.h"
#include <sys/socket.h>
#include "die_with_error.h"
#include "http_method.h"
#include "http_request.h"
struct http_response* abort_request(int response_code, char* message);

#endif