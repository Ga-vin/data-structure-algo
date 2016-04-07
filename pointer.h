/* ************************************************************* */
/* File Name : pointer.h                                         */
/* Function  : Definition of some new data type and interfaces   */
/* Author    : Gavin.Bai                                         */
/* Time      : 2016.04.04                                        */
/* Version   : (C) v1.0                                          */
/* Modified  :                                                   */
/* ************************************************************* */
#ifndef    __EX_POINTER_H_
#define    __EX_POINTER_H_

#include "common.h"

/* ************************************************************* */
/* Constants                                                     */
/* ************************************************************* */
#define    PTBL_MAX_SIZE         (100)
#define    PTBL_FIND_FLAG        (0xBB)
#define    PTBL_NOT_FIND_FLAG    (0xAA)

/* ************************************************************* */
/* Data-type                                                     */
/* ************************************************************* */
typedef    struct _PointNode_ {
    ElemType    *data;
    UINT32       length;
    UINT32       size;
} PointNode;

typedef    PointNode *    PPointNode;

/* ************************************************************* */
/* Interfaces                                                    */
/* ************************************************************* */
void       printItemPTblLst(ElemType item);

PointNode initPTblLst(UINT32 size);

STATE      destroyPTblLst(PPointNode p_tbl);

STATE      clearPTblLst(PPointNode p_tbl);

UINT32     getLengthPTblLst(const PointNode tbl);

UINT32     getSizePTblLst(const PointNode tbl);

STATE      getItemByIndexPTblLst(const PPointNode p_tbl,
                                 UINT32     index,
                                 ElemType  *p_item);

STATE      getIndexByItemPTblLst(const PPointNode p_tbl,
                                 UINT32    *p_index,
                                 ElemType   item);

STATE      isEmptyPTblLst(const PPointNode p_tbl);

STATE      isFullPTblLst(const PPointNode p_tbl);

STATE      insertItemHeaderPTblLst(PPointNode p_tbl,
                                   ElemType   item);

STATE      insertItemTailPTblLst(PPointNode   p_tbl,
                                 ElemType     item);

STATE      insertItemByIndexPTblLst(PPointNode p_tbl,
                                    UINT32     index,
                                    ElemType   item);

STATE      deleteItemHeaderPTblLst(PPointNode  p_tbl,
                                   ElemType   *p_item);

STATE      deleteItemTailPTblLst(PPointNode   p_tbl,
                                 ElemType    *p_item);

STATE      deleteItemByIndexPTblLst(PPointNode p_tbl,
                                    UINT32     index,
                                    ElemType  *p_item);

void       traversePTblLst(const PPointNode p_tbl,
                           void (*p_func)(ElemType item));

#endif /* __EX_POINTER_H_ */
