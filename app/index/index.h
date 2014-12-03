#ifndef INDEX_H
#define INDEX_H

#include "serializer.h"
#include "error/abort.h"
#include "http_response.h"
#include "http_request.h"
#include "app.h"
struct http_response* index_handler(struct http_request *req);

#endif