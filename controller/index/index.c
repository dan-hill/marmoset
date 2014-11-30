#include "index.h"

void index_handler(struct http_request_parser* req, struct http_response* res){
    if(req->type == REQ_TYPE_GET){
        printf("HEREHEHEHRHEHERHE");
        char * buffer = 0;
        long length;
        FILE * f = fopen ("/home/dan/Development/marmoset/view/index.html", "rb");

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
            printf("%s", buffer);
            res->content = buffer;
            res->content_length = length;
        }

    }

}