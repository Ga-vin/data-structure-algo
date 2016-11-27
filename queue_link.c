#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define __DEBUG_PRINTF_

#include "queue_link.h"

/* Name     : init_link_queue                      */
/* Function : To initialize queue with link format */
/* Input    : p_queue --> object to be initialized */
/* Output   : TRUE will be returned, when it is
              initialized, or else FALSE           */
BOOL init_link_queue(PLQueue p_queue)
{
#ifdef __DEBUG_QUEUE_    
    if ( p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue object has been initialized.  File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (TRUE);
    }
#endif __DEBUG_QUEUE_    

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

/* Name     : get_head_link_queue                  */
/* Function : Get the header of queue              */
/* Input    : queue --> Queue to be checked        */
/* Output   : Data of header for link queue        */
QNodeType get_head_link_queue(const PLQueue p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (-1);
    }

    if ( p_queue->front == p_queue->rear) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is empty. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (-1);
    } else {
        /* Return first node of queue except header of queue */
        return (p_queue->front->next->data);
    }
}

/* Name     : enqueue_link_queue                   */
/* Function : Insert item to  header of queue      */
/* Input    : queue --> Queue to be checked        */
/* Output   : TRUE will be returned when success   */
BOOL enqueue_link_queue(PLQueue p_queue,
                        void    *argv)
{
    PQLNode p_temp_node = NULL;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_temp_node = (PQLNode)malloc(sizeof(QLNode));
    if ( !p_temp_node) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Malloc fail. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_temp_node->data = *(QNodeType *)argv;
    p_temp_node->next = NULL;

    /* Insert new node into tail of queue, and move pointer of tail to last node */
    p_queue->rear->next = p_temp_node;
    p_queue->rear       = p_temp_node;
    
    return (TRUE);
}

/* Name     : dequeue_link_queue                   */
/* Function : Delete item from header of queue     */
/* Input    : queue --> Queue to be checked        */
/* Output   : TRUE will be returned when success   */
BOOL dequeue_link_queue(PLQueue p_queue,
                        void    *argv)
{
    PQLNode    p_temp_node = NULL;
    QNodeType *p_value     = (QNodeType *)argv;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( TRUE == is_empty_link_queue(*p_queue)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue is empty. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_temp_node = p_queue->front->next;
    *p_value    = p_temp_node->data;

    p_queue->front->next = p_temp_node->next;
    /* Make sure header be located before tail of queue */
    if ( p_temp_node == p_queue->rear) {
        p_queue->rear = p_queue->front;
    }
    free(p_temp_node);
    
    return (TRUE);
}

/* Name     : traverse_link_queue                  */
/* Function : Traverse each item of queue          */
/* Input    : queue --> Queue to be checked
              callback --> invoke function         */
/* Output   : TRUE will be returned when success   */
BOOL traverse_link_queue(const PLQueue p_queue,
                         PrintCallback callback)
{
    PQLNode p_temp = NULL;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initalized. File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_temp = p_queue->front->next;
    while ( p_temp != p_queue->rear) {
        callback((void *)&(p_temp->data));

        p_temp = p_temp->next;
    }
    callback((void *)&p_temp->data);
    fprintf(stdout, "\n");
    
    return (TRUE);
}
