/*    common.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UINT	unsigned int
#define INT		int
#define FLOAT	float


/*
 * common macros to maintain the stack using a linked list
 */
#define	CREATE_LIST(LL_NAME)	LL_NAME  *LL_NAME##_HEAD = NULL ; 

#define CREATE_LIST_NODE(LL_NAME, NODE_NAME)	LL_NAME *NODE_NAME = NULL; 	\
						NODE_NAME = malloc(sizeof(LL_NAME)); 				\
						if (NODE_NAME == NULL){		       					\
																			\
						}else{												\
							memset(NODE_NAME,0,sizeof(LL_NAME));			\
						}						


#define	ADD_TO_LIST(LL_NAME, NODE_NAME)		do { 					\
							if(LL_NAME##_HEAD == NULL) {			\
								LL_NAME##_HEAD = NODE_NAME;			\
							} else {								\
								NODE_NAME->next = LL_NAME##_HEAD;	\
								LL_NAME##_HEAD = NODE_NAME;			\
							}										\
						}while(0);

#define REMOVE_FROM_LIST(LL_NAME, NODE_NAME)	do {								\
							LL_NAME *parent_tmp = NULL;								\
							LL_NAME *temp = LL_NAME##_HEAD;							\
							while(temp) {											\
								if (temp == NODE_NAME)								\
									break;											\
								parent_tmp = temp;									\
								temp = (LL_NAME*)(temp->next);						\
							}														\
							if (temp == NULL)										\
								break;												\
							if (temp == LL_NAME##_HEAD) {							\
								LL_NAME##_HEAD = (LL_NAME *)(LL_NAME##_HEAD->next);	\
							}else {													\
								parent_tmp->next = temp->next;						\
							}														\
						}while(0);

#define SEARCH_FROM_LIST(LL_NAME, NODE_NAME, SEARCH_VALUE)     do {					\
									LL_NAME *temp = LL_NAME##_HEAD;					\
									while(temp) {									\
										if(LL_NAME##_compare(temp,SEARCH_VALUE)) {	\
											break;									\
										}											\
										temp = (LL_NAME*)(temp->next);				\
									}												\
									NODE_NAME = temp;								\
								}while(0);

#define DELETE_FROM_LIST(LL_NAME, DELETE_VALUE)	do {								\
								LL_NAME	*temp_node = NULL;							\
								SEARCH_FROM_LIST (LL_NAME, temp_node, DELETE_VALUE)	\
								if(temp_node != NULL) {								\
									REMOVE_FROM_LIST(LL_NAME,temp_node)				\
									LL_NAME##_delete(temp_node);					\
								}													\
						}while(0);

#define GET_NEXT_FROM_LIST(LL_NAME,NEXT_NAME)	do{				\
							if(NEXT_NAME != NULL)				\
								NEXT_NAME = (LL_NAME *)(NEXT_NAME->next);	\
							else 								\
								NEXT_NAME = (LL_NAME *)(LL_NAME##_HEAD);		\
						}while(0);

#define GET_HEAD_FROM_LIST(LL_NAME,HEAD_NAME)	HEAD_NAME = LL_NAME##_HEAD;

#define POP_FROM_LIST(LL_NAME,HEAD_NAME)	do {						\
							if (LL_NAME##_HEAD != (LL_NAME*)NULL) {				\
								HEAD_NAME = (LL_NAME *)(LL_NAME##_HEAD);				\
								LL_NAME##_HEAD = (LL_NAME *)(LL_NAME##_HEAD->next);	\
							} else {									\
								HEAD_NAME = (LL_NAME*)NULL;						\
							}											\
						}while(0);	
#endif //__COMMON_H__
