#include <assert.h>
#include <stdio.h>

#include "str_change.h"

void StrChange(void *ptr_str1, void *ptr_str2)
{
    assert(ptr_str1);
    assert(ptr_str2);

    char *change = *(char **)ptr_str1;
    *(char **)ptr_str1 = *(char **)ptr_str2;
    *(char **)ptr_str2 = change;
}
