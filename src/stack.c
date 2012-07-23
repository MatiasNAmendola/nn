/*    stack.c
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#include "stack.h"

STACK_N	*HEAD_STACK = NULL;
void push(CONST_VAL *val)
{
	STACK_N	*new_s_node = NULL;
	if (val == NULL)
		printf("\nFATAL_ERROR: value cannot be null in stack\n");

	new_s_node = malloc (sizeof(STACK_N));
	if (new_s_node == NULL) 
	{
		printf("\nFATAL_ERROR: malloc failed\n");
		return;
	}
	memset(new_s_node,0,sizeof(STACK_N));
	/* TODO:									       */										
	/* This is fine for now, but will have to take care once string handling is implemented*/
	new_s_node->val = *val;	

	if(HEAD_STACK == NULL)
	{
		HEAD_STACK = new_s_node;
	}
	else {
		new_s_node->next = HEAD_STACK;
		HEAD_STACK = new_s_node;	
	}
}

void pop(CONST_VAL *val)
{
	STACK_N	*temp_node = NULL;

	if (HEAD_STACK == NULL)
		return;
	if (val == NULL)
		printf ("\nFATAL_ERROR: val cannot be NULL");

	/* TODO:									       */										
	/* This is fine for now, but will have to take care once string handling is implemented*/
	*val = HEAD_STACK->val;
	temp_node = HEAD_STACK;
	HEAD_STACK = HEAD_STACK->next;
	free(temp_node);
}

void q_push(QUEUE_C *q, CONST_VAL *val)
{
	QUEUE_N	*new_q_node = NULL;
	if (val == NULL)
		printf("\nFATAL_ERROR: value cannot be null in stack\n");

	new_q_node = malloc (sizeof(QUEUE_N));
	if (new_q_node == NULL) 
	{
		printf("\nFATAL_ERROR: malloc failed\n");
		return;
	}
	memset(new_q_node,0,sizeof(QUEUE_N));
	/* TODO:									       */										
	/* This is fine for now, but will have to take care once string handling is implemented*/
	new_q_node->val = *val;	

	if(q->head == NULL)
	{
		q->head = new_q_node;
		q->tail = new_q_node;
	}
	else {
		q->tail->next = new_q_node;
		q->tail = new_q_node;	
	}

}

void q_pop(QUEUE_C *q, CONST_VAL *val)
{
	QUEUE_N	*temp_node = NULL;

	if (q->head == NULL)
		return;
	if (val == NULL)
		printf ("\nFATAL_ERROR: val cannot be NULL");

	/* TODO:									       */										
	/* This is fine for now, but will have to take care once string handling is implemented*/
	*val = q->head->val;
	temp_node = q->head;
	q->head = q->head->next;
	free(temp_node);
	if(q->head == NULL)
		q->tail = NULL;
}
