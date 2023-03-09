#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "header.h"
#include "my_linkedlist.h"

#define INCREMATION_SIZE 30
#define SIZE_EXTENSION 2
#define POSITION_TEXT {0, 0}
#define BACKGROUND_COLOR_IMG_IMPORT {170, 170, 170, 255}

static sfVector2f pos_text = {0, 0};

file_name_t *create_text(char *str, sfFont *font, bool is_a_dir)
{
    file_name_t *file_name = malloc(sizeof(file_name_t));
    file_name->text = sfText_create();
    sfText_setString(file_name->text, str);
    sfText_setFont(file_name->text, font);
    sfText_setCharacterSize(file_name->text, 20);
    pos_text.y += INCREMATION_SIZE;
    file_name->pos_text = (sfVector2f) {.x = 10, .y = pos_text.y += INCREMATION_SIZE};
    sfText_setPosition(file_name->text, file_name->pos_text);
    if (is_a_dir == true) {
        sfText_setColor(file_name->text, sfBlue);
    } else {
        sfText_setColor(file_name->text, sfGreen);
    }
    return file_name;
}

void manage_event_file(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
            pos_text.y = 0;
        }
    }
}

void create_window_all_file(node_t *head)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {640, 720, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "Import Image", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    while (sfRenderWindow_isOpen(window)) {
        manage_event_file(window, &event);
        sfRenderWindow_clear(window, (sfColor) BACKGROUND_COLOR_IMG_IMPORT);
        node_t *current = head;
        do {
            sfRenderWindow_drawText(window, GET_DATA(current, file_name_t)->text, NULL);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
                sfText_setPosition(GET_DATA(current, file_name_t)->text, (sfVector2f) {.x = file_name->pos_text.x, .y = file_name->pos_text.y -= 1});
                file_name->pos_text.y -= 1;
            }
            current = current->next;
        } while (current != head);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return;
}

void directory_append_text(struct stat st, const char *path_of_file, sfFont *font, node_t *head)
{
    if (S_ISDIR(st.st_mode)) {
        char *is_a_dir = malloc_str(my_strlen(path_of_file) + 15);
        my_strcpy(is_a_dir, "[");
        my_strcat(is_a_dir, path_of_file);
        my_strcat(is_a_dir, "]| IS_A_DIR\n");
        append_node(&head, create_node(create_text(is_a_dir, font, true)));
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
                total_size += strlen(words[i]);
            }
            char *name_of_file = malloc_str(total_size);
            name_of_file[0] = '\0';
            for (int i = 0; i < nb_word - 1; ++i) {
                my_strcat(name_of_file, words[i]);
            }
            for (int i = 0; i < SIZE_EXTENSION; ++i) {
                if (my_strcmp(all_extension[i], words[nb_word - 1]) == 0) {
                    char *is_a_file = malloc_str(my_strlen(name_of_file) + my_strlen(words[nb_word - 1]) + 7);
                    my_strcpy(is_a_file, "[");
                    my_strcat(is_a_file, name_of_file);
                    my_strcat(is_a_file, "]|[");
                    my_strcat(is_a_file, words[nb_word - 1]);
                    my_strcat(is_a_file, "]\n");
                    append_node(&head, create_node(create_text(is_a_file, font, false)));
                }
            }
            free(name_of_file);
        }
    }
}

void detect_type_of_files(struct stat st, const char *filename, sfFont *font, char **all_extension, node_t *head)
{
    if (filename[0] != '.') {
        char path[100] = "./";
        strcpy(path + strlen(path), filename);
        stat(path, &st);
        directory_append_text(st, filename, font, head);
        file_append_text(st, filename, font, head, all_extension);
    }
}

void import_from_files(void)
{
    DIR *dir;
    struct dirent *file;
    struct stat st;
    node_t *head = NULL;
    sfVector2f pos_text = {10, 10};
    sfFont* font;
    font = sfFont_createFromFile("game_data/font/JetBrainsMono-Regular.ttf");
    char previous_dir[] = "[X]| BACK TO THE PREVIOUS DIRECTORY\n";
    append_node(&head, create_node(create_text(previous_dir, font, true)));
    pos_text.y += INCREMATION_SIZE;
    char *all_extension[] = {"png", "jpg"};
    dir = opendir("./");
    file = readdir(dir);
    while (file != NULL) {
        detect_type_of_files(st, file->d_name, font, all_extension, head);
        file = readdir(dir);
    }
    create_window_all_file(head);
    closedir(dir);
}
