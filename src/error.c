/*    error.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "error.h"

static char *__nsmart_error_message[] = {
	"SUCCESS",
	"ERROR",
/*
 * NOTE: DO NOT MODIFY FOLLOWING TWO ERROR MESSAGES
 */
	"MAX_ERROR",
	"Error message not found"
};



char * __get_error_msg(unsigned int err_code)
{
	if (err_code < MAX_ERROR){
		return __nsmart_error_message[err_code];
	}else {
		return __nsmart_error_message[NO_ERROR_MSG];
	}
}
