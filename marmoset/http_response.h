#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <stdint.h>

/**
* The http_response struct contains pointers to the data that will be
* sent in response to a client's request. Not all fields that are present
* in the HTTP/1.1 specification are currently supported by Marmoset, but
* are included in the struct defintion. If you require an unsupported field
* for your application you will have to implement it's handling yourself.
*/
struct http_response {

    /**
    * The type of data contained in the response. There are macros in the
    * mime_type.h file as well as functions to convert the macro into string
    * form if required. Not all mime types are currently supported by
    * Marmoset.
    */
    uint8_t content_type;                       /* Supported */

    /**
    * The status of the response. Not all statuses are currently supported
    * by Marmoset.
    */
    uint8_t status;                             /* Supported */

    /**
    * The content of the response. Most fo the fields in the response struct
    * are ment to describe the data pointed to in this field.
    */
    char* content;                              /* Supported */

    /**
    * The length of the respons's content. This field is required by some
    * clients.
    *
    * @todo Change the response content_length to a size_t datatype.
    */
    int content_length;                         /* Supported */

    // char* access_control_allow_origin;       /* Unsupported */
    // uint8_t accept_ranges;                   /* Unsupported */
    // int age;                                 /* Unsupported */
    // uint8_t allow[];                         /* Unsupported */
    // char* cache_control;                     /* Unsupported */
    // uint8_t connection[];                    /* Unsupported */
    // uint8_t content_encoding;                /* Unsupported */
    // uint8_t content_language;                /* Unsupported */
    // char* content_location;                  /* Unsupported */
    // char* content_md5;                       /* Unsupported */
    // char* content_disposition;               /* Unsupported */
    // char* content_range;                     /* Unsupported */
    // char* date;                              /* Unsupported */
    // char* etag;                              /* Unsupported */
    // char* expires;                           /* Unsupported */
    // char* last_modified;                     /* Unsupported */
    // char* link;                              /* Unsupported */
    // char* location;                          /* Unsupported */
    // char* p3p;                               /* Unsupported */
    // char* http_pragma;                       /* Unsupported */
    // uint8_t proxy_authenticate;              /* Unsupported */
    // char* refresh;                           /* Unsupported */
    // char* retry_after;                       /* Unsupported */
    // char* server;                            /* Unsupported */
    // char* set_cookie;                        /* Unsupported */
    // char* strict_transport_security;         /* Unsupported */
    // char* trailer;                           /* Unsupported */
    // uint8_t transfer_encoding;               /* Unsupported */
    // uint8_t upgrade;                         /* Unsupported */
    // char* vary;                              /* Unsupported */
    // char* via;                               /* Unsupported */
    // char* warning;                           /* Unsupported */
    // uint8_t www_authenticate;                /* Unsupported */
};

#endif