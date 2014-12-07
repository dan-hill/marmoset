#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

/** HTTP Request Structure
*
* This struct represents all the fields present in an HTTP request. The
* struct only contains pointers to the data and none of the actual data.
*
* Not all HTTP fields are supported. Unsupported fields are commented
* out, so if you require one of them for your application, you will have
* to implement it yourself or wait until we find a reason to officially
* support it.
*
* @see mime_type.h
* @see http_method.h
* @see http_protocol.h
*/
struct http_request {

    /**
    * The method of the request is represented by an 8 bit integer. To make
    * this easier to follow while programming, macros for all methods can be
    * found in http_method.h as well as functions to get the string version
    * of the method if necessary.
    */
    uint8_t *type;              /* Supported */

    /**
    * The requested resource's path. The server uses this to route the
    * request to the appropriate handler or submoduled application.
    */
    char* path;                 /* Supported */

    /**
    * The version of the HTTP protocol the request is using. Marmoset only
    * supports HTTP/1.1, but still needs to be able to read the protocol
    * version and respond with an appropriate error.
    */
    uint8_t HTTP_version;       /* Supported */

    /**
    * The host that the request is for. This allows the server to support
    * multiple hostnames on a single IP. It is required by the HTTP specifiction.
    */
    char* host;                 /* Supported */

    /**
    * The length of the body included in the request. This field may be
    * required in future versions of Marmoset depending on how much processing
    * or memory use could be saved.
    */
    size_t content_length;      /* Supported */

    /**
    * The content included with the request. Not all methods will recongnize
    * this field. For example, the body in GET requests will not be read.
    */
    char* body;                 /* Supported */

    /**
    * The user-agent identifiction for the application that sent the request.
    */
    char* user_agent;           /* Supported */

    /**
    * The following fields are not currently supported by marmoset and
    * will be evaluated to see if they are needed or if they will cause
    * unnessisary overhead for marmoset's application domain.
    */

    // char* accept;               /* Not Supported */
    // uint8_t accept_charset;     /* Not Supported */
    // uint8_t accept_encoding;    /* Not Supported */
    // uint8_t accept_language;    /* Not Supported */
    // char* accept_datetime;      /* Not Supported */
    // char* authorization;        /* Not Supported */
    // char* cache_control;        /* Not Supported */
    // uint8_t connection;         /* Not Supported */
    // char* cookie;               /* Not Supported */
    // char* date;                 /* Not Supported */
    // uint8_t expect;             /* Not Supported */
    // char* from;                 /* Not Supported */
    // char* if_match;             /* Not Supported */
    // char* if_modified_since;    /* Not Supported */
    // char* if_none_match;        /* Not Supported */
    // char* if_range;             /* Not Supported */
    // char* if_unmodified_since;  /* Not Supported */
    // uint8_t max_forwards;       /* Not Supported */
    // char* origin;               /* Not Supported */
    // char* http_pragma;          /* Not Supported */
    // char* proxy_authorization;  /* Not Supported */
    // char* range;                /* Not Supported */
    // char* referer;              /* Not Supported */
    // char* te;                   /* Not Supported */
    // char* upgrade;              /* Not Supported */
    // char* via;                  /* Not Supported */
    // char* warning;              /* Not Supported */
};

#endif