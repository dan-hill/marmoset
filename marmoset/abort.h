#ifndef ABORT_H
#define ABORT_H

#include <sys/socket.h>

#include "http_response.h"
#include "response_status.h"
#include "serializer.h"
#include "debug.h"
#include "die_with_error.h"
#include "http_method.h"
#include "http_request.h"

/** @defgroup Responders
* Responders are functions that handle completion of responses. When an
* application calls one of these functions and passes it a pointer to a
* partially complete response struct, the function fills out the reamining
* fields with data provided by the server, then sends the response on to
* the network handler to be sent to the client.
*/
/** @{ */

/** Construct and return response for invalid requests.
*
* The abort_request() function is called when a request is found invalid
* or the server otherwise has encountered a problem processing the request.
* The function will include the string passed into it's message parameter
* in the body of the response message to give the client more details on the
* specific problem there was with the request and what might be done to avoid
* it in future requests.
*
* @param response_code The response code for the particular error.
* @param message Short description of the error.
* @returns struct http_response* Pointer to the response to be sent to the client.
*
* @see respond()
*/
struct http_response* abort_request(int response_code, char* message);
/** @} */
#endif