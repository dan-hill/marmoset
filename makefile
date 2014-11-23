makefile:
all: marmoset

clean:
	rm marmoset

marmoset:
	gcc main.c debug.c debug.h die_with_error.c die_with_error.h http_header.c http_header.h request.c request.h -o marmoset