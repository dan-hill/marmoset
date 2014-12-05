#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "die_with_error.h"
#include "debug.h"

#define REQBUFSIZE 30000

void app(int client_socket);

#endif
