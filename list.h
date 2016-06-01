/* ************************************************************************** */
/* File Name : list.h                                                         */
/* Function  : Definition of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.05.15                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef    __EXT_LIST_H_
#define    __EXT_LIST_H_

#include "common.h"

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/
#define    LIST_NULL    (NULL)
#define    LIST_EMPTY   (0)
/* *****************************************************************************
 * New definition of new structure
 ******************************************************************************/
typedef struct LNODE {
    ElemType         item;
    struct LNODE    *p_next;
}LNode;

typedef LNode     *PtrToNode;
typedef PtrToNode  List;
typedef PtrToNode  Position;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
List     createList(void);
STATE    destroyList(List p_list);
STATE    clearList(List p_list);
BOOL     isEmptyList(const List p_list);
BOOL     isLastList(const List p_list, const Position p_item);
UINT32   getLengthList(const List p_list);
STATE    getItemByIndexList(const List p_list, UINT32 index, ElemType *p_value);
STATE    getIndexByItemList(const List p_list, UINT32 value, UINT32 *p_index);
Position findItemList(const List p_list, const ElemType item);
STATE    deleteItemHeaderList(List p_list, ElemType *p_del_item);
STATE    deleteItemTailList(List p_list, ElemType *p_del_item);
STATE    deleteItemList(List p_list, const ElemType item);
Position findPreviousItemList(const List p_list, const ElemType item);
STATE    insertItemHeaderList(List p_list, const ElemType item);
STATE    insertItemTailList(List p_list, const ElemType item);
STATE    insertItemList(List p_list, const Position p_item, const ElemType item);
STATE    insertItemByIndexList(List p_header, UINT32 index, ElemType item);
Position getHeaderList(const List p_list);
Position getFirstList(const List p_list);
Position findLastList(const List p_list);
STATE    retrieveList(const List p_list);

#endif /* __EXT_LIST_H_ */
