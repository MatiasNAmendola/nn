/*    debug.h
 *
 *    Copyright (C) 2011, 2012 by Suhel Momin
 *
 *    You may distribute under the terms of the GNU General Public
 *    License as specified in the README file.
 *
 */

#ifndef __DEBUG_H__

extern uint	CURRENT_DEBUG_CODE;

#define DEBUG_NONE		0
#define DEBUG_VERBOSE	1  //  (0x1)
#define	DEBUG_INFO		2  //  (0x1 << 1)
#define DEBUG_WARNING	4  //  (0x1 << 2)
#define DEBUG_ERROR		8  //  (0x1 << 3)
/*TODO:Add More Debug Codes Here, before DEBUG_ALL when Applicable*/
#define DEBUG_ALL	(0xFFFFFFFF)   //  (0xFFFFFFFF)

#define PRINT_DEBUG(debug_code, args...) 							\
						do {									\
							if(CURRENT_DEBUG_CODE & debug_code)	\
							printf(args);				\
						}while(0);

#endif //__DEBUG_H__
