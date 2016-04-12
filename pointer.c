/* ************************************************************* */
/* File Name : pointer.c                                         */
/* Function  : Releasing of some new data type and interfaces    */
/* Author    : Gavin.Bai                                         */
/* Time      : 2016.04.04                                        */
/* Version   : (C) v1.0                                          */
/* Modified  :                                                   */
/* ************************************************************* */
#include "pointer.h"
#include <stdio.h>
#include <stdlib.h>

/* Name     : printItemPTblLst                     */
/* Function : Print each item of point table list  */
/* Input    : item --> Item to be printed          */
/* Output   : None                                 */
void printItemPTblLst(ElemType item)
{
    fprintf(stdout, "%8d", item);
}

/* Name     : initPTblLst                          */
/* Function : To initialize pointer table list     */
/* Input    : size --> Volumn of table list        */
/* Output   : Initialized pointer table object     */
PointNode initPTblLst(UINT32 size)
{
    PointNode tbl;
    
    if (!size) {
        tbl.size = (UINT32)PTBL_MAX_SIZE;
    } else {
        tbl.size = size;
    }

    tbl.length = (UINT32)0;

    tbl.data = (ElemType *)malloc(tbl.size * sizeof(ElemType));
    if (NULL == tbl.data) {
        fprintf(stdout, "[X] Malloc fail\n");

        exit(EXIT_FAILURE);
    }
    
    return tbl;
}

/* Name     : destroyPTblLst                       */
/* Function : To destroy pointer table list        */
/* Input    : p_tbl --> pointer table to be destroy*/
/* Output   : When destroy successfully TRUE return*/
STATE destroyPTblLst(PPointNode p_tbl)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    p_tbl->length = (UINT32)0;
    p_tbl->size   = (UINT32)0;

    free(p_tbl->data);
    p_tbl->data = NULL;

    return TRUE;
}

/* Name     : clearPTblLst                         */
/* Function : To clear pointer table list          */
/* Input    : p_tbl --> pointer table to be cleared*/
/* Output   : When clear successfully TRUE return  */
STATE clearPTblLst(PPointNode p_tbl)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    p_tbl->length = 0;

    return TRUE;
}

/* Name     : getLengthPTblLst                     */
/* Function : Return the length of pointer table   */
/* Input    : tbl --> table list to be checked     */
/* Output   : Return length                        */
UINT32 getLengthPTblLst(const PointNode tbl)
{
    if (!tbl.data) {
        fprintf(stdout, "[X] Pointer table empty, system will be terminated.\n");

        exit(EXIT_FAILURE);
    }

    return tbl.length;
}

/* Name     : getSizePTblLst                       */
/* Function : Return the size of pointer table     */
/* Input    : tbl --> table list to be checked     */
/* Output   : Return size                          */
UINT32 getSizePTblLst(const PointNode tbl)
{
    if (!tbl.data) {
        fprintf(stdout, "[X] Pointer table empty, system will terminated.\n");

        exit(EXIT_FAILURE);
    }

    return tbl.size;
}

/* Name     : getItemByIndexPTblLst                 */
/* Function : Return the specific item by index     */
/* Input    : p_tbl  --> table list to be checked   */
/*            index  --> index to be checked        */
/*            p_item --> store the value have found */
/* Output   : When found, return TRUE, or else FALSE*/
STATE getItemByIndexPTblLst(const PPointNode p_tbl,
                            UINT32           index,
                            ElemType         *p_item)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    if (index >= getLengthPTblLst(*p_tbl)) {
        return FALSE;
    }

    *p_item = *(p_tbl->data + index);

    return TRUE;
}

/* Name     : getIndexByItemPTblLst                 */
/* Function : Return the specific index by item     */
/* Input    : p_tbl   --> table list to be checked  */
/*            p_index --> index to be stored        */
/*            item    --> item to be checked        */
/* Output   : When found, return TRUE, or else FALSE*/
STATE getIndexByItemPTblLst(const PPointNode p_tbl,
                            UINT32           *p_index,
                            ElemType         item)
{
    UINT32 i = 0;
    
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    while (i < getLengthPTblLst(*p_tbl)) {
        if ( item == *(p_tbl->data + i)) {
            *p_index = i;

            return TRUE;
        }
    }

    return FALSE;
}

/* Name     : isEmptyPTblLst                        */
/* Function : Whehter the pointer table is empty    */
/* Input    : p_tbl   --> table list to be checked  */
/* Output   : Return TRUE when it is empty, or FALSE*/
STATE isEmptyPTblLst(const PPointNode p_tbl)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    if (getLengthPTblLst(*p_tbl) < (getSizePTblLst(*p_tbl) - 1)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* Name     : isFullPTblLst                        */
/* Function : Whehter the pointer table is full    */
/* Input    : p_tbl   --> table list to be checked */
/* Output   : Return TRUE when it is full, or FALSE*/
STATE isFullPTblLst(const PPointNode p_tbl)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    if ( getLengthPTblLst(*p_tbl) == getSizePTblLst(*p_tbl)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* Name     : insertItemHeaderPTblLst              */
/* Function : Insert item in the header table list */
/* Input    : p_tbl --> table list to be inserted  */
/*            item  --> item to be inserted        */ 
/* Output   : Return TRUE inserted successfully    */
STATE insertItemHeaderPTblLst(PPointNode p_tbl,
                              ElemType   item)
{
    UINT32    i;
    ElemType *p_new_data = NULL;
    
    /* 指针为空 */
    if (!p_tbl) {
        return EMPTY;
    }

    /* 指针为空 */
    if (!p_tbl->data) {
        return EMPTY;
    }

    /* 数组链表为满 */ 
    if ( TRUE != isFullPTblLst(p_tbl)) {
        /* 数组链表已经满时，要再添加新的分配空间，叠加到之前的空间上 */
        p_new_data = (ElemType *)realloc(p_tbl->data, (p_tbl->size + PTBL_ADD_SIZE) * sizeof(ElemType));
        if (!p_new_data) {
            fprintf(stdout, "[X] Realloc space fail\n");

            return FALSE;
        }

        p_tbl->data  = p_new_data;
        p_tbl->size += PTBL_ADD_SIZE;
    }

    /* 向后依次移动后面的length-1个元素 */
    for (i = getLengthPTblLst(*p_tbl); i > 1; i--) {
        *(p_tbl->data + i) = *(p_tbl->data + i - 1);
    }
    *(p_tbl->data + 0) = item;
    p_tbl->length++;

    return TRUE;
}

/* Name     : insertItemTailPTblLst                */
/* Function : Insert item in the tail table list   */
/* Input    : p_tbl --> table list to be inserted  */
/*            item  --> item to be inserted        */ 
/* Output   : Return TRUE inserted successfully    */
STATE insertItemTailPTblLst(PPointNode p_tbl,
                            ElemType   item)
{
    ElemType *p_new_data = NULL;
    
    /* 指针为空 */
    if (!p_tbl) {
        return EMPTY;
    }

    /* 指针为空 */
    if (!p_tbl->data) {
        return EMPTY;
    }

    /* 不为满 */
    if ( TRUE != isFullPTblLst(p_tbl)) {
        /* 数组链表为满时需要再分配新的空间 */
        p_new_data = (ElemType *)realloc(p_tbl->data, (p_tbl->size + PTBL_ADD_SIZE) * sizeof(ElemType));
        if (!p_new_data) {
            fprintf(stdout, "[X] Realloc space fail\n");

            return FALSE;
        }

        p_tbl->data  = p_new_data;
        p_tbl->size += PTBL_ADD_SIZE;
    }

    /* 不用移动，直接添加至最后一个位置 */
    *(p_tbl->data + getLengthPTblLst(*p_tbl)) = item;
    p_tbl->length++;

    return TRUE;
}

/* Name     : insertItemByIndexPTblLst                */
/* Function : Insert item by specific index table list*/
/* Input    : p_tbl --> table list to be inserted     */
/*            index --> specific inserted index       */
/*            item  --> item to be inserted           */ 
/* Output   : Return TRUE inserted successfully       */
STATE insertItemByIndexPTblLst(PPointNode p_tbl,
                               UINT32     index,
                               ElemType   item)
{
    UINT32    i;
    ElemType *p_new_data = NULL;
    
    /* 指针为空 */
    if (!p_tbl) {
        return EMPTY;
    }

    /* 指针为空 */
    if (!p_tbl->data) {
        return EMPTY;
    }

    /* 数组链表为满 */
    if ( TRUE != isFullPTblLst(p_tbl)) {
        p_new_data = (ElemType *)realloc(p_tbl->data, (p_tbl->size + PTBL_ADD_SIZE) * sizeof(ElemType));
        if (!p_new_data) {
            fprintf(stdout, "[X] Realloc space fail\n");

            return FALSE;
        }

        p_tbl->data  = p_new_data;
        p_tbl->size += PTBL_ADD_SIZE;
    }

    /* 指定索引不合法 */
    if (index >= getSizePTblLst(*p_tbl)) {
        return FALSE;
    }

    for (i = getLengthPTblLst(*p_tbl); i > index; i--) {
        *(p_tbl->data + i) = *(p_tbl->data + i - 1);
    }
    *(p_tbl->data + index) = item;
    p_tbl->length++;

    return TRUE;
}

/* Name     : deleteItemHeaderPTblLst                 */
/* Function : Delete item from header one by one      */
/* Input    : p_tbl  --> table list to be deleted     */
/*            p_item --> item to be deleted           */ 
/* Output   : Return TRUE delete successfully         */
STATE deleteItemHeaderPTblLst(PPointNode p_tbl,
                              ElemType  *p_item)
{
    UINT32 index;
    
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    if ( TRUE == isEmptyPTblLst(p_tbl)) {
        return FALSE;
    }

    *p_item = *(p_tbl->data + 0);
    for (index = 0; index < (getLengthPTblLst(*p_tbl) - 2); ++index) {
        *(p_tbl->data + index) = *(p_tbl->data + index + 1);
    }
    p_tbl->length--;

    return TRUE;
}

/* Name     : deleteItemTailPTblLst                   */
/* Function : Delete item from tail one by one        */
/* Input    : p_tbl  --> table list to be deleted     */
/*            p_item --> item to be deleted           */ 
/* Output   : Return TRUE delete successfully         */
STATE deleteItemTailPTblLst(PPointNode p_tbl,
                            ElemType  *p_item)
{
    if (!p_tbl) {
        return EMPTY;
    }

    if (!p_tbl->data) {
        return EMPTY;
    }

    if ( TRUE == isEmptyPTblLst(p_tbl)) {
        return FALSE;
    }

    *p_item = *(p_tbl->data + getLengthPTblLst(*p_tbl) - 1);
    p_tbl->length--;

    return TRUE;
}
