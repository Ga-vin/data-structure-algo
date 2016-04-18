#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
    fprintf(stdout, "[*] Test for check whether the point table is empty\n");

    if ( TRUE == isEmptyPTblLst(&g_point_node)) {
        fprintf(stdout, "[*] The pointer table is empty\n");
    } else {
        fprintf(stdout, "[*] The pointer table is not empty\n");
    }
}

void P_isFullPTblLst(void)
{
    fprintf(stdout, "[*] Test for checking whether the point table is full\n");

    if ( TRUE == isFullPTblLst(&g_point_node)) {
        fprintf(stdout, "[*] The pointer table is full\n");
    } else {
        fprintf(stdout, "[*] The pointer table is not full\n");
    }
}

void P_insertItemHeaderPTblLst(void)
{
    UINT32 value;
    UINT32 counter = 0;

    srand(time(0));

    /* 插入直到链表为满 */
    while ( TRUE != isFullPTblLst(&g_point_node)) {
        value = rand() % 1000;
        fprintf(stdout, "%d\t", value);
        if ( TRUE != insertItemHeaderPTblLst(&g_point_node, (ElemType)value)) {
            fprintf(stdout, "[X] <%s> : %d => Insert Item Header fail, system will terminate.\n", __FILE__,
                    __LINE__);

            return ;
        }

        if (counter < PTBL_MAX_SIZE) {
            fprintf(stdout, "[*] %d\n", counter++);
        } else {
            break;
        }
    }
    P_traversePTblLst();

    value = rand() % 200;
    if ( TRUE != insertItemHeaderPTblLst(&g_point_node, (ElemType)value)) {
        fprintf(stdout, "[X] <%s> : %d => Insert Item fail\n",
                __FILE__,
                __LINE__);

        return ;
    }
    P_traversePTblLst();
}

void P_insertItemTailPTblLst(void)
{
    UINT32 value;

    srand(time(0));

    /* 插入直到链表为满 */
    while ( TRUE != isFullPTblLst(&g_point_node)) {
        value = rand() % 1000;
        if ( TRUE != insertItemTailPTblLst(&g_point_node, (ElemType)value)) {
            fprintf(stdout, "[X] <%s> : %d => Insert Item Tail fail, system will terminate.\n", __FILE__,
                    __LINE__);

            return ;
        }
    }
    P_traversePTblLst();

    value = rand() % 200;
    if ( TRUE != insertItemTailPTblLst(&g_point_node, (ElemType)value)) {
        fprintf(stdout, "[X] <%s> : %d => Insert Item one above in tail fail\n",
                __FILE__,
                __LINE__);

        return ;
    }
    P_traversePTblLst();    
}

void P_insertItemByIndexPTblLst(void)
{
    UINT32 buffer[PTBL_MAX_SIZE];
    UINT32 index;
    static UINT32 counter = 0;
    UINT32 temp_value;

    memset((void *)buffer, 0, (size_t)PTBL_MAX_SIZE);
    srand(time(0));

    for (index = 0; counter != PTBL_MAX_SIZE; ++index) {
        temp_value = rand() % 100;
        if ( 1 != buffer[temp_value]) {
            if ( TRUE != insertItemByIndexPTblLst(&g_point_node,
                                                  temp_value,
                                                  counter)) {
                fprintf(stdout, "[X] <%s> : in %d => Insert item by index fail\n",
                        __FILE__,
                        __LINE__);

                return ;
            }
            buffer[temp_value] = 1;
            counter++;
        }
    }
}

void P_deleteItemHeaderPTblLst(void)
{
    ElemType value;
    
    fprintf(stdout, "[*] Test for delete item from header.\n");

    while ( TRUE != isEmptyPTblLst(&g_point_node)) {
        if ( FALSE == deleteItemHeaderPTblLst(&g_point_node,
                                              &value)) {
            fprintf(stdout, "[X] <%s> : in %d Delete item from header fail\n",
                    __FILE__,
                    __LINE__);

            return ;
        }

        fprintf(stdout, "[*] %d will be deleted.\n", value);
    }
    fprintf(stdout, "[*] All elements have been deleted.\n");
}

void P_deleteItemTailPTblLst(void)
{
    ElemType value;
    
    fprintf(stdout, "[*] Test for delete item from tail.\n");

    while ( TRUE != isEmptyPTblLst(&g_point_node)) {
        if ( FALSE == deleteItemTailPTblLst(&g_point_node,
                                              &value)) {
            fprintf(stdout, "[X] <%s> : in %d Delete item from tail fail\n",
                    __FILE__,
                    __LINE__);

            return ;
        }

        fprintf(stdout, "[*] %d will be deleted.\n", value);
    }
    fprintf(stdout, "[*] All elements have been deleted.\n");    
}

void P_deleteItemByIndexPTblLst(void)
{
    ElemType value;
    UINT32   buffer[PTBL_MAX_SIZE];
    UINT32   index;

    memset((void *)buffer, 0, PTBL_MAX_SIZE);

    srand(time(0));

    while ( TRUE != isEmptyPTblLst(&g_point_node)) {
        index = rand() % PTBL_MAX_SIZE;
        if (!buffer[index]) {
            buffer[index] = 1;
            if ( FALSE == deleteItemByIndexPTblLst(&g_point_node,
                                                   index,
                                                   &value)) {
                fprintf(stdout, "[X] <%s> : in %d Delete item by index fail\n",
                        __FILE__,
                        __LINE__);

                return ;
            }

            fprintf(stdout, "[*] Item %d will be deleted.\n", value);
        }
    }
    fprintf(stdout, "[*] All elements have been deleted.\n");
}

void P_traversePTblLst(void)
{
    traversePTblLst(&g_point_node, printItemPTblLst);
}
