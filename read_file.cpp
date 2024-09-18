#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "read_file.h"

enum func_res ReadFile(struct Text_data *onegin, const char *filename)
{
    assert(onegin);
    assert(filename);

    FILE *input = fopen(filename, "rb");
    assert(input);

    struct stat stbuf = {};
    stat(filename, &stbuf);

    onegin->buflen = stbuf.st_size + 1;

    onegin->buffer = (char *) calloc(onegin->buflen, sizeof(char));
    if (!(onegin->buffer))
    {
        fclose(input);
        return NULL_PTR;
    }

    unsigned int nsymb_read = fread(onegin->buffer, sizeof(char), onegin->buflen, input);

    //printf("%d, %d\n", nsymb_read, onegin->buflen);

    if (feof(input) && nsymb_read < onegin->buflen - 1)
    {
        fclose(input);
        return EOF_FOUND;
    }

    onegin->buffer[onegin->buflen - 1] = '\0';

    SplitText(onegin);

    fclose(input);

    return SUCCESS;
}

void SplitText(struct Text_data *onegin)
{
    assert(onegin);

    for (size_t i = 0; i < onegin->buflen; i++)
    {
        if (onegin->buffer[i] == '\r')
            onegin->n_strs++;
    }

    onegin->text = (char **) calloc(onegin->n_strs + 1, sizeof(char *));

    int str_i = 0;
    onegin->text[str_i] = onegin->buffer;
    str_i++;

    for (size_t i = 1; i < onegin->buflen; i++)
    {
        if (onegin->buffer[i - 1] == '\r')
            onegin->buffer[i - 1] == '\0';

        if (onegin->buffer[i - 1] == '\n')
        {
            onegin->buffer[i - 1] = '\0';
            onegin->text[str_i] = onegin->text[0] + i;
            str_i++;
        }
    }

    /*printf("%u\n", onegin->n_strs);
    for (size_t i = 0; i < onegin->n_strs + 1; i++)
    {
        printf("%d\n", onegin->text[i]);
    }*/

    onegin->text[onegin->n_strs] = NULL;
}
