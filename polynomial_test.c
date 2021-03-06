#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "polynomial_test.h"
#include "polynomial.h"

PPoly _G_list = LIST_NULL;

static void __print_title(const char *title)
{
    fprintf(stdout, "\n************************************************** \n");
    fprintf(stdout, "[*] %s test. \n", title);
}

static void __retrive(const TermType item)
{
    fprintf(stdout, "<%5.2f, %2d> ", item.coef, item.exp);
}

void T_init_list(void)
{
    __print_title("Init List");
    _G_list = init_list();
    if ( !_G_list) {
        fprintf(stderr, "[x] Initialize globol list header fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Initializatioin successfully. \n");
    }
}

void T_destroy_list(void)
{
    __print_title("Destroy List Test");
    if ( !_G_list) {
        fprintf(stdout, "[*] Global list has been NULL. \n");

        return ;
    }

    if ( FALSE == destroy_list(_G_list)) {
        fprintf(stderr, "[x] Destroy list Error. \n");

        return ;
    } else {
        if ( !_G_list) {
            fprintf(stdout, "[*] Destroy successfully. \n");
        } else {
            fprintf(stderr, "[x] Destroy Fail. \n");
        }
    }
}

void T_clear_list(void)
{
    __print_title("Clear List Test");

    if ( !_G_list) {
        fprintf(stdout, "[x] Global header pointer is NULL. \n");

        return ;
    }

    if (  FALSE == clear_list(_G_list)) {
        fprintf(stderr, "[x] Clear list Fail. \n");

        return ;
    } else{
        fprintf(stdout, "[*] Clear list successfully. \n");
    }
}

void T_get_length_list(void)
{
    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Get Length Test");
    fprintf(stdout, "[*] There is %d node in the list. \n", get_length_list(_G_list));
}

void T_is_empty_list(void)
{
    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Is Empty Test");
    if ( TRUE == is_empty_list(_G_list)) {
        fprintf(stdout, "[*] The list is Empty. \n");
    } else {
        fprintf(stdout, "[*] The list is Not Empty. \n");
    }
}

void T_get_item_by_index_list(void)
{
    UINT32   i;
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Get Item By Index Test");
    for (i = 1; i < get_length_list(_G_list); ++i) {
        if ( FALSE == get_item_by_index_list(_G_list,
                                             i,
                                             &item)) {
            fprintf(stderr, "[x] Get item by index %d fail. \n", i);
        } else {
            fprintf(stdout, "[*] Get item <%5.2f, %2d> successfully. \n", item.coef, item.exp);
        }
    }
}

void T_get_index_by_item_list(void)
{
    TermType item;
    UINT32   index;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Get Index By Item Test");
    item.coef = 1.10F;
    item.exp  = 2;
    if ( FALSE == get_index_by_item_list(_G_list,
                                         item,
                                         &index)) {
        fprintf(stderr, "[x] Can not find item <%5.2f, %2d> index. \n", item.coef, item.exp);
    } else {
        fprintf(stdout, "[*] Get index %d by item <%5.2f, %2d> successfully. \n", index, item.coef, item.exp);
    }

    item.coef = 5.2;
    item.exp  = 4;
    if ( FALSE == get_index_by_item_list(_G_list,
                                         item,
                                         &index)) {
        fprintf(stderr, "[x] Can not find item <%5.2f, %2d> index. \n", item.coef, item.exp);
    } else {
        fprintf(stdout, "[*] Get index %d by item <%5.2f, %2d> successfully. \n", index, item.coef, item.exp);
    }
}

void T_find_item_list(void)
{
    PPoly    p_node = LIST_NULL;
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Find Item Test");
    item.coef = 2.0;
    item.exp  = 2;
    p_node = find_item_list(_G_list, item);
    if ( !p_node) {
        fprintf(stderr,"[x] Find node of list with specific item fail. \n ");
    } else {
        if ( p_node->next) {
            fprintf(stdout, "[*] Next data is <%5.2f, %2d>. \n", p_node->next->item.coef, p_node->next->item.exp);
        } else {
            fprintf(stderr, "[x] Next node is NULL. \n");
        }
    }
    p_node = LIST_NULL;

    item.coef = 5.0;
    item.exp  = 5;
    p_node = find_item_list(_G_list, item);
    if ( !p_node) {
        fprintf(stderr, "[x] Find node of list with specific item fail. \n");
    } else {
        if ( p_node->next) {
            fprintf(stdout, "[*] Next data is <%5.2f, %2d>. \n", p_node->next->item.coef, p_node->next->item.exp);
        } else {
            fprintf(stderr, "[x] Next node is NULL. \n");
        }
    }
}

void T_delete_item_header_list(void)
{
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Delete Item Header Test");
    if ( FALSE == delete_item_header_list(_G_list,
                                          &item)) {
        fprintf(stderr, "[x] Delete node from list fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Delete from header node is <%5.2f, %2d>. \n", item.coef, item.exp);
    }

    T_retrieve_list();

    if ( FALSE == delete_item_header_list(_G_list,
                                          &item)) {
        fprintf(stderr, "[x] Delete node from list fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Delete from header node is <%5.2f, %2d>. \n", item.coef, item.exp);
    }

    T_retrieve_list();
}

void T_delete_item_tail_list(void)
{
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Delete Item Tail Test");
    if ( FALSE == delete_item_tail_list(_G_list,
                                        &item)) {
        fprintf(stderr, "[x] Delete node from list fail. \n");

        return ;
    } else {
        fprintf(stdout, "[*] Delete from tail node is <%5.2f, %2d>. \n", item.coef, item.exp);
    }

    T_retrieve_list();    
}

void T_delete_item_by_index_list(void)
{
    TermType item;
    UINT32   index = 0;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Delete Item By Index Test");
    do {
        ++index;
        if ( FALSE == delete_item_by_index_list(_G_list,
                                                1,
                                                &item)) {
            fprintf(stderr, "[x] Delete item of index %d fail. \n", index);
        } else {
            fprintf(stdout, "[*] Deleted item is <%5.2f, %2d>. \n", item.coef, item.exp);
        }

        if ( is_empty_list(_G_list)) {
            fprintf(stdout, "[*] The list has been empty");
            break;
        } else {
            T_retrieve_list();            
        }
    } while ( get_length_list(_G_list));
}

void T_delete_item_list(void)
{
    
}

void T_insert_item_header_list(void)
{
    UINT32   index;
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");
        return ;
    }

    __print_title("Insert Into Header of List Test");
    for (index = 1; index < 10; ++index) {
        item.coef = (float)index;
        item.exp  = index;

        if ( FALSE == insert_item_header_list(_G_list,
                                              item)) {
            fprintf(stderr, "[x] Insert item into header of list fail. \n");
        }
    }

    T_retrieve_list();
}

void T_insert_item_tail_list(void)
{
    UINT32   index;
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");
        return ;
    }

    __print_title("Insert Into Tail of List Test");
    for (index = 10; index > 0; index--) {
        item.coef = (float)index;
        item.exp  = index;

        if ( FALSE == insert_item_tail_list(_G_list,
                                              item)) {
            fprintf(stderr, "[x] Insert item into tail of list fail. \n");
        }
    }

    T_retrieve_list();    
}

void T_insert_item_by_index_list(void)
{
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Insert Item By Index Test");
    item.coef = 100.0;
    item.exp  = 100;
    if ( FALSE == insert_item_by_index_list(_G_list,
                                            5,
                                            item)) {
        fprintf(stderr, "[x] Insert item into list by index 5 fail. \n");

        return ;
    }

    T_retrieve_list();

    item.coef = 200.0;
    item.exp  = 200;
    if ( FALSE == insert_item_by_index_list(_G_list,
                                            10,
                                            item)) {
        fprintf(stderr, "[x] Insert item into list by index 10 fail. \n");

        return ;
    }

    T_retrieve_list();
}

void T_insert_item_list(void)
{
    PPoly    p_node = LIST_NULL;
    TermType item;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Insert Item List Test");
    p_node = init_list();
    if ( !p_node) {
        fprintf(stderr, "[x] Malloc list node fail. \n");

        return;
    }
    item.coef = 111.1;
    item.exp  = 111;
    memcpy(&p_node->item, &item, sizeof(TermType));
    if ( FALSE == insert_item_list(_G_list,
                                   p_node)) {
        fprintf(stderr, "[x] Insert node into list fail. \n");

        return ;
    }

    T_retrieve_list();
}

void T_find_last_list(void)
{
    PPoly p_node = LIST_NULL;

    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULl. \n");

        return ;
    }

    __print_title("Find Last List Test");
    p_node = find_last_list(_G_list);
    if ( LIST_NULL == p_node) {
        fprintf(stderr, "[x] Find last list fail. \n");
    } else {
        fprintf(stdout, "[*] Last node of list is <%5.2f, %2d>. \n", p_node->item.coef, p_node->item.exp);
    }
}

void T_retrieve_list(void)
{
    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Retrieve List Test");
    if ( FALSE == retrieve_list(_G_list, __retrive)) {
        fprintf(stderr, "[x] Retreive list fail. \n");

        return ;
    } else {
        putchar('\n');
    }
}


void T_sort_list(void)
{
    if ( !_G_list) {
        fprintf(stderr, "[x] Global header pointer is NULL. \n");

        return ;
    }

    __print_title("Sort List Test");
    if ( FALSE == sort_list(_G_list,
                            ASCENDING)) {
        fprintf(stderr, "[x] Sort list ascending order fail. \n");

        return ;
    } else {
        T_retrieve_list();
    }

    if ( FALSE == sort_list(_G_list,
                            DESCENDING)) {
        fprintf(stderr, "[x] Sort list ascending order fail. \n");

        return ;
    } else {
        T_retrieve_list();
    }    
}

void T_merge_list(void)
{
    PPoly    p_a = LIST_NULL;
    PPoly    p_b = LIST_NULL;
    PPoly    p_c = LIST_NULL;
    UINT32   i;
    TermType item;

    p_a = init_list();
    p_b = init_list();
    p_c = init_list();

    if ( !p_a ||
         !p_b ||
         !p_c) {
        fprintf(stderr, "[x] Init list error. \n");

        return ;
    }

    __print_title("Merge List Test");
    for (i = 1; i < 15; i += 3) {
        item.coef = (float)i;
        item.exp  = i;
        if ( FALSE == append_list(p_a, item)) {
            fprintf(stderr, "[x] Append to list-a error. \n");

            return ;
        }
    }

    for (i = 20; i > 0; i -= 4) {
        item.coef = (float)i;
        item.exp  = i;
        if ( FALSE == append_list(p_b, item)) {
            fprintf(stderr, "[x] Append to list-b error. \n");

            return ;
        }
    }

    fprintf(stdout, "[*] List-A: \n");
    retrieve_list(p_a, __retrive);
    putchar('\n');

    fprintf(stdout, "[*] List-B: \n");
    retrieve_list(p_b, __retrive);
    putchar('\n');

    if ( FALSE == merge_list(p_a, p_b, p_c)) {
        fprintf(stderr, "[x] Merge list unit test fail. \n");

        return ;
    }

    fprintf(stdout, "[*] List-A: \n");
    retrieve_list(p_a, __retrive);
    putchar('\n');

    fprintf(stdout, "[*] List-B: \n");
    retrieve_list(p_b, __retrive);
    putchar('\n');

    fprintf(stdout, "[*] List-C: \n");
    retrieve_list(p_c, __retrive);
    putchar('\n');

    destroy_list(p_a);
    destroy_list(p_b);
    destroy_list(p_c);
}

void T_add_polyn(void)
{
    PPoly    p_left       = LIST_NULL;
    PPoly    p_right      = LIST_NULL;
    PPoly    p_new        = LIST_NULL;
    float    left_coef[]  = { 2.0, 8.0, 100.0 };
    INT32    left_exp[]   = { 4, 10, 100 };
    float    right_coef[] = { -2.0, 1.0, 6.0, 10.0 };
    INT32    right_exp[]  = { 4, 1, 3, 20 };
    UINT32   index;
    TermType item;
    

    p_left = create_polyn();
    if ( LIST_NULL == p_left) {
        fprintf(stderr, "[x] Create header pointer for polynomial fail. \n");

        return ;
    }

    p_right = create_polyn();
    if ( LIST_NULL == p_right) {
        fprintf(stderr, "[x] Create header pointer for polynomial fail. \n");

        return ;
    }

    for (index = 0; index != sizeof(left_coef)/sizeof(float); ++index) {
        item.coef = left_coef[index];
        item.exp  = left_exp[index];

        if ( FALSE == append_polyn(p_left, item)) {
            fprintf(stderr, "[x] Append item<%5.2f, %3d> to left polynomial. \n", item.coef, item.exp);

            return ;
        }
    }

    for (index = 0; index != sizeof(right_coef)/sizeof(float); ++index) {
        item.coef = right_coef[index];
        item.exp  = right_exp[index];
        if ( FALSE == append_polyn(p_right, item)) {
            fprintf(stderr, "[x] Append item<%5.2f, %3d> to right polynomial. \n", item.coef, item.exp);

            return ;
        }
    }

    fprintf(stdout, "\nBEFORE ADD\n");
    fprintf(stdout, "[*] Polynomial Left: ");
    print_polyn(p_left);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial Right: ");
    print_polyn(p_right);
    putchar('\n');

    p_new = add_polyn(p_left, p_right);
    if ( LIST_NULL == p_new) {
        fprintf(stderr, "[x] Add two polynomial fail. \n");

        return ;
    }

    fprintf(stdout, "\nAFTER ADD\n");    
    fprintf(stdout, "[*] Polynomial Left: ");
    print_polyn(p_left);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial Right: ");
    print_polyn(p_right);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial new one: ");
    print_polyn(p_new);
    putchar('\n');

    if ( FALSE == destroy_polyn(p_left)) {
        fprintf(stderr, "[x] Destroy left polynomial fail. \n");

        return ;
    }

    if ( FALSE == destroy_polyn(p_right)) {
        fprintf(stderr, "[x] Destroy right polynomial fail. \n");

        return ;
    }

    if ( FALSE == destroy_polyn(p_new)) {
        fprintf(stderr, "[x] Destroy new polynomial fail. \n");

        return ;
    }
}

void T_sub_polyn(void)
{
    PPoly    p_left       = LIST_NULL;
    PPoly    p_right      = LIST_NULL;
    PPoly    p_new        = LIST_NULL;
    float    left_coef[]  = { 2.0, 8.0, 100.0 };
    INT32    left_exp[]   = { 4, 10, 100 };
    float    right_coef[] = { -2.0, 1.0, 6.0, 10.0 };
    INT32    right_exp[]  = { 4, 1, 3, 20 };
    UINT32   index;
    TermType item;
    

    p_left = create_polyn();
    if ( LIST_NULL == p_left) {
        fprintf(stderr, "[x] Create header pointer for polynomial fail. \n");

        return ;
    }

    p_right = create_polyn();
    if ( LIST_NULL == p_right) {
        fprintf(stderr, "[x] Create header pointer for polynomial fail. \n");

        return ;
    }

    for (index = 0; index != sizeof(left_coef)/sizeof(float); ++index) {
        item.coef = left_coef[index];
        item.exp  = left_exp[index];

        if ( FALSE == append_polyn(p_left, item)) {
            fprintf(stderr, "[x] Append item<%5.2f, %3d> to left polynomial. \n", item.coef, item.exp);

            return ;
        }
    }

    for (index = 0; index != sizeof(right_coef)/sizeof(float); ++index) {
        item.coef = right_coef[index];
        item.exp  = right_exp[index];
        if ( FALSE == append_polyn(p_right, item)) {
            fprintf(stderr, "[x] Append item<%5.2f, %3d> to right polynomial. \n", item.coef, item.exp);

            return ;
        }
    }

    fprintf(stdout, "\nBEFORE ADD\n");
    fprintf(stdout, "[*] Polynomial Left: ");
    print_polyn(p_left);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial Right: ");
    print_polyn(p_right);
    putchar('\n');

    p_new = sub_polyn(p_left, p_right);
    if ( LIST_NULL == p_new) {
        fprintf(stderr, "[x] Add two polynomial fail. \n");

        return ;
    }

    fprintf(stdout, "\nAFTER ADD\n");    
    fprintf(stdout, "[*] Polynomial Left: ");
    print_polyn(p_left);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial Right: ");
    print_polyn(p_right);
    putchar('\n');

    fprintf(stdout, "[*] Polynomial new one: ");
    print_polyn(p_new);
    putchar('\n');

    if ( FALSE == destroy_polyn(p_left)) {
        fprintf(stderr, "[x] Destroy left polynomial fail. \n");

        return ;
    }

    if ( FALSE == destroy_polyn(p_right)) {
        fprintf(stderr, "[x] Destroy right polynomial fail. \n");

        return ;
    }

    if ( FALSE == destroy_polyn(p_new)) {
        fprintf(stderr, "[x] Destroy new polynomial fail. \n");

        return ;
    }
}

void T_merge_polyn(void)
{
    PPoly p_polynomial = LIST_NULL;
    const float coef_array[] = {
        1.2, 3.5, 19.2 
    };
    const INT32 exp_array[] = {
        2, 2, 2 
    };
    size_t index;

    p_polynomial = create_polyn();
    if ( LIST_NULL == p_polynomial) {
        fprintf(stderr, "[x] Create new polynomial fail.\n");

        return ;
    }

    for (index = 0; index != sizeof(coef_array)/sizeof(float); ++index) {
        TermType item;
        item.coef = coef_array[index];
        item.exp  = exp_array[index];
        if ( FALSE == append_polyn(p_polynomial, item)) {
            fprintf(stderr, "[x] Append to polynomial fail. \n");

            return ;
        }
    }

    fprintf(stdout, "[*] Original polynomial is ");
    print_polyn(p_polynomial);
    putchar('\n');

    if ( FALSE == merge_polyn(p_polynomial)) {
        fprintf(stderr, "[x] Merged polynomial fail. \n");

        return ;
    }

    fprintf(stdout, "[*] After merged polynomial: ");
    print_polyn(p_polynomial);
    putchar('\n');
}

void T_multipy_polyn(void)
{
    PPoly p_left                   = LIST_NULL;
    PPoly p_right                  = LIST_NULL;
    PPoly p_result                 = LIST_NULL;
    const float left_coef_array[]  = {
        2.0, 1.0, 4.0, 3.0
    };
    const INT32 left_exp_array[]   = {
        3, 1, 5, 2
    };
    const float right_coef_array[] = {
        3.0, 1.0, 4.0
    };
    const INT32 right_exp_array[]  = {
        1, 2, 3
    };
    size_t index;
    
    p_left = create_polyn();
    if ( !p_left) {
        fprintf(stderr, "[x] Create header pointer for left polynomial fail. \n");

        return ;
    }

    p_right = create_polyn();
    if ( !p_right) {
        fprintf(stderr, "[x] Create header pointer for right polynomial fail. \n");

        return ;
    }

    p_result = create_polyn();
    if ( !p_result) {
        fprintf(stderr, "[x] Create header pointer for result polynomial fail. \n");

        return ;
    }

    for (index = 0; index != sizeof(left_coef_array)/sizeof(float); ++index) {
        TermType item;
        item.coef = left_coef_array[index];
        item.exp  = left_exp_array[index];
        if ( FALSE == append_polyn(p_left, item)) {
            fprintf(stderr, "[x] Appended to left polynomial fail. \n");

            return ;
        }
    }

    for (index = 0; index != sizeof(right_coef_array)/sizeof(float); ++index) {
        TermType item;
        item.coef = right_coef_array[index];
        item.exp  = right_exp_array[index];
        if ( FALSE == append_polyn(p_right, item)) {
            fprintf(stderr, "[x] Appended to right polynomial fail. \n");

            return ;
        }
    }

    p_result = multiply_polyn(p_left, p_right);
    if ( !p_result) {
        fprintf(stderr, "[x] Multiply two polynomials fail. \n");

        return ;
    }

    fprintf(stdout, "[*] Left polynomial: ");
    print_polyn(p_left);
    putchar('\n');

    fprintf(stdout, "[*] Right polynomial: ");
    print_polyn(p_right);
    putchar('\n');

    fprintf(stdout, "[*] Result polynomial: ");
    print_polyn(p_result);
    putchar('\n');

    /* if ( FALSE == merge_polyn(p_result)) { */
    /*     fprintf(stderr, "[x] Merged polynomial fail. \n"); */

    /*     return ; */
    /* } */

    /* fprintf(stdout, "[*] After merged: "); */
    /* print_polyn(p_result); */
    /* putchar('\n'); */
}
