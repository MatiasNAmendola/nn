/*    config.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "config.h"

uint	CURRENT_DEBUG_CODE;

static __nsmart_config CONFIG;

void __print_usage(char *prog_name)
{
	printf ("USAGE: %s file_name", prog_name);
}

int __set_nsmart_file(char *file_path)
{
	CONFIG._file_ = file_path;
	return SUCCESS;
}

char* __get_nsmart_file()
{
	return CONFIG._file_;
}

void __set_nsmart_debug_code(uint debug_code)
{
	CURRENT_DEBUG_CODE = debug_code;
}
