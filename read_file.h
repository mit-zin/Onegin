#ifndef READ_FILE_H
#define READ_FILE_H

#include "func_res.h"
#include "text_data.h"

enum func_res ReadFile (struct Text_data *onegin, const char *filename);
void          SplitText(struct Text_data *onegin);

#endif
