#ifndef MARMOSET_H
#define MARMOSET_H

#include <signal.h>     /* signal() */
#include <stdio.h>      /* printf(), fprintf() */
#include <sys/socket.h> /* socket(), bind(), connect() */
#include <arpa/inet.h>  /* sockaddr_in, inet_ntoa() */
#include <stdlib.h>     /* atoi(), exit() */
#include <string.h>     /* memset() */
#include <unistd.h>     /* close() */

#include "debug.h"              /* debug_message() */
#include "die_with_error.h"     /* die_with_error() */
#include "app_m.h"              /* app() */
#include "respond.h"
/** @defgroup Process Factory
* This function starts processes to handle incomming requests.
*/
/** @{ */
/**
* The maximum number of pending connections the server will allow.
*/
#define MAXPENDING 5

/** Start the application server.
*
* This function starts the application server on the specified port. It
* should be called form the main() function of the application after any
* setup for the application is complete.
*
* @param port The port number the application should list to for connections.
* @returns void
*/
void run(int port );
/** @} */

#endif