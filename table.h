#ifndef    __EX_TABLE_H_
#define    __EX_TABLE_H_

#include "common.h"

/* ********************* Constances Macros ********************* */
#define    TBL_MAX_SIZE    (100)

/* ******************** New Type Definition ******************** */
typedef    struct _TABLE_NODE_ {
    ElemType    t_data[TBL_MAX_SIZE];
    UINT32      t_length;
    UINT32      t_size;
} TableNode;

typedef    TableNode *    PTableNode;



#endif /* __EX_TABLE_H_ */
