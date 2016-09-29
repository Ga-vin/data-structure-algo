#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>

#include "application.h"
#include "stack_link.h"

static const INT8 _S_match_list[] = {
    '(', '[', '{', '}', ']', ')'
};

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

static BOOL __is_in_match_list(StackItemType item)
{
    size_t i;

    for (i = 0; i != sizeof(_S_match_list)/sizeof(INT8); ++i) {
        if ( item == _S_match_list[i]) {
            return (TRUE);
        }
    }

    return (FALSE);
}

static BOOL __is_match_left_parentheses(StackItemType item)
{
    INT8 cp_item = (INT8)item;
    
    if ( ('(' == cp_item) ||
         ('[' == cp_item) ||
         ('{' == cp_item) ){
        return (TRUE);
    } else {
        return (FALSE);;
    }
}

static BOOL __is_match_right_parentheses(StackItemType item)
{
    INT8 cp_item = (INT8)item;

    if ( (')' == cp_item) ||
         (']' == cp_item) ||
         ('}' == cp_item) ) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

static BOOL __is_match_pair(StackItemType left_item,
                            StackItemType right_item)
{
    if ( ('(' == left_item) &&
         (')' == right_item) ) {
        return (TRUE);
    }

    if ( ('[' == left_item) &&
         (']' == right_item) ) {
        return (TRUE);
    }

    if ( ('{' == left_item) &&
         ('}' == right_item) ) {
        return (TRUE);
    }

    return (FALSE);
}

BOOL is_parentheses_match(const INT8 *buf,
                          size_t      len)
{
    INT8         *p_buf_start = buf;
    INT8         *p_buf_end   = buf + len;
    PStackLink    p_stack     = STACK_LINK_NULL;
    StackItemType item;
    StackItemType top_item;
    StackItemType temp;
    static UINT32 counter     = 0;

    p_stack = init_lstack();
    if ( !p_stack) {
        fprintf(stderr, "Create stack with link format fail. \n");

        return (FALSE);
    } else {
        fprintf(stdout, "Create stack successfully. \n");
    }

    for ( ; p_buf_start < p_buf_end; ++p_buf_start) {
        ++counter;
        item = (StackItemType)*p_buf_start;
        if ( ispunct(item) &&
             __is_in_match_list(item) ) {
            if ( is_empty_lstack(p_stack) &&
                 __is_match_right_parentheses(item) ) {
                return (FALSE);
            } else if ( is_empty_lstack(p_stack) ||
                 __is_match_left_parentheses(item) ) {
                if ( FALSE == push_lstack(p_stack, item)) {
                    fprintf(stderr, "Push item into stack fail. \n");

                    return (FALSE);
                }
            } else {
                if ( FALSE == get_top_lstack(p_stack, &top_item)) {
                    fprintf(stderr, "Get top item of stack fail. \n");

                    return (FALSE);
                }

                if ( __is_match_pair(top_item, item)) {
                    if ( FALSE == pop_lstack(p_stack, &temp)) {
                        fprintf(stderr, "Pop from top of stack fail. \n");

                        return (FALSE);
                    }
                } else {
                    /* continue; */
                    return (FALSE);
                }
            }
        } else {
            continue;
        }
    }

    if ( is_empty_lstack(p_stack)) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

void T_is_parentheses_match(void)
{
    INT8 *p_buf       = "a]bfeifj[90238jr,3i2!]iio9032r23r{joiewf}iejfwie)";
    INT8 *p_buf_new   = "eiwoef(jioejwf[js2039!.we]jio903{e9w0fe}jiew)";
    INT8 *p_buf_other = "ioewfjiew(jiojewf]jeoiwfjwef]joiewf{joiewjfe}209323)";

    if ( is_parentheses_match(p_buf, strlen(p_buf))) {
        fprintf(stdout, "%s is match. \n", p_buf);
    } else {
        fprintf(stdout, "%s is not match. \n", p_buf);
    }

    if ( is_parentheses_match(p_buf_new, strlen(p_buf_new))) {
        fprintf(stdout, "%s is match. \n", p_buf_new);
    } else {
        fprintf(stdout, "%s is not match. \n", p_buf_new);
    }

    if ( is_parentheses_match(p_buf_other, strlen(p_buf_other))) {
        fprintf(stdout, "%s is match. \n", p_buf_other);
    } else {
        fprintf(stdout, "%s is not match. \n", p_buf_other);
    }        
}
