#include <assert.h>
#include <stdio.h>

#include "sort.h"

void SortText(struct Text_data *onegin, cmp_func_t cmp_func)
{
    assert(onegin);

    for (size_t i = 0; i < onegin->n_strs; i++)
    {
        for (size_t j = 0; j < onegin->n_strs - i - 1; j++)
        {
            //printf("%d %d\n", i, j);
            if (cmp_func(onegin->text[j], onegin->text[j + 1]) == SECOND_SMALLER)
            {
                char *ptr_change = onegin->text[j];
                onegin->text[j] = onegin->text[j + 1];
                onegin->text[j + 1] = ptr_change;
            }
        }
    }
}
