#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "die_with_error.h"
#include "debug.h"

/** @defgroup Networking
* These functions handle the socket network interaction for the server
* and application.
*/
/** @{ */
/**
* The maximum size request hte server will accept.
*/
#define MAXREQSIZE 4000

/** Accepts request and sends responses.
*
* This function accepts data from the socket and writes it to the buffer
* then passes the buffer off to the route to be directed to the appropriate
* part of the application. The function also sends the data when a response
* has been prepared.
*
* @param client_socket The file descriptor of the connected socket.
* @returns void
*/
void app(int client_socket);

/** @} */

#endif
