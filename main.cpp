#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ptr_compare.h"
#include "str_change.h"
#include "str_compare.h"
#include "sort.h"
#include "text_data.h"
#include "read_file.h"

int main(void)
{
    struct Text_data Onegin = {};

    enum func_res res = ReadFile(&Onegin, "onegin_f2.txt");

    FILE *output = fopen("sorted_onegin.txt", "wb");

    assert(output);


    fprintf(output, "SORT\n\n\n\n\n");

    Sort(Onegin.text, sizeof(char **), Onegin.n_strs, &StrCompare, &StrChange);

    for (size_t i = 0; i < Onegin.n_strs; i++)
        fputs(Onegin.text[i], output);


    fprintf(output, "\n\n\n\n\nBACK SORT\n\n\n\n\n");

    Sort(Onegin.text, sizeof(char **), Onegin.n_strs, &BackStrCompare, &StrChange);

    for (size_t i = 0; i< Onegin.n_strs; i++)
        fputs(Onegin.text[i], output);


    fprintf(output, "\n\n\n\n\nORIGINAL\n\n\n\n\n");

    Sort(Onegin.text, sizeof(char **), Onegin.n_strs, &PtrCompare, &StrChange);

    for (size_t i = 0; i< Onegin.n_strs; i++)
        fputs(Onegin.text[i], output);


    fclose(output);

    free(Onegin.buffer);
    Onegin.buffer = NULL;
    free(Onegin.text);
    Onegin.text = NULL;

    printf("%d\n", res);

    return 0;
}
