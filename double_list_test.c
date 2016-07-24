#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"
#include "double_list.h"
#include "double_list_test.h"

static DoubleList    _G_list_header = LIST_NULL;

static void _debugMsg(const INT8 *p_msg,
                      const INT8 *p_file,
                      UINT32      line)
{
    fprintf(stderr, "\n[x]In file <%s> at [%d]error: %s \n",
            p_file,
            line,
            p_msg);
}

static void _newLine(void)
{
    putchar('\n');
}

void T_createDoubleList(void)
{
    _G_list_header = createNodeDoubleList();
    if ( !_G_list_header) {
        fprintf(stderr, "\n[x] Create double list node error. [%s]- [%d]. \n",
                GET_FILE,
                GET_LINE);

        return ;
    } else {
        fprintf(stdout, "\n[*] Create node successfully. \n");
    }
}

void T_destroyDoubleList(void)
{
    if ( TRUE == destroyDoubleList(_G_list_header)) {
        if ( !_G_list_header) {
            fprintf(stdout, "\n[*] Destroy D-List successfully. \n");
        }  else {
            fprintf(stderr, "\n[x2] Destroy D-List error. \n");
        }
    } else {
        fprintf(stderr, "\n[x1] Destroy D-List error. \n");
    }
}

void T_clearDoubleList(void)
{
    if ( TRUE != clearDoubleList(_G_list_header)) {
        fprintf(stderr, "\n[x] Clear D-List error. \n ");

        return ;
    } else {
        if ( !_G_list_header) {
            fprintf(stderr, "\n[x] Clear D-List error. \n");
        } else {
            fprintf(stdout, "\n[*] Clear D-List successfully. \n");
        }
    }
}

void T_isEmptyDoubleList(void)
{
    if ( TRUE == isEmptyDoubleList(_G_list_header)) {
        fprintf(stdout, "\n[*] The list is empty. \n");
    } else {
        fprintf(stderr, "\n[x] The list is not empty. \n");
    }
}

void T_getLengthDoubleList(void)
{
    fprintf(stdout, "\n[*] Length of double list is <%d> \n",
            getLengthDoubleList(_G_list_header));
}

void T_isLastDoubleList(void)
{
    
}

void T_getIndexByItemDoubleList(void)
{
    
}

void T_getItemByIndexDoubleList(void)
{
    
}

void T_findItemDoubleList(void)
{
    
}

void T_deleteItemHeaderDoubleList(void)
{
    ElemType value = 0;
    UINT32   i;

    if ( !_G_list_header) {
        return ;
    }
    
    fprintf(stdout, "\n================Test Delete Item From Header of Double List================\n");
    for (i = 0; i != 5; ++i) {
        if ( FALSE == deleteItemHeaderDoubleList(_G_list_header,
                                                 &value)) {
            fprintf(stderr, "[x] Delete item from header error.\n");

            return ;
        } else {
            fprintf(stdout, "[*] Deleted item is <0x%x>\n", value);
            retrieveDoubleList(_G_list_header,
                               _printItem,
                               RET_FORWARD);
            _newLine();
        }
    }

    fprintf(stdout, "Has deleted 5 items \n");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();
}

void T_deleteItemTailDoubleList(void)
{
    ElemType value = 0;
    UINT32   i;

    if ( !_G_list_header) {
        return ;
    }
    
    fprintf(stdout, "\n================Test Delete Item From Tail of Double List================\n");
    for (i = 0; i != 5; ++i) {
        if ( FALSE == deleteItemTailDoubleList(_G_list_header,
                                                 &value)) {
            fprintf(stderr, "[x] Delete item from tail error.\n");

            return ;
        } else {
            fprintf(stdout, "[*] Deleted item is <0x%x>\n", value);
            retrieveDoubleList(_G_list_header,
                               _printItem,
                               RET_FORWARD);
            _newLine();
        }
    }

    fprintf(stdout, "Has deleted 5 items \n");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();    
}

void T_deleteItemDoubleList(void)
{
    ElemType buf[5] = {0};
    UINT32   i;

    srand(time(0));

    for (i = 0; i != 5; ++i) {
        buf[i] = rand() % 30 + 1;
    }

    for (i = 0; i != 5; ++i) {
        if ( FALSE == deleteItemDoubleList(_G_list_header,
                                           buf[i])) {
            fprintf(stderr, "Item 0x%X can not be found in list.\n", buf[i]);
        } else {
            fprintf(stdout, "Item[0x%X] has been deleted from list.\n", buf[i]);
            retrieveDoubleList(_G_list_header,
                               _printItem,
                               RET_FORWARD);
            _newLine();
        }
    }
}

void T_deleteItemByIndexDoubleList(void)
{
    UINT32   index_buf[3] = {2, 4, 6};
    ElemType value;
    UINT32   i;

    fprintf(stdout, "=====================Test Delete Item By Index===================\n");
    for (i = 0; i != 3; ++i) {
        if ( FALSE == deleteItemByIndexDoubleList(_G_list_header,
                                                  index_buf[i],
                                                  &value)) {
            fprintf(stderr, "Delete item at %d error. \n", index_buf[i]);
        } else {
            fprintf(stdout, "Delete item 0x%X at %d\n", value, index_buf[i]);
            retrieveDoubleList(_G_list_header, _printItem, RET_FORWARD);
            _newLine();
        }
    }

    fprintf(stdout, "Delete all items.\n");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();
}

void T_insertItemHeaderDoubelList(void)
{
    UINT32 i;
    UINT32 value;
    
    srand(time(NULL));
    
    if ( !_G_list_header) {
        _debugMsg("Global list header is NULL",
                  GET_FILE,
                  GET_LINE);

        return ;
    }

    for (i = 0; i != MAX_LEN; ++i) {
        value = rand() % 100 + 1;
        fprintf(stdout, "<0x%X> ", value);
        if ( FALSE == insertItemHeaderDoubleList(_G_list_header,
                                                 value)) {
            _debugMsg("insert item to header fail",
                      GET_FILE,
                      GET_LINE);

            return ;
        }
    }
    _newLine();
    if ( TRUE == isEmptyDoubleList(_G_list_header)) {
        fprintf(stdout, "\n[*] The list is EMPTY. \n");
    } else {
        fprintf(stdout, "\n[*] The list is not EMPTY. \n");
        T_getLengthDoubleList();
    }

    if ( FALSE == retrieveDoubleList(_G_list_header, _printItem, RET_FORWARD)) {
        _debugMsg("Retreive list fail. ",
                  GET_FILE,
                  GET_LINE);

        return ;
    } 
}

void T_insertItemTailDoubleList(void)
{
    UINT32 value;
    UINT32 i;
    
    srand(time(NULL));
    
    if ( !_G_list_header) {
        _debugMsg("Insert list global list NULL",
                  GET_FILE,
                  GET_LINE);

        return ;
    }

    _newLine();
    for (i = 0; i != MAX_LEN; ++i) {
        value = rand() % 10 + 1;
        fprintf(stdout, "<0x%X> ", value);

        if ( FALSE == insertItemTailDoubleList(_G_list_header,
                                               value)) {
            _debugMsg("Insert item to tail fail. ",
                      GET_FILE,
                      GET_LINE);

            return ;
        }
    }
    _newLine();    

    T_getLengthDoubleList();
    if ( FALSE == retrieveDoubleList(_G_list_header,
                                     _printItem,
                                     RET_FORWARD)) {
        _debugMsg("Retreive list fail ",
                  GET_FILE,
                  GET_LINE);

        return ;
    }
}

void T_insertItemDoubleList(void)
{
    UINT32 i;
    UINT32 value;
    
    srand(time(NULL));

    if ( !_G_list_header) {
        _debugMsg("insert item with specific position fail",
                  GET_FILE,
                  GET_LINE);

        return ;
    }

    _newLine();
    fprintf(stdout, "\n=============Test Insert Item Double List =================\n");
    for (i = 0; i != MAX_LEN; ++i) {
        value = rand() % 50 + 1;
        fprintf(stdout, "<0x%X> ", value);

        if ( !(i%2)) {
            if ( FALSE == insertItemDoubleList(_G_list_header,
                                               value,
                                               INS_HEADER)) {
                _debugMsg("insert item header fail",
                          GET_FILE,
                          GET_LINE);

                return ;
            }
            retrieveDoubleList(_G_list_header,
                               _printItem,
                               RET_FORWARD);
            _newLine();
        } else {
            if ( FALSE == insertItemDoubleList(_G_list_header,
                                               value,
                                               INS_TAIL)) {
                _debugMsg("insert item tail fail",
                          GET_FILE,
                          GET_LINE);

                return ;
            }
            retrieveDoubleList(_G_list_header,
                               _printItem,
                               RET_FORWARD);
            _newLine();
        }
    }
    _newLine();

    fprintf(stdout, "After all inserted.\n");
    T_getLengthDoubleList();
    if ( FALSE == retrieveDoubleList(_G_list_header,
                                     _printItem,
                                     RET_FORWARD)) {
        _debugMsg("retrieve double list fail",
                  GET_FILE,
                  GET_LINE);

        return ;
    }
    _newLine();
}

void T_insertItemByIndexDoubleList(void)
{
    UINT32 index_buf[5] = {1, 3, 5, 7, 9};
    UINT32 value_buf[5] = {0};
    UINT32 i;

    srand(time(0));

    for (i = 0; i != 5; ++i) {
        value_buf[i] = rand() % 30 + 1;
        fprintf(stdout, "{0x%x} ", value_buf[i]);
    }
    _newLine();

    if ( !_G_list_header) {
        fprintf(stderr, "[x] Global list header is NULL.\n");

        return ;
    }

    fprintf(stdout, "\n================Test Insert By Index ===================\n");
    for (i = 0; i != 5; ++i) {
        if ( FALSE == insertItemByIndexDoubleList(_G_list_header,
                                                  index_buf[i],
                                                  value_buf[i])) {
            fprintf(stderr, "[x] Insert item 0x%x at %d error.\n",
                    value_buf[i],
                    index_buf[i]);

            return ;
        }
        retrieveDoubleList(_G_list_header,
                           _printItem,
                           RET_FORWARD);
        _newLine();
    }

    fprintf(stdout, "All inserted.\n");
    retrieveDoubleList(_G_list_header, _printItem, RET_FORWARD);
    _newLine();
}

void T_getLastDoubleList(void)
{
    /*
     * Get last node of double list function has been used frequently to check
     *  whether it is last one, so its unit test could not be added here
     */
}
    
void T_retrieveDoubleLIst(void)
{
    /*
     * Retrieve function of double list function has been used frequently to
     * print all items of double list.
     */    
}

void T_sortDoubleList(void)
{
    if ( !_G_list_header) {
        fprintf(stderr, "[x] Global list header is NULL.\n");

        return ;
    }

    fprintf(stdout, "\n===================Test Sort As ASCENDING order Double List===================\n");
    puts("Before sorted double list");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();
    if ( FALSE == sortDoubleList(_G_list_header,
                                 ASCENDING)) {
        fprintf(stderr, "[x] Sort double list error. \n");

        return ;
    }

    puts("After sorted as ASCENDING order.");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();

    if ( !_G_list_header) {
        fprintf(stderr, "[x] Global list header is NULL.\n");

        return ;
    }

    fprintf(stdout, "\n===================Test Sort as DESCENDING order Double List===================\n");
    puts("Before sorted double list");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();
    if ( FALSE == sortDoubleList(_G_list_header,
                                 DESCENDING)) {
        fprintf(stderr, "[x] Sort double list error. \n");

        return ;
    }

    puts("After sorted as DESCENDING order.");
    retrieveDoubleList(_G_list_header,
                       _printItem,
                       RET_FORWARD);
    _newLine();
}

void T_mergeDoubleList(void)
{
    DoubleList _list_a = LIST_NULL;
    DoubleList _list_b = LIST_NULL;
    DoubleList _list_c = LIST_NULL;
    UINT32     i;
    ElemType   value;

    _list_a = createNodeDoubleList();
    if ( !_list_a) {
        fprintf(stderr, "[x] Create Node for List A error. \n");

        return ;
    }

    _list_b = createNodeDoubleList();
    if ( !_list_b) {
        fprintf(stderr, "[x] Create Node for List B error. \n");

        return ;
    }

    _list_c = createNodeDoubleList();
    if ( !_list_c) {
        fprintf(stderr, "[x] Create Node for List C error. \n");

        return ;
    }

    srand(time(0));

#define    LIST_A_MAX_LEN    (5)    
    for (i = 0; i != LIST_A_MAX_LEN; ++i) {
        value = rand() % 50 + 1;
        if ( FALSE == insertItemHeaderDoubleList(_list_a,
                                                 value)) {
            fprintf(stderr, "[x] Insert item to list A error. \n");

            return ;
        }
    }

#define    LIST_B_MAX_LEN    (10)
    for (i = 0; i != LIST_B_MAX_LEN; ++i) {
        value = rand() % 50 + 1;
        if ( FALSE == insertItemHeaderDoubleList(_list_b,
                                                 value)) {
            fprintf(stderr, "[x] Insert item to list B error. \n");

            return ;
        }
    }

    puts("Before merge double list.");
    puts("List-A.");
    retrieveDoubleList(_list_a,
                       _printItem,
                       RET_FORWARD);
    _newLine();

    puts("List-B.");
    retrieveDoubleList(_list_b,
                       _printItem,
                       RET_FORWARD);
    _newLine();

    if ( FALSE == mergeDoubleList(_list_a,
                        _list_b,
                        _list_c)) {
        fprintf(stderr, "[x] Merge list a and list b to list c error. \n");

        return ;
    }

    puts("After merge double list.");
    puts("List-A.");
    retrieveDoubleList(_list_a,
                       _printItem,
                       RET_FORWARD);
    _newLine();

    puts("List-B.");
    retrieveDoubleList(_list_b,
                       _printItem,
                       RET_FORWARD);
    _newLine();
    
    puts("List-C");
    retrieveDoubleList(_list_c,
                       _printItem,
                       RET_FORWARD);
    _newLine();

    destroyDoubleList(_list_a);
    destroyDoubleList(_list_b);
    destroyDoubleList(_list_c);

    if ( _list_a) {
        fprintf(stderr, "[x] Destroy List-A pointer error. \n");
    }

    if ( _list_b) {
        fprintf(stderr, "[x] Destroy List-B pointer error. \n");
    }

    if ( _list_c) {
        fprintf(stderr, "[x] Destroy List-C pointer error. \n");
    }
}
