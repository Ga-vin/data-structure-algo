#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "table_test.h"
#include "pointer.h"
#include "pointer_test.h"
#include "list_test.h"
#include "double_list_test.h"
#include "circular_list_test.h"
#include "polynomial_test.h"
#include "stack_table_test.h"
#include "stack_link_test.h"
#include "application.h"
#include "queue_link_test.h"

#define    DEBUG_WHICH_ONE     (2)
#define    DEBUG_LIST_SWITCH   (2)
#define    DEBUG_D_LIST_SWITCH (0)

int main(int argc, char *argv[])
{
#if DEBUG_WHICH_ONE < 1
    T_initializeTblLst();
    T_getSizeTblLst();
    T_getLengthTblLst();
    T_isEmptyTblLst();
    T_isFullTblLst();

    T_cleanTblLst();

    T_insertItemHeaderTblLst();

    T_insertItemTailTblLst();

    T_insertItemByIndexTblLst();

    T_deleteItemHeaderTblLst();

    T_deleteItemTailTblLst();

    T_deleteItemByIndexTblLst();

    P_initPTblLst();
    P_clearPTblLst();

    P_insertItemHeaderPTblLst();
    P_isEmptyPTblLst();
    P_isFullPTblLst();
    fprintf(stdout, "[*] Delete item from header.\n");
    P_deleteItemHeaderPTblLst();
    P_isEmptyPTblLst();
    fprintf(stdout, "[*] Delete item from list by index.\n");
    P_deleteItemByIndexPTblLst();

    fprintf(stdout, "[*] Clean the table list.\n");
    P_clearPTblLst();

    fprintf(stdout, "[*] Insert item into table-list in tail.\n");
    P_insertItemTailPTblLst();
    fprintf(stdout, "[*] Delete item from tail.\n");
    P_deleteItemTailPTblLst();
    P_isEmptyPTblLst();

    fprintf(stdout, "[*] Insert item into table-list valid random location.\n");
    P_insertItemByIndexPTblLst();
#endif /* DEBUG_SWITCH_ONE<1 */

#if    DEBUG_LIST_SWITCH > 2    
    T_createList();
    
    T_destroyList();
#endif /* DEBUG_LIST_SWITCH > 2 */

#if 0    
    T_createList();
    T_getLengthList();

    T_isEmptyList();
#endif    

#if 0    
    T_insertItemList();
    T_getLengthList();
    T_retrieveList();

    T_clearList();
    
    T_insertItemHeaderList();
    T_getLengthList();
    T_retrieveList();

    T_clearList();

    T_insertItemTailList();
    T_getLengthList();
    T_retrieveList();

    T_deleteItemHeaderList();
    T_findLastList();

    T_deleteItemTailList();

    T_getItemByIndexList();

    T_getIndexByItemList();

    T_insertItemByIndexList();

    T_sortList();
    
    T_destroyList();
#endif    

#if 0    
    T_mergeList();

    T_createDoubleList();
    
    T_insertItemHeaderDoubelList();

    T_insertItemTailDoubleList();

    T_clearDoubleList();
#endif

#if 0    
    T_isEmptyDoubleList();

    T_insertItemDoubleList();

    T_isEmptyDoubleList();

    T_insertItemByIndexDoubleList();

    T_sortDoubleList();

    /* T_deleteItemHeaderDoubleList(); */

    /* T_deleteItemByIndexDoubleList() */;

    /* T_deleteItemDoubleList(); */

    T_destroyDoubleList();

    T_mergeDoubleList();

#endif     

#ifdef __DEBUG_CIRCULE        
    T_createNodeCList();

    T_insertItemHeaderCList();

    T_insertItemHeaderCList();

    T_get_last_data_CList();

    T_insertItemTailCList();
p
    T_getItemByIndexCList();
#endif /* __DEBUG_CIRCULE */    

#ifdef __DEBUG_CIRCULE    
    T_insertItemByIndexCList();

    T_getItemPtrCList();

    T_getNextItemCList();

    /* T_getPriorItemCList(); */

    T_locateItemCList();

    T_getItemByIndexCList();
#endif /* __DEBUG_CIRCULE */

#ifdef __DEBUG_POLY_    
    T_init_list();

    T_get_length_list();

    T_is_empty_list();

    T_insert_item_header_list();

    T_find_last_list();

    T_is_empty_list();

    T_get_length_list();

    T_insert_item_tail_list();

    T_find_last_list();

    T_get_length_list();
    
    T_get_item_by_index_list();

    T_get_index_by_item_list();

    T_find_item_list();

    T_insert_item_by_index_list();

    T_find_last_list();

    T_insert_item_list();

    T_find_last_list();

    T_sort_list();
#endif /* __DEBUG_POLY_ */    

#ifdef __DEBUG_POLY_    
    T_delete_item_header_list();

    T_delete_item_tail_list();

    T_delete_item_by_index_list();

    T_merge_list();
#endif /* __DEBUG_POLY_ */

#ifdef __DEBUG_ADD_    
    T_add_polyn();
#endif /* __DEBUG_ADD_ */

#ifdef __DEBUG_SUB_    
    T_sub_polyn();
#endif /* __DEBUG_SUB_ */

#ifdef  __DEBUG_MERGE_    
    T_merge_polyn();
#endif /* __DEBUG_MERGE_ */

#ifdef __DEBUG_MULTIPY_    
    T_multipy_polyn();
#endif /* __DEBUG_MULTIPY_ */

#ifdef __DEBUG_STACK_TABLE_    
    T_init_tstack();

    T_get_length_tstack();

    T_is_empty_tstack();

    T_push_tstack();

    T_get_length_tstack();

    T_clear_tstack();

    T_push_tstack();

    T_pop_tstack();

    T_get_length_tstack();

    T_destroy_tstack();
#endif /* __DEBUG_STACK_TABLE_ */

#ifdef __DEBUG_STACK_LINK_    
    T_init_lstack();

    T_is_empty_lstack();

    T_get_length_lstack();

    T_push_lstack();

    T_is_empty_list();

    T_get_length_lstack();

    T_traverse_lstack();

    T_pop_lstack();

    T_is_empty_list();

    T_get_length_lstack();

    T_traverse_lstack();

    T_test_lstack();

    T_destroy_lstack();

#endif /* __DEBUG_STACK_LINK_ */

#ifdef __DEBUG_COMPLEX_    
    T_diff_test_stack();
#endif /* __DEBUG_COMPLEX_ */

#ifdef __DEBUG_CONVERT_    
    T_convert_10_to_any_system();
#endif /* __DEBUG_CONVERT_ */

#ifdef __DEBUG_MATH_    
    T_is_parentheses_match();
#endif /* __DEBUG_MATH_ */

#ifdef __DEBUG_EDIT_    
    line_edit_app();
#endif /* __DEBUG_EDIT_ */

#ifdef __DEBUG_SUFFIX_    
    calc_suffix_app();
#endif /* __DEBUG_SUFFIX_  */

#ifdef __DEBUG_MID_TO_SUFFIX_    
    mid_to_suffix();
#endif /* __DEBUG_MID_TO_SUFFIX_ */
    
    return 0;
}
