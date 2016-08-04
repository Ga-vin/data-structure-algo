#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "circular_list_test.h"

static PtrCNode  _G_p_list = LIST_NULL;

void T_createNodeCList(void)
{
    if ( _G_p_list) {
        fprintf(stdout, "Global list pointer has been created. \n");

        return ;
    }

    _G_p_list = createNodeCList();
    if ( !_G_p_list) {
        fprintf(stderr, "Malloc node for list error. \n");

        return ;
    } else{
        fprintf(stdout, "Create node for the list successfully. \n");
    }
}
