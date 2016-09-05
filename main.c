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

    T_delete_item_header_list();

    T_delete_item_tail_list();

    T_delete_item_by_index_list();
    
    T_destroy_list();
    
    return 0;
}
