#include <stdio.h>
#include "debug.h"
#include <unistd.h>

#define DEBUGMSGS 1

void debug_message(char *message)
{
    if (DEBUGMSGS == 1) {
        printf("DEBUG %d: %s\n", getpid(), message);
    }

}
