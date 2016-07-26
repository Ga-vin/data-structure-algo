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


#endif /* __CIRCULAR_LIST_H_ */
