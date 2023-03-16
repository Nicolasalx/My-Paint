/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_window_from_file
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
