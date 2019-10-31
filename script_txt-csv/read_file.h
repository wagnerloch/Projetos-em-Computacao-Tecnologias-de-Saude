#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct {

    char path[200];
    FILE *file;
} *read_file_t, struct_read_file;


read_file_t rf_open(char *path);


void rf_close(read_file_t *selected);


bool rf_next_line(read_file_t selected, char *stream);

#endif //READ_FILE_H