#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_array.h"

#define GET_DATA(queue, index)    \
    ((queue)->data[index])

#define GET_CURR(queue)           \
    ((queue)->front)

PQANode init_array_queue(INT32 max_size)
{
    PQANode p_queue = NULL;
    
    if ( max_size <= 0) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Max size of queue should be positive. "
                "File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (NULL);
    }

    p_queue = (PQANode)malloc(sizeof(QANode));
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Malloc space fail. "
                "File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);

        return (NULL);
#endif /* __DEBUG_PRINTF_ */        
    }

    p_queue->capacity = max_size;
    p_queue->size     = 0;
    p_queue->front    = p_queue->rear = 0;

    p_queue->data = (QANodeType *)malloc(sizeof(QANodeType) * p_queue->capacity);
    if ( !p_queue->data) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Malloc space fail. "
                "File: %s Line: %d Func: %s \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */
        free(p_queue);
        return (NULL);
    }

    return (p_queue);
}

BOOL destroy_array_queue(PQANode p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. "
                "File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);

#endif /* __DEBUG_PRINTF_ */
        return (FALSE);        
    }

    p_queue->capacity = 0;
    p_queue->size     = 0;
    p_queue->front    = p_queue->rear = 0;
    free(p_queue->data);
    free(p_queue);

    return (TRUE);
}

BOOL clear_array_queue(PQANode p_queue)
{
    INT32 i;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File :%s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    p_queue->size  = 0;
    p_queue->front = p_queue->rear = 0;

    memset(p_queue->data, 0, p_queue->capacity);

    return (TRUE);
}

BOOL is_empty_array_queue(const PQANode p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif _/* _DEBUG_PRINTF_ */

        return (QUEUE_ARRAY_INVALID_ITEM);        
    }
    
    return ((p_queue->size == 0) ? TRUE : FALSE);
}

BOOL is_full_array_queue(const PQANode p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif _/* _DEBUG_PRINTF_ */

        return (QUEUE_ARRAY_INVALID_ITEM);
    }
    
    return (((p_queue->size == p_queue->capacity) ||
             (p_queue->rear == (p_queue->capacity - 1))) ?
              TRUE :
              FALSE);
}

INT32 get_length_array_queue(const PQANode p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (QUEUE_ARRAY_INVALID_ITEM);
    }
    
    return (p_queue->size);
}

QANodeType get_head_array_queue(const PQANode p_queue)
{
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (QUEUE_ARRAY_INVALID_ITEM);
    }
    
    if ( TRUE == is_empty_array_queue(p_queue)) {
        return (QUEUE_ARRAY_INVALID_ITEM);
    }

    return (GET_DATA(p_queue, GET_CURR(p_queue)));
}

BOOL enqueue_array_queue(PQANode p_queue, void *p_argv)
{
    QANodeType *p_value = (QANodeType *)p_argv;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( !p_argv) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Input item pointer is NULL. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }
    
    if ( TRUE == is_full_array_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue is Full. File :%s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( (p_queue->rear + 1) == p_queue->capacity) {
        p_queue->rear = 0;
    }
    p_queue->data[p_queue->rear] = *p_value;
    p_queue->rear++;
    p_queue->size++;

    return (TRUE);
}

BOOL dequeue_array_queue(PQANode p_queue, void *p_argv)
{
    QANodeType *p_value = (QANodeType *)p_argv;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( !p_argv) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Output item pointer is NULL. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( TRUE == is_empty_array_queue(p_queue)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue is Empty. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    *p_value = GET_DATA(p_queue, p_queue->front);
    p_queue->front++;
    p_queue->size--;

    return (TRUE);
}

BOOL traverse_array_queue(const PQANode p_queue, Callback p_func)
{
    size_t i;
    
    if ( !p_queue) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Queue is not initialized. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( !p_func) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[ERROR] Callback function pointer is NULL. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( TRUE == is_empty_array_queue(p_queue)) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Queue is Empty. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    if ( p_queue->front > p_queue->rear) {
#ifdef __DEBUG_PRINTF_
        fprintf(stderr, "[INFO] Invalid pointer of front and rear for queue. File: %s Line: %d Func: %s. \n", GET_FILE, GET_LINE, GET_FUNC);
#endif /* __DEBUG_PRINTF_ */

        return (FALSE);
    }

    for (i = p_queue->front; i < p_queue->rear; ++i) {
        p_func(GET_DATA(p_queue, i));
    }

    return (TRUE);
}
