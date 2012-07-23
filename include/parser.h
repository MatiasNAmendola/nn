/*    parser.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>

#include "error.h"
#include "op.h"
#include "nsmart.tab.h"

/*
 * Entries that should have been in nsmart.y
 */
extern FILE *yyin;
extern char *yytext;
extern char *literal;
extern unsigned int literal_length;



int __parser_code();

#endif // __PARSER_H__
