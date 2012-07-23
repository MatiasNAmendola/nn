/*    config.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "common.h"
#include "error.h"

/*
 * STRUCTURE: __nsmart_config
 * DESCRIPTION: This contains all the configuration parameter required by 
 *              the parser, the run and the command_executer
 * ELEMENTS:  
 *            _file_ : This is the file name to be parsed
 */
typedef struct __nsmart_config__ {
	char *	_file_;
}__nsmart_config;

/* 
 * FUNCTION DEFINITIONS
 */

void __print_usage(char *prog_name);
int __set_nsmart_file(char *file_path);
char* __get_nsmart_file();

#endif // __CONFIG_H__
