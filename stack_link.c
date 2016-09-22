#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include "stack_link.h"

#define    GET_NEXT_STACK(p_stack)    (p_stack->next)
#define    GET_STACK_DATA(p_stack)    (p_stack->item)

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
    PStackLink p_node = STACK_LINK_NULL;
    PStackLink p_temp = STACK_LINK_NULL;
    
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_node = GET_NEXT_STACK(p_stack);
    while ( p_node) {
        p_temp = GET_NEXT_STACK(p_node);
        free(p_node);
        p_node = p_temp;
    }
    free(p_stack);
    p_stack = STACK_LINK_NULL;

    return (TRUE);
}

/* Name     : clear_lstack                                                   */
/* Function : Clear the whole stack                                          */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When cleared successfully, TRUE will be returned, or else FALSE*/
STATE      clear_lstack(PStackLink p_stack)
{
    PStackLink p_node = STACK_LINK_NULL;
    PStackLink p_temp = STACK_LINK_NULL;
    
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_node = GET_NEXT_STACK(p_stack);
    while ( p_node) {
        p_temp = GET_NEXT_STACK(p_node);
        free(p_node);
        p_node = p_temp;
    }

    return (TRUE);
}

/* Name     : is_empty_lstack                                               */
/* Function : Check whether the stack is empty                               */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When it is empty, TRUE will be returned, or else FALSE         */
BOOL      is_empty_lstack(const PStackLink p_stack)
{
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    return ( (STACK_LINK_NULL == GET_NEXT_STACK(p_stack)) ?
             (TRUE) :
             (FALSE));
}

/* Name     : get_length_lstack                                             */
/* Function : Get how many nodes in the stack                                */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : How many nodes in the stack                                    */
INT32      get_length_lstack(const PStackLink p_stack)
{
    PStackLink p_node = STACK_LINK_NULL;
    INT32      cnt;
    
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (0);
    }

    cnt = 0;
    p_node = GET_NEXT_STACK(p_stack);
    while ( p_node) {
        ++cnt;
        p_node = GET_NEXT_STACK(p_node);
    }

    return (cnt);
}

/* Name     : get_top_lstack                                                 */
/* Function : Acquire the top item in the stack                              */
/* Input    : p_stack   --- stack pointer                                    */
/* Output   : When got successfully, TRUE will be returned, or else FALSE    */
STATE      get_top_lstack(const PStackLink p_stack,
                          StackValueType  *p_item)
{
    if ( !p_stack ||
         !p_item) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        memset(p_item, 0, sizeof(StackValueType));
        return (FALSE);
    }

    if ( is_empty_lstack(p_stack)) {
#ifdef __DEBGU_PRINTF_
        fprintf(stderr, "[x] Stack is EMPTY. \n");
#endif /* __DEBUG_PRINTF_ */

        memset(p_item, 0, sizeof(StackValueType));
        return (FALSE);
    }

    memcpy(p_item, &(GET_NEXT_STACK(p_stack)->item), sizeof(StackValueType));

    return (TRUE);
}

/* Name     : push_lstack                                                    */
/* Function : Insert a new item into top of the stack                        */
/* Input    : p_stack   --- stack pointer
              item      --- item to be inserted                              */
/* Output   : When inserted successfully, TRUE will be returned, or else FALSE */
STATE      push_lstack(PStackLink     p_stack,
                       StackValueType item)
{
    PStackLink p_new_node = STACK_LINK_NULL;
    
    if ( !p_stack) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_new_node = (PStackLink)malloc(sizeof(StackLink));
    if ( !p_new_node) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Malloc for new node fail. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }
    memcpy(&(p_new_node->item), &item, sizeof(StackValueType));
    
    GET_NEXT_STACK(p_new_node) = GET_NEXT_STACK(p_stack);
    GET_NEXT_STACK(p_stack)    = p_new_node;

    return (TRUE);
}

/* Name     : pop_lstack                                                     */
/* Function : Pop the top item from the stack                                */
/* Input    : p_stack   --- stack pointer
              p_item    --- item to be removed                               */
/* Output   : When removed successfully, TRUE will be returned, or else FALSE */
STATE      pop_lstack(PStackLink      p_stack,
                      StackValueType *p_item)
{
    PStackLink p_node = STACK_LINK_NULL;
    
    if ( !p_stack ||
         !p_item) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        memset(p_item, 0, sizeof(StackValueType));
        return (FALSE);
    }

    if ( is_empty_lstack(p_stack)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack is EMPTY. \n");
#endif /* __DEBUG_PRINTF_ */

        memset(p_item, 0, sizeof(StackValueType));
        return (FALSE);
    }

    memcpy(p_item, &(GET_NEXT_STACK(p_stack)->item), sizeof(StackValueType));
    p_node = GET_NEXT_STACK(p_stack);
    GET_NEXT_STACK(p_stack) = GET_NEXT_STACK(GET_NEXT_STACK(p_stack));
    free(p_node);

    return (TRUE);
}

/* Name     : traverse_lstack                                                */
/* Function : Traverse each item of the stack                                */
/* Input    : p_stack   --- stack pointer
              callback  --- function pointer to traverse stack               */
/* Output   : When traversed successfully, TRUE will be returned, or else FALSE */
STATE      traverse_lstack(const PStackLink p_stack,
                           void (*callback)(StackValueType item))
{
    PStackLink p_node = STACK_LINK_NULL;
    
    if ( !p_stack ||
         !(callback)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack pointer is NULL. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( is_empty_lstack(p_stack)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[x] Stack is EMPTY. \n");
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }
    
    p_node = GET_NEXT_STACK(p_stack);
    while ( p_node) {
        callback(GET_STACK_DATA(p_node));

        p_node = GET_NEXT_STACK(p_node);
    }

    return (TRUE);
}
