#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

struct http_request {
    uint8_t *type;              /* Supported */
    char* path;                 /* Supported */
    uint8_t HTTP_version;       /* Supported */
    char* host;                 /* Supported */
    size_t content_length;      /* Supported */
    char* body;                 /* Supported */
    char* user_agent;           /* Supported */

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