
/* ************************************************************************* */
/* File Name : double_list.c                                                 */
/* Function  : Releasing of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                     */
/* Time      : 2016.06.27                                                    */
/* Version   : (C) v1.0                                                      */
/* Modified  :                                                               */
/* ************************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/* Name     : createDoubleList                                               */
/* Function : Create a new header of double list                             */
/* Input    : None                                                           */
/* Output   : New double list pointer                                        */
DoubleList createDoubleList(void)
{
    
}

/* Name     : destroyDoubleList                                              */
/* Function : Destroy a double list has been existed                         */
/* Input    : p_header    an existed list                                    */
/* Output   : TRUE destroy successfully FALSE error                          */
STATE destroyDoubleList(DoubleList p_header)
{
    
}

/* Name     : clearDoubleList                                                */
/* Function : Clear a double list has been existed                           */
/* Input    : p_header    an existed list                                    */
/* Output   : TRUE clear successfully FALSE error                            */
STATE clearDoubleList(DoubleList p_header)
{
    
}

/* Name     : isEmptyDoubleList                                              */
/* Function : Check whether the double list is empty                         */
/* Input    : p_header    an double list pointer                             */
/* Output   : TRUE if it is empty, or FALSE                                  */
BOOL isEmptyDoubleList(const DoubleList p_header)
{
    
}

/* Name     : isLastDoubleList                                               */
/* Function : Check whether it is the last one                               */
/* Input    : p_header    an double list pointer
              p_item      an specific node to check                          */
/* Output   : TRUE if it is last, or FALSE                                   */
BOOL isLastDoubleList(const DoubleList p_header, const Position p_item)
{
    
}

/* Name     : getLengthDoubleList                                            */
/* Function : Get the length of the double list                              */
/* Input    : p_header    an list pointer                                    */
/* Output   : Length of list                                                 */
UINT32 getLengthDoubleList(const DoubleList p_header)
{
    
}

/* Name     : getIndexByItemDoubleList                                       */
/* Function : Get the index by specific item                                 */
/* Input    : p_header    an list pointer
              index     specific location
              item      get value member                                     */
/* Output   : When get it, TRUE will be returned, or else FALSE              */
STATE getIndexByItemDoubleList(const DoubleList p_header,
                               ElemType         item,
                               UINT32          *p_index)
{
    
}

/* Name     : getItemByIndexDoubleList                                       */
/* Function : Get the item by specific index                                 */
/* Input    : p_header    an list pointer
              index     specific location
              item      get value member                                     */
/* Output   : When get it, TRUE will be returned, or else FALSE              */
STATE getItemByIndexDoubleList(const DoubleList p_header,
                               UINT32           index,
                               ElemType        *p_item)
{
    
}

/* Name     : findItemDoubleList                                             */
/* Function : Find specific item by item                                     */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When find it, TRUE will be returned, or else FALSE             */
Position findItemDoubleList(const DoubleList p_header,
                            ElemType         item)
{
    
}

/* Name     : deleteItemHeaderDoubleList                                     */
/* Function : Find specific item by item                                     */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When find it, TRUE will be returned, or else FALSE             */
STATE deleteItemHeaderDoubleList(DoubleList p_header,
                                 ElemType  *p_item)
{
    
}

STATE deleteItemTailDoubleList(DoubleList p_header,
                               ElemType  *p_item)
{
    
}

STATE deleteItemDoubleList(DoubleList p_header, ElemType item)
{
    
}

STATE deleteItemByIndexDoubleList(DoubleList p_header,
                                  UINT32     index,
                                  ElemType  *p_item)
{
    
}

STATE insertItemHeaderDoubleList(DoubleList p_header,
                                 ElemType   item)
{
    
}

STATE insertItemTailDoubleList(DoubleList p_header,
                               ElemType   item)
{
    
}

STATE insertItemDoubleList(DoubleList p_hedaer,
                           ElemType   item)
{
    
}

STATE insertItemByIndexDoubleList(DoubleList p_header,
                                  UINT32     index,
                                  ElemType   item)
{
    
}

Position getLastDoubleList(const DoubleList p_header)
{
    
}

STATE retrieveDoubleList(const DoubleList p_header)
{
    
}

STATE sortDoubleList(DoubleList p_header,
                     SortOrder  order)
{
    
}

STATE mergeDoubleList(DoubleList p_list_a,
                      DoubleList p_list_b,
                      DoubleList p_list_c)
{
    
}
