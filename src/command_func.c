/*    command_func.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "command.h"
#include "error.h"

unsigned int __command_help()
{
	printf("\nFollowing is the list of supported commands:\n"
	       "\t1. help 	: provides the help on all commands\n"
	       "\t2. quit	: quits the program\n"
	       "\t3. list network: lists down all the network names\n");
	return SUCCESS;
}

unsigned int __command_quit()
{
	/*TODO: need to call cleanup first*/
	/*for now returning error, so that it will quit the program*/
	return ERROR;
}

unsigned int __command_list_network()
{
	printf("\nlist network command is not yet implemented\n");
	return SUCCESS;
}

unsigned int __command_max_reached()
{
	return SUCCESS;
}
unsigned int __command_no_command()
{
	printf("\n This command does not exist\n");
	return SUCCESS;
}
