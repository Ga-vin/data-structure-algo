/* ************************************************************* */
/* File Name : table.h                                           */
/* Function  : Definition of some new data type and interfaces   */
/* Author    : Gavin.Bai                                         */
/* Time      : 2016.03.27                                        */
/* Version   : (C) v1.0                                          */
/* Modified  :                                                   */
/* ************************************************************* */

#ifndef    __EX_TABLE_H_
#define    __EX_TABLE_H_

#include "common.h"

/* ********************* Constances Macros ********************* */
#define    TBL_MAX_SIZE    (100)

/* ******************** New Type Definition ******************** */
typedef    struct _TABLE_NODE_ {
    ElemType    t_data[TBL_MAX_SIZE];
    UINT32      t_length;
    UINT32      t_size;
} TableNode;

typedef    TableNode *    PTableNode;

/* ********************Interfaces Protocols ******************** */
void      printItemTblLst(ElemType item);

PTableNode initTblLst(UINT32 size);

STATE     destroyTblLst(PTableNode tbl);

STATE     clearTblLst(PTableNode tbl);

UINT32    getLengthTblLst(const TableNode tbl);

UINT32    getSizeTblLst(const TableNode tbl);

STATE     getIndexByItemTblLst(const PTableNode p_tbl, UINT32 index, ElemType *p_item);

STATE     getItemByIndexTblLst(const PTableNode p_tbl, UINT32 *p_index, ElemType item);

STATE     isEmptyTblLst(const PTableNode p_tbl);

STATE     isFullTblLst(const PTableNode p_tbl);

STATE     insertItemHeaderTblLst(PTableNode p_tbl, ElemType item);

STATE     insertItemTailTblLst(PTableNode p_tbl, ElemType item);

STATE     insertItemByIndexTblLst(PTableNode p_tbl, UINT32 index, ElemType item);

STATE     deleteItemHeaderTblLst(PTableNode p_tbl, ElemType *p_item);

STATE     deleteItemTailTblLst(PTableNode p_tbl, ElemType *p_item);

STATE     deleteItemByIndexTblLst(PTableNode p_tbl, UINT32 index, ElemType *p_item);

void      traverseTblLst(const PTableNode p_tbl, void (*p_func)(ElemType item));

#endif /* __EX_TABLE_H_ */
