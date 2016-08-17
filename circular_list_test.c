#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "circular_list_test.h"
#include "circular_list.h"

static PtrCNode  _G_p_list = LIST_NULL;

static BOOL __equal(ElemType left, ElemType right)
{
    return ((left == right) ? TRUE : FALSE);
}

static BOOL __greater(ElemType left, ElemType right)
{
    return ((left > right) ? TRUE : FALSE);
}

static BOOL __less(ElemType left, ElemType right)
{
    return ((left < right) ? TRUE : FALSE);
}

static void __print(ElemType item)
{
    fprintf(stdout, "%d ", item);
}

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

void T_getItemByIndexCList(void)
{
    UINT32   i;
    UINT32   start = 1;
    UINT32   end;
    ElemType item;
    
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list header is NULL. \n");

        return ;
    }

    _printTitle("Get Item By Index. \n");
    end = getLengthCList(_G_p_list);
    for (i = start; i < end; i += 2) {
        if ( FALSE == getItemByIndexCList(_G_p_list,
                                          i,
                                          &item)) {
            fprintf(stderr, "[x] get item by index error. \n");

            return ;
        } else {
            fprintf(stdout, "[*] Index %d item is %d. \n", i, item);
        }
    }
}

void T_locateItemCList(void)
{
    UINT32 i;
    UINT32 start = 1;
    UINT32 end;
    
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list header is NULL. \n");

        return ;
    }

    _printTitle("LocateItem");
    end = getLengthCList(_G_p_list);
    for (i = start; i < end; i += 2) {
        if ( FALSE == locateItemCList(_G_p_list,
                                      i,
                                      __equal)) {
            fprintf(stderr, "[x] Item %d can not find. \n", i);
        } else {
            fprintf(stdout, "[*] Item %d has been found. \n", i);
        }
    }
}

void T_getPriorItemCList(void)
{
    UINT32   i;
    UINT32   start = 1;
    UINT32   end;
    ElemType prior_item;
    
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list header NULL. \n");

        return ;
    }

    end = getLengthCList(_G_p_list);
    for (i = start; i < end; i += 3) {
        if ( FALSE == getPriorItemCList(_G_p_list,
                                        i,
                                        &prior_item)) {
            fprintf(stderr, "[x] Can not find item %d's prior. \n", i);
        } else {
            fprintf(stdout, "[*] Item %d's prior is %d. \n", i, prior_item);
        }
    }
}

void T_getNextItemCList(void)
{
    UINT32   i;
    UINT32   start = 0;
    UINT32   end;
    ElemType next_item;
    
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list header error. \n");

        return ;
    }

    _printTitle("Get Next Item");
    end = getLengthCList(_G_p_list);
    for (i = start; i < end; i += 4) {
        if ( FALSE == getNextItemCList(_G_p_list,
                                       i,
                                       &next_item)) {
            fprintf(stderr, "[x] Can not find item %d's next. \n", i);
        } else {
            fprintf(stdout, "[*] Item %d's next item is %d. \n", i, next_item);
        }
    }
}

void T_getItemPtrCList(void)
{
    CircularList p_node = LIST_NULL;
    
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Global list header NULL. \n");

        return ;
    }

    _printTitle("Get Item Ptr Node");
    if ( FALSE == traverseForwardCList(_G_p_list,
                                       __print)) {
        fprintf(stderr, "[x] Traverse List error. \n");
    }

    p_node = getItemPtrCList(_G_p_list,
                             1);
    if ( !p_node) {
        fprintf(stderr, "[x] Get item ptr node error. \n");
    } else {
        fprintf(stdout, "[*] Get ptr node in list successfully. Data is %d. \n", p_node->data);
    }

    p_node = getItemPtrCList(_G_p_list,
                             getLengthCList(_G_p_list)/2);
    if ( !p_node) {
        fprintf(stderr, "[x] Get item ptr node error. \n");
    } else {
        fprintf(stdout, "[*] Get ptr node in list successfully. Data is %d. \n", p_node->data);
    }

    p_node = getItemPtrCList(_G_p_list,
                             getLengthCList(_G_p_list));
    if ( !_G_p_list) {
        fprintf(stderr, "[x] Get item ptr node error. \n");
    } else {
        fprintf(stdout, "[*] Get ptr node in list successfully. Data is %d. \n", p_node->data);
    }
}
