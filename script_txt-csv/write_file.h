#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct {

    char path[200];
    FILE *file;
} *write_file_t, struct_write_file;


write_file_t wf_open(char *path);


void wf_close(write_file_t *selected);


bool wf_next_line(write_file_t selected, char *stream);

#endif //WRITE_FILE_H