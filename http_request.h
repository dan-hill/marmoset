#include <string.h>
#include <stdint.h>

#define REQ_TYPE_GET 0
#define REQ_TYPE_POST 1

#define REQ_HTTP_VERSION_1_1 0

struct substr{
    char* location;
    size_t length;
};

struct http_request{
    uint8_t type;
    struct substr path;
    int HTTP_version;
    int host;
    size_t content_length;
    struct substr body;
};

uint8_t http_request_type(char *request);
struct http_request parse_request(char *request);

