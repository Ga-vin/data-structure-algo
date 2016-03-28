#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "table_test.h"

int main(int argc, char *argv[])
{
    T_initializeTblLst();
    T_getSizeTblLst();
    T_getLengthTblLst();
    T_isEmptyTblLst();
    T_isFullTblLst();

    return 0;
}
