#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_test.h"
#include "list.h"

void T_createList(void)
{
    List p_header = LIST_NULL;

    if (!p_header) {
        fprintf(stdout, "[*] %s: p_list is NULL\n", __FILE__);
    }

    p_header = createList();
    if (!p_header) {
        fprintf(stdout, "<X> Create list fail.\n");

        return ;
    } else {
        fprintf(stdout, "[*] Create list successfully.\n");

        p_header->item = 0xFFFFFFF;
        p_header->p_next = NULL;
    }
}

void T_destroyList(void)
{
    List p_header = LIST_NULL;

    p_header = createList();
    if (!p_header) {
        fprintf(stdout, "<X> %s: T_destroyList-object NULL.\n", __FILE__);

        return ;
    }

    p_header->item   = 0xFFFFFFF;
    p_header->p_next = LIST_NULL;

    if ( TRUE != destroyList(p_header)) {
        fprintf(stdout, "[X] Destroy list fail.\n");

        return ;
    }
    if (p_header) {
        fprintf(stdout, "<X> %s: T_destroyList-destroy fail.\n", __FILE__);

        return ;
    } else {
        fprintf(stdout, "<*> %s: T_destroyList-destroy successfully.\n", __FILE__);
    }
}
