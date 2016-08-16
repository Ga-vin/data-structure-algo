#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "circular_list.h"

BOOL equal(ElemType left, ElemType right)
{
    return ((left == right) ? (TRUE) : (FALSE));
}

BOOL greater(ElemType left, ElemType right)
{
    return ((left > right) ? (TRUE) : (FALSE));
}

BOOL less(ElemType left, ElemType right)
{
    return ((left < right) ? (TRUE) : (FALSE));
}

/* Name     : createNodeCList                                                */
/* Function : Create a node for element of double direction circular list    */
/* Input    : NONE                                                           */
/* Output   : Object of pointer points to node has been created              */
PtrCNode createNodeCList(void)
{
    PtrCNode p_node = LIST_NULL;

    p_node = (PtrCNode)malloc(sizeof(CircularLNode));
    if ( !p_node) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (LIST_NULL);
    }

    p_node->p_next = p_node->p_prior = p_node;
    p_node->data   = CIRCULE_LIST_PRIM_DATA;

    return (p_node);
}

/* Name     : destroyCList                                                   */
/* Function : Destroy all nodes of the list one by one                       */
/* Input    : p_list -- header pointer of the list                           */
/* Output   : If destroy successfully, TRUE will be returned, or else FALSE  */
STATE destroyCList(CircularList p_list)
{
    PtrCNode p_node = LIST_NULL;
    PtrCNode p_temp = LIST_NULL;

    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        p_temp = p_node->p_next;
        free(p_node);
        p_node = p_temp;
    }

    /* Release header at last */
    free(p_list);
    p_list = LIST_NULL;

    return (TRUE);
}

/* Name     : clearCList                                                     */
/* Function : Clear all nodes of the list one by one                         */
/* Input    : p_list -- header pointer of the list                           */
/* Output   : If clear successfully, TRUE will be returned, or else FALSE    */
STATE clearCList(CircularList p_list)
{
    PtrCNode p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        p_node = p_node->p_next;
        free(p_node->p_prior);
    }

    p_node->p_next = p_list->p_next = p_list;

    return (TRUE);
}

/* Name     : getLengthCList                                                 */
/* Function : Get length of the list                                         */
/* Input    : p_list -- header pointer of the list                           */
/* Output   : The counters of list                                           */
UINT32 getLengthCList(const CircularList p_list)
{
    PtrCNode p_node = LIST_NULL;
    UINT32   cnt    = 0;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        cnt++;
        p_node = p_node->p_next;
    }

    return (cnt);
}

/* Name     : isEmptyCList                                                   */
/* Function : Check whether the list is empty                                */
/* Input    : p_list -- header pointer of the list                           */
/* Output   : If the list is empty, TRUE will returned, or else FALSE        */
BOOL isEmptyCList(const CircularList p_list)
{
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }
    
    return ((p_list->p_next == p_list) ? (TRUE) : (FALSE));
}

/* Name     : getItemByIndexCList                                            */
/* Function : Acquire item by specific index                                 */
/* Input    : p_list -- header pointer of the list
              index  -- specific index to find
              p_item -- to store the item found
           */
/* Output   : If the value is found, TRUE will be returned, or else FALSE    */
STATE getItemByIndexCList(const CircularList p_list,
                          UINT32    index,
                          ElemType *p_item)
{
    PtrCNode p_node = LIST_NULL;
    UINT32   cnt    = 1;
    BOOL     flag   = FALSE;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        if ( cnt == index) {
            *p_item = p_node->data;
            flag = TRUE;
            break;
        }
        p_node = p_node->p_next;
    }

    if ( TRUE == flag) {
        return (TRUE);
    } else {
        *p_item = CIRCULE_LIST_PRIM_DATA;
        return (FALSE);
    }
}

/* Name     : locateItemCList                                                */
/* Function : Acquire item by specific item                                  */
/* Input    : p_list  -- header pointer of the list
              item    -- specific item to find
              compare -- method to call to compare
          */
/* Output   : If the value is found, TRUE will be returned, or else FALSE    */
STATE locateItemCList(const CircularList p_list,
                      ElemType item,
                      BOOL (*compare)(ElemType left, ElemType right))
{
    PtrCNode p_node = LIST_NULL;
    BOOL     flag   = FALSE;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !compare) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        if ( TRUE == compare(p_node->data, item)) {
            flag = TRUE;
            break;
        }
        p_node = p_node->p_next;
    }

    if ( TRUE == flag) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

/* Name     : getPriorItemCList                                              */
/* Function : Acquire prior item by specific item                            */
/* Input    : p_list    -- header pointer of the list
              curr_item -- current item to find
              p_prior_item -- item to store prior item
          */
/* Output   : If the value is found, TRUE will be returned, or else FALSE    */
STATE getPriorItemCList(const CircularList p_list,
                        ElemType  curr_item,
                        ElemType *p_prior_item)
{
    PtrCNode p_curr = LIST_NULL;
#ifdef __DEBUG_SUG1    
    PtrCNode p_last = LIST_NULL;
#endif    
    BOOL     flag   = FALSE;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

#ifdef __DEBUG_SUG1    
    p_curr = p_list->p_next;
    p_last = p_list;
    while ( p_curr != p_list) {
        if ( curr_item == p_curr->data) {
            flag          = TRUE;
            *p_prior_item = p_last->data;
            break;
        }

        p_last = p_curr;
        p_curr = p_curr->p_next;
    }
#endif /* __DEBUG_SUG1 */
    
    /* Set p_curr points to the second node of list */
    p_curr = p_list->p_next->p_next;
    while ( p_curr != p_list) {
        if ( curr_item == p_curr->data) {
            flag          = TRUE;
            *p_prior_item = p_curr->p_prior->data;
            break;
        }
    }

    if ( TRUE == flag) {
        return (TRUE);
    } else {
        *p_prior_item = CIRCULE_LIST_PRIM_DATA;
        return (FALSE);
    }
}

/* Name     : getNextItemCList                                               */
/* Function : Get the next item by specified one                             */
/* Input    : p_list    -- header pointer of the list
              curr_item -- current item to find
              p_next_item -- item to store next item
           */
/* Output   : If the value is found, TRUE will be returned, or else FALSE    */
STATE getNextItemCList(const CircularList p_list,
                       ElemType  curr_item,
                       ElemType *p_next_item)
{
    PtrCNode p_curr = LIST_NULL;
    BOOL     flag   = FALSE;
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

#ifdef __DEBUG_SUG2    
    p_curr = p_list->p_next;
    while ( p_curr->p_next != p_list) {
        if ( curr_item == p_curr->data) {
            flag         = TRUE;
            *p_next_item = p_curr->p_next->data;
            break;
        }

        p_curr = p_curr->p_next;
    }
#endif /* __DEBUG_SUG2 */

    p_curr = p_list->p_next->p_next;
    while ( p_curr != p_list) {
        if ( curr_item == p_curr->p_prior->data) {
            flag = TRUE;
            *p_next_item = p_curr->data;
        }

        p_curr = p_curr->p_next;
    }

    if ( TRUE == flag) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

/* Name     : getItemPtrCList                                                */
/* Function : Get the specific node by index                                 */
/* Input    : p_list    -- header pointer of the list
              index     -- specific index to find
           */
/* Output   : If it is found, the node will be returned, or else NULL        */
#define __DEBUG_FLAG
PtrCNode getItemPtrCList(const CircularList p_list,
                         UINT32             index)
{
    PtrCNode p_node = LIST_NULL;
    UINT32   cnt    = 1;
    BOOL     flag   = FALSE;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (LIST_NULL);
    }

    if ( index <= 0 || index > getLengthCList(p_list)) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (LIST_NULL);
    }

#ifdef __DEBUG_FLAG    
    p_node = p_list->p_next;
    while ( p_node != p_list) {
        if ( cnt == index) {
            flag = TRUE;
            break;
        }

        ++cnt;
        p_node = p_node->p_next;
    }

    if ( TRUE == flag) {
        return (p_node);
    } else {
        return (LIST_NULL);
    }
#endif /* __DEBUG_FLAG */

#ifdef __DEBUG_DIRECT    
    for (cnt = 1; cnt < index; ++cnt) {
        p_node = p_node->next;
    }
#endif /* __DEBUG_DIRECT */

    return (p_node);
}

/* Name     : insertItemHeaderCList                                          */
/* Function : Insert a new node into the header of list                      */
/* Input    : p_list    -- header pointer of the list
              item      -- item to be inserted the list
           */
/* Output   : If inserted successfully, TRUE will be returned, or else NULL  */
STATE insertItemHeaderCList(CircularList p_list, ElemType item)
{
    CircularList p_new_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_new_node = createNodeCList();
    if ( !p_new_node) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }
    p_new_node->data = item;

    p_new_node->p_next  = p_list->p_next;
    p_list->p_next      = p_new_node;
    p_new_node->p_prior = p_list->p_next->p_prior;

    return (TRUE);
}

/* Name     : insertItemTailCList                                            */
/* Function : Insert a new node into the tail of list                        */
/* Input    : p_list    -- header pointer of the list
              item      -- item to be inserted the list
           */
/* Output   : If inserted successfully, TRUE will be returned, or else NULL  */
STATE insertItemTailCList(CircularList p_list,
                          ElemType     item)
{
    CircularList p_new_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_new_node = createNodeCList();
    if ( !p_new_node) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }
    p_new_node->data        = item;
    p_list->p_prior->p_next = p_new_node;
    p_new_node->p_next      = p_list;
    p_list->p_prior         = p_new_node;

    return (TRUE);
}

/* Name     : insertItemByIndexCList                                         */
/* Function : Insert a new node into specific location of list               */
/* Input    : p_list    -- header pointer of the list
              index     -- specific location
              item      -- item to be inserted the list
           */
/* Output   : If inserted successfully, TRUE will be returned, or else NULL  */
STATE insertItemByIndexCList(CircularList p_list,
                             UINT32       index,
                             ElemType     item)
{
    CircularList p_new_node = LIST_NULL;
    CircularList p_node     = LIST_NULL;
    UINT32       cnt        = 1;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( index > getLengthCList(p_list)) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);
        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( (cnt < index) && (p_node != p_list)) {
        p_node = p_node->p_next;
        ++cnt;
    }

    p_new_node = createNodeCList();
    if ( !p_new_node) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_new_node->data    = item;
    p_new_node->p_next  = p_node->p_next;
    p_new_node->p_prior = p_node;
    p_node->p_next      = p_new_node;

    return (TRUE);
}

/* Name     : deleteItemHeaderCList                                          */
/* Function : Delete a node from the header of list                          */
/* Input    : p_list    -- header pointer of the list
              p_item    -- item to be deleted from the list
           */
/* Output   : If deleted successfully, TRUE will be returned, or else NULL   */
STATE deleteItemHeaderCList(CircularList p_list,
                            ElemType    *p_item)
{
    CircularList p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !p_item) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( TRUE == isEmptyCList(p_list)) {
        *p_item = CIRCULE_LIST_PRIM_DATA;

        return (FALSE);
    } else {
        *p_item = p_list->p_next->data;

        p_node                  = p_list->p_next;
        p_node->p_next->p_prior = p_list;
        p_list->p_next          = p_node->p_next;
        free(p_node);
        
        return (TRUE);
    }
}

/* Name     : deleteItemTailCList                                            */
/* Function : Delete a node from the tail of list                            */
/* Input    : p_list    -- header pointer of the list
              p_item    -- item to be deleted from the list
           */
/* Output   : If deleted successfully, TRUE will be returned, or else NULL   */
STATE deleteItemTailCList(CircularList p_list,
                          ElemType    *p_item)
{
    CircularList p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !p_item) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( TRUE == isEmptyCList(p_list)) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        *p_item = CIRCULE_LIST_PRIM_DATA;

        return (FALSE);
    }

    p_node = p_list;
    while ( p_node->p_next != p_list) {
        p_node = p_node->p_next;
    }

    *p_item = p_node->data;
    p_node->p_prior->p_next = p_list;    
    p_list->p_prior = p_node->p_prior;
    free(p_node);

    return (TRUE);
}

/* Name     : deleteItemByIndexCList                                         */
/* Function : Delete a node from the specific location of list               */
/* Input    : p_list    -- header pointer of the list
              index     -- specific location of list
              p_item    -- item to be deleted from the list
           */
/* Output   : If deleted successfully, TRUE will be returned, or else NULL   */
STATE deleteItemByIndexCList(CircularList p_list,
                             UINT32       index,
                             ElemType    *p_item)
{
    CircularList p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !p_item) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( TRUE == isEmptyCList(p_list)) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);
        *p_item = CIRCULE_LIST_PRIM_DATA;

        return (FALSE);
    }

    if ( (index <= 0) || (index > getLengthCList(p_list))) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);
        *p_item = CIRCULE_LIST_PRIM_DATA;

        return (FALSE);
    }

    p_node = getItemPtrCList(p_list, index);
    if ( !p_node) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);
        *p_item = CIRCULE_LIST_PRIM_DATA;

        return (FALSE);
    }
    
    *p_item = p_node->data;
    p_node->p_prior->p_next = p_node->p_next;
    p_node->p_next->p_prior = p_node->p_prior;
    free(p_node);

    return (TRUE);
}

/* Name     : traverseForwardCList                                           */
/* Function : Traverse each node of list by callback function                */
/* Input    : p_list      -- header pointer of the list
              ptrcallback -- function ptr to travserse node
           */
/* Output   : If traverse successfully, TRUE will be returned, or else NULL  */
STATE traverseForwardCList(const CircularList p_list,
                           void (*ptr_visit)(ElemType item))
{
    CircularList p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !ptr_visit) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_next;
    while ( p_node != p_list) {
        ptr_visit(p_node->data);

        p_node = p_node->p_next;
    }

    return (TRUE);
}

/* Name     : traverseBackwardCList                                          */
/* Function : Traverse each node of list by callback function                */
/* Input    : p_list      -- header pointer of the list
              ptrcallback -- function ptr to travserse node
           */
/* Output   : If traverse successfully, TRUE will be returned, or else NULL  */
STATE traverseBackwardCList(const CircularList p_list,
                            void (*ptr_visit)(ElemType item))
{
    CircularList p_node = LIST_NULL;
    
    if ( !p_list) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    if ( !ptr_visit) {
        errorHandler(GET_FILE,
                     GET_FUNC,
                     GET_LINE,
                     GET_DATE,
                     GET_TIME);

        return (FALSE);
    }

    p_node = p_list->p_prior;
    while ( p_node != p_list) {
        ptr_visit(p_node->data);

        p_node = p_node->p_prior;
    }

    return (TRUE);
}
