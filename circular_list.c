#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "circular_list.h"

/* Name     : createCList                                                    */
/* Function : Create a node for element of double direction circular list    */
/* Input    : NONE                                                           */
/* Output   : Object of pointer points to node has been created              */
PtrCNode createCList(void)
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

    return (p_node);
}

