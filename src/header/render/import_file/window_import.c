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

char *new_path = '\0';
int new_size_path = 0;
int size_name_of_file = 0;
int size_already_name_malloc = 0;

int move_to_a_dir()
{
    return 0;
}

int open_a_file(sfRenderWindow *window, node_t *current)
{
    sfRenderWindow_close(window);
    size_name_of_file = my_strlen(sfText_getString(GET_DATA(current, file_name_t)->text));
    new_size_path = size_name_of_file + my_strlen(path_to_open_dir) + 1;
    new_path = malloc_str(new_size_path);
    const char* name_of_files = sfText_getString(GET_DATA(current, file_name_t)->text);
    char* copy_of_name = my_strdup(name_of_files);
    copy_of_name[my_strlen(copy_of_name) - 1] = '\0';
    my_strcpy(new_path, path_to_open_dir);
    my_strcat(new_path, copy_of_name);
    if (import_image(new_path) == false) {
        return 84;
    }
    free(new_path);
    free(copy_of_name);
    return 1;
}

int define_file_to_import(sfRenderWindow *window, sfEvent *event, node_t *current, node_t *head)
{
    do {
        sfRenderWindow_drawText(window, GET_DATA(current, file_name_t)->text, NULL);
        if (is_mouse_over_texte(GET_DATA(current, file_name_t)->text, window) == true && event->type == sfEvtMouseButtonPressed) {
            if (GET_DATA(current, file_name_t)->is_a_dir == true) {
                if (my_strcmp(sfText_getString(GET_DATA(current, file_name_t)->text), "[X]| BACK TO THE PREVIOUS DIRECTORY\n") == 0) {
                    char *new_path = malloc_str(my_strlen(path_to_open_dir) + 3);
                    my_strcpy(new_path, path_to_open_dir);
                    my_strcat(new_path, "../");
                    path_to_open_dir = new_path;
                } else {
                    if (my_strcmp(path_to_open_dir, "./") != 0) {
                        size_already_name_malloc = my_strlen(path_to_open_dir + 1);
                        char *new_path = malloc_str(size_already_name_malloc + my_strlen(sfText_getString(GET_DATA(current, file_name_t)->text)) + 1);
                        my_strcpy(new_path, path_to_open_dir);
                        my_strcat(new_path, sfText_getString(GET_DATA(current, file_name_t)->text));
                        my_strcat(new_path, "/");
                        path_to_open_dir = new_path;
                    } else {
                        path_to_open_dir = malloc_str(my_strlen(sfText_getString(GET_DATA(current, file_name_t)->text)) + 1);
                        my_strcpy(path_to_open_dir, sfText_getString(GET_DATA(current, file_name_t)->text));
                        my_strcat(path_to_open_dir, "/");
                    }
                }
                sfRenderWindow_close(window);
                can_free_dir = true;
                return 2;
            } else {
                return (open_a_file(window, current));
            }
        }
        current = current->next;
    } while (current != head);
    return 0;
}

int loop_file_import(sfRenderWindow *window, sfEvent *event, node_t *head)
{
    int value_return = 0;
    while (sfRenderWindow_isOpen(window)) {
        manage_event_file(window, event);
        sfRenderWindow_clear(window, (sfColor) BACKGROUND_COLOR_IMG_IMPORT);
        node_t *current = head;
        value_return = define_file_to_import(window, event, current, head);
        event_text_display(head, current);
        sfRenderWindow_display(window);
    }
    return value_return;
}

int create_window_from_file(node_t *head)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {640, 720, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "Import Image", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    new_path = '\0';
    new_size_path = 0;
    size_name_of_file = 0;
    size_already_name_malloc = 0;
    return (loop_file_import(window, &event, head));
    sfRenderWindow_destroy(window);
    return 0;
}
