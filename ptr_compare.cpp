#include <assert.h>

#include "ptr_compare.h"

enum cmp_res PtrCompare(void *ptr1, void *ptr2)
{
    assert(ptr1);
    assert(ptr2);

    if (*(char **)ptr1 > *(char **)ptr2)
        return SECOND_SMALLER;
    else if (*(char **)ptr1 < *(char **)ptr2)
        return FIRST_SMALLER;
    else
        return EQUAL;
}
