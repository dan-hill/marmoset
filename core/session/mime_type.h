#ifndef MIME_TYPE_H
#define MIME_TYPE_H

#include <stdint.h>

#define MIME_TYPE_APPLICATION_JSON 0
#define MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED 1
#define MIME_TYPE_TEXT_PLAIN 2
#define MIME_TYPE_TEXT_HTML 3

char* mime_type_text(uint8_t mime_type);

#endif