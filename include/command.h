/*    command.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "common.h"
#include "error.h"

#define MAX_COMMAND_LENGTH	255
typedef unsigned int (*__command_function__)(void);

typedef struct __command_info__ {
	char command_name[MAX_COMMAND_LENGTH];
	__command_function__	command_func;
}__command_info;

/*NOTE: If you add a new command please add it also to __commands*/
typedef enum __list_of_commands__ {
	HELP	= 0,
	QUIT,			 /* = 1*/
	LIST_NETWORK,		 /* = 2*/
/*DO NOT MODIFY BELOW ENTRIES*/
	MAX_COMMANDS,		 /* = 3*/	
	NO_COMMAND		 /* = 4*/
} __list_of_commands;

/*
 * DECLARATIONS OF THE VARIOUS SUPPORTED COMMANDS
 */
unsigned int __command_help(void);
unsigned int __command_quit(void);
unsigned int __command_list_network(void);
unsigned int __command_max_reached();
unsigned int __command_no_command();


unsigned int __run_command (char *command);
__command_function__ __get_command_function(char *command_name);



#endif // __COMMAND_H__
