/*    error.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */
#ifndef __ERROR_H__
#define __ERROR_H__

#include "common.h"
/*
 * NOTE: If you happen to add a new error_code please add a corresponding
 *       Error message in __nsmart_error_message at appropriate point.
 */
typedef enum __nsmart_error_codes {
	SUCCESS = 0,
	ERROR,		/*   = 1,*/
	MAX_ERROR,	/*   = 2*/
	NO_ERROR_MSG	/*   = 3*/
}ERROR_CODES;


char * __get_error_msg(unsigned int err_code);

#endif // __ERROR__H__
