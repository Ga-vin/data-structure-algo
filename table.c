/* ************************************************************* */
/* File Name : table.c                                           */
/* Function  : Releasing of some new data type and interfaces    */
/* Author    : Gavin.Bai                                         */
/* Time      : 2016.03.27                                        */
/* Version   : (C) v1.0                                          */
/* Modified  :                                                   */
/* ************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "table.h"

void printItemTblLst(ElemType item)
{
    
}

/* Name     : initTblLst                           */
/* Function : To initialize table list             */
/* Input    : size --> Volumn of table list        */
/* Output   : Pointer to initialized table object  */
PTableNode initTblLst(UINT32 size)
{
    PTableNode p_node = NULL;

    p_node = (PTableNode)malloc(sizeof(TableNode));
    if (!p_node) {
        fprintf(stdout, "<Error> Malloc space fail\n");

        return NULL;
    }

    memset((void *)p_node->t_data, 0, TBL_MAX_SIZE);
    p_node->t_length = 0;
    p_node->t_size   = TBL_MAX_SIZE;
    
    return (p_node);
}

/* Name     : destroyTblLst                          */
/* Function : To destroy the table list              */
/* Input    : p_tbl --> Table object to be destroy   */
/* Output   : When destroy successfully, return TRUE */
STATE destroyTblLst(PTableNode p_tbl)
{
    if (!p_tbl) {
        fprintf(stdout, "<Error> Object is NULL.\n");
        
        return FALSE;
    } else {
        free(p_tbl);
        p_tbl = NULL;

        return TRUE;
    }
}

/* Name     : clearTblLst                          */
/* Function : To clear the table list              */
/* Input    : p_tbl --> Table object to be cleared */
/* Output   : When clear successfully, return TRUE */
STATE clearTblLst(PTableNode p_tbl)
{
    if (!p_tbl) {
        fprintf(stdout, "[Error] Object is NULL.\n");

        return FALSE;
    }

    memset((void *)p_tbl->t_data, 0, p_tbl->t_size);
    p_tbl->t_length = 0;
    
    return TRUE;
}


UINT32 getLengthTblLst(const TableNode tbl)
{

    return 0;
}

UINT32 getSizeTblLst(const TableNode tbl)
{

    return 0;
}

STATE getIndexByItemTblLst(const PTableNode p_tbl, UINT32 index, ElemType *p_item)
{

    return 0;
}

STATE getItemByIndexTblLst(const PTableNode p_tbl, UINT32 *p_index, ElemType item)
{

    return 0;
}

STATE isEmptyTblLst(const PTableNode p_tbl)
{

    return 0;
}

STATE isFullTblLst(const PTableNode p_tbl)
{

    return 0;
}

STATE insertItemHeaderTblLst(PTableNode p_tbl, ElemType item)
{

    return 0;
}

STATE insertItemTailTblLst(PTableNode p_tbl, ElemType item)
{

    return 0;
}

STATE insertItemByIndexTblLst(PTableNode p_tbl, UINT32 index, ElemType item)
{

    return 0;
}

STATE deleteItemHeaderTblLst(PTableNode p_tbl, ElemType *p_item)
{

    return 0;
}

STATE deleteItemTailTblLst(PTableNode p_tbl, ElemType *p_item)
{

    return 0;
}

STATE deleteItemByIndexTblLst(PTableNode p_tbl, UINT32 index, ElemType *p_item)
{

    return 0;
}

void traverseTblLst(const PTableNode p_tbl, void (*p_func)(ElemType item))
{

    return ;
}
