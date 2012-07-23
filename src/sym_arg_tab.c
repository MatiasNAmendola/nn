/*    sym_arg_tab.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "sym_tab.h"
#include "debug.h"

CREATE_LIST(__sym_tab_arg)

INT __sym_tab_arg_compare(__sym_tab_arg *src, __sym_tab_arg *dest)
{
	/*If we have reached a magic mark, return positive to stop any further comparison*/
	if (src->value.type == SYM_TYPE_MAGIC)
		return (1);
	if (src && dest && src->symbol && dest->symbol)
		return (!strcmp(src->symbol, dest->symbol));

	return (0);
}

INT __sym_tab_arg_delete(__sym_tab_arg *node)
{
	/* do not delete symbol name, it is being reused form OP tree */
	//if (node->symbol)
		//free(node->symbol);
	/*remove the value, only if it is string*/
	if (node) {
		if ((node->value.type == SYM_TYPE_STRING) ||
			(node->value.type == SYM_TYPE_SYMBOL))
			free(node->value.u.s_val);
	
		free(node);
	}
	return SUCCESS; 
}

INT __sym_tab_arg_delete_sym_arg_list()
{
    __sym_tab_arg *return_node = NULL;

    POP_FROM_LIST(__sym_tab_arg,return_node)
	GET_HEAD_FROM_LIST(__sym_tab_arg,return_node)
	while(return_node) {
		if (return_node->value.type == SYM_TYPE_MAGIC)
			break;
		POP_FROM_LIST(__sym_tab_arg,return_node)
	}
	if (return_node)
		__sym_tab_arg_delete(return_node);	
	return SUCCESS;
}

__sym_tab * __sym_tab_arg_get_sym(char *symbol)
{
	__sym_tab_arg search_node;
	__sym_tab_arg *return_node = NULL;

	search_node.symbol = symbol;

	SEARCH_FROM_LIST(__sym_tab_arg,return_node,&search_node);

	if (return_node && return_node->value.type != SYM_TYPE_MAGIC)
		return ((__sym_tab*)return_node);

	return (NULL);	
}
__sym_tab_value* __sym_tab_arg_get_value(char *symbol)
{
       __sym_tab *return_node = NULL; 
	return_node = __sym_tab_arg_get_sym(symbol);
	if (return_node)
		return (&return_node->value);

        return (NULL);
}

INT __sym_tab_arg_set_sym(char *symbol, __sym_tab_type sym_type, __sym_tab_value value)
{
        __sym_tab *return_node = NULL;
        return_node = __sym_tab_arg_get_sym(symbol);
        if (return_node) {
		return_node = __sym_tab_chase_symbol(return_node);
		return_node->value.type = sym_type;
		return_node->value = value;
		return SUCCESS;
	} else {
		__sym_tab_arg_create_sym(symbol);
		__sym_tab_arg_set_sym(symbol,sym_type,value);
	}
	return ERROR;
}

INT __sym_tab_arg_create_sym(char *symbol)
{
	CREATE_LIST_NODE(__sym_tab_arg, new_node)
	new_node->symbol = symbol;
	ADD_TO_LIST(__sym_tab_arg, new_node)	
	return SUCCESS;	

}

__sym_tab_arg * __sym_tab_arg_push_magic()
{
	CREATE_LIST_NODE(__sym_tab_arg, new_node)
	new_node->value.type = SYM_TYPE_MAGIC;
	ADD_TO_LIST(__sym_tab_arg, new_node)
	return new_node;
}

__sym_tab_arg * __sym_tab_arg_push_val(__sym_tab_type type, __sym_tab_value val)
{
	CREATE_LIST_NODE(__sym_tab_arg, new_node)
	new_node->value.type = type;
	new_node->value = val;
        ADD_TO_LIST(__sym_tab_arg, new_node)
        return new_node;

}

__sym_tab_arg * __sym_tab_arg_tmp_HEAD = NULL;
__sym_tab_arg * __sym_tab_arg_tmp_TAIL = NULL;	

void __sym_tab_arg_tmp_clear()
{
	__sym_tab_arg_tmp_HEAD = NULL;
	__sym_tab_arg_tmp_TAIL = NULL;	
}
__sym_tab_arg * __sym_tab_arg_tmp_push_magic()
{
	CREATE_LIST_NODE(__sym_tab_arg, new_node)
	new_node->value.type = SYM_TYPE_MAGIC;
	ADD_TO_LIST(__sym_tab_arg_tmp, new_node)
	if (__sym_tab_arg_tmp_TAIL == NULL)
		__sym_tab_arg_tmp_TAIL = new_node;
	return new_node;
}

__sym_tab_arg * __sym_tab_arg_tmp_push_val(__sym_tab_type type, __sym_tab_value val)
{
	CREATE_LIST_NODE(__sym_tab_arg, new_node)
	new_node->value.type = type;
	new_node->value = val;
    ADD_TO_LIST(__sym_tab_arg_tmp, new_node)
	if (__sym_tab_arg_tmp_TAIL == NULL)
		__sym_tab_arg_tmp_TAIL = new_node;

        return new_node;

}

INT __sym_tab_arg_set_sym_name(__sym_tab_arg *head,char *symbol)
{
	if (head == NULL || symbol == NULL)
		return ERROR;

	head->symbol = symbol;

	return SUCCESS;
}

INT __sym_tab_arg_print_sym(char *symbol)
{
	 __sym_tab_arg *return_node = NULL;
        return_node = __sym_tab_arg_get_sym(symbol);
	if (return_node == NULL)
	{
		PRINT_DEBUG(DEBUG_INFO,"FATAL_ERROR: symbol not present");
		return ERROR;
	}
	switch(return_node->value.type)
	{
		case SYM_TYPE_MAGIC:
			PRINT_DEBUG(DEBUG_INFO,"---- END OF SYMBOL STACK ---- ");
		case SYM_TYPE_UNKNOWN:
		break;
        case SYM_TYPE_INT:
        	PRINT_DEBUG(DEBUG_INFO," %d ",return_node->value.u.i_val);
		break;
        case SYM_TYPE_UINT:
        	PRINT_DEBUG(DEBUG_INFO," %u ",return_node->value.u.ui_val);
		break;
        case SYM_TYPE_FLOAT:
        	PRINT_DEBUG(DEBUG_INFO," %f ",return_node->value.u.f_val);
		break;
        case SYM_TYPE_STRING:
        	PRINT_DEBUG(DEBUG_INFO," %s ",return_node->value.u.s_val);
		break;
        case SYM_TYPE_SYMBOL:
        	PRINT_DEBUG(DEBUG_INFO," %s ",return_node->value.u.s_val);
        break;
        case SYM_TYPE_OP:
		break;
	}
	return SUCCESS;

}
INT __sym_tab_arg_print_all_sym()
{
	__sym_tab_arg	*next_node = NULL;

	PRINT_DEBUG(DEBUG_INFO,"\n-------------------------- PRINTING ARG SYMBOL STACK  -----------------\n");
	GET_NEXT_FROM_LIST(__sym_tab_arg,next_node)
	while(next_node)
	{
		PRINT_DEBUG(DEBUG_INFO,"\n %s = ",next_node->symbol);
		__sym_tab_arg_print_sym(next_node->symbol);

		if (next_node->value.type == SYM_TYPE_MAGIC)
			break;

		GET_NEXT_FROM_LIST(__sym_tab_arg,next_node)
	}
	PRINT_DEBUG(DEBUG_INFO,"\n------------------------------------------------------------------\n");
	return SUCCESS;
}

