#ifndef HTTP_REQUEST_PARSER_H
#define HTTP_REQUEST_PARSER_H

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
/* TODO expand the mimetypes to all mimetypes instead of just common ones. */
#define MIME_TYPE_APPLICATION_JSON 0
#define MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED 1


struct http_request_parser {
    uint8_t type;               /* Supported */
    char* path;                 /* Supported */
    uint8_t HTTP_version;       /* Supported */
    char* host;                 /* Supported */
    size_t content_length;      /* Supported */
    char* body;                 /* Supported */
    char* user_agent;           /* Supported */
    char* accept;               /* Not Supported */
    uint8_t accept_charset;     /* Not Supported */
    uint8_t accept_encoding;    /* Not Supported */
    uint8_t accept_language;    /* Not Supported */
    char* accept_datetime;      /* Not Supported */
    char* authorization;        /* Not Supported */
    char* cache_control;        /* Not Supported */
    uint8_t connection;         /* Not Supported */
    char* cookie;               /* Not Supported */
    char* date;                 /* Not Supported */
    uint8_t expect;             /* Not Supported */
    char* from;                 /* Not Supported */
    char* if_match;             /* Not Supported */
    char* if_modified_since;    /* Not Supported */
    char* if_none_match;        /* Not Supported */
    char* if_range;             /* Not Supported */
    char* if_unmodified_since;  /* Not Supported */
    uint8_t max_forwards;       /* Not Supported */
    char* origin;               /* Not Supported */
    char* http_pragma;          /* Not Supported */
    char* proxy_authorization;  /* Not Supported */
    char* range;                /* Not Supported */
    char* referer;              /* Not Supported */
    char* te;                   /* Not Supported */
    char* upgrade;              /* Not Supported */
    char* via;                  /* Not Supported */
    char* warning;              /* Not Supported */
};

void parse_request(struct http_request_parser * req, char *request);

#endif