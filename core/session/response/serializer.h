#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "response/http_response.h"

char* serializer(struct http_response* res);

#endif