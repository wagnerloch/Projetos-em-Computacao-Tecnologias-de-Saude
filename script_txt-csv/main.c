#include <stdio.h>
#include <string.h>
#include "read_file.h"
#include "write_file.h"


void separar_palavras(char *stream_ent, char *stream_1, char *stream_2);


int main(int argc, char* argv[]) {

    read_file_t txt_file = rf_open(argv[1]);
    write_file_t csv_file = wf_open(argv[2]);
    char stream[300];
    char new_stream[300];
    char stream_1[300];
    char stream_2[300];
    int number_sentence = 1;
    bool insert_sentence = true;
    int number_line = 1;

    //Inserindo cabeçalho
    wf_next_line(csv_file, "Sentence #,Word,Tag");

    while(rf_next_line(txt_file, stream)) {

        printf("Linha atual: %d\n", number_line);
        number_line++;

        if(strcmp(stream, "") != 0) {

            separar_palavras(stream, stream_1, stream_2);

            //Coloca no arquivo
            if(insert_sentence) {

                fprintf(csv_file->file, "Sentence:%d,%s,%s\n", number_sentence, stream_1, stream_2);
                number_sentence++;
                insert_sentence = false;

                printf("Sentence: %d,%s,%s\n", number_sentence, stream_1, stream_2);
            } else {

                fprintf(csv_file->file, ",%s,%s\n", stream_1, stream_2);

                printf(",%s,%s\n", stream_1, stream_2);
            }
        } else {

           insert_sentence = true;
           printf("\n");
        }
    }
    
    rf_close(&txt_file);
    wf_close(&csv_file);

    return 0;
}

void separar_palavras(char *stream_ent, char *stream_1, char *stream_2) {

    int i = 0;
    int j = 0;
    bool especial_1 = false;
    bool especial_2 = false;
    char teste;

    strcpy(stream_1, "");
    strcpy(stream_2, "");

    while(1) {

        if(stream_ent[i] == ' ') {

            stream_1[j] = '\0';
            i++;
            break;
        }

        teste = stream_ent[i];

        if(teste == '.' || teste == ',')
            especial_1 = true;

        stream_1[j] = stream_ent[i];

        i++;
        j++;     
    }

    j = 0;

    while(1) {

        if(stream_ent[i] == '\n' || stream_ent[i] == '\0') {

            stream_2[j] = '\0';
            break;
        }

        teste = stream_ent[i];

        if(teste == '.' || teste == ',')
            especial_2 = true;

        stream_2[j] = stream_ent[i];

        i++;
        j++;     
    }

    if(especial_1) {

        char auxiliar[300] = "\"";
        strcat(stream_1, auxiliar);
        strcat(auxiliar, stream_1);
        strcpy(stream_1, auxiliar);
    }

    if(especial_2) {

        char auxiliar[300] = "\"";
        strcat(stream_2, auxiliar);
        strcat(auxiliar, stream_2);
        strcpy(stream_2, auxiliar);
    }
}