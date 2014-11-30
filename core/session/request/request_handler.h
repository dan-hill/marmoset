#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

#include "response/response_handler.h"
#include "error/die_with_error.h"
#include "debug/debug.h"

#define REQBUFSIZE 3000

void handle_client(int client_socket);

#endif
