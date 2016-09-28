#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "application.h"
#include "stack_link.h"

static StackItemType __calc_value_from_stack(PStackLink p_stack)
{
    StackItemType result = 0;
    StackItemType temp   = 0;
    
    if ( !p_stack) {
        fprintf(stderr, "Stack is NULL. \n");

        return (STACK_FAIL_NUM);
    }

    if ( is_empty_lstack(p_stack)) {
        fprintf(stderr, "Convert fail. \n");

        return (STACK_FAIL_NUM);
    } else {
        while ( !is_empty_lstack(p_stack)) {
            if ( FALSE == pop_lstack(p_stack, &temp)) {
                fprintf(stderr, "Pop item from stack fail. \n");

                return (STACK_FAIL_NUM);
            }
            result = result * 10 + temp;
        }

        return (result);
    }    
}

StackItemType convert_10_to_any_system(const StackItemType item,
                                       StackBaseSystem     base)
{
    PStackLink    p_stack = STACK_LINK_NULL;
    StackItemType item_cp = item;
    StackItemType result  = 0;
    StackItemType temp    = 0;

    p_stack = init_lstack();
    if ( !p_stack) {
        fprintf(stderr, "Create empty stack for converting 10 system to any other system fail. \n");

        return (STACK_FAIL_NUM);
    }

    if ( base <= 1) {
        fprintf(stderr, "System base should be larger than 1. \n");

        destroy_lstack(p_stack);
        return (STACK_FAIL_NUM);
    }

    while ( (item_cp/base)) {
        if ( FALSE == push_lstack(p_stack, (item_cp%base))) {
            fprintf(stderr, "Push item into stack fail. \n");

            destroy_lstack(p_stack);
            return (STACK_FAIL_NUM);
        }
        item_cp /= base;
    }
    if ( FALSE == push_lstack(p_stack, item_cp)) {
        fprintf(stderr, "Push last item into stack fail. \n");

        destroy_lstack(p_stack);
        return (STACK_FAIL_NUM);
    }

    result = __calc_value_from_stack(p_stack);
    destroy_lstack(p_stack);
    
    return (result);
}

void T_convert_10_to_any_system(void)
{
    StackItemType value  = 1348;
    StackItemType result = 0;

    result = convert_10_to_any_system(value, 8);
    if ( STACK_FAIL_NUM == result) {
        fprintf(stderr, "Convert from %d with 10-system to 8-system fail. \n", value);

        return ;
    } else {
        fprintf(stdout, "Convert %d with 10-system to 8-system is %d.\n", value, result);
    }

    result = convert_10_to_any_system(value, 2);
    if ( STACK_FAIL_NUM == result) {
        fprintf(stderr, "Convert from %d with 10-system to 2-system fail. \n", value);

        return ;
    } else {
        fprintf(stdout, "Convert %d with 10-system to 2-system is %d.\n", value, result);
    }

    result = convert_10_to_any_system(value, 16);
    if ( STACK_FAIL_NUM == result) {
        fprintf(stderr, "Convert from %d with 10-system to 16-system fail. \n", value);

        return ;
    } else {
        fprintf(stdout, "Convert %d with 10-system to 16-system is %d.\n", value, result);
    }
}
