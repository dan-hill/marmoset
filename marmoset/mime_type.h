#ifndef MIME_TYPE_H
#define MIME_TYPE_H

#include <stdint.h>

/** @addtogroup Macros */
/** @{ */

/**
* Data is in JavaScript Object Notation.
*/
#define MIME_TYPE_APPLICATION_JSON 0

/**
* Data is formatted as form urlencoded data.
*/
#define MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED 1

/**
* Data is in plaintext with no special formatting.
*/
#define MIME_TYPE_TEXT_PLAIN 2

/**
* Data contains an HTML formatted document.
*/
#define MIME_TYPE_TEXT_HTML 3

/** Return string value for macro.
*
* Returns the name of the mime type for hte supplied macro.
*
* @param mime_type The mime type macro.
* @returns Pointer to string representation of mime type.
*/
char* mime_type_text(uint8_t mime_type);
/** @} */
#endif