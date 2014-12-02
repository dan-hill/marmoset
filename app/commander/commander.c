
/*#include "commander.h"


void commander_handler(int* client_sd, struct http_request * req, struct http_response* res){
    if(req->type == HTTP_GET){
        char * buffer = 0;
        long length;
        FILE * f = fopen ("../view/commander_form.html", "rb");

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
            res->content_length = length;
            res->content_type = MIME_TYPE_TEXT_PLAIN;
        }

        return;
    }

    if(*req->type == HTTP_POST){
        req->body = req->body + 9;

        char* space;
        while(space = strstr(req->body, "+")){
            *space = ' ';
        }

        char* slash;
        while(slash = strstr(req->body, "%2F")){
            *slash = '/';
            slash = slash + 2;
        }

        cats(&res->content, "<html>");
        printf("%s", req->body);
        FILE *ls = popen(req->body, "r");
        if(ls == NULL){
            abort_request(client_sd, HTTP_BAD_REQUEST, req, "okie");
        }
        char buf[256];
        while (fgets(buf, sizeof(buf), ls) != 0) {
            cats(&res->content, buf);
        }
        pclose(ls);

        res->content_length = sizeof(res->content);

        res->content_type = MIME_TYPE_TEXT_HTML;

        return;
    }

    fprintf(stdout, "\r\r");
    abort_request(client_sd, HTTP_BAD_REQUEST, req, "okie");

}*/