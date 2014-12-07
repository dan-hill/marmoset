#ifndef HTTP_STATUS_H
#define HTTP_STATUS_H

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

/** @addtogroup Macros */
/** @{ */

/**
* 200 OK. Response code for successful request.
*/
#define HTTP_OK 0

/**
* 400 Bad Request. Response code for request that was formatted
* or otherwise can not be serviced by the application.
*/
#define HTTP_BAD_REQUEST 1

/** Return string for response status macro.
*
* Returns a character pointer to the string for the http response
* status.
*
* @param status The http status macro.
* @returns Pointer to the string version of the status.
*/
char* http_status_text(uint8_t status);

/** Returns the integer for the status.
*
* This function returns the integer for the status macro.
*
* @param status HTTP status macro.
* @returns An integer of the status code.
*/
int http_status_int(uint8_t status);
/** @} */
#endif

