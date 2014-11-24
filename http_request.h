#include <string.h>

#define REQ_TYPE_GET 0
#define REQ_TYPE_POST 1

struct http_request{
    int type;
    int path;
    int HTTP_version;
    int host;
};

int http_request_type(char *request);
struct http_request parse_request(char *request);

