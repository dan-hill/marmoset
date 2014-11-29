#include <string.h>
#include <stdint.h>
#include "string_utilities.h"

/* Request types */
#define REQ_TYPE_GET 0
#define REQ_TYPE_POST 1
#define REQ_TYPE_OPTIONS 2
#define REQ_TYPE_HEAD 3
#define REQ_TYPE_PUT 4
#define REQ_TYPE_DELETE 5
#define REQ_TYPE_TRACE 6
#define REQ_TYPE_CONNECT 7

/* HTTP versions */
#define REQ_HTTP_VERSION_1_1 0

/* MIME Types */
#define MIME_TYPE_APPLICATION_JSON 0
#define MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED 1

struct http_request{
    uint8_t type;
    char* path;
    int HTTP_version;
    char* host;
    size_t content_length;
    char* body;
    char* user_agent;
    char* accept;

};

void parse_request(struct http_request* req, char *request);

