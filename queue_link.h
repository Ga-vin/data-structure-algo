#ifndef QUEUE_LINK_H_
#define QUEUE_LINK_H_

#include "common.h"

typedef void (*PrintCallback)(void *argv);

typedef struct _QLNode {
    void          *data;
    struct QLNode *next;
} QLNode;

typedef QLNode *PQLNode;

typedef struct _TNode {
    PQLNode front;
    PQLNode rear;
} LQueue;
typedef LQueue *PLQueue;

BOOL   init_link_queue(PLQueue p_queue);
BOOL   destroy_link_queue(PLQueue p_queue);
BOOL   clear_link_queue(PLQueue p_queue);
BOOL   is_empty_link_queue(const LQueue queue);
INT32  get_length_link_queue(const LQueue queue);
void * get_head_link_queue(const PLQueue p_queue);
BOOL   enqueue_link_queue(PLQueue p_queue, void *argv);
BOOL   dequeue_link_queue(PLQueue p_queue, void *argv);
BOOL   traverse_link_queue(const PLQueue p_queue, PrintCallback callback);

#endif /* QUEUE_LINK_H_ */
