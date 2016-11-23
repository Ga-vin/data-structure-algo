#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "queue_link.h"

/* Name     : init_link_queue                      */
/* Function : To initialize queue with link format */
/* Input    : p_queue --> object to be initialized */
/* Output   : TRUE will be returned, when it is
              initialized, or else FALSE           */
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
        fprintf(stderr, "[ERROR] Malloc fail. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_queue->front->next = NULL;
    
    return (TRUE);
}

/* Name     : destroy_link_queue                   */
/* Function : Destroy queue                        */
/* Input    : p_queue --> Queue to be destroied    */
/* Output   : TRUE will be returned, when it is
              initialized, or else FALSE           */
BOOL destroy_link_queue(PLQueue p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. ", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    while ( p_queue->front) {
        p_queue->rear = p_queue->front->next;
        free(p_queue->front);
        p_queue->front = p_queue->rear;
    }
    
    return (TRUE);
}

/* Name     : clear_link_queue                     */
/* Function : Clear queue                          */
/* Input    : p_queue --> Queue to be cleared      */
/* Output   : TRUE will be returned, when it is
              initialized, or else FALSE           */
BOOL clear_link_queue(PLQueue p_queue)
{
    PQLNode p_left  = NULL;
    PQLNode p_right = NULL;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    /* 保留队首队尾指针，并且两个指针指向同一处 */
    p_queue->rear        = p_queue->front;
    p_left               = p_queue->front->next;
    p_queue->front->next = NULL;
    while ( p_left) {
        p_right = p_left;
        p_left  = p_left->next;
        free(p_right);
    }

    return (TRUE);
}

/* Name     : is_empty_link_queue                  */
/* Function : Check whether queue is empty         */
/* Input    : queue --> Queue to be checked        */
/* Output   : TRUE will be returned, when it is
              empty, or else FALSE                 */
BOOL is_empty_link_queue(const LQueue queue)
{
    if ( (queue.front == queue.rear) && !(queue.front->next)) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

/* Name     : get_length_link_queue                */
/* Function : Get the length of queue              */
/* Input    : queue --> Queue to be checked        */
/* Output   : Length of queue                      */
INT32 get_length_link_queue(const LQueue queue)
{
    INT32   cnt    = 0;
    PQLNode p_temp = NULL;

    p_temp = queue.front;
    while ( p_temp != queue.rear) {
        cnt++;
        p_temp = p_temp->next;
    }

    return (cnt);
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
