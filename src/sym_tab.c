/*    sym_tab.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "sym_tab.h"
#include "debug.h"

CREATE_LIST(__sym_tab)
//__sym_tab *_HEAD = NULL;

INT	__sym_tab_compare(__sym_tab *src, __sym_tab *dest) 
{
	if (! strcmp(src->package, dest->package))
		return (!strcmp(src->symbol,dest->symbol));

	return 0;
}

INT	__sym_tab_delete(__sym_tab *node)
{
	if (node->package)
		free(node->package);
	if (node->symbol)
		free(node->symbol);
	/*remove the value, only if it is string*/
	if ( (node->value.type == SYM_TYPE_STRING) ||
		 (node->value.type == SYM_TYPE_SYMBOL))
		free(node->value.u.s_val);

	return SUCCESS; 
	
}

INT	__sym_tab_delete_sym_tab()
{
        __sym_tab *return_node = NULL;

        POP_FROM_LIST(__sym_tab,return_node);

        while(return_node) {
                DELETE_FROM_LIST(__sym_tab,return_node);
                POP_FROM_LIST(__sym_tab,return_node);
        }
        
        return SUCCESS;

}
__sym_tab *	__sym_tab_get_sym(char *package, char *symbol)
{
	__sym_tab search_node;
	__sym_tab *return_node = NULL;

	search_node.package = package;
	search_node.symbol = symbol;

	SEARCH_FROM_LIST(__sym_tab,return_node,&search_node);

	return (return_node);	
}

__sym_tab_value* __sym_tab_get_value(char *package, char *symbol)
{
        __sym_tab *return_node = NULL; 
	return_node = __sym_tab_get_sym(package,symbol);
	if (return_node)
		return (&return_node->value);

        return (NULL);

}

INT __sym_tab_set_sym(char *package, char *symbol, __sym_tab_type sym_type, __sym_tab_value value)
{
        __sym_tab *return_node = NULL;
        return_node = __sym_tab_get_sym(package,symbol);
        if (return_node) {
		return_node = __sym_tab_chase_symbol(return_node);
		return_node->value = value;
		return_node->value.type = sym_type;
		return SUCCESS;
	} else {
		__sym_tab_create_sym(package,symbol);
		__sym_tab_set_sym(package,symbol,sym_type,value);
	}
	return ERROR;
}

INT __sym_tab_create_sym(char *package, char *symbol)
{
	CREATE_LIST_NODE(__sym_tab, new_node)
	new_node->package = package;
	new_node->symbol = symbol;
	ADD_TO_LIST(__sym_tab, new_node)	
	return SUCCESS;	
}

__sym_tab * __sym_tab_chase_symbol(__sym_tab * symbol)
{
	if (symbol->value.type != SYM_TYPE_REF)
		return symbol;

	return __sym_tab_chase_symbol(symbol->value.u.ref_val);
}

INT __sym_tab_print_sym(char *package, char *symbol)
{
	 __sym_tab *return_node = NULL;
        return_node = __sym_tab_get_sym(package,symbol);
	if (return_node == NULL)
	{
		PRINT_DEBUG(DEBUG_INFO,"FATAL_ERROR: symbol not present");
		exit(1);
	}
	switch(return_node->value.type)
	{
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
	return 0;
}

char * __sym_tab_val_to_string(__sym_tab_value value)
{
	char *buf;
	char int_buffer[12];
	int radix;

	switch(value.type)
	{
		case SYM_TYPE_UNKNOWN:
			buf = NULL;
		break;
		case SYM_TYPE_INT:
			radix = 10;
			snprintf(int_buffer,sizeof(int_buffer),"%d",value.u.i_val);//int_buffer,radix);
			/*TODO: Remove memory leak*/
			buf = malloc(sizeof(int_buffer) +1);
			if (buf != NULL)
				strcpy(buf,int_buffer);
		break;
		case SYM_TYPE_UINT:
			buf = NULL;
		break;
		case SYM_TYPE_FLOAT:
			buf = NULL;
		break;
		case SYM_TYPE_STRING:
			//printf(" %s ",return_node->value.u.s_val);
			buf = value.u.s_val;
		break;
		case SYM_TYPE_SYMBOL:
			//printf(" %s ",return_node->value.u.s_val);
			buf = value.u.s_val;
		break;
		case SYM_TYPE_OP:
			buf = NULL;
		case SYM_TYPE_VAL:
			buf = __sym_tab_val_to_string(*(value.u.ptr_val));
			break;;
		break;
	}
	return buf;

}
INT __sym_tab_print_all_sym()
{
	__sym_tab	*next_node = NULL;

	PRINT_DEBUG(DEBUG_INFO,"\n-------------------------- PRINTING SYMBOL TABLE -----------------\n");
	GET_NEXT_FROM_LIST(__sym_tab,next_node)
	while(next_node != NULL)
	{
		PRINT_DEBUG(DEBUG_INFO,"\n %s:%s = ",next_node->package,next_node->symbol);
		__sym_tab_print_sym(next_node->package,next_node->symbol);
		GET_NEXT_FROM_LIST(__sym_tab,next_node)
	}
	PRINT_DEBUG(DEBUG_INFO,"\n------------------------------------------------------------------\n");
	return 0;
}
