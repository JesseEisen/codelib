
//
// codelib.h
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#ifndef _CODE_LIB_H_
#define _CODE_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commander/commander.h"
#include "strdup/strdup.h"
#include "fileread/fileread.h"

#define CODE_LIB_VERSION "0.0.1"

typedef struct {
	char *dir;
	char *key;
	int  bLocal;
}options;


#endif
