/*    io.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __IO_H__
#define __IO_H__

#include "common.h"
#include "op.h"


typedef struct nsmart_io_funcs	IOFuncs;
typedef struct nsmart_io		IO;

/* TODO: Structure to store the io v-table */
struct nsmart_io_funcs {
	UINT	flags;

	/*function pointers to the actual IO operation */
	size_t	(*Print) (IO *f, void *vbuf,size_t count);
	size_t	(*Read) (IO *f, void *vbuf, size_t count);
	size_t	(*Write) (IO *f, void *vbuf, size_t count);
	size_t	(*Unread) (IO *f, void *vbuf, size_t count);
	IO	*	(*Open) (IO *f, void *vbuf, const char * mode);
	UINT	(*Close) (IO *f);
};
/* TODO: structure to store the io layer */
struct nsmart_io {
	/*io file descriptor*/
	INT		fd;

	IO	*next; /*pointer to the next layer of IO*/
	IOFuncs *tab; /* io function pointers*/
};

INT __init_io();
UINT set_io(IO *io);
IO * get_io ();

/*Function definition for DO_IO function*/
#define DEF_DO_IO(ioOP)	INT DO_IO_##ioOP (CONST_VAL val)


#define DO_IO(ioOP,val)	{						\
							DO_IO_##ioOP(val);	\
						}
/*Declaration for IO functions*/
INT DO_IO_print(CONST_VAL val);
INT DO_IO_scan(CONST_VAL  val);
INT DO_IO_read(CONST_VAL val);
INT DO_IO_write(CONST_VAL fdval, CONST_VAL val);
INT DO_IO_open(CONST_VAL *retval,CONST_VAL val,CONST_VAL mode);
INT DO_IO_close(CONST_VAL val);
#endif /* __IO_H__ */

