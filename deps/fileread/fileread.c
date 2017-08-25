
//
// fileread.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include "fileread.h"

/*
 * Return the file size of `filename` or -1
 */

size_t
file_size(FILE *stream) {
    size_t size = 0;
    fseek(stream, 0, SEEK_END);
    size = ftell(stream);
    rewind(stream);
    return size;
}


/*
 * read the conetents of `filename` or return NULL
 */

char *
file_read(const char *filename) {
    FILE *fh = fopen(filename, "r");
    size_t len = file_size(fh);

    char *buf = malloc(len + 1);
    if(!buf)  return NULL;

    size_t read = fread(buf, sizeof(char), len, fh);
    fclose(fh);
    buf[read] = 0;
    return buf;
}

/*
 * read `stream` until EOF
 */

char *
read_until_eof(FILE *stream) {
    off_t len = 0;
    char buf[1024];
    char *str = malloc(1);
    assert(str);

    while (!feof(stream) && !ferror(stream)) {
        size_t n = fread(buf, 1, 1024, stream);
        len += strlen(buf);
        str = realloc(str, len);
        strncat(str, buf, n);
    }

    return str;
}
