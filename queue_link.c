#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "queue_link.h"

BOOL init_link_queue(PLQueue *pp_queue)
{

    return (TRUE);
}

BOOL destroy_link_queue(PLQueue *pp_queue)
{

    return (TRUE);
}

BOOL clear_link_queue(PLQueue *pp_queue)
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

BOOL enqueue_link_queue(PLQueue *pp_queue,
                        void    *argv)
{

    return (TRUE);
}

BOOL dequeue_link_queue(PLQueue *pp_queue,
                        void    *argv)
{


    return (TRUE);
}

BOOL traverse_link_queue(const PLQueue p_queue,
                         PrintCallback callback)
{


    return (TRUE);
}
