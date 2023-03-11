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

file_name_t *create_text(char *str, bool is_a_dir)
{
    file_name_t *file_name = malloc(sizeof(file_name_t));
    file_name->text = sfText_create();
    sfText_setString(file_name->text, str);
    sfText_setFont(file_name->text, FONT);
    sfText_setCharacterSize(file_name->text, 20);
    file_name->pos_text.y = pos_text.y + INCREMATION_SIZE;
    file_name->pos_text.x = 10;
    pos_text.y += INCREMATION_SIZE;
    sfText_setPosition(file_name->text, file_name->pos_text);
    file_name->is_a_dir = is_a_dir;
    if (is_a_dir == true) {
        sfText_setColor(file_name->text, sfBlue);
    } else {
        sfText_setColor(file_name->text, sfGreen);
    }
    return file_name;
}

void move_text_import_file(node_t *head, node_t *current, int move)
{
    do {
        file_name_t *file_name = GET_DATA(current, file_name_t);
        if (file_name != NULL) {
            file_name->pos_text.y += move;
            sfText_setPosition(file_name->text, (sfVector2f)
                {.x = file_name->pos_text.x, .y = file_name->pos_text.y});
        }
    current = current->next;
    } while (current != head);
}

void event_text_display(node_t *head, node_t *current)
{
    if (is_key_up_pressed_and_released() == true) {
        move_text_import_file(head, current, -MOVE_TEXT_SCREEN);
    } else if (is_key_down_pressed_and_released() == true) {
        move_text_import_file(head, current, +MOVE_TEXT_SCREEN);
    } else {
        return;
    }
}

bool is_mouse_over_texte(sfText* text, sfRenderWindow* window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect text_bounds = sfText_getGlobalBounds(text);
    return sfFloatRect_contains(&text_bounds, mouse_pos.x, mouse_pos.y);
}

void open_new_directory(struct stat st, char **all_extension, node_t *head)
{
    DIR *dir; struct dirent *file; pos_text.y = 0;
    char previous_dir[] = "[X]| BACK TO THE PREVIOUS DIRECTORY\n";
    append_node(&head, create_node(create_text(previous_dir, true)));
    pos_text.y += INCREMATION_SIZE; dir = opendir(path_to_open_dir);
    file = readdir(dir);
    while (file != NULL) {
        detect_type_of_files(st, file->d_name, all_extension, head);
        file = readdir(dir);
    }
    switch (create_window_from_file(head)) {
        case 1:
            free(file_name); free_linked_list(&head);
            free(path_to_open_dir); path_to_open_dir = malloc_str(2);
            path_to_open_dir = "./"; return;
        break;
        case 2:
            free(file_name); free_linked_list(&head);
            open_new_directory(st, all_extension, head); break;
        case 84: return; break;
        default: break;
    } closedir(dir);
}

void import_from_files(void)
{
    struct stat st;
    node_t *head = NULL;
    if (my_strlen(path_to_open_dir) == 0) {
        path_to_open_dir = malloc_str(2);
        my_strcpy(path_to_open_dir, "./");
    }
    char *all_extension[] = {"png", "jpg", "bmp"};
    open_new_directory(st, all_extension, head);
}
