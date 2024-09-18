#ifndef FUNC_RES_H
#define FUNC_RES_H

enum func_res
{
    SUCCESS        = 0,
    UNKNOWN_ERROR  = 1,
    FILE_NOT_FOUND = 2,
    FILE_READ_ER   = 3,
    NULL_PTR       = 4,
    EOF_FOUND      = 5
};

enum cmp_res
{
    FIRST_SMALLER  = -1,
    EQUAL          = 0,
    SECOND_SMALLER = 1
};

#endif
