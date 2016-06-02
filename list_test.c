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
    if (!_g_list_header) {
        fprintf(stdout, "<T_destroyList> %s-%d: global list is NULL.\n", __FILE__, __LINE__);

        exit(EXIT_FAILURE);
    }

    if ( TRUE != destroyList(_g_list_header)) {
        fprintf(stdout, "<T_destroyList> Destroy list fail %s-%d.\n", __FILE__, __LINE__);

        exit(EXIT_FAILURE);
    }
    
    if ( !_g_list_header) {
        fprintf(stdout, "<T_destroyList> %s-%d: destroy fail.\n", __FILE__, __LINE__);

        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "<T_destroyList> %s-%d: destroy list successfully.\n", __FILE__, __LINE__);
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

void T_findLastList(void)
{
    Position p_temp = LIST_NULL;
    
    if ( !_g_list_header) {
        fprintf(stdout, "<T_findLastList> global list is NULL. %s - %d\n", __FILE__, __LINE__);

        exit(EXIT_FAILURE);
    }

    p_temp = findLastList(_g_list_header);
    if ( LIST_NULL == p_temp) {
        fprintf(stdout, "<T_findLastList> find last list is NULL. %s - %d\n", __FILE__, __LINE__);

        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "Find last node: value is %d\n", p_temp->item);
    }
}

void T_deleteItemTailList(void)
{
    ElemType value_to_be_deleted;
    int      user_get;
    
    if ( !_g_list_header) {
        fprintf(stdout, "<T_deleteItemTailList> global list is NULL %s-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }

    do {
        if ( TRUE == deleteItemTailList(_g_list_header, &value_to_be_deleted)) {
            fprintf(stdout, "Delete item ok. value is [*%d]\n", value_to_be_deleted);
        } else {
            fprintf(stdout, "<T_deleteItemTailList> delete item fail. %s-%d\n",
                    __FILE__,
                    __LINE__);
        }

        T_retrieveList();

        puts("Do you want to continue? <4 to quit>");
        scanf("%d", &user_get);
        cleanLine();
    } while ( 4 != user_get);
}

void T_getItemByIndexList(void)
{
    UINT32   index;
    ElemType value = 0;
    if ( !_g_list_header) {
        fprintf(stdout, "<T_getItemByIndex> global is NULL. %s-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }

    if ( getLengthList(_g_list_header) > 0) {
        index = 3;
        if ( FALSE == getItemByIndexList(_g_list_header,
                                         index,
                                         &value)) {
            fprintf(stdout, "<T_getItemByIndex> get item fail. %s-%d\n",
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        } else {
            fprintf(stdout, "Index<%d> value is %d\n", index, value);
        }

        index = 6;
        if ( FALSE == getItemByIndexList(_g_list_header,
                                         index,
                                         &value)) {
            fprintf(stdout, "<T_getItemByIndex> get item fail. %s-%d\n",
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        } else {
            fprintf(stdout, "Index<%d> value is %d\n", index, value);
        }        
    }
}

void T_getIndexByItemList(void)
{
    UINT32 index;
    UINT32 value = 0;

    if ( !_g_list_header) {
        fprintf(stdout, "<T_getIndexByItemList> global is NULL. %s-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }

    if ( getLengthList(_g_list_header) > 0) {
        value = 1000;
        if ( TRUE == getIndexByItemList(_g_list_header,
                                        value,
                                        &index)) {
            fprintf(stdout, "Value %d's index is %d.\n",
                    value, index);
        } else {
            fprintf(stderr, "<T_getIndexByItemList> get index fail. %s-%d\n",
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        }

        value = 1020;
        if ( TRUE == getIndexByItemList(_g_list_header,
                                        value,
                                        &index)) {
            fprintf(stdout, "Value %d's index is %d.\n",
                    value, index);
        } else {
            fprintf(stderr, "<T_getIndexByItemList> get index fail. %s-%d\n",
                    __FILE__,
                    __LINE__);

            // exit(EXIT_FAILURE);
            return ;
        }        
    }
}

void T_insertItemByIndexList(void)
{
    if ( !_g_list_header) {
        fprintf(stdout, "<T_insertItemByIndexList> global is NULL. %s-%d\n",
                __FILE__,
                __LINE__);

        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "We will insert item 1111 into location of 5.\n");
    if ( TRUE == insertItemByIndexList(_g_list_header,
                                       5,
                                       1111)) {
        fprintf(stdout, "Insert successfully.\n");
    } else {
        fprintf(stdout, "Insert 1111 into location of 5 fail.\n");
    }
    T_retrieveList();

    fprintf(stdout, "We will insert item 2222 into location of 10.\n");
    if ( TRUE == insertItemByIndexList(_g_list_header,
                                       10,
                                       2222)) {
        fprintf(stdout, "Insert successfully.\n");
    } else {
        fprintf(stdout, "Insert 2222 into location of 10 fail.\n");
    }
    T_retrieveList();
}
