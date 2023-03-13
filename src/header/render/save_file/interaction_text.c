/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** interaction_text
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"
#include <SFML/Graphics.h>
#include "save_image.h"
#include "icon_to_draw.h"
#include "tool.h"
#include "save_file.h"

void get_input_text_user(sfEvent *event, char *inputText, sfText *text)
{
    if (my_strlen(inputText) < 30 - 1) {
        char c = event->text.unicode;
        if (c >= 32 && c <= 126) {
            inputText[my_strlen(inputText)] = c;
        }
    }
    sfText_setString(text, inputText);
}

void event_input_text_save_file(sfEvent *event, char *inputText, sfText *text)
{
    if (event->type == sfEvtTextEntered) {
        if (event->type == sfEvtTextEntered) {
            get_input_text_user(event, inputText, text);
        }
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyBackspace) {
        size_t len = my_strlen(inputText);
        if (len > 0) {
            inputText[len - 1] = '\0';
            sfText_setString(text, inputText);
        }
    }
}

void manage_event_save_file(sfRenderWindow *window, sfEvent *event,
    char *inputText, sfText *text)
{
    mouse_button_pressed_save_file = false;
    mouse_button_released_save_file = false;
    if (event->type == sfEvtMouseButtonPressed) {
        mouse_button_pressed_save_file = true;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        mouse_button_released_save_file = true;
    }
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        event_input_text_save_file(event, inputText, text);
    }
}

sfBool is_mouse_over_rectangle_shape_save_file(sfRectangleShape*
    rectangle_shape, sfVector2i mouse_position_save)
{
    sfFloatRect rectangle_bound =
    sfRectangleShape_getGlobalBounds(rectangle_shape);
    return sfFloatRect_contains(&rectangle_bound, mouse_position_save.x,
        mouse_position_save.y);
}

void set_color_to_button_save(int i, int *index_can_draw)
{
    if (selection_extension_button[i].can_click == true) {
        if (can_press == true) {
            sfRectangleShape_setFillColor(selection_extension_button
                [* index_can_draw].rectangle,
                    selection_extension_button[i].color);
        }
        sfRectangleShape_setFillColor(selection_extension_button[i].rectangle,
            (sfColor) {0, 73, 153, 255});
        can_press = true;
        * index_can_draw = i;
    }
}
