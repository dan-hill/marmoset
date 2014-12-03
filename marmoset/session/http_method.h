#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <stdint.h>
#include <string.h>

/* Request types */
#define HTTP_GET 0
#define HTTP_POST 1
#define HTTP_OPTIONS 2
#define HTTP_HEAD 3
#define HTTP_PUT 4
#define HTTP_DELETE 5
#define HTTP_TRACE 6
#define HTTP_CONNECT 7

char *http_method_text(uint8_t* status);
uint8_t *http_method_macro(char *method_str);
#endif