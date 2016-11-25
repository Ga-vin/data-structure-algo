#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "queue_link.h"
#include "queue_link_test.h"
#include "common.h"

static LQueue _G_queue;

void T_init_link_queue(void)
{
    BOOL ret = FALSE;

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
    
}

void T_get_length_link_queue(void)
{
    
}

void T_get_head_link_queue(void)
{
    
}

void T_enqueue_link_queue(void)
{
    
}

void T_dequeue_link_queue(void)
{
    
}

void T_traverse_link_queue(void)
{
    
}
