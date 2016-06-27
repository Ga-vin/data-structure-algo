#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void debugError(const char *str,
                       const char *p_file_name,
                       INT32 line)
{
    fprintf(stdout, "[X] <Error> : %s in %s-%d.\n", str,
            p_file_name,
            line);
}
