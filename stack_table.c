#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "stack_table.h"

/* Name     : init_stack                                                     */
/* Function : Initialization for stack with table format                     */
/* Input    : size   --- the size of the stack                               */
/* Output   : The stack has been created                                     */
StackTable init_tstack(StackSize size)
{
    StackTable stack;

    memset(&stack, 0, sizeof(StackTable));
    stack.top    = STACK_NULL;
    stack.bottom = STACK_NULL;
    
    if ( !size) {
        stack.size = STACK_INIT_SIZE;
    } else {
        stack.size = size;
    }

    stack.top    = (StackItemType *)malloc(sizeof(StackItemType) * stack.size);
    if ( !stack.top) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Malloc stack top pointer fail. \n");
#endif /* __DEBUG_PRINTF_ */

        return (stack);
    }
    stack.bottom = stack.top;

    return (stack);
}

/* Name     : destroy_stack                                                  */
/* Function : Destroy for stack with table format                            */
/* Input    : p_stack   --- the stack which has been created                 */
/* Output   : When destroied successfully, TRUE will be returned, or else FALSE*/
STATE destroy_tstack(PStackTable p_stack)
{
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( !p_stack->top ||
         !p_stack->bottom) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack top or bottom pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    free(p_stack->top);
    p_stack->top    = STACK_NULL;
    p_stack->bottom = STACK_NULL;
    p_stack->size   = 0;
    
    return (TRUE);
}

/* Name     : clear_tstack                                                   */
/* Function : Clear for stack with table format                              */
/* Input    : p_stack   --- the stack which has been created                 */
/* Output   : When cleared successfully, TRUE will be returned, or else FALSE*/
STATE clear_tstack(PStackTable p_stack)
{

    return (TRUE);
}

/* Name     : is_empty_tstack                                                */
/* Function : Check whether the stack is empty                               */
/* Input    : p_stack   --- the stack which has been created                 */
/* Output   : When empty, TRUE will be returned, or else FALSE               */
BOOL is_empty_tstack(const PStackTable p_stack)
{

}

/* Name     : get_length_tstack                                              */
/* Function : Get how many elements in the stack                             */
/* Input    : p_stack   --- the stack which has been created                 */
/* Output   : How many elements in it                                        */
StackSize get_length_tstack(const PStackTable p_stack)
{
    
}

/* Name     : get_top_tstack                                                 */
/* Function : Get the top element in the stack                               */
/* Input    : p_stack   --- the stack which has been created
              p_item    --- to store the top element                         */
/* Output   : When got successfully, TRUE will be returned, or else FALSE    */
STATE get_top_tstack(const PStackTable  p_stack,
                     StackItemType     *p_item)
{


    return (TRUE);
}

/* Name     : push_tstack                                                    */
/* Function : Push specific item into the top of stack                       */
/* Input    : p_stack   --- the stack which has been created
              item      --- specific element to be push                      */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE*/
STATE push_tstack(PStackTable   p_stack,
                  StackItemType item)
{


    return (TRUE);
}

/* Name     : pop_tstack                                                     */
/* Function : Pop top item from the stack                                    */
/* Input    : p_stack   --- the stack which has been created
              p_item    --- store element to be deleted                      */
/* Output   : When popped successfully, TRUE will be returned, or else FALSE */
STATE pop_tstack(PStackTable    p_stack,
                 StackItemType *p_item)
{


    return (TRUE);
}

/* Name     : traverse_tstack                                                */
/* Function : Traverse each element of the stack                             */
/* Input    : p_stack   --- the stack which has been created
              callback  --- callback function to visit each element of stack */
/* Output   : When visited successfully, TRUE will be returned, or else FALSE*/
STATE traverse_tstack(const PStackTable p_stack,
                      void (*callback)(const StackItemType item))
{


    return (TRUE);
}
