/*    support_run.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

/* This file contains the supporting functionality required by run.c */
#include "run.h"
extern unsigned int line_num;

void get_val(CONST_VAL *val, CONST_VAL **real_val)
{
	*real_val = val;

	  switch (val->type)
	  {
	  case SYM_TYPE_UNKNOWN:
	  case SYM_TYPE_MAGIC:
	  case SYM_TYPE_STRING:
	  case SYM_TYPE_OP:
	  case SYM_TYPE_ARRAY:

		  break;
	  case SYM_TYPE_INT:
	  case SYM_TYPE_UINT:
	  case SYM_TYPE_FLOAT:
		  // no change
		  break;
	  case SYM_TYPE_REF:
		  *real_val = &(val->u.ref_val->value);
		  break;
	  case SYM_TYPE_VAL:
		  do {
			  *real_val = val->u.ptr_val;
			  val = val->u.ptr_val;
		  }while (val->type == SYM_TYPE_VAL);

		  break;

	  }
}

void get_real_val (CONST_VAL *left_val, CONST_VAL *right_val,
				   CONST_VAL **real_l_val, CONST_VAL **real_r_val)
{
	*real_l_val = left_val;
	*real_r_val = right_val;

	 get_val(left_val,real_l_val);
	 get_val(right_val,real_r_val);
}

CONST_VAL add_val(CONST_VAL *left_val, CONST_VAL *right_val)
{
  
  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;
  

  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val + result_right_val->u.i_val;
    return result_val;
}

CONST_VAL sub_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val - result_right_val->u.i_val;
    return result_val;
}


CONST_VAL div_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val / result_right_val->u.i_val;
    return result_val;
}


CONST_VAL mult_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val * result_right_val->u.i_val;
    return result_val;
}


CONST_VAL l_or_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val || result_right_val->u.i_val;
    return result_val;
}


CONST_VAL l_and_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val && result_right_val->u.i_val;
    return result_val;
}

CONST_VAL i_or_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val | result_right_val->u.i_val;
    return result_val;
}

CONST_VAL i_and_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val & result_right_val->u.i_val;
    return result_val;
}


CONST_VAL ex_or_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val ^ result_right_val->u.i_val;
    return result_val;
}

CONST_VAL lt_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val < result_right_val->u.i_val;
    return result_val;
}

CONST_VAL gt_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val > result_right_val->u.i_val;
    return result_val;
}


CONST_VAL lt_eq_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val <= result_right_val->u.i_val;
    return result_val;
}

CONST_VAL gt_eq_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val >= result_right_val->u.i_val;
    return result_val;
}

CONST_VAL eq_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val == result_right_val->u.i_val;
    return result_val;
}

CONST_VAL neq_val(CONST_VAL *left_val, CONST_VAL *right_val)
{

  CONST_VAL *result_left_val = left_val;
  CONST_VAL *result_right_val = right_val;
  CONST_VAL result_val;


  get_real_val (left_val, right_val,
  				&result_left_val, &result_right_val);

	result_val.type = SYM_TYPE_INT;
    result_val.u.i_val = result_left_val->u.i_val != result_right_val->u.i_val;
    return result_val;
}
