#include "read_file.h"
#include <string.h>

read_file_t rf_open(char *path) {

    read_file_t new_struct;

    if((new_struct = malloc(sizeof(struct_read_file)))== NULL)
        return NULL;

    strcpy(new_struct->path, path);

    if((new_struct->file = fopen(new_struct->path, "r")) == NULL) {

        free(new_struct);
        return NULL;   
    }

    return new_struct;
}


void rf_close(read_file_t *selected) {

    fclose((*selected)->file);
    free(*selected);
    *selected = NULL;
}


bool rf_next_line(read_file_t selected, char *stream) {

    //strcpy(stream, "");
    
    char ch = ' ';
    int index = 0;

    while((ch = fgetc(selected->file)) != EOF) {

        if(ch == '\n') {

            stream[index] = '\0';
            return true;
        }

        stream[index] = ch;
        index++;
    }

    return false;
}