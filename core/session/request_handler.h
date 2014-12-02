#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "response_handler.h"
#include "error/die_with_error.h"
#include "debug/debug.h"

#define REQBUFSIZE 30000

void handle_client(int client_socket);

#endif
