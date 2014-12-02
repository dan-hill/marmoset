#ifndef ROUTES_H
#define ROUTES_H

#include "marmoset.h"

#include "serializer.h"


#include "index/index.h"
#include "commander/commander.h"


struct http_response* route(struct http_request * req);

#endif