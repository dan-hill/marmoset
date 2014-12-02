#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http_response.h"
#include "session/mime_type.h"
#include <session/response_status.h>

char* serializer(struct http_response* res);

#endif