/* ************************************************************************** */
/* File Name : stack_link.h                                                   */
/* Function  : Definition of some new data type and interfaces for stack      */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.09.21                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef __STACK_LINK_H_
#define __STACK_LINK_H_

#include "common.h"

/* *****************************************************************************
 * Macros and some constants
 ******************************************************************************/
#define    STACK_LINK_EMPTY    (0)
#define    STACK_LINK_NULL     (NULL)

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
typedef    INT32    StackValueType;
/* typedef    INT32     StackSize; */

typedef struct _StackLink_ {
    StackValueType      item;
    struct _StackLink_ *next;
} StackLink;

typedef StackLink*    PStackLink;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
PStackLink init_lstack(void);
STATE      destroy_lstack(PStackLink p_stack);
STATE      clear_lstack(PStackLink p_stack);
BOOL       is_empty_lstack(const PStackLink p_stack);
INT32      get_length_lstack(const PStackLink p_stack);
STATE      get_top_lstack(const PStackLink p_stack, StackValueType *p_item);
STATE      push_lstack(PStackLink p_stack, StackValueType item);
STATE      pop_lstack(PStackLink p_stack, StackValueType *p_item);
STATE      traverse_lstack(const PStackLink p_stack, void (*callback)(StackValueType item));

#endif /* __STACK_LINK_H_ */




