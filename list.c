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

/* Name     : createList                                                     */
/* Function : Create a new header of list                                    */
/* Input    : None                                                           */
/* Output   : New list pointer                                               */
List createList(void)
{
    
}

/* Name     : destroyList                                                    */
/* Function : Destroy a list has been existed                                */
/* Input    : p_list    an existed list                                      */
/* Output   : TRUE destroy successfully FALSE error                          */
STATE destroyList(List p_list)
{
    
}

/* Name     : clearList                                                      */
/* Function : Clear a list has been existed                                  */
/* Input    : p_list    an existed list                                      */
/* Output   : TRUE clear successfully FALSE error                            */
STATE clearList(List p_list)
{
    
}

/* Name     : isEmptyList                                                    */
/* Function : Check whether the list is empty                                */
/* Input    : p_list    an list pointer                                      */
/* Output   : TRUE if it is empty, or FALSE                                  */
BOOL isEmptyList(const List p_list)
{
    
}

/* Name     : isLastList                                                     */
/* Function : Check whether it is the last one                               */
/* Input    : p_list    an list pointer                                      */
/* Output   : TRUE if it is last, or FALSE                                   */
BOOL isLastList(const List p_list)
{
    
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
