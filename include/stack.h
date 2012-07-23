/*    stack.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "common.h"
#include "op.h"

#define STACK_N		struct _stack_node
struct _stack_node {
	CONST_VAL	val;
	STACK_N	*next;
};


void push(CONST_VAL *val);
void pop(CONST_VAL *val);


/* queue definition */
#define QUEUE_N	struct _queue_node
struct _queue_node {
	CONST_VAL	val;
	QUEUE_N		*next;
};
#define QUEUE_C	struct _queue_container
struct _queue_container {
	QUEUE_N	*head;
	QUEUE_N *tail;
};
void q_push(QUEUE_C *q, CONST_VAL *val);
void q_pop(QUEUE_C *q, CONST_VAL *val);
#endif // __STACK_H__
