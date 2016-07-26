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

void errorHandler(const char *file,
                  const char *func,
                  INT32 line,
                  const char *date,
                  const char *time)
{
    fprintf(stdout, "\n[Error] in file %s of func %s at line %d in %s-%s \n",
            file,
            func,
            line,
            date,
            time);
}
