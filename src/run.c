/*    run.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "run.h"

__EXEC_FUNC_PTR exec_func [] = {

	_null_,
	_const_,
	_array_,
	_array_exp_,
	_add_,
	_sub_,
	_mult_,
	_div_,
	_l_or_,
	_l_and_,
	_i_or_,
	_i_and_,
	_ex_or_,
	_lt_,
	_gt_,
	_lt_eq_,
	_gt_eq_,
	_eq_,
	_neq_,
	_assign_eq_,
	_assign_add_eq_,
	_assign_sub_eq_,
	_assign_mul_eq_,
	_assign_div_eq_,
	_assign_mod_eq_,
	_simple_proc_,
	_conn_proc_,
	_node_proc_,
	_layer_proc_,
	_network_proc_,
	_if_stmt_,
	_if_else_stmt_,
	_while_stmt_,
	_proc_call_,
	_package_,
	_io_print_,
	_io_scan_,
	_io_read_,
	_io_write_,
	_io_open_,
	_io_close_,
	_return_stmt_
};

/*Required Globals */
extern OP * HEAD_OP;
#define GLOBAL_PACKAGE "__GLOBAL_PACKAGE__";
char *CURR_PACKAGE = GLOBAL_PACKAGE;
OP NULL_OP;
OP *PTR_NULL_OP = NULL;

set_null_op()
{
	NULL_OP.next = NULL;
	NULL_OP.type = OP_TYPE_NULL;
	NULL_OP.op_func = NULL;
	NULL_OP.sibling = NULL;
	PTR_NULL_OP = &NULL_OP;
}

INT __execute_nsmart_root()
{
	if (HEAD_OP == NULL) 
	{
		return 1;
	}
	_execute_sequence(CALL_GLOB, HEAD_OP);
	//delete_sym(GLOB_CALL);
	return 0;
}

EXEC_DEF(_execute_sequence)
{
	OP *temp = in_op;
	while (temp)
	{
		temp = exec_func[temp->type](flag,temp);
		if (temp && temp->type == OP_TYPE_CONST)
			break;	
	}
}
EXEC_DEF(_null_)
{
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _null_");
	return ((OP*)in_op->next);
}
EXEC_DEF(_const_)
{
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _const_");
	__sym_tab *sym_val = NULL;
	CONST_VAL val; 
	memset(&val,0,sizeof(CONST_VAL));

	switch (((CONST_OP*)in_op)->value.type)
	{
		case SYM_TYPE_INT:
			PRINT_DEBUG(DEBUG_INFO,"  value: %d",((CONST_OP*)in_op)->value.u.i_val);
		    push(&((CONST_OP*)in_op)->value);
		break;
		case SYM_TYPE_UINT:
			PRINT_DEBUG(DEBUG_INFO,"  value: %d",((CONST_OP*)in_op)->value.u.ui_val);
		    push(&((CONST_OP*)in_op)->value);
		break;
		case SYM_TYPE_FLOAT:
			PRINT_DEBUG(DEBUG_INFO,"  value: %f",((CONST_OP*)in_op)->value.u.f_val);
		    push(&((CONST_OP*)in_op)->value);
		break;
		case SYM_TYPE_STRING:
			PRINT_DEBUG(DEBUG_INFO," value: %s",((CONST_OP*)in_op)->value.u.s_val);
			push(&((CONST_OP*)in_op)->value);
		break;
		case SYM_TYPE_SYMBOL:
			/**/
			sym_val = get_sym(flag,CURR_PACKAGE,((CONST_OP*)in_op)->value.u.s_val);
			if (sym_val == NULL) {
				set_sym(flag,CURR_PACKAGE,((CONST_OP*)in_op)->value.u.s_val,SYM_TYPE_UNKNOWN,val);
				sym_val = get_sym(flag,CURR_PACKAGE,((CONST_OP*)in_op)->value.u.s_val);
			}
			PRINT_DEBUG(DEBUG_INFO,"  value: %s",((CONST_OP*)in_op)->value.u.s_val);
		    if ((sym_val->value.type == SYM_TYPE_VAL) ||
		    		(sym_val->value.type == SYM_TYPE_REF)) {
		    	val = sym_val->value;
		    } else {
		    	val.type = SYM_TYPE_VAL;
		    	val.u.ptr_val = &(sym_val->value);
		    }
		    push(&val);
		break;
		case SYM_TYPE_REF:
		    sym_val = get_sym(flag,CURR_PACKAGE,((CONST_OP*)in_op)->value.u.s_val);
		    PRINT_DEBUG(DEBUG_INFO,"  value: & %s",((CONST_OP*)in_op)->value.u.s_val);
		    val.type = SYM_TYPE_REF;
		    val.u.ref_val = sym_val;
		    push(&val);
		break; 
	}	
	return (in_op);
}
EXEC_DEF(_array_)
{
	

	OP *left_op = NULL;
	OP *sib_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;
	QUEUE_C	q;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _array_");
	// setting queue;
	q.head = q.tail = NULL;

	//TODO:	get the object from the left node
	left_op = ((UN_OP*)in_op)->left;
	sib_op  = in_op->sibling;
	// go to the symbol table for the object
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: array symbol %s not defined\n",((CONST_OP*)left_op)->value.u.s_val);
	} else {
		if (sym->value.type != SYM_TYPE_ARRAY)
			PRINT_DEBUG(DEBUG_ERROR,"\nERROR: array symbol %s not defined\n",((CONST_OP*)left_op)->value.u.s_val);

		//TODO: calculate all the expression list from the sibling
		// and put it in the array queue
		while(sib_op) {
			_execute_sequence(flag,sib_op);
			//TODO: pop the value and put in the queue for array-exp-value
			pop(&val);
			q_push(&q,&val);
			sib_op = sib_op->sibling;
		}
		// TODO:extract the expression value from the array queue one by one
		// and go to the location (create if not already present)
		
		
	}
	return(in_op->next);

		
}
EXEC_DEF(_array_exp_)
{
	//TODO: calculate all the expression list from the next_list
	_execute_sequence(flag,in_op->next);
}

EXEC_DEF(_add_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _add_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);
	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val + right_val.u.i_val;
	val = add_val(&left_val,&right_val);
	push(&val);
	return(in_op->next);
}
EXEC_DEF(_sub_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _sub_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);
	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val - right_val.u.i_val;
	val = sub_val(&left_val,&right_val);
	push(&val);
	return(in_op->next);

}
EXEC_DEF(_mult_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _mult_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val * right_val.u.i_val;
	val = mult_val(&left_val,&right_val);
	push(&val);
	return(in_op->next);

}
EXEC_DEF(_div_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _div_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val / right_val.u.i_val;
	val = div_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}
EXEC_DEF(_l_or_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _l_or_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val || right_val.u.i_val;
	val = l_or_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_l_and_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _l_and_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val && right_val.u.i_val;
	val = l_and_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_i_or_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _i_or_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val | right_val.u.i_val;
	val = i_or_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_i_and_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _i_and_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val & right_val.u.i_val;
	val = i_and_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_ex_or_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _ex_or_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val ^ right_val.u.i_val;
	val = ex_or_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_lt_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _lt_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val < right_val.u.i_val;
	val = lt_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_gt_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _gt_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val > right_val.u.i_val;
	val = gt_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_lt_eq_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _lt_eq_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val <= right_val.u.i_val;
	val = lt_eq_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_gt_eq_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _gt_eq_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val >= right_val.u.i_val;
	val = gt_eq_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}
EXEC_DEF(_eq_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _eq_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val == right_val.u.i_val;
	val = eq_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_neq_)
{
	CONST_VAL val,left_val,right_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _neq_");
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	/*pop left get the value, if string get value from */
	pop(&right_val);
	pop(&left_val);

	//val.type = right_val.type;
	//val.u.i_val = left_val.u.i_val != right_val.u.i_val;
	val = neq_val(&left_val,&right_val);
	push(&val);

	return(in_op->next);

}

EXEC_DEF(_assign_eq_)
{
	OP *left_op = NULL;
	CONST_VAL left_val, right_val;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->left);
	pop(&left_val);
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	pop(&right_val);

	set_value(&left_val,&right_val);
	//set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	return(in_op->next);

}
EXEC_DEF(_assign_add_eq_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_add_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	pop(&val);
	if (sym == NULL) {
		sym_val.u.i_val = val.u.i_val;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	} else {
		sym->value.u.i_val += val.u.i_val;
	}
	return(in_op->next);

}
EXEC_DEF(_assign_sub_eq_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_sub_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	pop(&val);
	if (sym == NULL) {
		sym_val.u.i_val = val.u.i_val;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	} else {		
		sym->value.u.i_val -= val.u.i_val;
	}
	return(in_op->next);

}
EXEC_DEF(_assign_mul_eq_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_mul_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	pop(&val);
	if (sym == NULL) {
		sym_val.u.i_val = val.u.i_val;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	} else {		
		sym->value.u.i_val *= val.u.i_val;
	}
	return(in_op->next);

}
EXEC_DEF(_assign_div_eq_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_div_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	pop(&val);
	if (sym == NULL) {
		sym_val.u.i_val = val.u.i_val;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	} else {		
		sym->value.u.i_val /= val.u.i_val;
	}
	return(in_op->next);


}
EXEC_DEF(_assign_mod_eq_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_mod_eq_");
	left_op = ((UN_OP*)in_op)->left;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	pop(&val);
	if (sym == NULL) {
		sym_val.u.i_val = val.u.i_val;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,val.type,sym_val);
	} else {		
		sym->value.u.i_val %= val.u.i_val;
	}
	return(in_op->next);



}

EXEC_DEF(_simple_proc_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _simple_proc_");
	left_op = ((UN_OP*)in_op)->left;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		sym_val.u.op_val = in_op;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,SYM_TYPE_OP,sym_val);
	} else {	
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Redeclaration of procedure %s\n",sym->symbol);
	}
	return(in_op->next);

}
EXEC_DEF(_conn_proc_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _conn_proc_");
	left_op = ((UN_OP*)in_op)->left;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		sym_val.u.op_val = in_op;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,SYM_TYPE_OP,sym_val);
	} else {	
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Redeclaration of CONNECTION %s\n",sym->symbol);
	}
	return(in_op->next);

}
EXEC_DEF(_node_proc_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _node_proc_");
	left_op = ((UN_OP*)in_op)->left;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		sym_val.u.op_val = in_op;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,SYM_TYPE_OP,sym_val);
	} else {	
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Redeclaration of NODE %s\n",sym->symbol);
	}
	return(in_op->next);

}
EXEC_DEF(_layer_proc_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _layer_proc_");
	left_op = ((UN_OP*)in_op)->left;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		sym_val.u.op_val = in_op;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,SYM_TYPE_OP,sym_val);
	} else {	
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Redeclaration of LAYER %s\n",sym->symbol);
	}
	return(in_op->next);
}

EXEC_DEF(_network_proc_)
{
	OP *left_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _network_proc_");
	left_op = ((UN_OP*)in_op)->left;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		sym_val.u.op_val = in_op;
		set_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val,SYM_TYPE_OP,sym_val);
	} else {	
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Redeclaration of NETWORK %s\n",sym->symbol);
	}
	return(in_op->next);
}

EXEC_DEF(_if_stmt_)
{
	CONST_VAL val,sib_val,*real_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _if_stmt_");
	/*execute the expression in the grammer " IF '(' EXPRESSION ')' STATEMENT*/
	_execute_sequence(flag,((UN_OP*)in_op)->sibling);
	pop(&sib_val);
	get_val(&sib_val,&real_val);
	/*if the expression results in true thene execute the STATEMENT*/
	if (real_val->u.i_val)
		_execute_sequence(flag,((UN_OP*)in_op)->right);

	/*TODO:pop all to remove stale push */
	//pop_all();

	return(in_op->next);
}

EXEC_DEF(_if_else_stmt_)
{
	CONST_VAL val,sib_val,*real_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _if_else_stmt_");
	/*execute the expression in the grammar " IF '(' EXPRESSION ')' STATEMENT ELSE STATEMENT*/
	_execute_sequence(flag,((UN_OP*)in_op)->sibling);
	pop(&sib_val);
	get_val(&sib_val,&real_val);
	/*if the expression results in true then execute the STATEMENT*/
	if (real_val->u.i_val)
		_execute_sequence(flag,((UN_OP*)in_op)->right);
	else 
		_execute_sequence(flag,((UN_OP*)in_op)->left);
	
	/*TODO:pop all to remove stale push */
	//pop_all();

	return(in_op->next);
}
EXEC_DEF(_while_stmt_)
{
	CONST_VAL val,sib_val,*real_val;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _if_stmt_");
	/*execute the expression in the grammar " WHILE '(' EXPRESSION ')' STATEMENT*/
	_execute_sequence(flag,((UN_OP*)in_op)->sibling);
	pop(&sib_val);
	get_val(&sib_val,&real_val);
	/*if the expression results in true then execute the STATEMENT*/
	while(real_val->u.i_val)
	{
		_execute_sequence(flag,((UN_OP*)in_op)->right);
		/*TODO:pop all to remove stale push */
		//pop_all();
		_execute_sequence(flag,((UN_OP*)in_op)->sibling);
		pop(&sib_val);
	}
	/*TODO:pop all to remove stale push */
	//pop_all();

	return(in_op->next);

}
EXEC_DEF(_proc_call_)
{
	/*TODO: implement the stack based procedure call process
		only simple procedure call is considered now.
		also implement the variable scoping for procedures	
	*/
	OP *left_op = NULL;
	OP *sib_op = NULL;
	CONST_VAL val;
	__sym_tab *sym = NULL;
	__sym_tab_value sym_val;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _proc_call_");
	left_op = ((UN_OP*)in_op)->left;
	sib_op  = in_op->sibling;
	sym = get_sym(flag,CURR_PACKAGE,((CONST_OP*)left_op)->value.u.s_val);
	if (sym == NULL) {
		PRINT_DEBUG(DEBUG_ERROR,"\nERROR: Procedure %s not defined\n",((CONST_OP*)left_op)->value.u.s_val);
	} else {
		if (sym->value.type != SYM_TYPE_OP)
			printf("\nERROR: Procedure %s not defined\n",((CONST_OP*)left_op)->value.u.s_val);
		/*Create the stack for procedure call*/
		_create_proc_arg_stack(flag,sym->value.u.op_val,sib_op);
		_execute_sequence(CALL_PROC,((UN_OP*)(sym->value.u.op_val))->right);
		__sym_tab_arg_print_all_sym();
		delete_sym(CALL_PROC);
	}
	return(in_op->next);

}	
INT _create_proc_arg_stack(UINT flag, OP *proc_op,OP *param_op)
{
	OP *tmp_param = param_op;
	__sym_tab_arg *head = NULL;
	CONST_VAL val;
 	__sym_tab_value arg_val;
	__sym_tab_type  arg_type;
	
	//head = __sym_tab_arg_push_magic();
	head = __sym_tab_arg_tmp_push_magic();
	while(tmp_param) {
		_execute_sequence(flag, tmp_param);
		pop(&val);
		// TODO: use appropriate type
		if (val.type == SYM_TYPE_VAL) {
				arg_val = *(val.u.ptr_val);
				arg_type = val.u.ptr_val->type;
		} else {
			arg_val = val;
			arg_type = val.type;
		}
		//head = __sym_tab_arg_push_val(arg_type,arg_val);
		head = __sym_tab_arg_tmp_push_val(arg_type,arg_val);
		tmp_param = tmp_param->sibling;
	}
	reset_arg_stack_symbol(head,(CONST_OP *)proc_op->sibling);
	__sym_tab_arg_tmp_TAIL->next = (__sym_tab *)__sym_tab_arg_HEAD;
	__sym_tab_arg_HEAD = __sym_tab_arg_tmp_HEAD;
	__sym_tab_arg_tmp_clear();	
}
__sym_tab_arg *reset_arg_stack_symbol(__sym_tab_arg *head,CONST_OP *param)
{
	if ((head == NULL) || (head->value.type == SYM_TYPE_MAGIC))
		return head;

	if (param && param->sibling) {
		head = reset_arg_stack_symbol(head,(CONST_OP *)param->sibling);
	} 

	if (param) {
		__sym_tab_arg_set_sym_name(head,param->value.u.s_val);
	}
	
	return ((__sym_tab_arg *)(head->next));
}

EXEC_DEF(_package_)
{
	OP *left_op = NULL;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _assign_package_eq_");
	left_op = ((UN_OP*)in_op)->left;
	CURR_PACKAGE = ((CONST_OP*)left_op)->value.u.s_val;
	_execute_sequence(flag,((UN_OP*)in_op)->right);
	CURR_PACKAGE = GLOBAL_PACKAGE;
	return(in_op->next);

}

EXEC_DEF(_io_print_)
{
	CONST_VAL val;
	OP *sib_op = NULL;
	sib_op  = in_op->sibling;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_print_");

	while (sib_op)
	{
		_execute_sequence(flag,sib_op);
		pop(&val);
		DO_IO(print,val);
		sib_op = sib_op->sibling;
	}
	return (in_op->next);
}

EXEC_DEF(_io_scan_)
{
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_scan_");
	PRINT_DEBUG(DEBUG_INFO," : NOT IMPLEMENTED YET");
	return (in_op->next);
}

EXEC_DEF(_io_read_)
{
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_read_");
	PRINT_DEBUG(DEBUG_INFO," : NOT IMPLEMENTED YET");
	return (in_op->next);
}

EXEC_DEF(_io_write_)
{

	CONST_VAL fd, val;
	OP *sib_op = NULL;
	sib_op  = in_op->sibling;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_write_");
	_execute_sequence(flag,sib_op);
	pop(&fd);
	sib_op = sib_op->sibling;
	_execute_sequence(flag,sib_op);
	pop(&val);
	DO_IO_write(fd,val);
	return (in_op->next);
}

EXEC_DEF(_io_open_)
{
	CONST_VAL val,retval,mode;
	OP *sib_op = NULL;
	sib_op  = in_op->sibling;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_open_");



	_execute_sequence(flag,sib_op);
	pop(&val);
	sib_op = sib_op->sibling;
	_execute_sequence(flag,sib_op);
	pop(&mode);
	//DO_IO(open,val);
	DO_IO_open(&retval,val,mode);
	push(&retval);

	return (in_op->next);
}

EXEC_DEF(_io_close_)
{
	CONST_VAL val;
	OP *sib_op = NULL;
	sib_op  = in_op->sibling;

	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _io_close_");

	_execute_sequence(flag,sib_op);
	pop(&val);

	//DO_IO(close,val);
	DO_IO_close(val);

	return (in_op->next);
}

EXEC_DEF(_return_stmt_)
{
	OP *sib_op = NULL;

	sib_op  = in_op->sibling;
	PRINT_DEBUG(DEBUG_INFO,"\nexecuting _return_stmt_");
	/*TODO: execute the return expression
	 * put the return from the expression on top of the code stack
	 * and then terminate the current context
	 * */
	if (sib_op != NULL)
		_execute_sequence(flag,sib_op);

	/*Returning the NULL OP, since we want to get out of the scope*/
	return (PTR_NULL_OP);
}
