#ifndef    __EX_COMMON_H_
#define    __EX_COMMON_H_

#include <stdio.h>

typedef    unsigned int    UINT32;
typedef    unsigned short  UINT16;
typedef    unsigned char   UINT8;
typedef    int             INT32;
typedef    short           INT16;
typedef    char            INT8;
typedef    UINT32          STATE;
typedef    UINT32          ElemType;
typedef    INT32           BOOL;

#ifndef    TRUE
#define    TRUE        (1)
#endif /* TRUE */

#ifndef    FALSE
#define    FALSE       (0)
#endif /* FALSE */

#ifndef    OK
#define    OK          (1)
#endif /* OK */

#ifndef    ERROR
#define    ERROR       (0)
#endif /* ERROR */

#ifndef    OVERFLOW
#define    OVERFLOW    (-1)
#endif /* OVERFLOW */

#ifndef    EMPTY
#define    EMPTY       (-2)
#endif /* EMPTY */

#define    GET_FILE    (__FILE__)
#define    GET_LINE    (__LINE__)

#define    LIST_NULL   (NULL)
#define    LIST_EMPTY  (0)

typedef enum _SortOrder_ {
    ASCENDING  = 1,
    DESCENDING = 2,
} SortOrder;

void debugError(const char *str, const char *p_file_name, INT32 line);

#endif /* __EX_COMMON_H_ */
