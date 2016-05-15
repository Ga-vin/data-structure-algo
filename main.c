#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "table_test.h"
#include "pointer.h"
#include "pointer_test.h"

#define    DEBUG_WHICH_ONE    (2)

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

#ifdef    __DEBUG_DELITEMHEADER_    
    T_deleteItemHeaderTblLst();
#endif /* __DEBUG_DELITEMHEADER_ */

#ifdef    __DEBUG_DELITEMTAIL_    
    T_deleteItemTailTblLst();
#endif /* __DEBUG_DELITEMTAIL_ */

    T_deleteItemByIndexTblLst();
#endif /* DEBUG_WHICH_ONE */

    P_initPTblLst();
    P_clearPTblLst();

    P_insertItemHeaderPTblLst();
    P_isEmptyPTblLst();
    P_isFullPTblLst();
    fprintf(stdout, "[*] Delete item from header.\n");
#ifdef    __DEBUG_DELITEMINDEX_    
    P_deleteItemHeaderPTblLst();
    P_isEmptyPTblLst();
#endif /* __DEBUG_DELITEMINDEX_ */
    fprintf(stdout, "[*] Delete item from list by index.\n");
    P_deleteItemByIndexPTblLst();

#ifdef    __DEBUG_DELITEMINDEX_    
    fprintf(stdout, "[*] Clean the table list.\n");
    P_clearPTblLst();

    fprintf(stdout, "[*] Insert item into table-list in tail.\n");
    P_insertItemTailPTblLst();
    fprintf(stdout, "[*] Delete item from tail.\n");
    P_deleteItemTailPTblLst();
    P_isEmptyPTblLst();

    fprintf(stdout, "[*] Insert item into table-list valid random location.\n");
    P_insertItemByIndexPTblLst();
#endif /* __DEBUG_DELITEMINDEX_ */    
    
    return 0;
}
