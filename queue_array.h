#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#include "common.h"

#define    QUEUE_ARRAY_INVALID_ITEM    (-1)

typedef INT32 QANodeType;
typedef void (*Callback)(void *argv);

typedef struct   _QANode {
    INT32       capacity;
    INT32       size;
    INT32       front;
    INT32       rear;
    QANodeType *data;
} QANode;

typedef QANode * PQANode;

PQANode    init_array_queue(INT32 max_size);
BOOL       destroy_array_queue(PQANode p_queue);
BOOL       clear_array_queue(PQANode p_queue);
BOOL       is_empty_array_queue(const PQANode p_queue);
BOOL       is_full_array_queue(const PQANode p_queue);
INT32      get_length_array_queue(const PQANode p_queue);
QANodeType get_head_array_queue(const PQANode p_queue);
BOOL       enqueue_array_queue(PQANode p_queue, void *argv);
BOOL       dequeue_array_queue(PQANode p_queue, void *argv);
BOOL       traverse_array_queue(const PQANode p_queue, Callback p_func);

#endif /* QUEUE_ARRAY_H_ */
