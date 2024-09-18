#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "str_compare.h"

enum cmp_res StrCompare(char *str1, char *str2)
{
    assert(str1);
    assert(str2);

    size_t index1 = 0, index2 = 0;

    bool flag1 = false, flag2 = false;

    while (str1[index1] != '\0' && str2[index2] != '\0')
    {
        while (!isalpha(str1[index1]) && str1[index1] != '\0')
            index1++;
        if (str1[index1] == '\0' && !flag1)
            return SECOND_SMALLER;
        flag1 = true;

        while (!isalpha(str2[index2]) && str2[index2] != '\0')
            index2++;
        if (str2[index2] == '\0' && !flag2)
            return FIRST_SMALLER;
        flag2 = true;

        int dif = tolower(str1[index1]) - tolower(str2[index2]);
        if (dif < 0)
            return FIRST_SMALLER;
        else if (dif > 0)
            return SECOND_SMALLER;
        else
        {
            if (str1[index1] == '\0')
                return EQUAL;
            else
            {
                index1++;
                index2++;
                continue;
            }
        }
    }

    return EQUAL;
}

enum cmp_res BackStrCompare(char *str1, char *str2)
{
    assert(str1);
    assert(str2);

    size_t index1 = 0, index2 = 0;

    while (str1[index1] != '\0')
        index1++;
    index1--;

    while (str2[index2] != '\0')
        index2++;
    index2--;

    bool flag1 = false, flag2 = false;

    while (index1 > 0 && index2 > 0)
    {
        while (index1 > 0 && !isalpha(str1[index1]))
            index1--;
        if (!index1 && !flag1)
            return SECOND_SMALLER;
        flag1 = true;

        while (index2 > 0 && !isalpha(str2[index2]))
            index2--;
        if (!index2 && !flag2)
            return FIRST_SMALLER;
        flag2 = true;

        int dif = tolower(str1[index1]) - tolower(str2[index2]);
        if (dif < 0)
            return FIRST_SMALLER;
        else if (dif > 0)
            return SECOND_SMALLER;
        else
        {
            index1--;
            index2--;
            continue;
        }
    }

    return EQUAL;
}
