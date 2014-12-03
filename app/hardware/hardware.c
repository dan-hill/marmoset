#include "hardware.h"

struct http_response *hardware_handler(struct http_request *req) {
    if (*req->type == HTTP_GET) {

        struct http_response *res = (struct http_response *) malloc(sizeof(struct http_response));
        cats(&res->content, "<html>\n<body>\n\t<pre>");
        FILE *ls = popen("lshw -short", "r");
        if (ls == NULL) {
            abort_request(HTTP_BAD_REQUEST, "Hardware information not availible at this time.");
        }
        char buf[256];
        while (fgets(buf, sizeof(buf), ls) != 0) {
            cats(&res->content, buf);
        }
        pclose(ls);
        cats(&res->content, "</pre></body></html>");
        res->content_type = MIME_TYPE_TEXT_HTML;

        return respond(HTTP_OK, res);
    }

    abort_request(HTTP_BAD_REQUEST, "Method not allowed.");
}