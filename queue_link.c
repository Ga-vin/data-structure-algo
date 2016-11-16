#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "queue_link.h"

BOOL init_link_queue(PLQueue p_queue)
{
    if ( p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue object has been initialized.  File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (TRUE);
    }

    p_queue->front = p_queue->rear = (PQLNode)malloc(sizeof(QLNode));
    if ( !p_queue->front) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Malloc fail. File: %s Line: %d Func: %s. ", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_queue->front->next = NULL;
    
    return (TRUE);
}

BOOL destroy_link_queue(PLQueue p_queue)
{

    return (TRUE);
}

BOOL clear_link_queue(PLQueue p_queue)
{


    return (TRUE);
}

BOOL is_empty_link_queue(const LQueue queue)
{


    return (TRUE);
}

INT32 get_length_link_queue(const LQueue queue)
{

    
}

void * get_head_link_queue(const PLQueue p_queue)
{
    
}

BOOL enqueue_link_queue(PLQueue p_queue,
                        void    *argv)
{

    return (TRUE);
}

BOOL dequeue_link_queue(PLQueue p_queue,
                        void    *argv)
{


    return (TRUE);
}

BOOL traverse_link_queue(const PLQueue p_queue,
                         PrintCallback callback)
{


    return (TRUE);
}
