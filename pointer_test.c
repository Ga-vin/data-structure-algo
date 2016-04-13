#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "pointer.h"
#include "pointer_test.h"

#define    RIGHT    (1)
#define    ERR_INFO (-1)

PointNode    g_point_node;

static void debug(const char *information, INT32 prompt)
{
    if ( RIGHT == prompt) {
        fprintf(stdout, "[*] ");
    } else if (ERR_INFO == prompt) {
        fprintf(stdout, "[X] In <%s> at line <%d> : ", __FILE__, __LINE__);
    }

    fprintf(stdout, "%s\n", information);
}

void P_initPTblLst(void)
{
    INT8 *p_infor = NULL;

    p_infor = (INT8 *)malloc(64);
    if (!p_infor) {
        debug("Malloc fail", ERR_INFO);
    }
    
    debug("Initilization PointNode> ", RIGHT);
    g_point_node = initPTblLst(PTBL_MAX_SIZE);
    debug("Finish initializatioin", RIGHT);
    if (g_point_node.size <= 0) {
        debug("Initialization fail.", ERR_INFO);

        exit(EXIT_FAILURE);
    }
    sprintf(p_infor, "Len: %d Size: %d", getLengthPTblLst(g_point_node),
            getSizePTblLst(g_point_node));
    debug(p_infor, RIGHT);
    free(p_infor);
    p_infor = NULL;
}

void P_destroyPTblLst(void)
{
    if ( TRUE != destroyPTblLst(&g_point_node)) {
        debug("Destroy fail", ERR_INFO);
    }
    debug("Destroy successfully!", RIGHT);
}

void P_clearPTblLst(void)
{
    if ( TRUE != clearPTblLst(&g_point_node)) {
        debug("Clear fail", ERR_INFO);
    }
    debug("Clear successfully!", RIGHT);
}

void P_getLengthPTblLst(void)
{
    
}

void P_getSizePTblLst(void)
{
    
}

void P_getItemByIndexPTblLst(void)
{
    
}

void P_getIndexByItemPTblLst(void)
{
    
}

void P_isEmptyPTblLst(void)
{
    
}

void P_isFullPTblLst(void)
{
    
}

void P_insertItemHeaderPTblLst(void)
{
    
}

void P_insertItemTailPTblLst(void)
{
    
}

void P_insertItemByIndexPTblLst(void)
{
    
}

void P_deleteItemHeaderPTblLst(void)
{
    
}

void P_deleteItemTailPTblLst(void)
{
    
}

void P_deleteItemByIndexPTblLst(void)
{
    
}

void P_traversePTblLst(void)
{
    
}
