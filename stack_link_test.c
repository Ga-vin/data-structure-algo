#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include "stack_link.h"
#include "stack_link_test.h"

static PStackLink _G_p_stack = STACK_LINK_NULL;

static void __print_title(const char *msg)
{
    fprintf(stdout, "\n ******************** %s ******************** \n", msg);
}

static void __print_msg(const StackValueType item)
{
    fprintf(stdout, "%4d ", item);
}

void T_init_lstack(void)
{
    __print_title("Initialize Stack");
    if ( !_G_p_stack) {
        _G_p_stack = init_lstack();
        if ( !_G_p_stack) {
            fprintf(stderr, "[x] Global stack pointer malloc fail. \n");

            return ;
        } else {
            fprintf(stdout, "[*] Malloc stack pointer successfully. \n");
        }
    }
}

void T_destroy_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Destroy Stack");
    if ( FALSE == destroy_lstack(_G_p_stack)) {
        fprintf(stderr, "[x] Destroy stack fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Destroy stack successfully. \n");
    }
}

void T_clear_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Clear Stack");
    if ( FALSE == clear_lstack(_G_p_stack)) {
        fprintf(stderr, "[x] Clear stack fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Clear stack successfully. \n");
    }
}

void T_is_empty_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Is Empty Stack");
    if ( is_empty_lstack(_G_p_stack)) {
        fprintf(stdout, "[*] Stack is EMPTY. \n");
    } else {
        fprintf(stdout, "[*] Stack is not EMPTY. \n");
    }
}

void T_get_length_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Get Length Stack");
    fprintf(stdout, "[*] There are %d nodes in the stack. \n", get_length_lstack(_G_p_stack));
}

void T_get_top_lstack(void)
{
    StackValueType item;

    memset(&item, 0, sizeof(StackValueType));

    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Get Top Stack");
    if ( FALSE == get_top_lstack(_G_p_stack, &item)) {
        fprintf(stderr, "[x] Get top item from stack fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] The top item is %d \n", item);
    }
}

void T_push_lstack(void)
{
    UINT32         index;
    StackValueType item;
    
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    srand(time(0));

    __print_title("Push Stack");
    for (index = 0; index != 10; ++index) {
        item = rand() % 50;
        if ( FALSE == push_lstack(_G_p_stack, item)) {
            fprintf(stderr, "[x] Push item %d into stack fail. \n", item);
            
            return ;
        } else {
            fprintf(stdout, "[*] Push item %d into stack successfully. \n", item);
        }
    }
}

void T_pop_lstack(void)
{
    StackValueType item;

    if ( !_G_p_stack){
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Pop Stack");
    while ( !is_empty_lstack(_G_p_stack)) {
        if ( FALSE == pop_lstack(_G_p_stack, &item)) {
            fprintf(stderr, "[x] Pop from stack fail. \n");

            break;
        } else {
            fprintf(stdout, "[*] Popped from stack item is %d. \n", item);
        }
    }
}

void T_traverse_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack pointer is NULL. \n");

        return ;
    }

    __print_title("Traverse Stack");
    if ( FALSE == traverse_lstack(_G_p_stack, __print_msg))  {
        fprintf(stderr, "[x] Traverse stack fail. \n");

        return ;
    } else {
        putchar('\n');
        fprintf(stdout, "[*] Traverse stack successfully. \n");
    }
}

static void __print_menu(void)
{
    fprintf(stdout, "\n **************************************** \n");
    fprintf(stdout, "            Complex Stack Test.\n");
    fprintf(stdout, "\n a> Push item into stack");
    fprintf(stdout, "\n d> Pop item from stack");
    fprintf(stdout, "\n l> Get length of stack");
    fprintf(stdout, "\n g> Get top of stack");
    fprintf(stdout, "\n t> Traverse stack");
    fprintf(stdout, "\n x> Exit from program\n");
    fprintf(stdout, "Your choice> ");
}

static void __clean_line(void)
{
    while ( '\n' != getchar()) {
        ;
    }
}

static void __add_item(void)
{
    StackValueType item;

    puts("Enter item pushing to stack> ");
    scanf("%d", &item);
    __clean_line();
    
    if ( FALSE == push_lstack(_G_p_stack, item)) {
        fprintf(stderr, "[x] Push fail. \n");
    }
}

static void __del_item(void)
{
    StackValueType item;

    if ( FALSE == pop_lstack(_G_p_stack, &item)) {
        fprintf(stderr, "[x] Del item from stack fail. \n");
    } 
}

static void __get_counts(void)
{
    fprintf(stdout, "There are %d total. \n", get_length_lstack(_G_p_stack));
}

static void __get_top(void)
{
    StackValueType item;

    if ( FALSE == get_top_lstack(_G_p_stack, &item)) {
        fprintf(stderr, "[x] Get top item from stack fail. \n");
    } else {
        fprintf(stdout, "Top item is %d. \n", item);
    }
}

static void __print_item(void)
{
    if ( FALSE == traverse_lstack(_G_p_stack, __print_msg)) {
        fprintf(stderr, "[x] Traverse stack fail. \n");
    } 
}

static void __get_user_input(void)
{
    UINT8 user_input;
    
    do {
        __print_menu();

        scanf("%c", &user_input);
        __clean_line();

        switch( user_input)  {

        case 'a':
        case 'A':
            __add_item();
            break;

        case 'd':
        case 'D':
            __del_item();
            break;

        case 'l':
        case 'L':
            __get_counts();
            break;

        case 'g':
        case 'G':
            __get_top();
            break;

        case 'T':
        case 't':
            __print_item();
            break;

        case 'x':
        case 'X':
            fprintf(stdout, "System will be terminated. \n");
            exit(EXIT_FAILURE);
            break;
        }
    } while ( TRUE);    
}

void T_test_lstack(void)
{
    if ( !_G_p_stack) {
        fprintf(stderr, "[x] Global stack is NULL. \n");

        return ;
    }

    __get_user_input();
}
