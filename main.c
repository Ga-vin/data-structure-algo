#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "table_test.h"
#include "pointer.h"
#include "pointer_test.h"
#include "list_test.h"

#define    DEBUG_WHICH_ONE    (2)
#define    DEBUG_LIST_SWITCH  (2)

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

    T_createList();
    T_getLengthList();

    T_isEmptyList();

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
    
    return 0;
}
