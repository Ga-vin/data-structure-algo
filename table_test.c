#include "table_test.h"
#include "table.h"

#include <stdio.h>
#include <stdlib.h>

static PTableNode p_node;

static inline void cleanLine(void)
{
    while ( '\n' != getchar()) {
        continue;
    }
}

void T_initializeTblLst(void)
{
    p_node = NULL;
    p_node = initTblLst(TBL_MAX_SIZE);
    if (NULL == p_node) {
        fprintf(stdout, "Initialize table list fail\n");

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "[*] Length is %d\n", p_node->t_length);
    fprintf(stdout, "[*] Size is %d\n", p_node->t_size);
}

void T_getLengthTblLst(void)
{
    if (NULL == p_node) {
        fprintf(stdout, "<Error> The table is not ready\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout, "[*] The length is %d\n", getLengthTblLst(*p_node));
}

void T_getSizeTblLst(void)
{
    if (NULL == p_node) {
        fprintf(stdout, "<Error> The table is not ready\n");

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "[*] The size is %d\n", getSizeTblLst(*p_node));
}

void T_isEmptyTblLst(void)
{
    if ( TRUE == isEmptyTblLst(p_node)) {
        fprintf(stdout, "[*] The table is empty\n");
    } else {
        fprintf(stdout, "[*] The table is not empty\n");
    }
}

void T_isFullTblLst(void)
{
    if ( TRUE == isFullTblLst(p_node)) {
        fprintf(stdout, "[*] The table is full\n");
    } else {
        fprintf(stdout, "[*] The table is not full\n");
    }
}

void T_cleanTblLst(void)
{
    fprintf(stdout, "[*] The length of table is %d\n",
            getLengthTblLst(*p_node));
    p_node->t_length = 0;
    fprintf(stdout, "[*] The length of table is %d\n",
            getLengthTblLst(*p_node));
}

void T_insertItemHeaderTblLst(void)
{
    ElemType value;

    do {
        fprintf(stdout, "[*] Enter a number to insert> ");

        scanf("%d", &value);
        if ( TRUE != insertItemHeaderTblLst(p_node, value)) {
            fprintf(stdout, "[*] Insert item %d Fail\n", value);

            break;
        }
        
        cleanLine();
    } while (value != 12321);

    fprintf(stdout, "[*] The length of table is %d\n", getLengthTblLst(*p_node));
    fprintf(stdout, "[*] All elements of table is \n");
    traverseTblLst(p_node, printItemTblLst);
}

void T_insertItemTailTblLst(void)
{
    ElemType value;

    do {
        fprintf(stdout, "[*] Enter a number to insert> ");

        scanf("%d", &value);
        if ( TRUE != insertItemTailTblLst(p_node, value)) {
            fprintf(stdout, "[*] Insert item %d Fail\n", value);

            break;
        }
        
        cleanLine();
    } while (value != 12321);

    fprintf(stdout, "[*] The length of table is %d\n", getLengthTblLst(*p_node));
    fprintf(stdout, "[*] All elements of table is \n");
    traverseTblLst(p_node, printItemTblLst);    
}
