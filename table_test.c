#include "table_test.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>

void T_initializeTblLst(void)
{
    PTableNode p_node = NULL;
    p_node = initTblLst(TBL_MAX_SIZE);
    if (NULL == p_node) {
        fprintf(stdout, "Initialize table list fail\n");

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "[*] Length is %d\n", p_node->t_length);
    fprintf(stdout, "[*] Size is %d\n", p_node->t_size);
}
