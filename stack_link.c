#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include "stack_link.h"

/* Name     : init_lstack                                                    */
/* Function : Initialization for the stack                                   */
/* Input    : NONE                                                           */
/* Output   : When initialized successfully, stack pointer will be returned  */
PStackLink init_lstack(void)
{
    PStackLink p_new_stack = STACK_LINK_NULL;

    p_new_stack = (PStackLink)malloc(sizeof(StackLink));
    if ( !p_new_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Malloc for starter of stack fail. \n");
#endif /* __DEBUG_PRINTF_ */

        return (STACK_LINK_NULL);
    }

    p_new_stack->next = STACK_LINK_NULL;

    return (p_new_stack);
}

/* Name     : destroy_lstack                                                 */
/* Function : Destroy the stack                                              */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When destroyed successfully, TRUE will be returned, or else FALSE */
STATE      destroy_lstack(PStackLink p_stack)
{
    
}

/* Name     : clear_lstack                                                   */
/* Function : Clear the whole stack                                          */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When cleared successfully, TRUE will be returned, or else FALSE*/
STATE      clear_lstack(PStackLink p_stack)
{
    
}

/* Name     : is_empty_lstack                                               */
/* Function : Check whether the stack is empty                               */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When it is empty, TRUE will be returned, or else FALSE         */
BOOL      is_empty_lstack(const PStackLink p_stack)
{
    
}

/* Name     : get_length_lstack                                             */
/* Function : Get how many nodes in the stack                                */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : How many nodes in the stack                                    */
INT32      get_length_lstack(const PStackLink p_stack)
{
    
}

/* Name     : get_top_lstack                                                 */
/* Function : Acquire the top item in the stack                              */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When got successfully, TRUE will be returned, or else FALSE    */
STATE      get_top_lstack(const PStackLink p_stack)
{
    
}

/* Name     : push_lstack                                                    */
/* Function : Insert a new item into top of the stack                        */
/* Input    : p_stack   --- stack pointer
              item      --- item to be inserted                              */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE */
STATE      push_lstack(PStackLink     p_stack,
                       StackValueType item)
{
    
}

/* Name     : pop_lstack                                                     */
/* Function : Pop the top item from the stack                                */
/* Input    : p_stack   --- stack pointer
              p_item    --- item to be removed                               */
/* Output   : When removed successfully, TRUE will be returned, or else FALSE */
STATE      pop_lstack(PStackLink      p_stack,
                      StackValueType *p_item)
{
    
}

/* Name     : traverse_lstack                                                */
/* Function : Traverse each item of the stack                                */
/* Input    : p_stack   --- stack pointer
              callback  --- function pointer to traverse stack               */
/* Output   : When traversed successfully, TRUE will be returned, or else FALSE */
STATE      traverse_lstack(const PStackLink p_stack,
                           void (*callback)(StackValueType item))
{
    
}
