#ifndef INDEX_H
#define INDEX_H

#include "serializer.h"
#include "abort.h"
#include "http_response.h"
#include "http_request.h"
#include "app.h"
/** @addtogroup Application */
/** @{ */
/** Marmoset example application handler
*
* This function is used as an example of the Marmoset server and application
* routing. It returns an html file when a GET request is made to the domain's
* root.
*
* Application's endpoints should always accept the request from the route and
* return a response pointer. If either one of these are missing from the endpoint
* function, the application will most likely crash.
*
* When the request enters the handler it must be filtered by method. You may want
* to refer to the [HTTP Spec](http://www.w3.org/Protocols/rfc2616/rfc2616.html) to learn
* more about what method to accept and what responses are appropriate. Once the request
* has been filtered it can be processed and a response built. When the response content
* has been built the response should be returned using the respond() function so all
* missing and required fields can be populated before transmission.
*
* If a request is not caught by a method filter, it will be returned using the abort()
* function and an error returned to the client that the request method is not supported
* for the requested route.
*
* @param req The client's request.
* @returns http_response* Pointer to the response struct.
*/
struct http_response* index_handler(struct http_request *req);
/** @} */
#endif