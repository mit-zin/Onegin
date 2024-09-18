#include <assert.h>
#include <stdio.h>

#include "sort.h"

void Sort(void *data, size_t type_size, size_t data_size, cmp_func_t cmp_func, chng_func_t chng_func)
{
    assert(data);

    for (size_t i = 0; i < data_size; i++)
    {
        for (size_t j = 0; j < data_size - i - 1; j++)
        {
            //printf("%d %d\n", i, j);
            if (cmp_func((data + j * type_size), (data + (j + 1) * type_size)) == SECOND_SMALLER)
                chng_func(data + j * type_size, data + (j + 1) * type_size);
                /*void *change = (data + j * type_size);
                (data + j * type_size) = (data + (j + 1) * type_size);
                (data + (j + 1) * type_size) = change;*/
        }
    }
}
