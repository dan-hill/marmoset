#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http_response.h"
#include "http_request.h"
#include "session/mime_type.h"
#include <session/response_status.h>
#include "http_method.h"

char* serialize_response(struct http_response *res);
struct http_response* deserialize_response(char* res_str);
char* serialize_request(struct http_request *req);
struct http_request* deserialize_request(char* req);
void cats(char **str, const char *str2);
#endif