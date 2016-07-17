/* ************************************************************************** */
/* File Name : double_list.h                                                         */
/* Function  : Definition of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.06.27                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef __DOUBLE_LIST_H_
#define __DOUBLE_LIST_H_

#include "common.h"

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
void (*p_func)(ElemType item);

/* *****************************************************************************
 * New definition of new structure
 ******************************************************************************/
typedef struct __DOUBLE_LNODE {
    ElemType                item;
    struct __DOUBLE_LNODE  *next;
    struct __DOUBLE_LNODE  *prior;
} DoubleLNode;

typedef DoubleLNode    *PtrDNode;
typedef DoubleLNode    *DoubleList;
typedef PtrDNode        Position;

typedef enum __INSERT_POS {
    INS_HEADER    = 0x1,
    INS_TAIL      = 0x2,
} InsertPos;

typedef enum __RETRIEVE_DIR {
    RET_FORWARD   = 0x1,
    RET_BACKWARD  = 0x2,
} RetrieveDir;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
void          _printItem(ElemType item);
DoubleList    createNodeDoubleList(void);
STATE         destroyDoubleList(DoubleList p_header);
STATE         clearDoubleList(DoubleList p_header);

BOOL          isEmptyDoubleList(const DoubleList p_header);
BOOL          isLastDoubleList(const DoubleList p_header, const Position p_item);

UINT32        getLengthDoubleList(const DoubleList p_header);
STATE         getIndexByItemDoubleList(const DoubleList p_header, ElemType item, UINT32 *p_index);
STATE         getItemByIndexDoubleList(const DoubleList p_header, UINT32 index, ElemType *p_item);
Position      findItemDoubleList(const DoubleList p_header, ElemType item);

STATE         deleteItemHeaderDoubleList(DoubleList p_header, ElemType *p_item);
STATE         deleteItemTailDoubleList(DoubleList p_header, ElemType *p_item);
STATE         deleteItemDoubleList(DoubleList p_header, ElemType item);
STATE         deleteItemByIndexDoubleList(DoubleList p_header, UINT32 index, ElemType *p_item);

STATE         insertItemHeaderDoubleList(DoubleList p_header, ElemType item);
STATE         insertItemTailDoubleList(DoubleList p_header, ElemType item);
STATE         insertItemDoubleList(DoubleList p_header, ElemType item, InsertPos position);
STATE         insertItemByIndexDoubleList(DoubleList p_header, UINT32 index, ElemType item);

Position      getLastDoubleList(const DoubleList p_header);
STATE         retrieveDoubleList(const DoubleList p_header, void (*p_func)(ElemType item), RetrieveDir direct);
STATE         sortDoubleList(DoubleList p_header, SortOrder order);
STATE         mergeDoubleList(DoubleList p_list_a,
                              DoubleList p_list_b,
                              DoubleList p_list_c);

#endif /* __DOUBLE_LIST_H_ */
