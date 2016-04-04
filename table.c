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

/* Name     : printItemTblLst                      */
/* Function : Print item to screen                 */
/* Input    : item --> To be printed on screen     */
/* Output   : None                                 */
void printItemTblLst(ElemType item)
{
    fprintf(stdout, "%5d", item);
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
        /* When the pointer has been free, NULL should be set */
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

/* Name     : getLengthTblLst                      */
/* Function : Acquire the length of table list     */
/* Input    : tbl --> Table object to be acquired  */
/* Output   : The length of the table list         */
UINT32 getLengthTblLst(const TableNode tbl)
{
    return tbl.t_length;
}

/* Name     : getSizeTblLst                        */
/* Function : Acquire the size of table list       */
/* Input    : tbl --> Table object to be acquired  */
/* Output   : The size of the table list           */
UINT32 getSizeTblLst(const TableNode tbl)
{
    return tbl.t_size;
}

/* Name     : getItemByIndexTblLst                 */
/* Function : Get item by specific index           */
/* Input    : p_tbl   --> Table object to be check */
/*            index   --> specific index           */
/*            *p_item --> to store item            */
/* Output   : When find, return TRUE, or else FALSE*/
STATE getItemByIndexTblLst(const PTableNode p_tbl,
                           UINT32 index,
                           ElemType *p_item)
{
    if (NULL == p_tbl) {
        *p_item = 0;
        
        return FALSE;
    }

    if (index >= getLengthTblLst(*p_tbl)) {
        *p_item = 0;

        return FALSE;
    }

    *p_item = p_tbl->t_data[index];
    
    return TRUE;
}

/* Name     : getIndexByItemTblLst                 */
/* Function : Get index by specific item           */
/* Input    : p_tbl    --> Table object to be check*/
/*            *p_index --> to store index          */
/*            item     --> specific item           */
/* Output   : When find, return TRUE, or else FALSE*/
STATE getIndexByItemTblLst(const PTableNode p_tbl,
                           UINT32 *p_index,
                           ElemType item)
{
    UINT32 i;
    UINT32 flag = TBL_NOT_FIND_FLAG;
    
    if (NULL == p_tbl) {
        *p_index = 0;

        return FALSE;
    }

    for (i = 0; i != getLengthTblLst(*p_tbl); ++i) {
        if ( item == p_tbl->t_data[i]) {
            *p_index = i;
            flag = TBL_FIND_FLAG;
            break;
        }
    }

    if ( TBL_FIND_FLAG == flag) {
        return TRUE;
    } else {
        *p_index = 0;

        return FALSE;
    }
}

/* Name     : isEmptyTblLst                        */
/* Function : Check whether the table is empty     */
/* Input    : p_tbl    --> Table object to be check*/
/* Output   : When it is empty, return TRUE,       */
/*            or else FALSE.                       */
STATE isEmptyTblLst(const PTableNode p_tbl)
{
    if (NULL == p_tbl) {
        return FALSE;
    }
    
    return ((0 == getLengthTblLst(*p_tbl)) ? TRUE : FALSE);
}

/* Name     : isFullTblLst                         */
/* Function : Check whether the table is full      */
/* Input    : p_tbl    --> Table object to be check*/
/* Output   : When it is full, return TRUE,        */
/*            or else FALSE.                       */
STATE isFullTblLst(const PTableNode p_tbl)
{
    if (NULL == p_tbl) {
        return FALSE;
    }
    
    return ((getLengthTblLst(*p_tbl) == getSizeTblLst(*p_tbl))
            ? TRUE
            : FALSE);
}

/* Name     : insertItemHeaderTblLst               */
/* Function : Insert item to header of table list  */
/* Input    : p_tbl    --> Table object to be check*/
/*            item     --> To be inserted          */
/* Output   : When it is inserted successfullly,   */
/*            TRUE will be returned, or else FALSE */
STATE insertItemHeaderTblLst(PTableNode p_tbl,
                             ElemType item)
{
    UINT32 i;
    
    if (NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");
        
        return FALSE;
    }

    if ( (TRUE == isFullTblLst(p_tbl)) ||
         getLengthTblLst(*p_tbl) > getSizeTblLst(*p_tbl)) {
        fprintf(stdout, "<Error> The table is full.\n");

        return OVERFLOW;
    }

    for (i = getLengthTblLst(*p_tbl); i > 0; i--) {
        p_tbl->t_data[i] = p_tbl->t_data[i-1];
    }
    p_tbl->t_data[0] = item;
    p_tbl->t_length++;
    
    return TRUE;
}

/* Name     : insertItemTailTblLst                 */
/* Function : Insert item to tail of table list    */
/* Input    : p_tbl    --> Table object to be check*/
/*            item     --> To be inserted          */
/* Output   : When it is inserted successfullly,   */
/*            TRUE will be returned, or else FALSE */
STATE insertItemTailTblLst(PTableNode p_tbl,
                           ElemType item)
{
    if (NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");

        return FALSE;
    }

    if ( ( TRUE == isFullTblLst(p_tbl)) ||
         (getLengthTblLst(*p_tbl) > getSizeTblLst(*p_tbl))) {
        fprintf(stdout, "<Error> Table is full.\n");

        return FALSE;
    }

    p_tbl->t_data[getLengthTblLst(*p_tbl)] = item;
    p_tbl->t_length++;
    
    return TRUE;
}

/* Name     : insertItemByIndexTblLst              */
/* Function : Insert item to specific index        */
/* Input    : p_tbl    --> Table object to be check*/
/*            index    --> Specific index          */
/*            item     --> To be inserted          */
/* Output   : When it is inserted successfullly,   */
/*            TRUE will be returned, or else FALSE */
STATE insertItemByIndexTblLst(PTableNode p_tbl,
                              UINT32 index,
                              ElemType item)
{
    UINT32 i;
    
    if (NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");

        return FALSE;
    }

    if (index < 0 || index > getLengthTblLst(*p_tbl)) {
        fprintf(stdout, "<Error> Specific index fail.\n");

        return FALSE;
    }

    if ( ( TRUE == isFullTblLst(p_tbl)) ||
         (getLengthTblLst(*p_tbl) > getSizeTblLst(*p_tbl))) {
        fprintf(stdout, "<Error> Table is full.\n");

        return OVERFLOW;
    }

    for (i = getLengthTblLst(*p_tbl); i > index; i--) {
        p_tbl->t_data[i] = p_tbl->t_data[i-1];
    }

    p_tbl->t_data[index] = item;
    p_tbl->t_length++;
    
    return TRUE;
}

/* Name     : deleteItemHeaderTblLst               */
/* Function : Delete item from header of list      */
/* Input    : p_tbl    --> Table object to be check*/
/*            p_item   --> To be stored to be del  */
/* Output   : When it is deleted successfullly,    */
/*            TRUE will be returned, or else FALSE */
STATE deleteItemHeaderTblLst(PTableNode p_tbl, ElemType *p_item)
{
    UINT32 i;
    
    if ( NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");
        *p_item = 0;

        return FALSE;
    }

    if ( TRUE == isEmptyTblLst(p_tbl)) {
        fprintf(stdout, "<Error> Table Empty.\n");
        *p_item = 0;

        return FALSE;
    }
    
    *p_item = p_tbl->t_data[0];
    for (i = 0; i != (getLengthTblLst(*p_tbl)-1); ++i) {
        p_tbl->t_data[i] = p_tbl->t_data[i+1];
    }
    p_tbl->t_length--;
    
    return TRUE;
}

STATE deleteItemTailTblLst(PTableNode p_tbl, ElemType *p_item)
{
    if ( NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");
        *p_item = 0;

        return FALSE;
    }

    if ( TRUE == isEmptyTblLst(p_tbl)) {
        fprintf(stdout, "<Error> Table Empty.\n");
        *p_item = 0;

        return FALSE;
    }

    *p_item = p_tbl->t_data[getLengthTblLst(*p_tbl)-1];
    p_tbl->t_length--;
    
    return TRUE;
}

STATE deleteItemByIndexTblLst(PTableNode p_tbl, UINT32 index, ElemType *p_item)
{
    UINT32 i;
    
    if ( NULL == p_tbl) {
        fprintf(stdout, "<Error> Table NULL.\n");
        *p_item = 0;

        return FALSE;
    }

    if ( TRUE == isEmptyTblLst(p_tbl)) {
        fprintf(stdout, "<Error> Table Empty.\n");
        *p_item = 0;

        return FALSE;
    }

    if (index < 0 || index > getLengthTblLst(*p_tbl)) {
        fprintf(stdout, "<Error> Index failed.\n");
        *p_item = 0;

        return OVERFLOW;
    }

    if ( TRUE != getItemByIndexTblLst(p_tbl, index, p_item)) {
        fprintf(stdout, "<Error> Get item fails.\n");
        *p_item = 0;

        return FALSE;
    } else {
        for (i = index; i < (getLengthTblLst(*p_tbl)-1); ++i) {
            p_tbl->t_data[i] = p_tbl->t_data[i+1];
        }
        p_tbl->t_length--;
    }
    
    return TRUE;
}

/* Name     : traverseTblLst                       */
/* Function : Traverse the table list one by one   */
/* Input    : p_tbl    --> Table object to be check*/
/*            p_func   --> Function pointer to do  */
/* Output   : None                                 */
void traverseTblLst(const PTableNode p_tbl, void (*p_func)(ElemType item))
{
    UINT32 i;
    ElemType item;

    for (i = 0; i < getLengthTblLst(*p_tbl); ++i) {
        if ( TRUE == getItemByIndexTblLst(p_tbl, i, &item)) {
            p_func(item);
        } else {
            fprintf(stdout, "<ERROR> Can not locate item by index.\n");
        }
    }
    fprintf(stdout, "\n");
    return ;
}
