#include "die_with_error.h"

void die_with_error(char *error_message) {
    perror(error_message);
    exit(1);
}
