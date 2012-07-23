/*    op.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "op.h"

OP *HEAD_OP = NULL;
OP *TAIL_OP = NULL;

void __print_op()
{
int i=0;
OP *temp = HEAD_OP;
	while(temp != NULL) {
		i++; temp = temp->next;
	}
	PRINT_DEBUG(DEBUG_INFO,"\n---number of op's = %d ---\n",i);
}

OP * create_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s line %d\n",__FILE__,__LINE__);

	memset(op,0,sizeof(OP));
	if (HEAD_OP == NULL) {
		HEAD_OP = TAIL_OP = op;
	} else {
		TAIL_OP->next = op;
		TAIL_OP = op;
	}
	return op;
}
	
OP * create_base_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	return op;
}

OP * create_const_op(CONST_VAL value)
{
	CONST_OP *op;
	op = malloc(sizeof(CONST_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(CONST_OP));
	op->type = OP_TYPE_CONST;
	//op->const_type = const_type;
	op->value = value;
 
	return ((OP*)op);
}

OP * update_as_ref_const_op (OP *op)
{
	op->type = OP_TYPE_CONST;
	((CONST_OP*)op)->value.type = SYM_TYPE_REF;
	return (op);
}

char * create_const_str_value(char *literal)
{
	char *new_literal = NULL;

	if (literal == NULL) {
		return NULL;
	}
		
	new_literal = malloc(strlen(literal) + 1);
	if (new_literal == NULL)
	{
		printf("\nFatal error\n");
		return NULL;
	}
	memset(new_literal,0,strlen(literal)+1);
	strncpy(new_literal,literal,strlen(literal));

	return new_literal;
}

OP * create_add_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_ADD;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_sub_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_SUB;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_mult_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);
	
	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_MULT;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_div_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_DIV;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_logical_or_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_L_OR;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}
OP * create_logical_and_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_L_AND;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_inclusive_or_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_I_OR;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_inclusive_and_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_I_AND;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_exclusive_or_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_EX_OR;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_lt_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_LT;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_gt_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_GT;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);

}

OP * create_lt_eq_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_LT_EQ;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_gt_eq_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_GT_EQ;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_eq_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_EQ;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_neq_op(OP *left_op, OP *right_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_NEQ;
	op->left = left_op;
	op->right = right_op; 
	return ((OP*)op);
}

OP * create_array_exp_op(OP *exp_op)
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);
		
	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_ARRAY_EXP;
	op->next = exp_op;
	
	return((OP*)op);
}

OP * create_array_exp_list_op(OP *left_op, OP *right_op)
{
	OP *tmp_sib = left_op;
	while (tmp_sib->sibling)
		tmp_sib = tmp_sib->sibling;

	tmp_sib->sibling = right_op;
	return (left_op);

}

OP * create_obj_array(OP *obj, OP *array_exp)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);
		
	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_ARRAY;
	op->left = obj;
	op->sibling = array_exp;
	
	return((OP*)op);
}

OP * create_assign_op (OP* object_op, UINT assign_type, OP* expression_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);
		
	memset (op,0,sizeof(UN_OP));
	switch (assign_type)
	{
		case EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_EQ;
		break;
		case PLUS_EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_ADD_EQ;
		break;
		case MINUS_EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_SUB_EQ;
		break;
		case MULTIPLY_EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_MUL_EQ;
		break;
		case DIVIDE_EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_DIV_EQ;
		break;
		case MOD_EQUAL_TO:
			op->type = OP_TYPE_ASSIGN_MOD_EQ;
		break;
		default:
			op->type = OP_TYPE_ASSIGN_EQ;
		break;
	}
	op->left = object_op;
	op->right = expression_op; 
	return ((OP*)op);
}

OP * create_simple_proc (OP *proc_name_op, OP *proc_param_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_SIMPLE_PROC;
	op->left = proc_name_op;
	op->sibling = proc_param_op;
	op->right = statement_op; 
	return ((OP*)op);

}

OP * create_proc_param (OP *param_left_op, OP *param_right_op)
{
	OP *tmp_sib = param_left_op;
	while (tmp_sib->sibling)
		tmp_sib = tmp_sib->sibling;

	tmp_sib->sibling = param_right_op;
	return (param_left_op);
}

OP * create_conn_proc (OP *conn_name_op, OP *conn_param_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_CONN_PROC;
	op->left = conn_name_op;
	op->sibling = conn_param_op;
	op->right = statement_op; 
	return ((OP*)op);
}
OP * create_conn_param (OP *param1_type_op, OP *param1_op, OP *param2_type_op, OP *param2_op)
{
	param1_type_op->next = param1_op;
	param2_type_op->next = param2_op;
	param1_type_op->sibling = param2_type_op;
	return ((OP*)param1_type_op);
}
OP * create_node_proc (OP *node_name_op, OP *node_param_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_NODE_PROC;
	op->left = node_name_op;
	op->sibling = node_param_op;
	op->right = statement_op; 
	return ((OP*)op);

}
OP * create_node_param (OP *param1_type_op, OP *param1_op, OP *param2_type_op, OP *param2_op)
{
	param1_type_op->next = param1_op;
	param2_type_op->next = param2_op;
	param1_type_op->sibling = param2_type_op;
	return ((OP*)param1_type_op);
}
OP * create_layer_proc (OP *layer_name_op, OP *layer_param_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_LAYER_PROC;
	op->left = layer_name_op;
	op->sibling = layer_param_op;
	op->right = statement_op; 
	return ((OP*)op);
}
OP * create_layer_param ( OP *param_op)
{
	return ((OP*)param_op);
}
OP * create_network_proc (OP *net_name_op, OP *net_param_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_NETWORK_PROC;
	op->left = net_name_op;
	op->sibling = net_param_op;
	op->right = statement_op; 
	return ((OP*)op);

}

OP * create_network_param_list (OP *param_list_op, OP *param_type_op, OP *param_op)
{
	param_type_op->next = param_op;
	param_list_op->sibling = param_type_op;
	return ((OP*)param_list_op);
}

OP * create_network_param (OP *param_type_op, OP *param_op)
{
	param_type_op->next = param_op;
	return ((OP*)param_type_op);
}

OP * create_param_expression_list(OP *exp_left_op, OP *exp_right_op)
{
	OP *tmp_sib = exp_left_op;
	while (tmp_sib->sibling)
		tmp_sib = tmp_sib->sibling;

	tmp_sib->sibling = exp_right_op;
	return (exp_left_op);
}

OP * create_expression_op (OP *exp_left_op, OP  *exp_right_op)
{
	OP *tmp_op = exp_left_op;
	while (tmp_op->next)
		tmp_op = tmp_op->next;

	tmp_op->next = exp_right_op;
	return ((OP*)exp_left_op);
}
OP * create_return_stmt_op(OP *exp_op)
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_RETURN_STMT;
	op->sibling = exp_op;
	return ((OP*)op);
}
OP * create_if_op (OP *if_exp_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_IF_STMT;
	op->sibling = if_exp_op;
	op->right = statement_op; 
	return ((OP*)op);
}

OP * create_if_else_op (OP *if_exp_op, OP *if_statement_op, OP *else_statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_IF_ELSE_STMT;
	op->sibling = if_exp_op;
	op->right = if_statement_op; 
	op->left = else_statement_op;
	return ((OP*)op);
}

OP * create_while_op (OP *while_exp_op, OP *statement_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_WHILE_STMT;
	op->sibling = while_exp_op;
	op->right = statement_op; 
	return ((OP*)op);

}

OP * create_statement_list_op(OP *statement_list_op, OP *statement_op)
{
	OP *temp_op = statement_list_op;

	while (temp_op->next != NULL)
		temp_op = temp_op->next;
	
	temp_op->next = statement_op;
	return ((OP*)statement_list_op);
}

OP * create_proc_call(OP *proc_name_op, OP *param_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_PROC_CALL;
	op->left = proc_name_op;
	op->sibling = param_op;
	return ((OP*)op);

}

OP * create_const_proc_call(OP *const_proc_op, OP *param_op)
{
	const_proc_op->sibling = param_op;
	return (const_proc_op);
}
OP * create_package_op(OP *package_name_op, OP *package_parts_op)
{
	UN_OP *op;
	op = malloc(sizeof(UN_OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(UN_OP));
	op->type = OP_TYPE_PACKAGE;
	op->left = package_name_op;
	op->right = package_parts_op; 
	return ((OP*)op);

}

OP * create_program_op(OP *package_list_op, OP *package_op)
{
	OP *temp_op = package_list_op;

	while (temp_op->next != NULL)
		temp_op = temp_op->next;
	
	temp_op->next = package_op;
	return ((OP*)package_list_op);
}

OP * create_const_object_print_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_PRINT;
	return ((OP*)op);
}

OP * create_const_object_scan_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_SCAN;
	return ((OP*)op);
}

OP * create_const_object_read_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_READ;
	return ((OP*)op);
}

OP * create_const_object_write_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_WRITE;
	return ((OP*)op);
}

OP * create_const_object_open_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_OPEN;
	return ((OP*)op);
}

OP * create_const_object_close_op()
{
	OP *op;
	op = malloc(sizeof(OP));
	if (!op)
		PRINT_DEBUG(DEBUG_ERROR,"\nMalloc failure: file %s, line %d\n",__FILE__,__LINE__);

	memset (op,0,sizeof(OP));
	op->type = OP_TYPE_CLOSE;
	return ((OP*)op);
}

OP * create_root_op(OP * program_op)
{
	HEAD_OP = program_op;	
	return ((OP*) HEAD_OP);
}
