/* ************************************************************************* */
/* File Name : list.c                                                        */
/* Function  : Releasing of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                     */
/* Time      : 2016.05.16                                                    */
/* Version   : (C) v1.0                                                      */
/* Modified  :                                                               */
/* ************************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define    GET_FILE    (__FILE__)
#define    GET_LINE    (__LINE__)

static void debugError(const char *str,
                       const char *p_file_name,
                       INT32 line)
{
    fprintf(stdout, "[X] <Error> : %s in %s-%d.\n", str,
            p_file_name,
            line);
}

/* Name     : createList                                                     */
/* Function : Create a new header of list                                    */
/* Input    : None                                                           */
/* Output   : New list pointer                                               */
List createList(void)
{
    List p_list = NULL;

    p_list = (List)malloc(sizeof(LNode));
    if (!p_list) {
        debugError("createList", GET_FILE, GET_LINE);
        return LIST_NULL;
    }

    return p_list;
}

/* Name     : destroyList                                                    */
/* Function : Destroy a list has been existed                                */
/* Input    : p_list    an existed list                                      */
/* Output   : TRUE destroy successfully FALSE error                          */
STATE destroyList(List p_list)
{
    Position p_temp_list;
    Position p_temp;

    if (!p_list) {
        debugError("destroyList", GET_FILE, GET_LINE);

        return FALSE;
    }

    p_temp_list    = p_list->p_next;
    p_list->p_next = NULL;
    free(p_list);
    p_list         = LIST_NULL;
    while (p_temp_list) {
        /* Make sure next node of list is valid */
        p_temp      = p_temp_list->p_next;
        free(p_temp_list);
        p_temp_list = p_temp;
    }

    return TRUE;
}

/* Name     : clearList                                                      */
/* Function : Clear a list has been existed                                  */
/* Input    : p_list    an existed list                                      */
/* Output   : TRUE clear successfully FALSE error                            */
STATE clearList(List p_list)
{
    if (!p_list) {
        debugError("clearList", GET_FILE, GET_LINE);

        return (FALSE);
    }

    p_list->p_next = LIST_NULL;

    return TRUE;
}

/* Name     : isEmptyList                                                    */
/* Function : Check whether the list is empty                                */
/* Input    : p_list    an list pointer                                      */
/* Output   : TRUE if it is empty, or FALSE                                  */
BOOL isEmptyList(const List p_list)
{
    if (!p_list) {
        debugError("isEmptyList", GET_FILE, GET_LINE);

        exit(EXIT_FAILURE);
    }

    return ((LIST_NULL == p_list->p_next) ? TRUE : FALSE);
}

/* Name     : isLastList                                                     */
/* Function : Check whether it is the last one                               */
/* Input    : p_list    an list pointer                                      */
/* Output   : TRUE if it is last, or FALSE                                   */
BOOL isLastList(const List p_list, const Position p_item)
{
    if (!p_list || !p_item) {
        debugError("isLastList", GET_FILE, GET_LINE);

        exit(EXIT_FAILURE);
    }

    return ((LIST_NULL == p_item->p_next) ? TRUE : FALSE);
}

/* Name     : getLengthList                                                  */
/* Function : Get the length of the list                                     */
/* Input    : p_list    an list pointer                                      */
/* Output   : Length of list                                                 */
UINT32 getLengthList(const List p_list)
{
    
}

/* Name     : findItemList                                                   */
/* Function : Find the object with its value member is item                  */
/* Input    : p_list    an list pointer                                      */
/*            item      specific value member                                */
/* Output   : List pointer when find it, or NULL                             */
Position findItemList(const List p_list, const ElemType item)
{
    
}

/* Name     : deleteItemHeaderList                                           */
/* Function : Delete item from header of list                                */
/* Input    : p_list      an list pointer                                    */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemHeaderList(List p_list, Position p_del_item)
{
    
}

/* Name     : deleteItemTailList                                             */
/* Function : Delete item from tail of list                                  */
/* Input    : p_list      an list pointer                                    */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemTailList(List p_list, Position p_del_item)
{
    
}

/* Name     : deleteItemList                                                 */
/* Function : Delete item of list by specific item                           */
/* Input    : p_list      an list pointer                                    */
/*            item        specific item                                      */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemList(List p_list, const ElemType item, Position p_del_item)
{
    
}

/* Name     : findPreviousItemList                                           */
/* Function : Find the previous one of specific item part                    */
/* Input    : p_list      an list pointer                                    */
/*            item        specific item                                      */
/* Output   : TRUE when find successfully, or FALSE                          */
Position findPreviousItemList(const List p_list, const ElemType item)
{
    
}

/* Name     : insertItemHeaderList                                           */
/* Function : Insert item into the list in header position                   */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemHeaderList(List p_list, const Position p_item)
{
    
}

/* Name     : insertItemTailList                                             */
/* Function : Insert item into the list in tail position                     */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemTailList(List p_list, const Position p_item)
{
    
}

/* Name     : insertItemList                                                 */
/* Function : Insert item into the list position by specific item            */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/*            item        specific one                                       */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemList(List p_list, const Position p_item, const ElemType item)
{
    
}

/* Name     : getHeaderList                                                  */
/* Function : Get the header of the existed list                             */
/* Input    : p_list      an list pointer                                    */
/* Output   : Header pointer object                                          */
Position getHeaderList(const List p_list)
{
    
}

/* Name     : getFirstList                                                   */
/* Function : Get the first one of the existed list                          */
/* Input    : p_list      an list pointer                                    */
/* Output   : Pointer points to first one                                    */
Position getFirstList(const List p_list)
{
    
}

/* Name     : retrieveList                                                   */
/* Function : Retreieve the list one by one                                  */
/* Input    : p_list      an list pointer                                    */
/* Output   : TRUE when retrieved successfully, or FALSE                     */
STATE retrieveList(const Position p_list)
{
    
}
