#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"
#include "double_list_test.h"

static DoubleList    _G_list_header = LIST_NULL;

void T_createDoubleList(void)
{
    _G_list_header = createNodeDoubleList();
    if ( !_G_list_header) {
        fprintf(stderr, "[x] Create double list node error. [%s]- [%d]. \n",
                GET_FILE,
                GET_LINE);

        return ;
    } else {
        fprintf(stdout, "[*] Create node successfully. \n");
    }
}

void T_destroyDoubleList(void)
{
    if ( TRUE == destroyDoubleList(_G_list_header)) {
        if ( !_G_list_header) {
            fprintf(stdout, "[*] Destroy D-List successfully. \n");
        }  else {
            fprintf(stderr, "[x2] Destroy D-List error. \n");
        }
    } else {
        fprintf(stderr, "[x1] Destroy D-List error. \n");
    }
}

void T_clearDoubleList(void)
{
    if ( TRUE != clearDoubleList(_G_list_header)) {
        fprintf(stderr, "[x] Clear D-List error. \n ");

        return ;
    } else {
        if ( !_G_list_header) {
            fprintf(stderr, "[x] Clear D-List error. \n");
        } else {
            fprintf(stdout, "[*] Clear D-List successfully. \n");
        }
    }
}

void T_isEmptyDoubleList(void)
{
    if ( TRUE == isEmptyDoubleList(_G_list_header)) {
        fprintf(stdout, "[*] The list is empty. \n");
    } else {
        fprintf(stderr, "[x] The list is not empty. \n");
    }
}
