
#include "debug.h"

void debug_message(char *message)
{
    /** @todo Change the debug_message() message argument to handle string formatting. */
    if (DEBUGMSGS == 1) {
        printf("DEBUG %d: %s\n", getpid(), message);
    }

}
