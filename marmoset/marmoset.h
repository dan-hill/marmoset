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

#define MAXPENDING 5

void run(int port );


#endif