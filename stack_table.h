/* ************************************************************************** */
/* File Name : stack_table.h                                                  */
/* Function  : Definition of some new data type and interfaces for stack      */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.09.18                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef __STACK_TABLE_H_
#define __STACK_TABLE_H_

#include "common.h"

/* *****************************************************************************
 * Macros and some constants
 ******************************************************************************/
#define    STACK_INIT_SIZE     (100)
#define    STACK_INCREASE_STEP (10)

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
typedef INT32    StackItemType;
typedef INT32    StackSize;

typedef struct _StackTable_ {
    StackItemType    *top;
    StackItemType    *bottom;
    StackSize         stack_size;            
} StackTable;

typedef StackTable    *PStackTable;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
StackTable init_tstack(StackSize size);
STATE      destroy_tstack(PStackTable p_stack);
STATE      clear_tstack(PStackTable p_stack);
BOOL       is_empty_tstack(const PStackTable p_stack);
StackSize  get_length_tstack(const PStackTable p_stack);
STATE      get_top_tstack(const PStackTable p_stack, StackItemType *p_item);
STATE      push_tstack(PStackTable p_stack, const StackItemType item);
STATE      pop_tstack(PStackTable p_stack, StackItemType *p_item);
STATE      traverse_tstack(const PStackTable p_stack, void (*callback)(const StackItemType item));


#endif /* __STACK_TABLE_H_ */
