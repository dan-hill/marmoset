#include "index.h"

void index_handler(int* client_sd, struct http_request_parser* req, struct http_response* res){
    if(req->type == HTTP_GET){
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

    if(req->type == HTTP_POST){
        printf("here we are   |");
        abort_request(client_sd, HTTP_BAD_REQUEST, "Bad Request Mr. Facehole");
    }

}