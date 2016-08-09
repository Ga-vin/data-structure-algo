#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "circular_list_test.h"
#include "circular_list.h"

static PtrCNode  _G_p_list = LIST_NULL;

static void _printTitle(const char *p_title)
{
    fprintf(stdout, "\n************************************************************\n");
    fprintf(stdout, "          %s\n", p_title);
    fprintf(stdout, "************************************************************\n");    
}

void T_createNodeCList(void)
{
    if ( _G_p_list) {
        fprintf(stdout, "Global list pointer has been created. \n");

        return ;
    }

    _printTitle("T_createNodeCList");
    _G_p_list = createNodeCList();
    if ( !_G_p_list) {
        fprintf(stderr, "Malloc node for list error. \n");

        return ;
    } else{
        fprintf(stdout, "Create node for the list successfully. \n");
    }
}

void T_getLengthCList(void)
{
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list pointer is NULL. \n");

        return ;
    }

    _printTitle("T_getLengthCList");
    fprintf(stdout, "[*] Length of list is %d. \n", getLengthCList(_G_p_list));
}

void T_isEmptyCList(void)
{
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Gloabl list pointer is NULL. \n");

        return ;
    }

    _printTitle("T_isEmptyCList");
    if ( TRUE == isEmptyCList(_G_p_list)) {
        fprintf(stdout, "[*] List is empty. \n");
    } else {
        fprintf(stdout, "[*] List is not empty. \n");
    }
}
