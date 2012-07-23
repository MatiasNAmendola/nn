/*    io.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "io.h"

/*global IO variable*/
IO *gIO = NULL;

/* Currently int_io calls set_io which considers only
 * unix io, if tomorrow we want to consider windows io
 * we will have to write windows sepecific code
 * */
INT __init_io()
{
	gIO = malloc(sizeof(IO));
	if (gIO == NULL){
		PRINT_DEBUG(DEBUG_ERROR,"Malloc Failed\n");
		return ERROR;
	}
	memset(gIO,0,sizeof(gIO));
	gIO->tab = malloc(sizeof(IOFuncs));
	if (gIO->tab == NULL) {
		PRINT_DEBUG(DEBUG_ERROR,"Malloc Failed\n");
		free(gIO);
		return ERROR;
	}
	set_io(gIO);
	return SUCCESS;
}

UINT set_io(IO *io)
{
	unix_io_set_funcs(io);
}

IO * get_io ()
{
	return gIO;
}

INT DO_IO_print(CONST_VAL val)
{
	char *temp;
	IO *io;

	/* convert the CONST_VAL to string						 */
	/* Get the IO pointer									 */
	/* use the io v-table function to execute the proper IO */

	temp = __sym_tab_val_to_string(val);//CONST_VAL_TO_STRING(val);
	io = get_io();


	if (temp != NULL && temp[0] != '\0')
		io->tab->Print(io,temp,strlen(temp));

	return SUCCESS;
}

INT DO_IO_scan(CONST_VAL  val)
{
}

INT DO_IO_read(CONST_VAL val)
{
}

INT DO_IO_write(CONST_VAL fdval, CONST_VAL val)
{
	char *temp;
	CONST_VAL *realval;
	IO *io;

	/* convert the CONST_VAL to string						 */
	/* Get the IO pointer									 */
	/* use the io v-table function to execute the proper IO */

	temp = __sym_tab_val_to_string(val);//CONST_VAL_TO_STRING(val);
	io = get_io();

	/*TODO: need to be careful that fdval will always be integer*/
	get_val(&fdval,&realval);
	io->fd = realval->u.i_val;

	if (temp != NULL && temp[0] != '\0')
		io->tab->Write(io,temp,strlen(temp));

	return SUCCESS;
}

INT DO_IO_open(CONST_VAL *retval, CONST_VAL val,CONST_VAL modeval)
{
	char *temp, *mode;
	IO *io;

	/* convert the CONST_VAL to string						 */
	/* Get the IO pointer									 */
	/* use the io v-table function to execute the proper IO */

	temp = __sym_tab_val_to_string(val);//CONST_VAL_TO_STRING(val);
	mode = __sym_tab_val_to_string(modeval);//CONST_VAL_TO_STRING(val);
	io = get_io();


	if (temp != NULL && temp[0] != '\0')
		io->tab->Open(io,temp,mode);


	retval->type = SYM_TYPE_INT;
	retval->u.i_val = io->fd;

	return SUCCESS;
}

INT DO_IO_close(CONST_VAL val)
{
	IO *io;

	io = get_io();
	io->fd = val.u.i_val;
	io->tab->Close(io);

	return SUCCESS;
}


