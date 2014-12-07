#ifndef DIE_WITH_ERROR_H
#define DIE_WITH_ERROR_H

#include <stdlib.h>
#include <stdio.h>
/** @addtogroup Utilities */
/** @{ */

/** Prints error and exits process.
*
* This function is used when doing socket operations and is used to handle
* errors and exit the process gracefully.
*
* @param error_message Pointer to a message to be logged before exiting.
*/
void die_with_error(char *error_message);
/** @} */
#endif