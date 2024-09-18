#ifndef TEXT_DATA_H
#define TEXT_DATA_H

struct Text_data
{
    char *buffer;
    size_t buflen;
    char **text;
    size_t n_strs;
};

#endif
