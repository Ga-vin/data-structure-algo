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
    
}

void T_deleteItemTailDoubleList(void)
{
    
}

void T_deleteItemDoubleList(void)
{
    
}

void T_deleteItemByIndexDoubleList(void)
{
    
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
        } else {
            if ( FALSE == insertItemDoubleList(_G_list_header,
                                               value,
                                               INS_TAIL)) {
                _debugMsg("insert item tail fail",
                          GET_FILE,
                          GET_LINE);

                return ;
            }
        }
    }
    _newLine();

    T_getLengthDoubleList();
    if ( FALSE == retrieveDoubleList(_G_list_header,
                                     _printItem,
                                     RET_FORWARD)) {
        _debugMsg("retrieve double list fail",
                  GET_FILE,
                  GET_LINE);

        return ;
    }
}

void T_insertItemByIndexDoubleList(void)
{
    
}

void T_getLastDoubleList(void)
{
    
}
    
void T_retrieveDoubleLIst(void)
{
    
}

void T_sortDoubleList(void)
{
    
}

void T_mergeDoubleList(void)
{
    
}
