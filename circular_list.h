/* ************************************************************************** */
/* File Name : circular_list.h                                                */
/* Function  : Definition of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.07.24                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef __CIRCULAR_LIST_H_
#define __CIRCULAR_LIST_H_

#include "common.h"

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
#define    CIRCULE_LIST_PRIM_DATA    (0xFFFFFFFF)
typedef enum __C_INSERT_POS {
    INS_HEADER    = 0x1,
    INS_TAIL      = 0x2,
} CInsertPos;

typedef enum __C_RETRIEVE_DIR {
    RET_FORWARD   = 0x1,
    RET_BACKWARD  = 0x2,
} CRetrieveDir;

/* *****************************************************************************
 * New definition of new structure
 ******************************************************************************/
typedef struct __CIRCULAR_LNODE {
    ElemType                    data;
    struct __CIRCULAR_LNODE    *p_next;
    struct __CIRCULAR_LNODE    *p_prior;
} CircularLNode;

typedef CircularLNode    *PtrCNode;
typedef CircularLNode    *CircularList;
typedef CircularLNode    *Position;

typedef struct _CIRCU_LIST {
    CircularList         *p_header;
    CircularList         *p_tail;
    UINT32                size;
} CircuList;

typedef CircuList        *PtrCircuList;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
PtrCNode createNodeCList(void);
STATE    destroyCList(CircularList p_list);
STATE    clearCList(CircularList p_list);
UINT32   getLengthCList(const CircularList p_list);
BOOL     isEmptyCList(const CircularList p_list);
STATE    getItemByIndexCList(const CircularList p_list, UINT32 index, ElemType *p_item);
STATE    locateItemCList(const CircularList p_list, ElemType item, BOOL (*compare)(ElemType left, ElemType right));
STATE    getPriorItemCList(const CircularList p_list, ElemType curr_item, ElemType *p_prior_item);
STATE    getNextItemCList(const CircularList p_list, ElemType curr_item, ElemType *p_next_item);
PtrCNode getItemPtrCList(const CircularList p_list, UINT32 index);
STATE    insertItemByIndexCList(CircularList p_list, UINT32 index, ElemType item);
STATE    insertItemHeaderCList(CircularList p_list, ElemType item);
STATE    insertItemTailCList(CircularList p_list, ElemType item);
STATE    deleteItemByIndexCList(CircularList p_list, UINT32 index, ElemType *p_item);
STATE    deleteItemHeaderCList(CircularList p_list, ElemType *p_item);
STATE    deleteItemTailCList(CircularList p_list, ElemType *p_item);
STATE    traverseForwardCList(const CircularList p_list, void (*visit)(ElemType item));
STATE    traverseBackwardCList(const CircularList p_list, void (*visit)(ElemType item));

#endif /* __CIRCULAR_LIST_H_ */
