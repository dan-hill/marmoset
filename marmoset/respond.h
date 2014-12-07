#ifndef RESPOND_H
#define RESPOND_H

#include <string.h>
#include "http_response.h"
/** @addtogroup Responders */
/** @{ */
/** Send successful response to client.
*
* This function constructs a response for a request that has been processes
* successfully by the application.
*
* @param status The status code of the response.
* @param res Pointer to the response struct.
* @returns http_response* Pointer to the response object that is ready to be transmitted to the client.
*/
struct http_response* respond(uint8_t status, struct http_response* res);
/** @} */
#endif
;