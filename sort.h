#ifndef SORT_H
#define SORT_H

#include "str_compare.h"
#include "text_data.h"

typedef enum cmp_res (*cmp_func_t)(char *str1, char *str2);

void SortText(struct Text_data *onegin, cmp_func_t cmp_func);

#endif
