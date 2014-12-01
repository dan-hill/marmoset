#ifndef HTTP_STATUS_H
#define HTTP_STATUS_H

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define HTTP_OK 0
#define HTTP_BAD_REQUEST 1

char* http_status_text(uint8_t status);
int http_status_int(uint8_t status);

#endif

