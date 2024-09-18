#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "str_compare.h"
#include "sort.h"
#include "text_data.h"
#include "read_file.h"

/*const size_t N_STRINGS = 14;
const size_t STR_LEN = 50;*/

//int StrCompare(char *str1, char *str2, size_t max_len);
//void StrChange(char *str1, char *str2, size_t length);
//void SortText(char text[][STR_LEN]);

int main(void)
{
    struct Text_data Onegin = {};

    enum func_res res = ReadFile(&Onegin, "onegin_f2.txt");

    /*printf("%s\n", Onegin.buffer);
    printf("%c\n", Onegin.buffer[0]);
    printf("%d\n", Onegin.buffer[Onegin.buflen - 3]);
    printf("%s\n", Onegin.text[0]);*/

    //FILE *input = fopen("onegin.txt", "r");
    FILE *output = fopen("sorted_onegin.txt", "wb");
    //assert(input);
    assert(output);

    /*fseek(input, 0L, SEEK_END);
    printf("%Ld\n", ftell(input));
    fseek(input, 0L, SEEK_SET);*/

    /*char text[N_STRINGS][STR_LEN] = {};

    for (size_t i = 0; i < N_STRINGS; i++)
    {
        fgets(text[i], STR_LEN, input);
    }*/

    SortText(&Onegin, &StrCompare);
    //printf("%c\n", text[0][0]);

    //StrChange(text[0], text[1], STR_LEN);
    //StrChange(text[1], text[2], STR_LEN);

    for (size_t i = 0; i < Onegin.n_strs; i++)
    {
        //printf("%c%c\n", text[i][0], text[i][1]);
        fputs(Onegin.text[i], output);
    }

    fprintf(output, "\n\n\n\n\nBACK SORT\n\n\n\n\n");

    SortText(&Onegin, &BackStrCompare);

    for (size_t i = 0; i< Onegin.n_strs; i++)
        fputs(Onegin.text[i], output);

    //printf("%d\n", StrCompare(text[0], text[1], STR_LEN));

    //fclose(input);
    fclose(output);

    free(Onegin.buffer);
    Onegin.buffer = NULL;
    free(Onegin.text);
    Onegin.text = NULL;

    printf("%d\n", res);

    return 0;
}
