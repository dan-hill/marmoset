#include <signal.h>
#include <stdio.h>      /* printf(), fprintf() */
#include <sys/socket.h> /* socket(), bind(), connect() */
#include <arpa/inet.h>  /* sockaddr_in, inet_ntoa() */
#include <stdlib.h>     /* atoi(), exit() */
#include <string.h>     /* memset() */
#include <unistd.h>     /* close() */

#include "debug/debug.h"
#include "error/die_with_error.h"
#include "app_m.h"

#define MAXPENDING 5
#define REQBUFSIZE 30000
#define DEBUGMSGS 0


void run(int port){
    printf("Starting marmoset...\n");

    signal(SIGCHLD, SIG_IGN);

    int server_sd;                          /* Socket descriptor for server */
    int client_sd;                          /* Socket descriptor for client */
    struct sockaddr_in server_address;      /* Server address structure*/
    struct sockaddr_in client_address;      /* Client address structure*/
    unsigned short server_port;             /* Server port */
    unsigned int client_address_length;     /* Length of client address data structure */


    server_port = (unsigned short) port;       /* The server port to be opened */

    /* Create socket for incoming connections */
    debug_message("Creating socket for incomming connections...");
    if ((server_sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die_with_error("socket() failed");

    /* Construct local address structure */
    debug_message("Constructing local address structure...");
    memset(&server_address, 0, sizeof(server_address));     /* Clear the server_address structure */
    server_address.sin_family = AF_INET;              /* Internet protocol family */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);    /* Any incoming interface */
    server_address.sin_port = htons(server_port);   /* Local port */

    /* Bind to the local address */
    debug_message("Binding socket to the local address...");
    if (bind(server_sd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        die_with_error("bind() failed");

    /* Mark the socket so it will listen for incoming connections */
    char *msg_pa = malloc((size_t) (snprintf(NULL, 0, "%s %hu", "Listening to port ", server_port) + 1));
    sprintf(msg_pa, "%s %hu", "Listening to port ", server_port);
    debug_message(msg_pa);

    if (listen(server_sd, MAXPENDING) < 0)
        die_with_error("listen() failed");

    debug_message("End server setup.\n");

    debug_message("Start main application loop.");
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1) /* Run forever */
    {
        /* Set the size of the in and out parameter */
        client_address_length = sizeof(client_address);

        /* Wait for a client to connect */
        debug_message("Listening for new client connections...");
        if ((client_sd = accept(server_sd, (struct sockaddr *) &client_address, &client_address_length)) < 0)
            die_with_error("accept() failed");

        /* deal with the client connection request */
        int pid = fork();
        if (pid == 0) {
            debug_message("Handling request in child process.");
            app(client_sd);
        }

        debug_message("Closing client socket in main thread.");
        close(client_sd);

    }
    #pragma clang diagnostic pop
}


