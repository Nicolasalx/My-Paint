/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** set_render_window_icon
*/

#include "my_graphical.h"

void set_render_window_icon(sfRenderWindow* window, char *icon_path)
{
    sfImage* icon_image = sfImage_createFromFile(icon_path);
    sfVector2u icon_size = sfImage_getSize(icon_image);
    const sfUint8* pixels = sfImage_getPixelsPtr(icon_image);
    sfRenderWindow_setIcon(window, icon_size.x, icon_size.y, pixels);
    sfImage_destroy(icon_image);
}
