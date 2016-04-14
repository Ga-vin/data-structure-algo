#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "pointer.h"
#include "pointer_test.h"

#define    RIGHT    (1)
#define    ERR_INFO (-1)

PointNode    g_point_node;

static void cleanLine(void)
{
    while ( '\n' != getchar()) {
        continue;
    }
}

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

        return ;
    }
    debug("Destroy successfully!", RIGHT);
}

void P_clearPTblLst(void)
{
    if ( TRUE != clearPTblLst(&g_point_node)) {
        debug("Clear fail", ERR_INFO);

        return ;
    }
    debug("Clear successfully!", RIGHT);
}

void P_getLengthPTblLst(void)
{
    fprintf(stdout, "[*] Test for get length of pointer table list: ");
    fprintf(stdout, "<Length> : %d\n", getLengthPTblLst(g_point_node));
}

void P_getSizePTblLst(void)
{
    fprintf(stdout, "[*] Test for get size of pointer table list: ");
    fprintf(stdout, "<Size> : %d\n", getSizePTblLst(g_point_node));
}

void P_getItemByIndexPTblLst(void)
{
    UINT32   index = 0;
    ElemType value = 0;
    
    fprintf(stdout, "[*] Test for get item by specific index you input: \n");

    do {
        fprintf(stdout, "Enter index to find > ");
        scanf("%d", &value);
        if ( TRUE != getItemByIndexPTblLst(&g_point_node, index, &value)) {
            debug("[X] Get item by index failed.", ERR_INFO);
        } else {
            fprintf(stdout, "[*] Item in index(%d) is %d\n", index, value);            
        }
    } while ( 1000 != index);
    debug("[*] Finish test", RIGHT);
}

void P_getIndexByItemPTblLst(void)
{
    UINT32   index = 0;
    ElemType value = 0;
    
    fprintf(stdout, "[*] Test for get index by specific item you input: \n");

    do {
        fprintf(stdout, "Enter item to find > ");
        scanf("%d", &value);
        if ( TRUE != getIndexByItemPTblLst(&g_point_node, &index, value)) {
            debug("[X] Get index by item failed.", ERR_INFO);
        } else {
            fprintf(stdout, "[*] Item(%d) in index(%d)\n", value, index);            
        }
    } while ( 1000 != index);
    debug("[*] Finish test", RIGHT);    
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