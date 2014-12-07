#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "http_response.h"
#include "http_request.h"
#include "mime_type.h"
#include "response_status.h"
#include "http_method.h"

/** @defgroup Serialization
*
* Serialization functions handle the parsing, serialization, and deserialization
* of raw request and response structs.
*/
/** @{ */

/** Serialize a response struct into a string for transmission.
*
* Serializes a response struct into a single string for transmission over
* a TCP socket to the requesting client.
*
* @param res Pointer to the response struct.
* @returns Pointer to the serialized response struct.
*/
char* serialize_response(struct http_response *res);

/** Deserializes a raw request.
*
* This function takes a raw request string that has been received from a TCP
* socked and parses it into an http_request struct for processing by the
* application.
*
* This function does change it's parameter so be aware that the request will
* no longer be accessable after this operation.
*
* @param req The raw request string.
* @returns http_request Pointer to the request struct.
*/
struct http_request* deserialize_request(char* req);

/** Concat strings.
*
* This is a helper function that makes it easier to deal with struct serialization
* of dynamically sized data. This function modifies it's first argument.
*
* @param str Address of the base string.
* @param str2 Pointer to the string to concat to the base string.
* @returns void
*/
void cats(char **str, const char *str2);

/** @} */
#endif