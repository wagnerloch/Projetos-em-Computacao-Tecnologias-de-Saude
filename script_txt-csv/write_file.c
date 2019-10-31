#include "write_file.h"
#include <string.h>

write_file_t wf_open(char *path) {

    write_file_t new_struct;

    if((new_struct = malloc(sizeof(struct_write_file)))== NULL)
        return NULL;

    strcpy(new_struct->path, path);

    if((new_struct->file = fopen(new_struct->path, "w")) == NULL) {

        free(new_struct);
        return NULL;   
    }

    return new_struct;
}


void wf_close(write_file_t *selected) {

    fclose((*selected)->file);
    free(*selected);
    *selected = NULL;
}


bool wf_next_line(write_file_t selected, char *stream) {

    fprintf(selected->file, "%s\n", stream);

    return true;
}