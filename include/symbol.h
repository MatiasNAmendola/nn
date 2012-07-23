/*    symbol.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "op.h"
#include "sym_tab.h"



/*FLAGS FOR PROCESSING*/
#define CALL_GLOB       0X00
#define CALL_PROC       0x01
/*END OF FLAGS*/


__sym_tab * get_sym (UINT flag,char *package,char *symbol);
INT set_sym (UINT flag,char *package, char *symbol, __sym_tab_type sym_type, __sym_tab_value value);
__sym_tab_value * get_sym_value (UINT flag,char *package, char *symbol);
INT delete_sym(UINT flag);

void set_value(CONST_VAL *set_val, CONST_VAL *result_val);
#endif // __SYMBOL_H__
