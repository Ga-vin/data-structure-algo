#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_table.h"
#include "stack_table_test.h"

static StackTable _G_stack;

static void __print_title(const char *p_msg)
{
    fprintf(stdout, "\n ********** %s ********** \n", p_msg);
}

static void __print_stack(const StackItemType item)
{
    fprintf(stdout, "%4d ", item);
}

#define    __DEBUG_SIZE_50_
#undef     __DEBUG_SIZE_50_
#define    __DEBUG_SIZE_0_
void T_init_tstack(void)
{
#ifdef __DEBUG_SIZE_0_    
    __print_title("Initalize Stack");
    _G_stack = init_tstack(0);
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Initalize stack fail. \n");
    } else {
        fprintf(stderr, "[x] Initialize stack successfully. Stack size is %d \n", _G_stack.size);
    }
#endif /* __DEBUG_SIZE_0_ */

#ifdef __DEBUG_SIZE_50_    
    __print_title("Initalize Stack");
    _G_stack = init_tstack(50);
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Initalize stack fail. \n");
    } else {
        fprintf(stderr, "[x] Initialize stack successfully. Stack size is %d \n", _G_stack.size);
    }
#endif /* __DEBUG_SIZE_50_ */        
}

void T_destroy_tstack(void)
{
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Stack top or bottom pointer is NULL. \n");

        return ;
    }

    __print_title("Destroy Stack");
    
    if ( FALSE == destroy_tstack(&_G_stack)) {
        fprintf(stderr, "[x] Destroy stack fail. \n");

        return ;
    } else {
        if ( _G_stack.top ||
             _G_stack.bottom) {
            fprintf(stderr, "[xx] Destroy stack fail. \n");

            return ;
        } else {
            fprintf(stdout, "[*] Destroy stack successfully. \n");
        }
    }
}

void T_clear_tstack(void)
{
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Clear Stack");
    if ( FALSE == clear_tstack(&_G_stack)) {
        fprintf(stderr, "[x] Clear stack fail. \n");

        return ;
    }

    if ( _G_stack.top != _G_stack.bottom) {
        fprintf(stderr, "[x] Clear stack also fail. \n");

        return ;
    }
}

void T_get_length_tstack(void)
{
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Get Length Stack");
    fprintf(stdout, "[*] The length of stack is %d. \n", get_length_tstack(&_G_stack));
}

void T_is_empty_tstack(void)
{
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Is Empty Stack");
    if ( TRUE == is_empty_tstack(&_G_stack)) {
        fprintf(stdout, "[*] The stack is empty. \n");
    } else {
        fprintf(stdout, "[*] The stack is not empty. \n");
    }
}

void T_get_top_tstack(void)
{
    StackItemType item;
    
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Get Top Stack");
    memset(&item, 0, sizeof(StackItemType));
    if ( FALSE == get_top_tstack(&_G_stack,
                                 &item)) {
        fprintf(stderr, "[x] Get top item of stack fail. \n");

        return;
    } else {
        fprintf(stdout, "[*] Get top item of stack successfully. %d \n", item);
    }
}

void T_push_tstack(void)
{
    size_t        index;
    StackItemType item;
    
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Push Stack");
    for (index = 0; index != 30; ++index) {
        item = index;
        if ( FALSE == push_tstack(&_G_stack,
                                  item)) {
            fprintf(stderr, "[x] Push item %d into stack fail. \n", item);
        } else {
            fprintf(stdout, "[*] Push <%d> into stack successfully. \n", item);
        }

        if ( FALSE == traverse_tstack(&_G_stack,
                                      __print_stack)) {
            fprintf(stderr, "[x] Traverse stack fail. \n");
        }
        putchar('\n');        
    }

    if ( FALSE == traverse_tstack(&_G_stack,
                                  __print_stack)) {
        fprintf(stderr, "[x] Traverse stack fail. \n");
    }
    putchar('\n');
}

void T_pop_tstack(void)
{
    StackItemType item;
    
    if ( !_G_stack.top ||
         !_G_stack.bottom) {
        fprintf(stderr, "[x] Global stack is not ready. \n");

        return ;
    }

    __print_title("Pop Stack");
    while ( !is_empty_tstack(&_G_stack)) {
        if ( FALSE == pop_tstack(&_G_stack,
                                 &item)) {
            fprintf(stderr, "[x] Pop from stack fail. \n");
        } else {
            fprintf(stdout, "[*] Pop <%4d> from stack top success. \n", item);
        }

        if ( FALSE == traverse_tstack(&_G_stack,
                                      __print_stack)) {
            fprintf(stderr, "[x] Traverse stack fail. \n");
        }
        putchar('\n');        
    }
}
