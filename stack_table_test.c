#include <stdio.h>
#include <stdlib.h>
#include "stack_table.h"
#include "stack_table_test.h"

static StackTable _G_stack;

static void __print_title(const char *p_msg)
{
    fprintf(stdout, "\n ********** %s ********** \n", p_msg);
}

#define    __DEBUG_SIZE_50_
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
