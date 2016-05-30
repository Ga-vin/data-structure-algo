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
UINT32 getLengthList(const List p_header)
{
    UINT32   ui_counter = 0;
    Position p_list = LIST_NULL;
    
    if ( !p_header) {
        debugError("Object is NULL", GET_FILE, GET_LINE);

        return 0;
    }

    /* Check from the first node */
    p_list = p_header->p_next;
    while (p_list) {
        ui_counter++;
        p_list = p_list->p_next;
    }

    return ui_counter;
}

/* Name     : findItemList                                                   */
/* Function : Find the object with its value member is item                  */
/* Input    : p_list    an list pointer                                      */
/*            item      specific value member                                */
/* Output   : List pointer when find it, or NULL                             */
Position findItemList(const List p_header, const ElemType item)
{
    Position p_list = LIST_NULL;
    BOOL     b_flag = FALSE;
    
    if (!p_header) {
        debugError("<findItemList>:Object is NULL", GET_FILE, GET_LINE);

        return LIST_NULL;
    }

    p_list = p_header->p_next;
    while (p_list) {
        if ( item  == p_list->item) {
            b_flag = TRUE;
            break;
        }

        p_list = p_list->p_next;
    }

    if ( TRUE == b_flag) {
        return p_list;
    } else {
        return LIST_NULL;
    }
}

/* Name     : deleteItemHeaderList                                           */
/* Function : Delete item from header of list                                */
/* Input    : p_list      an list pointer                                    */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemHeaderList(List p_header, ElemType *p_del_item)
{
    Position p_temp = LIST_NULL;
    
    if ( !p_header) {
        debugError("<deleteItemHeaderList> object is NULL", GET_FILE,
                   GET_LINE);

        return FALSE;
    }

    p_temp = p_header->p_next;
    if ( !p_temp) {
        debugError("<deleteItemHeaderList> next is NULL",
                   GET_FILE,
                   GET_LINE);

        return FALSE;
    }
    *p_del_item = p_temp->item;
    p_header->p_next = p_temp->p_next;
    free(p_temp);

    return TRUE;
}

/* Name     : deleteItemTailList                                             */
/* Function : Delete item from tail of list                                  */
/* Input    : p_list      an list pointer                                    */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemTailList(List p_header, ElemType *p_del_item)
{
    Position p_prev = LIST_NULL;
    Position p_next = LIST_NULL;
    
    if ( !p_header) {
        debugError("<deleteItemTailList> header is NULL",
                   GET_FILE,
                   GET_LINE);

        return FALSE;
    }

    if ( TRUE != isEmptyList(p_header)) {
        p_prev = p_header;
        p_next = p_header->p_next;

        while ( LIST_NULL != p_next->p_next) {
            p_prev = p_next;
            p_next = p_next->p_next;
        }

        *p_del_item    = p_next->item;
        p_prev->p_next = LIST_NULL;
        free(p_next);

        return TRUE;
    } else {
        debugError("<deleteItemTailList> list is empty: <%s>-%d\n",
                   GET_FILE,
                   GET_LINE);

        return FALSE;
    }

    return TRUE;
}

/* Name     : deleteItemList                                                 */
/* Function : Delete item of list by specific item                           */
/* Input    : p_list      an list pointer                                    */
/*            item        specific item                                      */
/*            p_del_item  will be deleted item                               */
/* Output   : TRUE when delete successfully, or FALSE                        */
STATE deleteItemList(List p_header, const ElemType item)
{
    Position p_list = LIST_NULL;
    Position p_temp = LIST_NULL;

    if ( !p_header) {
        debugError("<deleteItemList>:Object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }

    p_list = findPreviousItemList(p_header, item);
    if ( LIST_NULL == p_list) {
        debugError("<deleteItemList>:find previous item fail", GET_FILE, GET_LINE);

        return FALSE;
    }

    /* If the link list pointer is last, just return TRUE */
    if ( !isLastList(p_header, p_list)) {
        p_temp = p_list->p_next;
        p_list->p_next = p_temp->p_next;
        free(p_temp);
    }

    return TRUE;
}

/* Name     : findPreviousItemList                                           */
/* Function : Find the previous one of specific item part                    */
/* Input    : p_list      an list pointer                                    */
/*            item        specific item                                      */
/* Output   : TRUE when find successfully, or FALSE                          */
Position findPreviousItemList(const List p_header, const ElemType item)
{
    Position p_list = LIST_NULL;

    if ( !p_header) {
        debugError("<findPreviousItemList> : Object is NULL", GET_FILE, GET_LINE);

        return LIST_NULL;
    }

    p_list = p_header;
    while ( (p_list->p_next) && (p_list->p_next->item != item)) {
        p_list = p_list->p_next;
    }

    return p_list;
}

/* Name     : insertItemHeaderList                                           */
/* Function : Insert item into the list in header position                   */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemHeaderList(List p_header, const ElemType item)
{
    Position p_node = LIST_NULL;
    
    if ( !p_header) {
        debugError("<insertItemHeaderList>:Object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }

    /* Malloc new node for link list */
    p_node = (Position)malloc(sizeof(LNode));
    if ( !p_node) {
        debugError("<insertItemHeaderList>:Malloc object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }
    p_node->item = item;

    /* Link new node to the link list */
    p_node->p_next = p_header->p_next;
    p_header->p_next = p_node;

    return TRUE;
}

/* Name     : insertItemTailList                                             */
/* Function : Insert item into the list in tail position                     */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemTailList(List p_header, const ElemType item)
{
    Position p_node = LIST_NULL;
    Position p_temp = LIST_NULL;

    if ( !p_header) {
        debugError("<insertItemTailList>:Object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }

    /* Malloc new node for inserting */
    p_node = (Position)malloc(sizeof(LNode));
    if ( !p_node) {
        debugError("<insertItemTailList>:Malloc object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }
    p_node->item = item;

    /* Find the last node of list */
    p_temp = p_header;
    while ( p_temp->p_next) {
        p_temp = p_temp->p_next;
    }

    /* Link node into list */    
    p_node->p_next = p_temp->p_next;
    p_temp->p_next = p_node;

    return TRUE;
}

/* Name     : insertItemList                                                 */
/* Function : Insert item into after the list position by specific item      */
/* Input    : p_list      an list pointer                                    */
/*            p_item      inserted item                                      */
/*            item        specific one                                       */
/* Output   : TRUE when inserted successfully, or FALSE                      */
STATE insertItemList(List p_header, const Position p_item, const ElemType item)
{
    Position p_node = LIST_NULL;
    
    if ( !p_header || !p_item) {
        debugError("<insertItemList>:Object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }

    /* Malloc new node */
    p_node = (Position)malloc(sizeof(LNode));
    if ( !p_node) {
        debugError("<insertItemList>:Malloc object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }
    p_node->item = item;

    /* Assume the p_item is a node of list p_header */
    p_node->p_next = p_item->p_next;
    p_item->p_next = p_node;

    return TRUE;
}

/* Name     : getHeaderList                                                  */
/* Function : Get the header of the existed list                             */
/* Input    : p_list      an list pointer                                    */
/* Output   : Header pointer object                                          */
Position getHeaderList(const List p_header)
{
    Position p_node = LIST_NULL;

    return p_node;
}

/* Name     : getFirstList                                                   */
/* Function : Get the first one of the existed list                          */
/* Input    : p_list      an list pointer                                    */
/* Output   : Pointer points to first one                                    */
Position getFirstList(const List p_list)
{
    Position p_node = LIST_NULL;

    return p_node;
}

/* Name     : findLastList                                                   */
/* Function : Find the last node of the list                                 */
/* Input    : p_list      an list pointer                                    */
/* Output   : Last node when found, or else LIST_NULL                        */
Position findLastList(const List p_header)
{
    Position p_temp = LIST_NULL;
    
    if ( !p_header) {
        debugError("<findLastList> header is NULL",
                   GET_FILE,
                   GET_LINE);

        return LIST_NULL;
    }

    p_temp = p_header->p_next;
    while (p_temp) {
        if ( LIST_NULL != p_temp->p_next) {
            p_temp = p_temp->p_next;
            continue;
        } else {
            return p_temp;
        }
    }

    return p_temp;
}

/* Name     : retrieveList                                                   */
/* Function : Retreieve the list one by one                                  */
/* Input    : p_list      an list pointer                                    */
/* Output   : TRUE when retrieved successfully, or FALSE                     */
STATE retrieveList(const List p_header)
{
    Position p_node  = LIST_NULL;
    UINT32   counter = 0;

    if ( !p_header) {
        debugError("<retrieveList>:Object is NULL", GET_FILE, GET_LINE);

        return FALSE;
    }
    
    p_node = p_header->p_next;
    while ( p_node) {
        if ( !((counter+1)%10)) {
                putchar('\n');
        }
        fprintf(stdout, "Node[%d] : %d\t", counter++, p_node->item);
        p_node = p_node->p_next;
    }
    putchar('\n');
    
    return TRUE;
}
