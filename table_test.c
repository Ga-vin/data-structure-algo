#include "table_test.h"
#include "table.h"

#include <stdio.h>
#include <stdlib.h>

#define    TB_END_POINT    (12321)

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

    while (TRUE) {
        fprintf(stdout, "[*] Enter a number to insert> ");

        scanf("%d", &value);
        if (TB_END_POINT == value) {
            fprintf(stdout, "[*] Insert to header finish\n");
            
            break;
        }
        
        if ( TRUE != insertItemHeaderTblLst(p_node, value)) {
            fprintf(stdout, "[*] Insert item %d Fail\n", value);

            break;
        }
        
        cleanLine();
    } 

    fprintf(stdout, "[*] The length of table is %d\n", getLengthTblLst(*p_node));
    fprintf(stdout, "[*] All elements of table is \n");
    traverseTblLst(p_node, printItemTblLst);
}

void T_insertItemTailTblLst(void)
{
    ElemType value;

    while (TRUE) {
        fprintf(stdout, "[*] Enter a number to insert> ");

        scanf("%d", &value);
        if (TB_END_POINT == value) {
            fprintf(stdout, "[*] Insert item to tail finish\n");

            break;
        }
        
        if ( TRUE != insertItemTailTblLst(p_node, value)) {
            fprintf(stdout, "[*] Insert item %d Fail\n", value);

            break;
        }
        
        cleanLine();
    } 

    fprintf(stdout, "[*] The length of table is %d\n", getLengthTblLst(*p_node));
    fprintf(stdout, "[*] All elements of table is \n");
    traverseTblLst(p_node, printItemTblLst);    
}

void T_insertItemByIndexTblLst(void)
{
    ElemType value;
    UINT32   index;

    while (TRUE) {
        fputs("> Enter index to be inserted <", stdout);
        scanf("%d", &index);
        cleanLine();
        fputs("> Enter value to be inserted <", stdout);
        scanf("%d", &value);
        cleanLine();
        if (TB_END_POINT == value) {
            fprintf(stdout, "[*] Insert item by index finish\n");

            break;
        }

        if (TRUE != insertItemByIndexTblLst(p_node,
                                            index,
                                            value)) {
            fprintf(stdout, "[X] Insert item by index fail\n");

            break;
        }
    }

    fprintf(stdout, "[*] Table list length is %d\n", getLengthTblLst(*p_node));
    fprintf(stdout, "[*] All item of table is \n");
    traverseTblLst(p_node, printItemTblLst);
}

void T_deleteItemHeaderTblLst(void)
{
    ElemType value = 0;

    while (TRUE) {
        if (TRUE == isEmptyTblLst(p_node)) {
            fprintf(stdout, "[X] Table list is empty\n");

            break;
        }

        if (TRUE != deleteItemHeaderTblLst(p_node,
                                           &value)) {
            fprintf(stdout, "[X] Delete item fail\n");

            break;
        }

        fprintf(stdout, "[*] %d item has been deleted\n", value);
    }

    fprintf(stdout, "[*] The length of table list is %d\n", getLengthTblLst(*p_node));
}

void T_deleteItemTailTblLst(void)
{
    ElemType value = 0;

    while (TRUE) {
        if (TRUE == isEmptyTblLst(p_node)) {
            fprintf(stdout, "[X] Table list is empty\n");

            break;
        }

        if (TRUE != deleteItemTailTblLst(p_node,
                                           &value)) {
            fprintf(stdout, "[X] Delete item fail\n");

            break;
        }

        fprintf(stdout, "[*] %d item has been deleted\n", value);
    }

    fprintf(stdout, "[*] The length of table list is %d\n", getLengthTblLst(*p_node));    
}

void T_deleteItemByIndexTblLst(void)
{
    ElemType value = 0;
    UINT32   index = 0;

    while (TRUE) {
        if (TRUE == isEmptyTblLst(p_node)) {
            fprintf(stdout, "[X] Table list is empty\n");

            break;
        }

        fputs("[> Enter the index to be deleted <]", stdout);
        scanf("%d", &index);
        cleanLine();

        if (TRUE != deleteItemByIndexTblLst(p_node,
                                            index,
                                           &value)) {
            fprintf(stdout, "[X] Delete item fail\n");

            break;
        }

        fprintf(stdout, "[*] %d item has been deleted\n", value);
    }

    fprintf(stdout, "[*] The length of table list is %d\n", getLengthTblLst(*p_node));       
}
