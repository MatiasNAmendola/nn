/*    command.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "command.h"
/*
 * LIST OF SUPPORTED COMMAND NAMES
 * not being used currently *

static char * __names_of_commands[] = {
	"help",
	"quit",
	"list network",
	"MAX REACHED",
	"Command not found"
};
*/

/*
 * LIST OF COMMANDS
 */
static __command_info  __commands[] = {
	{ "help", __command_help},
	{ "quit", __command_quit},
	{ "list network", __command_list_network},
	{ "MAX REACHED", __command_max_reached},
	{ "no command", __command_no_command}
};


__command_function__ __get_command_function (char *command_name) {

unsigned int counter = 0;
	if (NULL == command_name) {
		return __commands[HELP].command_func;
	}
	while(counter < MAX_COMMANDS) {
		if (0 == strcmp(command_name,__commands[counter].command_name)) 
			return __commands[counter].command_func;
		counter++;
	}
	return (__commands[NO_COMMAND].command_func);
}

unsigned int __run_command (char *command) {
	unsigned int error;
	__command_function__ command_func;
	
	command_func = __get_command_function(command);
	error = command_func();
	return error;
}
