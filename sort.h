#ifndef SORT_H
#define SORT_H

#include "func_res.h"
#include "ptr_compare.h"
#include "str_change.h"
#include "str_compare.h"
#include "text_data.h"

typedef enum cmp_res (*cmp_func_t)(void *var1, void *var2);
typedef void         (*chng_func_t)(void *var1, void *var2);

void Sort(void *data, size_t type_size, size_t data_size, cmp_func_t cmp_func, chng_func_t chng_func);

#endif
