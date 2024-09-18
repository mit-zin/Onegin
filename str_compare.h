#ifndef STR_COMPARE_H
#define STR_COMPARE_H

enum cmp_res
{
    FIRST_SMALLER  = -1,
    EQUAL          = 0,
    SECOND_SMALLER = 1
};

enum cmp_res StrCompare    (void *ptr_str1, void *ptr_str2);
enum cmp_res BackStrCompare(void *ptr_str1, void *ptr_str2);

#endif
