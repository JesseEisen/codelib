
//
// fileread.h
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#ifndef __FILE_READ_H__
#define __FILE_READ_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

size_t
file_size(FILE *stream);

char *
file_read(const char *filename);

char *
read_until_eof(FILE *stream);


#endif 
