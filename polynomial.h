/* ************************************************************************** */
/* File Name : polynomial.h                                                   */
/* Function  : Definition of some new data type and interfaces                */
/* Author    : Gavin.Bai                                                      */
/* Time      : 2016.08.25                                                     */
/* Version   : (C) v1.0                                                       */
/* Modified  :                                                                */
/* ************************************************************************** */
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "common.h"

/* *****************************************************************************
 * New definition of new constances
 ******************************************************************************/

/* *****************************************************************************
 * New definition of new structure
 ******************************************************************************/
typedef struct _TermType_ {
    float    coef;
    INT32    exp;
} TermType;

typedef struct _Polynomial_ {
    TermType             item;
    struct _Polynomial_ *next;
} Polynomial;

typedef Polynomial*    PPoly;

/* *****************************************************************************
 * New definition of new function protocols
 ******************************************************************************/
PPoly init_list(void);
STATE destroy_list(PPoly p_header);
STATE clear_list(PPoly p_header);
INT32 get_length_list(const PPoly p_header);
BOOL  is_empty_list(const PPoly p_header);
STATE get_item_by_index_list(const PPoly p_header, UINT32 index, TermType *p_term);
STATE get_index_by_item_list(const PPoly p_header, TermType term, UINT32 *p_index);
PPoly find_item_list(const PPoly p_header, TermType term);
STATE delete_item_header_list(PPoly p_header, TermType *p_del_item);
STATE delete_item_tail_list(PPoly p_header, TermType *p_del_item);
STATE delete_item_list(PPoly p_header, const PPoly p_node);
STATE delete_item_by_index_list(PPoly p_header, UINT32 index, TermType *p_del_item);
STATE insert_item_header_list(PPoly p_header, const TermType term);
STATE insert_item_tail_list(PPoly p_header, const TermType term);
STATE insert_item_list(PPoly p_header, const PPoly p_node);
STATE insert_item_by_index_list(PPoly p_header, UINT32 index, const TermType term);
PPoly find_last_list(const PPoly p_header);
STATE retrieve_list(const PPoly p_header, void (*callback)(const TermType term));
STATE sort_list(PPoly p_header, SortOrder order);
STATE merge_list(PPoly p_left, PPoly p_right, PPoly p_new_header);
STATE append_list(PPoly p_header, const TermType item);
STATE remove_list(PPoly p_header, TermType *item);

#endif /* _POLYNOMIAL_H_ */
