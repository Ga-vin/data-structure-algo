/* ************************************************************************** */
/* File Name : application.h                                                  */
/* Function  : Definition of some new data type and interfaces for application*/
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.09.28                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "common.h"

/* *****************************************************************************
 * Macros and some constants
 ******************************************************************************/
#define    STACK_FAIL_NUM    (-1)

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
typedef    INT32       StackItemType;
typedef    UINT32      StackBaseSystem;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
StackItemType convert_10_to_any_system(const StackItemType item, StackBaseSystem base);
void T_convert_10_to_any_system(void);

#endif /* __APPLICATION_H_ */
