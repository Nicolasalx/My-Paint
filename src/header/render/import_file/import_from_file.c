/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** import_from_file
*/

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
        case 1: free(file_name); free_linked_list(&head);
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
