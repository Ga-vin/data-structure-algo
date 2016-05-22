#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_test.h"
#include "list.h"

List _g_list_header = LIST_NULL;
#define    MAX_BUF_SIZE    (20)

void T_createList(void)
{
    List p_header = LIST_NULL;

    if (!p_header) {
        fprintf(stdout, "[*] %s: p_list is NULL\n", __FILE__);
    }

    p_header = createList();
    if ( !p_header) {
        fprintf(stdout, "<X> Create list fail.\n");

        return ;
    } else {
        fprintf(stdout, "[*] Create list successfully.\n");

        p_header->item   = 0xFFFFFFF;
        p_header->p_next = NULL;
        _g_list_header   = p_header;
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

void T_getLengthList(void)
{
    if ( !_g_list_header) {
        fprintf(stdout, "[X] Global list header is NULL\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout, "[*] Length of list is %d\n", getLengthList(_g_list_header));
}

void T_isEmptyList(void)
{
    if ( !_g_list_header) {
        fprintf(stdout, "[X] Global list header is NULL : <%s>-%d\n", __FILE__, __LINE__);

        return ;
    }

    if ( TRUE == isEmptyList(_g_list_header)) {
        fprintf(stdout, "[*] List is empty\n");
    } else {
        fprintf(stdout, "[*] List is not empty\n");
    }
}

void T_insertItemHeaderList(void)
{
    
}

void T_insertItemTailList(void)
{
    
}

void T_insertItemList(void)
{
    UINT32 buffer[MAX_BUF_SIZE];
    UINT32 index;
    
    if ( !_g_list_header) {
        fprintf(stdout, "[X] Global list is NULL. <%s>-%d\n",
                __FILE__, __LINE__);

        return ;
    }

    for (index = 0; index != MAX_BUF_SIZE; ++index) {
        buffer[index] = index * 10;
        if ( TRUE != insertItemList(_g_list_header, _g_list_header, buffer[index])) {
            fprintf(stdout, "[X] Insert item to list fail. <%s>-%d\n", __FILE__, __LINE__);

            return ;
        } else {
            fprintf(stdout, "[*] Insert item to list successfully. <%s>-%d\n", __FILE__, __LINE__);
        }
    }
}

void T_retrieveList(void)
{
    fprintf(stdout, "[*] Retrieve list:\n");

    if ( !_g_list_header) {
        fprintf(stdout, "[X] Global list is NULL. <%s>-%d.\n",
                __FILE__,
                __LINE__);

        return ;
    }
    
    retrieveList(_g_list_header);
}










