#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "circular_list.h"

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
