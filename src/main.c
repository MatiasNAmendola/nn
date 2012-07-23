/*    main.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "nsmart.h"
#include "sym_tab.h"
#include "debug.h"

//#include <stdio.h>
//#include <readline/readline.h>
//#include <readline/history.h>
/*
 * FUNCTION: __get_configuration()
 * DESCRIPTION: This gets the configuration from the config file and
 *              also from the command line options, which overwrites 
	        any config file options.
 * CONSTRAINTS: 1. For now there is no config file reading. 
 *              2. only command line options
 *              3. from command line only file list is considered 
 */
int __get_configuration(int argc,char *argv[])
{
	if (argc < 2) {
		__print_usage(argv[0]);
		return ERROR;
	}
	__set_nsmart_file(argv[1]);
	__set_nsmart_debug_code(DEBUG_NONE);
	__init_io();
	return SUCCESS;
}
/*
 * FUNCTION: __parse_nsmart()
 * DESCRIPTION: This is the main parser for the nsmart.
 * CONSTRAINTS: Currently only capable of parsing one file.
 *		however, it should not be hard to make it multi-file parser.
 */
unsigned int __parse_nsmart()
{
char *file_name = NULL;
	file_name = __get_nsmart_file();
	yyin = fopen(file_name,"r");
	yyparse();
	fclose(yyin);

	return SUCCESS;
}

/*
 * FUNCTION: __run_nsmart()
 * DESCRIPTION: This will actual/really simulation of neural network
 * CONSTRAINT: will be implemented once the parser is done.
 * NOTE:       STAY TUNED :) HERE IS THE REAL FUN            
 */
unsigned int __run_nsmart()
{
	__execute_nsmart_root();
	return SUCCESS;
}
/*
 * FUNCTION: __run_command_executer()
 * DESCRIPTION: This creates a new thread, 
		binds to a port and listens for any commands from external world.
		once the command is received, it executes it.
 * CONSTRAINT: only two commands are identified YET. look into commands.h
 * NOTE:       STAY TUNED :) 
               HERE IS WHAT MAKES YOU GET INTO THE RUNNING SIMULATION            
 */

void __run_command_executer()
{
	/*TODO: Create a new thread which will bind to port and listens for commands*/
	/*for now getting it from command line*/
unsigned int error = SUCCESS;
char command[MAX_COMMAND_LENGTH];

	while (SUCCESS == error) {
		printf("\nnsmart : ");
		//if (NULL != gets((char*)command)) {

			//error = __run_command(command);
		//}

		command[0] = '\0';
	}
}

int main(int argc, char *argv[])
{
unsigned int retcode = SUCCESS;

	__get_configuration(argc,argv);

	PRINT_DEBUG(DEBUG_INFO,"\n ----- PARSING STARTED -----\n");
	retcode = __parse_nsmart();
	if (retcode != SUCCESS) 
		return SUCCESS;

	PRINT_DEBUG(DEBUG_INFO,"\n ----- EXECUTION STARTED -----\n");
	retcode = __run_nsmart();
	if (retcode != SUCCESS)
		return SUCCESS;

	/*command executer is not doing anything importat for now...so muted it down*/
	//__run_command_executer();

	//TODO: remove it once parser is okay
	//__parser_code();
	__sym_tab_print_all_sym();
	__print_op();
	return SUCCESS;
}


