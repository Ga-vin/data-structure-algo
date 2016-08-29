#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#include "polynomial.h"

/* Name     : _list_get_next                                                 */
/* Function : Get next node of list                                          */
/* Input    : p_node -- specific node of list                                */
/* Output   : Next node of list                                              */
static PPoly _list_get_next(const PPoly p_node)
{
    return (p_node->next);
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
