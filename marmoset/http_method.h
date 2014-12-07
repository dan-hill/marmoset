#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/** @defgroup Macros
*
* These are macros that are used in place of strings for efficieny in many
* HTTP operations.
*/
/** @{ */
/**
* HTTP Get request macro. Get request should be used when no data on the
* server will be changed or saved and the client only wishes to retrieve
* information.
*/;
#define HTTP_GET 0

/**
* HTTP Post request macro. Post request should be used when the client
* indeds to store data on the server.
*/
#define HTTP_POST 1

/** @todo Document the remaining HTTP method macros. */

#define HTTP_OPTIONS 2
#define HTTP_HEAD 3
#define HTTP_PUT 4
#define HTTP_DELETE 5
#define HTTP_TRACE 6
#define HTTP_CONNECT 7

/** Get string for HTTP method macro
*
* Returns a string representation of the HTTP macro passed to it. This
* should only be used when serializing the data to respond to the client.
* It is much more efficient to pass the method around using it's macro than
* it's string.
*
* @param method The HTTP method macro.
* @returns char* The string representation (GET, POST, ect) of the method.
*/
char *http_method_text(uint8_t* method);


uint8_t *http_method_macro(char *method_str);
#endif

/* @} */