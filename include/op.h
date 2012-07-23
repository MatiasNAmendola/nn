/*    op.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __OP_H__
#define __OP_H__

#include "common.h"
#include "sym_tab.h"
#include "debug.h"

#define OP	struct opcode
#define UN_OP	struct un_opcode
#define CONST_OP	struct const_opcode
#define CONST_VAL	__sym_tab_value

#define BASE_OPCODE	OP 	*next; \
			OP	*sibling; \
			OP *	(*op_func) (OP *); \
			UINT	type;

struct opcode {
	BASE_OPCODE
};

struct 	un_opcode {
	BASE_OPCODE
	OP *left;
	OP *right;
};
/*
struct const_value {
	union {
		INT     		i_val;
        	UINT    		ui_val;
	        FLOAT   		f_val;
        	char    		*s_val;
		OP			*op_val;
		struct __sym_tab__	*ref_val;
	}u;
	UINT	type;
};
*/
struct const_opcode {
	BASE_OPCODE
	CONST_VAL  	value;
};
/*
typedef enum {
	CONST_TYPE_UNKNOWN 	= 0,
	CONST_TYPE_MAGIC	= 1,
	CONST_TYPE_INT	 	= 2,
	CONST_TYPE_UINT	 	= 3,
	CONST_TYPE_FLOAT	= 4,
	CONST_TYPE_STRING  	= 5,
	CONST_TYPE_OP		= 6,
	CONST_TYPE_REF		= 7,
	CONST_TYPE_VAL	 	= 8,
	CONST_TYPE_ARRAY	= 9
} __const_type;
*/
typedef enum {
	OP_TYPE_NULL		= 0,
	OP_TYPE_CONST		= 1,
	OP_TYPE_ARRAY		= 2,    // Array type 
	OP_TYPE_ARRAY_EXP	= 3,
	OP_TYPE_ADD		= 4,	// Addition
	OP_TYPE_SUB		= 5,	// Subtraction
	OP_TYPE_MULT		= 6,	// Multiplication
	OP_TYPE_DIV		= 7,	// Division
	OP_TYPE_L_OR		= 8,	// Logical OR
	OP_TYPE_L_AND		= 9,	// Logical AND
	OP_TYPE_I_OR		= 10,	// Inclusive OR
	OP_TYPE_I_AND		= 11,	// Inclusive AND
	OP_TYPE_EX_OR		= 12,	// Exclusive OR
	OP_TYPE_LT		= 13,	// Less Then
	OP_TYPE_GT		= 14,	// Greater Then
	OP_TYPE_LT_EQ		= 15,	// Less Then Equal To
	OP_TYPE_GT_EQ		= 16,	// Greater Then Equal To
	OP_TYPE_EQ		= 17,	// Equal-To Equal-To
	OP_TYPE_NEQ		= 18,	// Not-Equal-To
	OP_TYPE_ASSIGN_EQ	= 19,	// Assignment ( =, +=, -=, *=, /= ...)
	OP_TYPE_ASSIGN_ADD_EQ	= 20,
	OP_TYPE_ASSIGN_SUB_EQ	= 21,
	OP_TYPE_ASSIGN_MUL_EQ	= 22,
	OP_TYPE_ASSIGN_DIV_EQ	= 23,
	OP_TYPE_ASSIGN_MOD_EQ	= 24,
	OP_TYPE_SIMPLE_PROC	= 25,	// Procedure definition
	OP_TYPE_CONN_PROC	= 26,	// Connection definition
	OP_TYPE_NODE_PROC	= 27,	// Node definition
	OP_TYPE_LAYER_PROC	= 28,	// Layer definition
	OP_TYPE_NETWORK_PROC	= 29,	// Network definition
	OP_TYPE_IF_STMT		= 30,	// If Statement
	OP_TYPE_IF_ELSE_STMT	= 31,	// If-Else Statement
	OP_TYPE_WHILE_STMT	= 32,	// While Statement
	OP_TYPE_PROC_CALL	= 33,	// Procedure Call
	OP_TYPE_PACKAGE		= 34,	// Package definition
	OP_TYPE_PRINT		= 35,	// IO: constant object : PRINT
	OP_TYPE_SCAN		= 36,	// IO: constant object : SCAN
	OP_TYPE_READ		= 37,	// IO: constant object : READ
	OP_TYPE_WRITE		= 38,	// IO: constant object : WRITE
	OP_TYPE_OPEN		= 39,	// IO: constant object : OPEN
	OP_TYPE_CLOSE		= 40,	// IO: constant object : CLOSE
	OP_TYPE_RETURN_STMT	= 41,	// OP for returns statement
	OP_TYPE_MAX			= 42	// MAX TYPE OF OP
} __op_type;

enum operator {
        EQUAL_TO = 0,
        PLUS_EQUAL_TO,
        MINUS_EQUAL_TO,
        MULTIPLY_EQUAL_TO,
        DIVIDE_EQUAL_TO,
        MOD_EQUAL_TO
};

/*
 *function definitions
 */
void __print_op();

char *create_const_str_value(char *literal);

OP * create_op();
OP * create_base_op();
OP * create_const_op(CONST_VAL value);
OP * create_add_op(OP* left_op, OP* right_op);
OP * create_sub_op(OP* left_op, OP* right_op);
OP * create_mult_op(OP* left_op, OP* right_op);
OP * create_div_op(OP* left_op, OP* right_op);
OP * create_logical_or_op(OP *left_op, OP *right_op);
OP * create_logical_and_op(OP *left_op, OP *right_op);
OP * create_inclusive_or_op(OP *left_op, OP *right_op);
OP * create_inclusive_and_op(OP *left_op, OP *right_op);
OP * create_exclusive_or_op(OP *left_op, OP *right_op);
OP * create_lt_op(OP *left_op, OP *right_op);
OP * create_gt_op(OP *left_op, OP *right_op);
OP * create_lt_eq_op(OP *left_op, OP *right_op);
OP * create_gt_eq_op(OP *left_op, OP *right_op);
OP * create_eq_op(OP *left_op, OP *right_op);
OP * create_neq_op(OP *left_op, OP *right_op);
OP * create_array_exp_op(OP *exp_op);
OP * create_array_exp_list_op(OP *left_op, OP *right_op);
OP * create_obj_array(OP *obj, OP *array_exp);

OP * create_assign_op (OP* object_op, UINT assign_type, OP* expression_op);
OP * create_simple_proc (OP *proc_name_op, OP *proc_param_op, OP *statement_op);
OP * create_proc_param (OP *param_left_op, OP *param_right_op);
OP * create_conn_proc (OP *conn_name_op, OP *conn_param_op, OP *statement_op);
OP * create_conn_param (OP *param1_type_op, OP *param1_op, OP *param2_type_op, OP *param2_op);
OP * create_node_proc (OP *node_name_op, OP *node_param_op, OP *statement_op);
OP * create_node_param (OP *param1_type_op, OP *param1_op, OP *param2_type_op, OP *param2_op);
OP * create_layer_proc (OP *layer_name_op, OP *layer_param_op, OP *statement_op);
OP * create_layer_param ( OP *param_op);
OP * create_network_proc (OP *net_name_op, OP *net_param_op, OP *statement_op);
OP * create_network_param_list (OP *param_list_op, OP *param_type_op, OP *param_op);
OP * create_network_param (OP *param_type_op, OP *param_op);
OP * create_param_expression_list(OP *exp_left_op, OP *exp_right_op);
OP * create_expression_op (OP *exp_left_op, OP  *exp_right_op);
OP * create_return_stmt_op(OP *exp_op);
OP * create_if_op (OP *if_exp_op, OP *statement_op);
OP * create_if_else_op (OP *if_exp, OP *if_statement_op, OP *else_statement);
OP * create_while_op (OP *while_exp, OP *statement);
OP * create_statement_list_op(OP *statement_list_op, OP *statement_op);
OP * create_proc_call(OP *proc_name_op, OP *param_op);
OP * create_const_proc_call(OP *const_proc_op, OP *param_op);
OP * create_package_op(OP *package_name_op, OP *package_parts_op);
OP * create_program_op(OP *package_list_op, OP *package_op);

/*Const object op's */
OP * create_const_object_print_op();
OP * create_const_object_scan_op();
OP * create_const_object_read_op();
OP * create_const_object_write_op();
OP * create_const_object_open_op();
OP * create_const_object_close_op();

OP * create_root_op(OP * program_op);
#endif // __OP_H__
