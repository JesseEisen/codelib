
//
// codelib.c
//
// Copyright (c) 2017 JesseChen <lkchan0719@gmail.com>
//

#include "codelib.h"

options g_opt = {NULL,NULL,0};

static void
setopt_dir(command_t *self)
{
	g_opt.dir = strdup(self->arg);	
}

static void
setopt_searchkey(command_t *self)
{
	g_opt.key = strdup(self->arg);
}

static void
setopt_local(command_t *self)
{
	g_opt.bLocal = 1;
}

void 
cleanup(void)
{
	if(g_opt.dir)  free(g_opt.dir);
	if(g_opt.key)  free(g_opt.key);
}

int main(int argc, char **argv)
{
	command_t cmd;
	command_init(&cmd, argv[0],CODE_LIB_VERSION);
	command_option(&cmd,	
			"-o","--out <dir>",
			"change the default output directory [deps]",
			setopt_dir);
	command_option(&cmd,
			"-s","--search <key>",
			"search package name or descriptions contain the keyword",
			setopt_searchkey);
	command_option(&cmd,
			"-l", "--local",
			"install package defined in package.json dependencies",
			setopt_local);
	command_parse(&cmd,argc,argv);

	cleanup();

	return 0;
}
