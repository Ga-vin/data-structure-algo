
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

/* Name     : _isSorted                                                      */
/* Function : Check whether the double list is sorted as ASCENING order      */
/* Input    : p_header   Header pointer of double list                       */
/* Output   : If sorted as ASCENDING order, TRUE will returned, or else FALSE*/
static BOOL _isSorted(const DoubleList p_header)
{
    Position p_curr = LIST_NULL;
    Position p_last = LIST_NULL;
    
    if ( !p_header) {
        return (FALSE);
    }

    p_curr = p_header->next;
    p_last = p_header->next;
    while ( p_curr) {
        if ( p_curr->item < p_last->item) {
            
            return (FALSE);
        }

        p_last = p_curr;
        p_curr = p_curr->next;
    }

    return TRUE;
}

/* Name     : _swap                                                          */
/* Function : Swap the value of two item by reference                        */
/* Input    : p_item_left   to be swpped left value
              p_item_right  to be swapped right value                        */
/* Output   : NONE                                                           */
static void _swap(ElemType *p_item_left, ElemType *p_item_right)
{
    ElemType tmp;

    tmp           = *p_item_left;
    *p_item_left  = *p_item_right;
    *p_item_right = tmp;
}

/* Name     : _printItem                                                     */
/* Function : Print item of each node in the double list                     */
/* Input    : item   to be print on the screen                               */
/* Output   : NONE                                                           */
void _printItem(ElemType item)
{
    UINT32 counter = 0;

    ++counter;
    if ( !((counter+1) % 10)) {
        putchar('\n');
    }
    
    fprintf(stdout, "[0x%X] ", item);
}

/* Name     : createDoubleList                                               */
/* Function : Create a new header of double list                             */
/* Input    : None                                                           */
/* Output   : New double list pointer                                        */
DoubleList createNodeDoubleList(void)
{
    DoubleList p_node = LIST_NULL;

    p_node = (DoubleList)malloc(sizeof(DoubleLNode));
    if ( !p_node) {
        debugError("createDoubleList",
                   GET_FILE,
                   GET_LINE);

        return (LIST_NULL);
    }
    p_node->item  = LIST_INVALID_VALUE;
    p_node->next  = NULL;
    p_node->prior = NULL;

    return (p_node);
}

/* Name     : destroyDoubleList                                              */
/* Function : Destroy a double list has been existed                         */
/* Input    : p_header    an existed list                                    */
/* Output   : TRUE destroy successfully FALSE error                          */
STATE destroyDoubleList(DoubleList p_header)
{
    DoubleList p_temp = LIST_NULL;
    DoubleList p_ptr  = LIST_NULL;
    
    if ( !p_header) {
        return (TRUE);
    }
    
    p_ptr = p_header->next;
    while ( p_ptr) {
        p_temp       = p_ptr->next;  /* 保存指向下一个节点的指针                 */
        p_ptr->next  = LIST_NULL;    /* 前向后向都指空，成为单独一个节点          */
        p_ptr->prior = LIST_NULL;
        free(p_ptr);                 /* 释放该独立的节点                       */
        p_ptr        = p_temp;
    }

    free(p_header);
    p_header         = LIST_NULL;    

    return (TRUE);
}

/* Name     : clearDoubleList                                                */
/* Function : Clear a double list has been existed                           */
/* Input    : p_header    an existed list                                    */
/* Output   : TRUE clear successfully FALSE error                            */
STATE clearDoubleList(DoubleList p_header)
{
    DoubleList p_ptr  = LIST_NULL;
    DoubleList p_temp = LIST_NULL;
    
    if ( !p_header) {
        return (FALSE);
    }

    p_ptr            = p_header->next;

    while ( p_ptr) {
        p_temp       = p_ptr->next;
        p_ptr->next  = LIST_NULL;
        p_ptr->prior = LIST_NULL;
        free(p_ptr);
        p_ptr        = LIST_NULL;

        p_ptr = p_temp;
    }

    p_header->next  = LIST_NULL;
    p_header->prior = LIST_NULL;    

    return (TRUE);
}

/* Name     : isEmptyDoubleList                                              */
/* Function : Check whether the double list is empty                         */
/* Input    : p_header    an double list pointer                             */
/* Output   : TRUE if it is empty, or FALSE                                  */
BOOL isEmptyDoubleList(const DoubleList p_header)
{
    if ( !p_header) {
        return (FALSE);
    } else {
        if ( !(p_header->next) &&
             !(p_header->prior)) {
            return (TRUE);
        } else {
            return (FALSE);
        }
    }
}

/* Name     : isLastDoubleList                                               */
/* Function : Check whether it is the last one                               */
/* Input    : p_header    an double list pointer
              p_item      an specific node to check                          */
/* Output   : TRUE if it is last, or FALSE                                   */
BOOL isLastDoubleList(const DoubleList p_header, const Position p_item)
{
#ifdef __DEBUG_LAST_    
    DoubleList p_temp = LIST_NULL;
    DoubleList p_last = LIST_NULL;
#endif /* __DEBUG_LAST_ */

    if ( !p_header) {
        debugError("<isLastDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return FALSE;
    }

    if ( p_item && ( LIST_NULL == p_item->next))  {
        return (TRUE);
    } else {
        return (FALSE);
    }
    
#ifdef __DEBUG_LAST_    
    p_temp = p_header->next;
    while ( p_temp) {
        p_last = p_temp;
        p_temp = p_temp->next;
    }

    if ( p_last->item == p_item->item) {
        return TRUE;
    } else {
        return FALSE;
    }
#endif /* __DEBUG_LAST_ */    
}

/* Name     : getLengthDoubleList                                            */
/* Function : Get the length of the double list                              */
/* Input    : p_header    an list pointer                                    */
/* Output   : Length of list                                                 */
UINT32 getLengthDoubleList(const DoubleList p_header)
{
    DoubleList p_temp  = LIST_NULL;
    UINT32     counter = 0;

    if ( !p_header) {
        debugError("<getLengthDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (0);
    }

    p_temp = p_header->next;
    while ( p_temp) {
        counter++;

        p_temp = p_temp->next;
    }

    return (counter);
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
    DoubleList p_temp  = LIST_NULL;
    UINT32     counter = 0;

    if ( p_header) {
        debugError("<getIndexByItemDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_temp = p_header->next;
    while ( p_temp &&
            (p_temp->item != item)) {
        counter++;
        p_temp = p_temp->next;            
    }

    if ( p_temp->item == item) {
        *p_index = counter;

        return (TRUE);
    } else {
        *p_index = 0;

        return (FALSE);
    }
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
    DoubleList p_ptr = LIST_NULL;
    UINT32     i;

    if ( !p_header) {
        debugError("<getItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    if ( !p_item) {
        debugError("<getItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    i = 0;
    p_ptr = p_header->next;
    while ( (p_ptr) &&
            (i < index)) {
        p_ptr = p_ptr->next;
        ++i;
    }

    if ( !p_ptr || i >= index) {
        *p_item = 0;
        
        return (FALSE);
    } else {
        *p_item = p_ptr->item;

        return (TRUE);
    }
}

/* Name     : findItemDoubleList                                             */
/* Function : Find specific item by item                                     */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When find it, TRUE will be returned, or else FALSE             */
Position findItemDoubleList(const DoubleList p_header,
                            ElemType         item)
{
    Position p_temp = LIST_NULL;

    if ( !p_header) {
        debugError("<findItemDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (LIST_NULL);
    }

    p_temp = p_header->next;
    while ( p_temp && (item != p_temp->item)) {
        p_temp = p_temp->next;
    }

    if ( item == p_temp->item) {
        return (p_temp);
    } else {
        return (LIST_NULL);
    }
}

/* Name     : deleteItemHeaderDoubleList                                     */
/* Function : Find specific item by item                                     */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When find it, TRUE will be returned, or else FALSE             */
STATE deleteItemHeaderDoubleList(DoubleList p_header,
                                 ElemType  *p_item)
{
    Position p_curr = LIST_NULL;
    
    if ( !p_header) {
        debugError("<deleteItemHeaderDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    if ( p_header->next) {
        p_curr = p_header->next;
        if ( p_curr->next) {
            *p_item             = p_curr->item;

            p_header->next      = p_curr->next;
            p_curr->next->prior = p_header;

            free(p_curr);

            return (TRUE);
        } else {
            *p_item = p_curr->item;
            p_header->next = LIST_NULL;

            free(p_curr);

            return (TRUE);
        }
    } else {
        *p_item = 0;

        return (FALSE);
    }
}

/* Name     : deleteItemTailDoubleList                                       */
/* Function : Delete last node of double list                                */
/* Input    : p_header  an list pointer
              item      deleted value member                                 */
/* Output   : When deleted successfully, TRUE will be returned, or else FALSE*/
STATE deleteItemTailDoubleList(DoubleList p_header,
                               ElemType  *p_item)
{
    Position p_curr = LIST_NULL;
    Position p_last = LIST_NULL;
    
    if ( !p_header) {
        debugError("<deleteItemTailDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_curr = p_header->next;
    while ( p_curr) {
        if ( p_curr->next ) {
            p_last = p_curr;
            p_curr = p_curr->next;
            continue;
        } else if ( TRUE == isLastDoubleList(p_header, p_curr)) {
            *p_item      = p_curr->item;

            p_last->next = LIST_NULL;
            free(p_curr);
            p_curr       = LIST_NULL;

            return (TRUE);
        } else {
            *p_item = 0;
            return (FALSE);
        }
    }

    return (TRUE);
}

/* Name     : deleteItemDoubleList                                           */
/* Function : Delete specific node which value is equal of double list       */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When deleted successfully, TRUE will be returned, or else FALSE*/
STATE deleteItemDoubleList(DoubleList p_header, ElemType item)
{
    Position p_curr = LIST_NULL;
    Position p_last = LIST_NULL;
    
    if ( !p_header) {
        debugError("<deleteItemDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_curr = p_header->next;
    p_last = p_header;
    while ( p_curr) {
        if ( item == p_curr->item) {
            if ( TRUE == isLastDoubleList(p_header, p_curr)) {
                p_last->next = LIST_NULL;
                free(p_curr);
                p_curr       = LIST_NULL;
            } else {
                p_curr->next->prior = p_last;
                p_last->next        = p_curr->next;
                free(p_curr);
                p_curr              = LIST_NULL;
            }

            return (TRUE);
        }

        p_last = p_curr;
        p_curr = p_curr->next;
    }

    return (FALSE);
}

/* Name     : deleteItemByIndexDoubleList                                    */
/* Function : Delete specific node which value is equal of double list       */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When deleted successfully, TRUE will be returned, or else FALSE*/
STATE deleteItemByIndexDoubleList(DoubleList p_header,
                                  UINT32     index,
                                  ElemType  *p_item)
{
    Position p_last  = LIST_NULL;
    Position p_curr  = LIST_NULL;
    UINT32   counter = 0;
    UINT32   length  = 0;
    
    if ( !p_header) {
        debugError("<deleteItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    length = getLengthDoubleList(p_header);
    if ( index > length) {
        debugError("<deleteItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_curr = p_header->next;
    p_last = p_header;
    while ( p_curr && (counter < (index - 1))) {
        p_last = p_curr;
        p_curr = p_curr->next;

        ++counter;
    }

    *p_item = p_curr->item;
    if ( TRUE == isLastDoubleList(p_header, p_curr)) {
        p_last->next = LIST_NULL;
        free(p_curr);
        p_curr = LIST_NULL;
    } else {
        p_curr->next->prior = p_last;
        p_last->next = p_curr->next;
        free(p_curr);
        p_curr = LIST_NULL;
    }

    return (TRUE);
}

/* Name     : insertItemHeaderDoubleList                                     */
/* Function : Insert node into header of double list                         */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE*/
STATE insertItemHeaderDoubleList(DoubleList p_header,
                                 ElemType   item)
{
    DoubleList p_node = LIST_NULL;
    
    if ( !p_header) {
        debugError("<insertItemHeaderDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_node = createNodeDoubleList();
    if ( !p_node) {
        debugError("<insertItemHeaderDoubleList-NULL>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_node->item   = item;
    p_node->next   = p_header->next;
    p_node->prior  = p_header;
    p_header->next = p_node;

    return (TRUE);
}

/* Name     : insertItemTailDoubleList                                       */
/* Function : Insert node into tail of double list                           */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE*/
STATE insertItemTailDoubleList(DoubleList p_header,
                               ElemType   item)
{
    DoubleList p_node = LIST_NULL;
    Position   p_curr = LIST_NULL;
    
    if ( !p_header) {
        debugError("<insertItemTailDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_node = createNodeDoubleList();
    if ( !p_node) {
        debugError("<insertItemTailDoubleList-NULL>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }
    p_node->item = item;
    p_node->next = LIST_NULL;

    p_curr = p_header->next;
    while ( p_curr) {
        if ( TRUE == isLastDoubleList(p_header, p_curr)) {
            p_curr->next  = p_node;
            p_node->prior = p_curr;

            return (TRUE);
        }

        p_curr = p_curr->next;
    }

    return (FALSE);
}

/* Name     : insertItemDoubleList                                           */
/* Function : Insert node into header or tail of double list                 */
/* Input    : p_header  an list pointer
              item      specific value member                                */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE*/
STATE insertItemDoubleList(DoubleList p_header,
                           ElemType   item,
                           InsertPos  position)
{
    switch ( position) {
    case INS_HEADER:
        return insertItemHeaderDoubleList(p_header, item);

        break;

    case INS_TAIL:
        return insertItemTailDoubleList(p_header, item);

        break;

    default:
        debugError("<insertItemDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }
}

/* Name     : insertItemByIndexDoubleList                                    */
/* Function : Insert node specific position of double list                   */
/* Input    : p_header  an list pointer
              index     specific position      
              item      specific value member                                */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE*/
STATE insertItemByIndexDoubleList(DoubleList p_header,
                                  UINT32     index,
                                  ElemType   item)
{
    Position   p_curr = LIST_NULL;
    Position   p_last = LIST_NULL;
    DoubleList p_node = LIST_NULL;
    UINT32     counts = 0;
    UINT32     i      = 0;
    
    if ( !p_header) {
        debugError("<insertItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    counts = getLengthDoubleList(p_header);
    if ( index > counts) {
        debugError("<insertItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    i = 0;
    p_curr = p_header->next;
    p_last = p_header;
    while ( p_curr && i < index) {
        p_last = p_curr;
        p_curr = p_curr->next;
        ++i;
    }

    p_node = createNodeDoubleList();
    if ( !p_node)  {
        debugError("<insertItemByIndexDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }
    p_node->item = item;

    if ( (!p_curr) || (i > index)) {
        return (FALSE);
    } else {
        p_node->next = p_curr;
        p_curr->prior = p_node;
        p_last->next  = p_node;
        p_node->prior = p_last;

        return (TRUE);
    }
}

/* Name     : getLastDoubleList                                              */
/* Function : Acquire last node of double list                               */
/* Input    : p_header  an list pointer                                      */
/* Output   : When find it, the pointer of last node will returned, or NULL  */
Position getLastDoubleList(const DoubleList p_header)
{
    Position p_curr = LIST_NULL;
    
    if ( !p_header) {
        debugError("<getLastDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (LIST_NULL);
    }

    p_curr = p_header;
    if ( !p_curr->next) {
        return (LIST_NULL);
    }
    
    p_curr = p_curr->next;
    while ( p_curr->next) {
        p_curr = p_curr->next;
    }

    return (p_curr);
}

/* Name     : retrieveDoubleList                                             */
/* Function : Retrieve every node of the double list                         */
/* Input    : p_header  an list pointer                                      */
/* Output   : When retrieve all nodes, TRUE will be returned, or else FALSE  */
STATE retrieveDoubleList(const DoubleList p_header,
                         void (*p_func)(ElemType item),
                         RetrieveDir      direct)
{
    Position p_curr = LIST_NULL;
    
    if ( !p_header) {
        debugError("<retrieveDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    if ( !p_func) {
        debugError("<retrieveDoubleList>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    switch ( direct) {
    case RET_FORWARD:
        p_curr = p_header->next;
        while ( p_curr) {
            (*p_func)(p_curr->item);
            p_curr = p_curr->next;
        }
        break;
    case RET_BACKWARD:
        p_curr = getLastDoubleList(p_header);
        while ( p_curr) {
            (*p_func)(p_curr->item);
            p_curr = p_curr->prior;
        }
        break;
    default:
        debugError("<retrieveDoubleList-Direction>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    return (TRUE);
}

/* Name     : sortDoubleList                                                 */
/* Function : Sort double list with specific order                           */
/* Input    : p_header  an list pointer
              order     sort order                                           */
/* Output   : When sorted successfully, TRUE will be returned, or else FALSE */
STATE sortDoubleList(DoubleList p_header,
                     SortOrder  order)
{
    Position p_curr = LIST_NULL;
    Position p_next = LIST_NULL;
    
    if ( !p_header) {
        debugError("<sortDoubleList-OBJECT>",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    p_curr = p_header->next;
    while ( p_curr) {
        p_next = p_curr->next;
        while ( p_next) {
            switch ( order) {
            case ASCENDING:
                if ( p_curr->item > p_next->item) {
                    _swap(&p_curr->item, &p_next->item);
                }
                break;
            case DESCENDING:
                if ( p_curr->item < p_next->item) {
                    _swap(&p_curr->item, &p_next->item);
                }
                break;
            default:
                debugError("<sortDoubleList-SORT>",
                           GET_FILE,
                           GET_LINE);

                return (FALSE);
            }

            p_next = p_next->next;
        }
        p_curr = p_curr->next;
    }

    return (TRUE);
}

/* Name     : mergeDoubleList                                                */
/* Function : Merge two double lists into another one                        */
/* Input    : p_list_a  list pointer
              p_list_b  list pointer
              p_list_c  merge to list pointer                                */
/* Output   : When merged successfully, TRUE will be returned, or else FALSE */
STATE mergeDoubleList(DoubleList p_list_a,
                      DoubleList p_list_b,
                      DoubleList p_list_c)
{
    Position p_curr_a = LIST_NULL;
    Position p_curr_b = LIST_NULL;
    Position p_curr_c = LIST_NULL;
    
    if ( !p_list_a || !p_list_b)  {
        debugError("<mergeDoubleList> header pointer NULL.",
                   GET_FILE,
                   GET_LINE);

        return (FALSE);
    }

    if ( !p_list_c) {
        p_list_c = createNodeDoubleList();
        if ( !p_list_c) {
            debugError("<mergeDoubleList> Create node error.",
                       GET_FILE,
                       GET_LINE);

            return (FALSE);
        }
    }

    if ( FALSE == _isSorted(p_list_a)) {
        if ( FALSE == sortDoubleList(p_list_a,
                                     ASCENDING)) {
            debugError("<mergeDoubleList> sorted list a error",
                       GET_FILE,
                       GET_LINE);

            return (FALSE);
        }
    }

    if ( FALSE == _isSorted(p_list_b)) {
        if ( FALSE == sortDoubleList(p_list_b,
                                     ASCENDING)) {
            debugError("<mergeDoubleList> sorted list b error",
                       GET_FILE,
                       GET_LINE);

            return (FALSE);
        }
    }

    p_curr_a = p_list_a->next;
    p_curr_b = p_list_b->next;
    p_curr_c = p_list_c;
    while ( p_curr_a && p_curr_b) {
        if ( p_curr_a->item < p_curr_b->item) {
            p_curr_c->next  = p_curr_a;
            p_curr_c        = p_curr_a;
            p_curr_a        = p_curr_a->next;
        } else {
            p_curr_c->next  = p_curr_b;
            p_curr_c        = p_curr_b;
            p_curr_b        = p_curr_b->next;
        }
    }

    p_curr_c->next = (p_curr_a ? p_curr_a : p_curr_b);
    
    return (TRUE);
}
