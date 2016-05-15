/* ************************************************************************** */
/* File Name : list.h                                                         */
/* Function  : Definition of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.05.15                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef    __EXT_LIST_H_
#define    __EXT_LIST_H_

#include "common.h"

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/

/* *****************************************************************************
 * New definition of new structure
 ******************************************************************************/
typedef struct LNODE {
    ElemType         item;
    struct LNODE    *p_next;
}LNode;

typedef LNode     *PtrToNode;
typedef PtrToNode  List;
typedef PtrToNode  Position;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
List createList(void);
BOOL destroyList(List p_list);
BOOL clearList(List p_list);
BOOL isEmptyList(const List p_list);
BOOL isLastList(const List p_list);


#endif /* __EXT_LIST_H_ */
