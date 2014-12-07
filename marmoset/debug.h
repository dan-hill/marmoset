#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <unistd.h>

/** @defgroup Utility
*
* These functions are general purpose utility functions that help with operations but do not have any
* specificity to any module.
*/
/** @{ */
/**
* Sets the debug messages on or off.
*/
#define DEBUGMSGS 0

/** Print a debug message.
*
* This function prints a message ment for debugging. These messages can be
* be enabled/disabled via the DEBUGMSGS macro for the entire application. In
* a normal release environment, having debug messages enabled can cause a
* significant slowdown as console print speeds are very inefficient.
*
* @param message Message to be output to the console.
* @returns void
*/
void debug_message(char *message);
/** @} */
#endif