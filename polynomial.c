#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>

#include "polynomial.h"

/* Name     : _is_equal                                                      */
/* Function : Check whether the two item is equal                            */
/* Input    : left  -- left item to be checked
              right -- right item to be checked                              */
/* Output   : If equal, TRUE will returned, or else FALSE                    */
#define    PRECISION    (1.0E-006)
static BOOL _is_equal(TermType left, TermType right)
{
    if ( (left.exp == right.exp) &&
         (abs(left.coef - right.coef) <= PRECISION) ) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

/* Name     : _list_get_next                                                 */
/* Function : Get next node of list                                          */
/* Input    : p_node -- specific node of list                                */
/* Output   : Next node of list                                              */
static PPoly _list_get_next(const PPoly p_node)
{
    return (p_node->next);
}

/* Name     : _list_get_data                                                 */
/* Function : Get data for the node of list                                  */
/* Input    : p_node -- specific node of list                                */
/* Output   : Item field of the node for the list                            */
static TermType _list_get_data(const PPoly p_node)
{
    return (p_node->item);
}

/* Name     : init_list                                                      */
/* Function : Initialize list node with malloc                               */
/* Input    : NONE                                                           */
/* Output   : New node pointer to be returned                                */
PPoly init_list(void)
{
    PPoly p_list = LIST_NULL;

    p_list = (PPoly)malloc(sizeof(Polynomial));
    p_list->next = LIST_NULL;
    memset(&(p_list->item), 0, sizeof(TermType));

    return (p_list);
}

/* Name     : destroy_list                                                   */
/* Function : Destroy list node one by one for all the list                  */
/* Input    : p_header    ---   header of list pointer                       */
/* Output   : Destroied successfully, TRUE will be returned, or else FALSE   */
STATE destroy_list(PPoly p_header)
{
    PPoly p_temp = LIST_NULL;
    PPoly p_node = LIST_NULL;

    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL.\n");

        return (FALSE);
#endif        
    }

    p_node = _list_get_next(p_header);
    while ( p_temp) {
        p_temp = _list_get_next(p_node);
        free(p_node);
        p_node = p_temp;
    }
    free(p_header);
    p_header = LIST_NULL;

    return (TRUE);
}

/* Name     : clear_list                                                     */
/* Function : Clear list node one by one for all the list                    */
/* Input    : p_header    ---   header of list pointer                       */
/* Output   : Cleared successfully, TRUE will be returned, or else FALSE   */
STATE clear_list(PPoly p_header)
{
    PPoly p_node = LIST_NULL;
    PPoly p_temp = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_node = _list_get_next(p_header);
    while ( p_node) {
        p_temp = _list_get_next(p_node);
        free(p_node);

        p_node = _list_get_next(p_node);
    }
    p_header->next = LIST_NULL;

    return (TRUE);
}

/* Name     : get_length_list                                                */
/* Function : Get how many nodes in the link list                            */
/* Input    : p_header    ---   header of list pointer                       */
/* Output   : How many nodes in the list                                     */
INT32 get_length_list(const PPoly p_header)
{
    PPoly p_node = LIST_NULL;
    INT32 cnt    = 0;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (-1);
    }

    p_node = _list_get_next(p_header);
    while ( p_node) {
        ++cnt;

        p_node = _list_get_next(p_node);
    }

    return (cnt);
}

/* Name     : is_empty_list                                                  */
/* Function : Check whether the list is empty                                */
/* Input    : p_header    ---   header of list pointer
           */
/* Output   : If it is empty, TRUE will be returned, or else FALSE           */
BOOL is_empty_list(const PPoly p_header)
{
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    return ((LIST_NULL == p_header->next) ?
            (TRUE) :
            (FALSE));
}

/* Name     : get_item_by_index_list                                         */
/* Function : Get item of node by specific index                             */
/* Input    : p_header    ---   header of list pointer
              index       ---   specific index
              p_term      ---   to store node has found                      */
/* Output   : If found, TRUE will be returned, or else FALSE                 */
STATE get_item_by_index_list(const PPoly p_header,
                             UINT32      index,
                             TermType   *p_term)
{
    PPoly  p_node = LIST_NULL;
    UINT32 cnt    = 0;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_term, 0, sizeof(TermType));
        return (FALSE);
    }

    if ( !p_term) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Storage space for term is NULL. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_term, 0, sizeof(TermType));
        return (FALSE);
    }

    if (  index > get_length_list(p_header)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Index has been exceeded. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_term, 0, sizeof(TermType));
        return (FALSE);
    }

    p_node = _list_get_next(p_header);
    while ( p_node && (cnt < index)) {
        ++cnt;
        p_node = _list_get_next(p_node);
    }

    memcpy(p_term, &p_node->item, sizeof(TermType));

    return (TRUE);
}

/* Name     : get_index_by_item_list                                         */
/* Function : Get index of node by specific item                             */
/* Input    : p_header    ---   header of list pointer
              term        ---   specific item
              p_index     ---   to store index has found                     */
/* Output   : If found, TRUE will be returned, or else FALSE                 */
STATE get_index_by_item_list(const PPoly p_header,
                             TermType    term,
                             UINT32     *p_index)
{
    PPoly  p_node = LIST_NULL;
    UINT32 cnt    = 0;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( !p_index) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Index pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_node = _list_get_next(p_header);
    while ( p_node &&
            ( FALSE == _is_equal(_list_get_data(p_node),term)) ) {
        cnt++;
        p_node = _list_get_next(p_node);
    }

    if ( !p_node) {
        *p_index = 0xFFFFFFFF;
        
        return (FALSE);
    }

    *p_index = cnt;
    return (TRUE);
}

/* Name     : find_item_list                                                 */
/* Function : Find a node which item is equal with specific one              */
/* Input    : p_header    ---   header of list pointer
              term        ---   specific item                                */
/* Output   : If found, the node pointer will be returned, or else NULL      */
PPoly find_item_list(const PPoly p_header,
                     TermType    term)
{
    PPoly p_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_node = _list_get_next(p_header);
    while ( p_node &&
            ( FALSE == _is_equal(_list_get_data(p_node), term)) ) {
        p_node = _list_get_next(p_node);
    }

    if ( !p_node) {
        return (LIST_NULL);
    } else {
        return (p_node);
    }
}

/* Name     : insert_item_header_list                                        */
/* Function : Insert item node into header of the list                       */
/* Input    : p_header    ---   header of list pointer
              term        ---   specific item                                */
/* Output   : If inserted successfully, TRUE will be returned, or else FALSE */
STATE insert_item_header_list(PPoly          p_header,
                              const TermType term)
{
    PPoly p_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_node = init_list();
    if ( !p_node) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Malloc pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }
    memcpy(&(p_node->item), &term, sizeof(TermType));
    p_node->next   = _list_get_next(p_header);
    p_header->next = p_node;

    return (TRUE);
}

/* Name     : insert_item_tail_list                                          */
/* Function : Insert item node into tail of the list                         */
/* Input    : p_header    ---   header of list pointer
              term        ---   specific item                                */
/* Output   : If inserted successfully, TRUE will be returned, or else FALSE */
STATE insert_item_tail_list(PPoly          p_header,
                            const TermType item)
{
    PPoly p_inter_node = LIST_NULL;
    PPoly p_new_node   = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_new_node = init_list();
    if ( !p_new_node) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Malloc NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }
    memcpy(&(p_new_node->item), &item, sizeof(TermType));

    p_inter_node = p_header;
    while ( _list_get_next(p_inter_node)) {
        p_inter_node = _list_get_next(p_inter_node);
    }

    p_new_node->next    = LIST_NULL;
    p_inter_node->next  = p_new_node;

    return (TRUE);
}

/* Name     : insert_item_list                                               */
/* Function : Insert node pointer into tail of the list                      */
/* Input    : p_header    ---   header of list pointer
              p_node      ---   specific node pointer                        */
/* Output   : If inserted successfully, TRUE will be returned, or else FALSE */
STATE insert_item_list(PPoly       p_header,
                       const PPoly p_node)
{
    PPoly p_inter_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( !p_node) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Node pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_inter_node = p_header;
    while ( _list_get_next(p_inter_node)) {
        p_inter_node = _list_get_next(p_inter_node);
    }

    p_inter_node->next = p_node;

    return (TRUE);
}

/* Name     : insert_item_by_index_list                                      */
/* Function : Insert node pointer into specific index of the list            */
/* Input    : p_header    ---   header of list pointer
              index       ---   specific index
              term        ---   data field to be inserted                    */
/* Output   : If inserted successfully, TRUE will be returned, or else FALSE */
STATE insert_item_by_index_list(PPoly          p_header,
                                UINT32         index,
                                const TermType term)
{
    PPoly  p_node     = LIST_NULL;
    PPoly  p_new_node = LIST_NULL;
    UINT32 cnt        = 0;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( (!index) || (index > get_length_list(p_header)) ) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Index invalid. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_new_node = init_list();
    if ( !p_new_node) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Malloc NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }
    memcpy(&(p_new_node->item), &term, sizeof(TermType));
    
    p_node = _list_get_next(p_header);
    while ( p_node && (cnt < index) ) {
        p_node = _list_get_next(p_node);
    }
    p_new_node->next = _list_get_next(p_node);
    p_node->next     = p_new_node;

    return (TRUE);
}

/* Name     : delete_item_header_list                                        */
/* Function : Delete node from header of the list                            */
/* Input    : p_header    ---   header of list pointer
              p_term      ---   item pointer to store node                   */
/* Output   : If deleted successfully, TRUE will be returned, or else FALSE  */
STATE delete_item_header_list(PPoly     p_header,
                              TermType *p_item)
{
    if ( !p_header) {
#ifdef  __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_item, 0, sizeof(TermType));
        return (FALSE);
    }

    if ( !p_item) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Store pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( 0 == get_length_list(p_header)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] There is no node list. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_item, 0, sizeof(TermType));
        return (FALSE);
    }

    memcpy(p_item, &p_header->next->item, sizeof(TermType));
    p_header->next = _list_get_next(_list_get_next(p_header));/* p_header->next->next; */

    return (TRUE);
}

/* Name     : delete_item_tail_list                                          */
/* Function : Delete node from tail of the list                              */
/* Input    : p_header    ---   header of list pointer
              p_term      ---   item pointer to store node                   */
/* Output   : If deleted successfully, TRUE will be returned, or else FALSE  */
STATE delete_item_tail_list(PPoly     p_header,
                            TermType *p_item)
{
    PPoly p_curr = LIST_NULL;
    PPoly p_last = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_item, 0, sizeof(TermType));
        return (FALSE);
    }

    if ( !p_item) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Store pointer is NULL. \n ");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( 0 == get_length_list(p_header)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] There is no node in ths list. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_item, 0, sizeof(TermType));
        return (FALSE);
    }

    p_last = p_curr = p_header;
    while ( _list_get_next(p_curr)) {
        p_last = p_curr;
        p_curr = _list_get_next(p_curr);
    }
    memcpy(p_item, &p_curr->item, sizeof(TermType));
    p_last->next = _list_get_next(p_curr);
    free(p_curr);

    return (TRUE);
}

/* Name     : delete_item_by_index_list                                      */
/* Function : Delete node from specific index of the list                    */
/* Input    : p_header    ---   header of list pointer
              index       ---   specific index to be deleted
              p_term      ---   item pointer to store node                   */
/* Output   : If deleted successfully, TRUE will be returned, or else FALSE  */
STATE delete_item_by_index_list(PPoly     p_header,
                                UINT32    index,
                                TermType *p_item)
{
    UINT32 cnt         = 1;
    PPoly  p_curr_node = LIST_NULL;
    PPoly  p_last_node = LIST_NULL;
    
    if ( !p_header ){
#ifdef __DEBUG_PRINTF        
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( !p_item) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Store pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( ( TRUE == is_empty_list(p_header)) ||
         (index > get_length_list(p_header)) ) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Index exceed. \n");
#endif /* __DEBUG_PRINTF */

        memset(p_item, 0, sizeof(TermType));
        return (FALSE);
    }

    p_last_node = p_header;
    p_curr_node = _list_get_next(p_header);
    while ( p_curr_node && (cnt < index))  {
        ++cnt;
        p_last_node = p_curr_node;
        p_curr_node = _list_get_next(p_curr_node);
    }

    if ( (!p_curr_node) || (cnt > index)) {
        memset(p_item, 0, sizeof(TermType));

        return (FALSE);
    } else {
        memcpy(p_item, &p_curr_node->item, sizeof(TermType));
        p_last_node->next = _list_get_next(p_curr_node);
        free(p_curr_node);

        return (TRUE);
    }
}

/* Name     : delete_item_list                                               */
/* Function : Delete node from list with specific node                       */
/* Input    : p_header    ---   header of list pointer
              p_node      ---   specific node                                */
/* Output   : If deleted successfully, TRUE will be returned, or else FALSE  */
STATE delete_item_list(PPoly       p_header,
                       const PPoly p_node)
{
    PPoly p_temp = LIST_NULL;
    PPoly p_last = LIST_NULL;
    
    if ( !p_header || !p_node) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( TRUE == is_empty_list(p_header)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] List is empty. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }
    
    p_temp = _list_get_next(p_header);
    p_last = p_header;
    while ( p_temp) {
        if ( TRUE == _is_equal(_list_get_data(p_temp),
                               _list_get_data(p_node))) {
            p_last->next = _list_get_next(p_temp);
            free(p_temp);
            return (TRUE);
        }

        p_last = p_temp;
        p_temp = _list_get_next(p_temp);
    }

    return (FALSE);
}
