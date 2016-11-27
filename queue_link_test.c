#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "queue_link.h"
#include "queue_link_test.h"
#include "common.h"

static LQueue _G_queue;

static void __print_call(void *arg)
{
    QNodeType *p_value = (QNodeType *)arg;

    fprintf(stdout, "0x%x ", *p_value);
}

static void __display_test_title(INT8 *p_msg)
{
    fprintf(stdout, "\n ****************************************\n");
    fprintf(stdout, "%s \n", p_msg);
    fprintf(stdout, " ****************************************\n");
}

void T_init_link_queue(void)
{
    BOOL ret = FALSE;

    __display_test_title("Init Link Queue Test");
    
    ret = init_link_queue(&_G_queue);
    if ( FALSE == ret) {
        fprintf(stderr, "Initialize queue [FAIL]. \n");
    } else {
        fprintf(stdout, "Initialize queue [OK]. \n");
    }
}

void T_destroy_link_queue(void)
{
    BOOL ret = FALSE;

    __display_test_title("Destroy Link Queue Test");
    
    ret = destroy_link_queue(&_G_queue);
    if ( FALSE == ret) {
        fprintf(stderr, "Destroy queue [FAIL]. \n");
    } else {
        fprintf(stdout, "Destroy queue [OK]. \n");
    }
}

void T_clear_link_queue(void)
{
    BOOL ret;

    __display_test_title("Clear Link Queue Test");
    
    ret = clear_link_queue(&_G_queue);
    if ( FALSE == ret) {
        fprintf(stderr, "Clear queue [FAIL]. \n");
    } else {
        if ( _G_queue.front != _G_queue.rear) {
            fprintf(stderr, "Clear queue [FAIL]. \n");
        } else {
            fprintf(stdout, "Clear queue [OK]. \n");
        }
    }
}

void T_is_empty_link_queue(void)
{
    __display_test_title("Is Empty Link Queue Test");
    
    if ( TRUE == is_empty_link_queue(_G_queue)) {
        fprintf(stderr, "Queue is empty. \n");
    } else {
        fprintf(stderr, "Queue is not empty. \n");
    }
}

void T_get_length_link_queue(void)
{
    fprintf(stdout, "There are total [%d] items in the queue. \n", get_length_link_queue(_G_queue));
}

void T_get_head_link_queue(void)
{
    QNodeType value_head    = 0;

    __display_test_title("Get Head Link Queue Test");
    
    value_head = (QNodeType *)get_head_link_queue(&_G_queue);
    if ( value_head < 0) {
        fprintf(stderr, "Get value from head [FAIL] \n");
    } else {
        fprintf(stdout, "Get value from head [OK]. Is 0x%x \n", value_head);
    }
}

void T_enqueue_link_queue(void)
{
#define   EN_QUEUE_NM  (10)    
    INT32 i;

    __display_test_title("Enqueue Link Queue Test");
    
    for (i = 2; i < EN_QUEUE_NM; ++i) {
        if ( FALSE == enqueue_link_queue(&_G_queue, (void *)&i)) {
            fprintf(stderr, "Enqueue value[%d] to queue [FAIL]. \n", i);
        } else {
            fprintf(stdout, "Enqueue value to queue [OK]. \n");
        }
    }
}

void T_dequeue_link_queue(void)
{
    QNodeType value;

    memset(&value, 0, sizeof(INT32));

    __display_test_title("Dequeue Link Queue Test");
    
    while ( TRUE != is_empty_link_queue(_G_queue)) {
        if ( FALSE == dequeue_link_queue(&_G_queue, (void *)&value)) {
                fprintf(stderr, "Dequeue from queue [FAIL]. \n");
            } else {
                fprintf(stdout, "Dequeue from queue [OK]. 0x%x. \n", value);
            }

        fprintf(stdout, "Total %d items in queue. \n", get_length_link_queue(_G_queue));
    }
}

void T_traverse_link_queue(void)
{
    __display_test_title("Traverse Link Queue Test");
    
    if ( TRUE == is_empty_link_queue(_G_queue)) {
        fprintf(stderr, "Queue is empty. \n");
        return ;
    } else {
        fprintf(stdout, "Begin. \n");
        if ( FALSE == traverse_link_queue(&_G_queue, __print_call)) {
            fprintf(stderr, "Traverse queue [FAIL]. \n");
        } else {
            fprintf(stdout, "Traverse queue [OK]. \n");
        }
    }
}

void T_link_queue_test(void)
{
    INT32     i;
    QNodeType value;
    
    T_init_link_queue();
    sleep(1);

    T_is_empty_link_queue();
    sleep(1);

    T_get_length_link_queue();
    sleep(1);

    T_get_head_link_queue();
    sleep(1);

    T_enqueue_link_queue();
    sleep(1);

    T_traverse_link_queue();

    T_get_length_link_queue();
    sleep(2);
    
    T_get_head_link_queue();
    sleep(1);

    T_dequeue_link_queue();
    sleep(2);

    for (i = 3; i < 8; ++i) {
        value = i;
        if ( FALSE == enqueue_link_queue(&_G_queue, (void *)&value)) {
            fprintf(stderr, "Enqueue fail at %d .", value);
        }
    }

    fprintf(stdout, "There are total %d items in queue. \n", get_length_link_queue(_G_queue));

    for (i = 0; i < 3; ++i) {
        if ( FALSE == dequeue_link_queue(&_G_queue, (void *)&value)) {
            fprintf(stderr, "Dequeue fail at %d. ", i);
        }
    }

    fprintf(stdout, "There are total %d items in queue. \n", get_length_link_queue(_G_queue));

    for (i = 0; i < 10; ++i) {
        value = i;
        if ( FALSE == enqueue_link_queue(&_G_queue, (void *)&value)) {
            fprintf(stderr, "Enqueue fail at %d .", value);
        }        
    }
    fprintf(stdout, "There are total %d items in queue. \n", get_length_link_queue(_G_queue));

    T_traverse_link_queue();
    
    T_destroy_link_queue();
    sleep(1);
}
