#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stdint.h>

struct http_response {
    char* access_control_allow_origin;
    uint8_t accept_ranges;
    int age;
    // uint8_t allow[];
    char* cache_control;
    // uint8_t connection[];
    uint8_t content_encoding;
    uint8_t content_language;
    int content_length;
    char* content_location;
    char* content_md5;
    char* content_disposition;
    char* content_range;
    uint8_t content_type;
    char* date;
    char* etag;
    char* expires;
    char* last_modified;
    char* link;
    char* location;
    char* p3p;
    char* http_pragma;
    uint8_t proxy_authenticate;
    char* refresh;
    char* retry_after;
    char* server;
    char* set_cookie;
    uint8_t status;
    char* strict_transport_security;
    char* trailer;
    uint8_t transfer_encoding;
    uint8_t upgrade;
    char* vary;
    char* via;
    char* warning;
    uint8_t www_authenticate;
    // uint8_t x_frame_options[];

    char* content;
};

#endif