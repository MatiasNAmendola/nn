/*    run.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __RUN_H__
#define __RUN_H__

#include "nsmart.h"
#include "op.h"
#include "symbol.h"
#include "stack.h"
#include "io.h"

/*Some indescent things for workaround*/
extern __sym_tab_arg * __sym_tab_arg_tmp_HEAD;
extern __sym_tab_arg * __sym_tab_arg_tmp_TAIL;
extern __sym_tab_arg * __sym_tab_arg_HEAD;

/* COMPLEMENTARY FUNCTIONS*/

__sym_tab_arg *reset_arg_stack_symbol(__sym_tab_arg *head,CONST_OP *param);
INT _create_proc_arg_stack(UINT flag,OP *proc_op, OP *param_op);

/* END OF COMPLEMENTARY FUNCTIONS*/

#define EXEC_DEF(func_name)	OP * func_name (UINT flag, OP * in_op)

typedef OP * (* __EXEC_FUNC_PTR) (UINT flag, OP * param);

EXEC_DEF(_execute_sequence);
EXEC_DEF(_null_);
EXEC_DEF(_const_);
EXEC_DEF(_array_);
EXEC_DEF(_array_exp_);
EXEC_DEF(_add_);
EXEC_DEF(_sub_);
EXEC_DEF(_mult_);
EXEC_DEF(_div_);
EXEC_DEF(_l_or_);
EXEC_DEF(_l_and_);
EXEC_DEF(_i_or_);
EXEC_DEF(_i_and_);
EXEC_DEF(_ex_or_);
EXEC_DEF(_lt_);
EXEC_DEF(_gt_);
EXEC_DEF(_lt_eq_);
EXEC_DEF(_gt_eq_);
EXEC_DEF(_eq_);
EXEC_DEF(_neq_);
EXEC_DEF(_assign_eq_);
EXEC_DEF(_assign_add_eq_);
EXEC_DEF(_assign_sub_eq_);
EXEC_DEF(_assign_mul_eq_);
EXEC_DEF(_assign_div_eq_);
EXEC_DEF(_assign_mod_eq_);
EXEC_DEF(_simple_proc_);
EXEC_DEF(_conn_proc_);
EXEC_DEF(_node_proc_);
EXEC_DEF(_layer_proc_);
EXEC_DEF(_network_proc_);
EXEC_DEF(_if_stmt_);
EXEC_DEF(_if_else_stmt_);
EXEC_DEF(_while_stmt_);
EXEC_DEF(_proc_call_);	
EXEC_DEF(_package_);
EXEC_DEF(_io_print_);
EXEC_DEF(_io_scan_);
EXEC_DEF(_io_read_);
EXEC_DEF(_io_write_);
EXEC_DEF(_io_open_);
EXEC_DEF(_io_close_);
EXEC_DEF(_return_stmt_);

/*Supporting function definition*/
void get_val(CONST_VAL *val, CONST_VAL **real_val);
CONST_VAL add_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL sub_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL div_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL mult_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL l_or_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL l_and_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL i_or_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL i_and_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL ex_or_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL lt_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL gt_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL lt_eq_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL gt_eq_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL eq_val(CONST_VAL *left_val, CONST_VAL *right_val);
CONST_VAL neq_val(CONST_VAL *left_val, CONST_VAL *right_val);

#endif // __RUN_H__
