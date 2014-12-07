
#include "index.h"

struct http_response* index_handler(struct http_request * req)
{
    struct http_response* res = (struct http_response *) malloc(sizeof(struct http_response));

    if(*req->type == HTTP_GET){
        char * buffer = 0;
        long length;
        FILE * f = fopen ("../view/index.html", "rb");

        if (f)
        {
            fseek (f, 0, SEEK_END);
            length = ftell (f);
            fseek (f, 0, SEEK_SET);
            buffer = malloc (length);
            if (buffer)
            {
                fread (buffer, 1, length, f);
            }
            fclose (f);
        }

        if (buffer)
        {
            res->content = buffer;
            res->content_type = MIME_TYPE_TEXT_HTML;
        }

        return respond(HTTP_OK, res);
    }

    return abort_request(HTTP_BAD_REQUEST, "Method not allowed.");
}