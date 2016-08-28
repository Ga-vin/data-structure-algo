#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#include "polynomial.h"

#define    GET_NEXT_NODE(list)    (list->next)

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

    p_node = GET_NEXT_NODE(p_header);
    while ( p_temp) {
        p_temp = GET_NEXT_NODE(p_node);
        free(p_node);
        p_node = p_temp;
    }
    free(p_header);
    p_header = LIST_NULL;

    return (TRUE);
}
