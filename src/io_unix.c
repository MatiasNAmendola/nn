/*    io_unix.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "io.h"
//#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

typedef struct _unix_flags_
{
	char * cmode;
	int    imode;
}_unix_flags;

#define MAX_UNIX_FLAG  4

_unix_flags unix_flag[MAX_UNIX_FLAG] = {
		{"R",O_RDONLY},
		{"W",O_WRONLY},
		{"RW",O_RDWR},
		{"APP",O_APPEND}
};

INT unix_get_open_flag (char *mode)
{
	int i = 0;

	for(i=0;i<MAX_UNIX_FLAG;i++)
	{
		if(0 == strcmp(mode,unix_flag[i].cmode))
			break;
	}
	if (i!=MAX_UNIX_FLAG)
		return unix_flag[i].imode;
	else
		return 0;
}

size_t unix_io_Read (IO *f, void *vbuf, size_t count)
{
	INT fd = f->fd;
	read(fd,vbuf,count);
}

size_t unix_io_Write (IO *f, void *vbuf, size_t count)
{
	INT fd = f->fd;
	write(fd,vbuf,count);
}

size_t unix_io_Unread (IO *f, void *vbuf, size_t count)
{
}

IO	*  unix_io_Open (IO *f, void *vbuf, const char * mode)
{
	int flag = unix_get_open_flag(mode);
	f->fd = open((char *)vbuf,flag);
	if (f->fd == -1)
	{
		char *prob = strerror(errno);
		printf("\n%s\n",prob);

	}
	return f;
}

UINT unix_io_Close (IO *f)
{
	close(f->fd);
}

UINT unix_io_Print(IO *io, void *vbuf,size_t count)
{
	io->fd = 1;
	unix_io_Write(io,vbuf,count);
}

UINT unix_io_set_funcs(IO *io)
{
	io->tab->Print = unix_io_Print;
	io->tab->Read = unix_io_Read;
	io->tab->Write = unix_io_Write;
	io->tab->Unread = unix_io_Unread;
	io->tab->Open = unix_io_Open;
	io->tab->Close = unix_io_Close;

	return SUCCESS;
}
