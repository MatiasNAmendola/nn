/*    symbol.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "symbol.h"

/*TODO: Implement all the basic functions for the symbol*/

__sym_tab * get_sym (UINT flag, char *package,char *symbol)
{
	__sym_tab *ret_sym = NULL;
	/* Get symbol from symbol_argument_table stack if its same package */
	if (flag & CALL_PROC)
		ret_sym =(__sym_tab *) __sym_tab_arg_get_sym(symbol);

	/* package is not current package OR */
	/* not found in argument stack OR */
	if (ret_sym == NULL)
		ret_sym = __sym_tab_get_sym(package,symbol);

	return ret_sym;
}

INT set_sym (UINT flag, char *package, char *symbol, __sym_tab_type sym_type, __sym_tab_value value)
{
	__sym_tab *ret_sym = NULL;
	INT ret = ERROR;
	/* Get symbol from symbol_argument_table */
	if (flag & CALL_PROC){
		ret_sym = __sym_tab_arg_get_sym(symbol);
		if (ret_sym == NULL) { 
			ret_sym = __sym_tab_get_sym(package,symbol);
			if (ret_sym != NULL){
				ret = __sym_tab_set_sym(package,symbol,sym_type,value);
				return ret;
			}
		}
		ret = __sym_tab_arg_set_sym(symbol,sym_type,value);
		return ret;
	}

	/* Set the symbol in symbol table*/
	ret = __sym_tab_set_sym(package,symbol,sym_type,value);
	return ret;
}

__sym_tab_value * get_sym_value (UINT flag, char *package, char *symbol)
{
	__sym_tab_value *ret_val = NULL;
	/* if proc call, get it from argument table or symbol table*/
	if (flag & CALL_PROC)
		ret_val = __sym_tab_arg_get_value(symbol);
	
	/* not a proc call, get it only from symbol table*/
	if (ret_val == NULL)
		ret_val = __sym_tab_get_value(package,symbol);

	return ret_val;
}

INT delete_sym(UINT flag)
{
	if (flag & CALL_PROC){
	/* Delete symbol from symbol_argument_table stack */
		__sym_tab_arg_delete_sym_arg_list();
	} else {
	/* Delete symbol from global symbol table */
		__sym_tab_delete_sym_tab();
	}

	return SUCCESS;
}

void set_value(CONST_VAL *set_val, CONST_VAL *result_val)
{
	if (set_val->type == SYM_TYPE_VAL) {
			if (result_val->type != SYM_TYPE_VAL)
				*(set_val->u.ptr_val) = *result_val;
			else
				*(set_val->u.ptr_val) = *(result_val->u.ptr_val);

	} else if(set_val->type == SYM_TYPE_REF) {
			while (set_val->type == SYM_TYPE_REF)
					set_val = &(set_val->u.ref_val->value);

			*set_val = *result_val;
	} else {
		*set_val = *result_val;
	}
}

