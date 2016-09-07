#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>

#include "polynomial.h"

void __debug_print(const TermType item)
{
    fprintf(stdout, "<%5.3f, %2d> ", item.coef, item.exp);
}

static BOOL _is_exp_greater(TermType left, TermType right)
{
    return ((left.exp > right.exp) ? (TRUE) : (FALSE));
}

static BOOL _is_exp_less(TermType left, TermType right)
{
    return ((left.exp < right.exp) ? (TRUE) : (FALSE));
}

static BOOL _is_exp_equal(TermType left, TermType right)
{
    return ((left.exp == right.exp) ? (TRUE) : (FALSE));
}

static BOOL _swap_item_node(PPoly p_left, PPoly p_right)
{
    TermType item;

    memcpy(&item, &p_left->item, sizeof(TermType));
    memcpy(&p_left->item, &p_right->item, sizeof(TermType));
    memcpy(&p_right->item, &item, sizeof(TermType));

    return (TRUE);
}

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

    p_list       = (PPoly)malloc(sizeof(Polynomial));
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
    UINT32 cnt        = 1;
    
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
        ++cnt;
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

/* Name     : find_last_list                                                 */
/* Function : Find the last node of list                                     */
/* Input    : p_header    ---   header of list pointer                       */
/* Output   : If found successfully, the node will be returned, or else NULL */
PPoly find_last_list(const PPoly p_header)
{
    PPoly p_curr_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (LIST_NULL);
    }

    p_curr_node = p_header;
    while ( _list_get_next(p_curr_node)) {
        p_curr_node = _list_get_next(p_curr_node);
    }

    return (p_curr_node);
}

/* Name     : retrieve_list                                                  */
/* Function : Retrieve every node of the list                                */
/* Input    : p_header    ---   header of list pointer                       */
/* Output   : If trieved successfully, TRUE will be returned, or else FALSE  */
STATE retrieve_list(const PPoly p_header,
                    void (*callback)(const TermType term))
{
    PPoly p_curr_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( TRUE == is_empty_list(p_header)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] List is Empty. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }
    
    p_curr_node = _list_get_next(p_header);
    while ( p_curr_node) {
        callback(_list_get_data(p_curr_node));
        p_curr_node = _list_get_next(p_curr_node);
    }

    return (TRUE);
}

/* Name     : sort_list                                                      */
/* Function : Sort every node of the list with specific order                */
/* Input    : p_header    ---   header of list pointer
              order       ---   specific sorted order                        */
/* Output   : If sorted successfully, TRUE will be returned, or else FALSE   */
STATE sort_list(PPoly p_header, SortOrder order)
{
    PPoly p_curr_node = LIST_NULL;
    PPoly p_last_node = LIST_NULL;
    
    if ( !p_header) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] List header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( is_empty_list(p_header) ||
         (1 == get_length_list(p_header))) {
        return (TRUE);
    }

    p_curr_node = _list_get_next(p_header);
    while ( p_curr_node) {
        p_last_node = _list_get_next(p_curr_node);
        while ( p_last_node) {
            switch (order) {

            case ASCENDING:
                if ( _is_exp_greater(_list_get_data(p_curr_node),
                                     _list_get_data(p_last_node))) {
                    _swap_item_node(p_curr_node, p_last_node);
                }
                break;

            case DESCENDING:
                if ( _is_exp_less(_list_get_data(p_curr_node),
                                  _list_get_data(p_last_node))) {
                    _swap_item_node(p_curr_node, p_last_node);
                }
                break;

            default:
                break;
            }

            p_last_node = _list_get_next(p_last_node);
        }

        p_curr_node = _list_get_next(p_curr_node);
    }

    return (TRUE);
}

/* Name     : merge_list                                                     */
/* Function : Merge two list into a new list with ascending order            */
/* Input    : p_left        ---   to be merged
              p_right       ---   to be merged
              p_new_header  ---   to store new list                          */
/* Output   : If merged successfully, TRUE will be returned, or else FALSE   */
STATE merge_list(PPoly p_left,
                 PPoly p_right,
                 PPoly p_new_header)
{
    PPoly p_curr_left_node  = LIST_NULL;
    PPoly p_curr_right_node = LIST_NULL;
    
    if ( !p_left ||
         !p_right) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] List header pointer is NULL. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( is_empty_list(p_left) &&
         !is_empty_list(p_right)) {
        p_left = _list_get_next(p_right);

        return (TRUE);
    }

    if ( !is_empty_list(p_left) &&
         is_empty_list(p_right)) {
        
        return (TRUE);
    }

    if ( !p_new_header) {
        p_new_header = (PPoly)malloc(sizeof(Polynomial));
        if ( !p_new_header) {
            fprintf(stderr, "[x] Malloc space fail. \n");

            return (FALSE);
        }
    }

    if ( FALSE == sort_list(p_left, ASCENDING)) {
#ifdef __DEBUG_PRINTF        
        fprintf(stderr, "[x] Sort left list error. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    if ( FALSE == sort_list(p_right, ASCENDING)) {
#ifdef __DEBUG_PRINTF
        fprintf(stderr, "[x] Sort right list error. \n");
#endif /* __DEBUG_PRINTF */

        return (FALSE);
    }

    p_curr_left_node  = _list_get_next(p_left);
    p_curr_right_node = _list_get_next(p_right);
    while ( p_curr_left_node &&
            p_curr_right_node) {
        if ( TRUE == _is_exp_less(_list_get_data(p_curr_left_node),
                                  _list_get_data(p_curr_right_node))) {
            if ( FALSE == append_list(p_new_header, _list_get_data(p_curr_left_node))) {
#ifdef __DEBUG_PRINTF
                fprintf(stderr, "[x] Append left to new list error. \n");
#endif /* __DEBUG_PRINTF */

                return (FALSE);
            }
            p_curr_left_node = _list_get_next(p_curr_left_node);
        } else {
            if ( FALSE == append_list(p_new_header, _list_get_data(p_curr_right_node))) {
#ifdef __DEBUG_PRINTF
                fprintf(stderr, "[x] Append right to new list error. \n");
#endif /* __DEBUG_PRINTF */

                return (FALSE);
            }
            p_curr_right_node = _list_get_next(p_curr_right_node);
        }
    }

    if ( p_curr_left_node) {
        if ( FALSE == insert_item_list(p_new_header, p_curr_left_node)) {
#ifdef __DEBUG_PRINTF
            fprintf(stderr, "[x] Insert item to list left error. \n");
#endif /* __DEBUG_PRINTF */

            return (FALSE);
        }
    }

    if ( p_curr_right_node) {
        if ( FALSE == insert_item_list(p_new_header, p_curr_right_node)) {
#ifdef __DEBUG_PRINTFf
            fprintf(stderr, "[x] Insert item to list right error. \n");
#endif /* __DEBUG_PRINTF */

            return (FALSE);
        }
    }

    return (TRUE);
}

/* Name     : append_list                                                    */
/* Function : Append node into the tail of list                              */
/* Input    : p_header      ---   to be merged
              item          ---   item to be appended                        */
/* Output   : If appended successfully, TRUE will be returned, or else FALSE */
STATE append_list(PPoly          p_header,
                  const TermType item)
{
    return (insert_item_tail_list(p_header, item));
}

/* Name     : remove_list                                                    */
/* Function : Remove last node from the tail of list                         */
/* Input    : p_header      ---   to be merged
              item          ---   item to be removed                         */
/* Output   : If removed successfully, TRUE will be returned, or else FALSE  */
STATE remove_list(PPoly     p_header,
                  TermType *p_item)
{
    return (delete_item_tail_list(p_header, p_item));
}

/* Name     : create_polyn                                                   */
/* Function : Create header of the polynomial                                */
/* Input    : NONE                                                           */
/* Output   : When created successfully, header of polynomial will be returned, or else LIST_NULL                                              */
PPoly create_polyn(void)
{
    return (init_list());
}

/* Name     : destroy_polyn                                                  */
/* Function : Destroied every node of the polynomial                         */
/* Input    : p_header  ---  header pointer of polynomial                    */
/* Output   : When destroied successfully, header of polynomial will be returned, or else LIST_NULL                                            */
STATE destroy_polyn(PPoly p_header)
{
    return (destroy_list(p_header));
}

/* Name     : is_empty_polyn                                                 */
/* Function : Check whether the polynomial is empty                          */
/* Input    : p_header  ---  header pointer of polynomial                    */
/* Output   : When it is empty, TRUE will be returned, or else FALSE         */
BOOL is_empty_polyn(const PPoly p_header)
{
    return (is_empty_list(p_header));
}

/* Name     : get_length_polyn                                               */
/* Function : How many nodes in the polynomial                               */
/* Input    : p_header  ---  header pointer of polynomial                    */
/* Output   : How many nodes in the polynomial                               */
UINT32 get_length_polyn(const PPoly p_header)
{
    return (get_length_list(p_header));
}

/* Name     : append_polyn                                                   */
/* Function : Append new item into tail of polynomial                        */
/* Input    : p_header  ---  header pointer of polynomial
              item      ---  to be appended                                  */
/* Output   : When appended successfully, TRUE will be returned, or else FALSE*/
STATE append_polyn(PPoly          p_header,
                   const TermType item)
{
    return (append_list(p_header,
                        item));
}

/* Name     : print_polyn                                                    */
/* Function : Print each node of polynomial                                  */
/* Input    : p_header  ---  header pointer of polynomial                    */
/* Output   : When print successfully, TRUE will be returned, or else FALSE  */
STATE print_polyn(const PPoly p_header)
{
    PPoly    p_node = LIST_NULL;
    TermType item;
    
    if ( !p_header) {
        fprintf(stderr, "[x] Polynomial list is NULL. \n");

        return (FALSE);
    }

    if ( TRUE == is_empty_polyn(p_header)) {
        fprintf(stderr, "[x] Polynomial is Empty. \n");

        return (FALSE);
    }

    if ( FALSE == sort_polyn(p_header)) {
        fprintf(stderr, "[x] Sort polynomial error. \n");

        return (FALSE);
    }

    fprintf(stdout, "P(x) = ");
    p_node = _list_get_next(p_header);
    while ( p_node) {
        item = _list_get_data(p_node);
        fprintf(stdout, "%5.2fx^%2d ", item.coef, item.exp);
        if ( _list_get_next(p_node)) {
            fprintf(stdout, "+ ");
        }

        p_node = _list_get_next(p_node);
    }
    putchar('\n');

    return (TRUE);
}

/* Name     : sort_polyn                                                     */
/* Function : Sort the polynomial with ascending order                       */
/* Input    : p_header  ---  header pointer of polynomial                    */
/* Output   : When sorted successfully, TRUE will be returned, or else FALSE */
STATE sort_polyn(PPoly p_header)
{
    return (sort_list(p_header, ASCENDING));
}
