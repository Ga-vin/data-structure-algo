#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_test.h"
#include "list.h"

List _g_list_header = LIST_NULL;
#define    MAX_BUF_SIZE    (20)

static void cleanLine(void)
{
    while ( '\n' != getchar()) {
        ;
    }
}

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
    UINT32 buffer[MAX_BUF_SIZE];
    UINT32 index;

    fputs("[*] Insert item to header of list.\n", stdout);
    
    for (index = 0; index != MAX_BUF_SIZE; ++index) {
        buffer[index] = (index + 1) * 11;
    }

    for (index = 0; index != MAX_BUF_SIZE; ++index) {
        if ( TRUE != insertItemHeaderList(_g_list_header,
                                          buffer[index])) {
            fprintf(stdout, "[X] Insert item fail. <%s>-%d\n",
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        }
    }
}

void T_insertItemTailList(void)
{
    UINT32 buffer[MAX_BUF_SIZE];
    UINT32 index;

    fputs("[*] Insert item to tail of list.\n", stdout);
    
    for (index = 0; index != MAX_BUF_SIZE; ++index) {
        buffer[index] = (index + 1) * 100;
    }

    for (index = 0; index != MAX_BUF_SIZE; ++index) {
        if ( TRUE != insertItemTailList(_g_list_header,
                                          buffer[index])) {
            fprintf(stdout, "[X] Insert item fail. <%s>-%d\n",
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        }
    }    
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

void T_clearList(void)
{
    if ( !_g_list_header) {
        fprintf(stdout, "[X] List header is NULL. <%s>-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }

    if ( FALSE == clearList(_g_list_header)) {
        fprintf(stdout, "[X] Clear list fail.<%s>-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    } else {
        if ( !getLengthList(_g_list_header)) {
            fprintf(stdout, "[*] Clear list successfully.\n");            
        }
    }
}

void T_deleteItemHeaderList(void)
{
    int      user_get;
    ElemType value_to_be_deleted;
    
    if ( !_g_list_header) {
        fprintf(stdout, "Gloabl list header is NULL: <%s>-%d\n",
                __FILE__,
                __LINE__);

        return ;
    }

    do {
        if ( TRUE != deleteItemHeaderList(_g_list_header, &value_to_be_deleted)) {
            fprintf(stdout, "<T_deleteItemHeaderList> delete fail: <%s>-%d\n",
                    __FILE__,
                    __LINE__);

            return ;
        }

        T_getLengthList();
        T_retrieveList();

        puts("Do you want to continue to delete? <4 to quit>");
        scanf("%d", &user_get);
        cleanLine();
    } while ( 4 != user_get);

    T_getLengthList();
    T_retrieveList();
}
