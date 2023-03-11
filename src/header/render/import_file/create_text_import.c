#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "header.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"

void directory_append_text(struct stat st, const char *path_of_file, sfFont *font, node_t *head)
{
    if (S_ISDIR(st.st_mode)) {
        char *is_a_dir = malloc_str(my_strlen(path_of_file));
        my_strcpy(is_a_dir, path_of_file);
        append_node(&head, create_node(create_text(is_a_dir, font, true)));
        free(is_a_dir);
    }
}

void file_append_text(struct stat st, const char *path_of_file, sfFont *font, node_t *head, char **all_extension)
{
    if (S_ISREG(st.st_mode)) {
        int nb_word = count_nb_word(path_of_file, ".");
        int *size_word = count_size_word(path_of_file, ".", nb_word);
        char **words = my_str_to_word(path_of_file, ".", nb_word, size_word);
        if (nb_word > 1) {
            int total_size = 1;
            for (int i = 0; i < nb_word - 1; ++i) {
                total_size += my_strlen(words[i]);
            }
            char *name_of_file = malloc_str(total_size);
            name_of_file[0] = '\0';
            for (int i = 0; i < nb_word - 1; ++i) {
                my_strcat(name_of_file, words[i]);
            }
            for (int i = 0; i < SIZE_EXTENSION; ++i) {
                if (my_strcmp(all_extension[i], words[nb_word - 1]) == 0) {
                    char *is_a_file = malloc_str(my_strlen(name_of_file) + my_strlen(words[nb_word - 1]) + 2);
                    my_strcpy(is_a_file, name_of_file);
                    my_strcat(is_a_file, ".");
                    my_strcat(is_a_file, words[nb_word - 1]);
                    my_strcat(is_a_file, "\n");
                    append_node(&head, create_node(create_text(is_a_file, font, false)));
                    free(is_a_file);
                }
            }
            free(name_of_file);
        }
    }
}

void detect_type_of_files(struct stat st, const char *filename, sfFont *font, char **all_extension, node_t *head)
{
    if (filename[0] != '.') {
        char path[100];
        my_strcpy(path, path_to_open_dir);
        strcpy(path + my_strlen(path), filename);
        stat(path, &st);
        directory_append_text(st, filename, font, head);
        file_append_text(st, filename, font, head, all_extension);
    }
}