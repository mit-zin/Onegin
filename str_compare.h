#ifndef STR_COMPARE_H
#define STR_COMPARE_H

enum cmp_res
{
    FIRST_SMALLER  = -1,
    EQUAL          = 0,
    SECOND_SMALLER = 1
};

enum cmp_res StrCompare    (char *str1, char *str2);
enum cmp_res BackStrCompare(char *str1, char *str2);

#endif
