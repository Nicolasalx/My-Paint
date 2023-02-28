/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include <stdio.h>

#include "user_interface.h"
#include "color_selection.h"
#include "header.h"

sfVector2u window_size;

int gestion_header_file_menu(sfEvent event, sfRenderWindow *window, int *verif_open_file_menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= 61 && mouse_pos.x <= 137) && (mouse_pos.y >= 16 && mouse_pos.y <= 69)) {
            *verif_open_file_menu = true;
        }
    }
    if (*verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, file_menu_header[i].rectangle, NULL);
        }
    }
    if (*verif_open_file_menu == true) {
        if (event.type == sfEvtMouseButtonPressed) {
            if ((mouse_pos.x <= 60 || mouse_pos.x >= 210) || (mouse_pos.y <= 15 || mouse_pos.y >= 220)) {
                *verif_open_file_menu = false;
            }
        }
    }
    return *verif_open_file_menu;
}

void main_loop()
{
    sfRenderWindow *window;
    sfEvent event;
    int verif_open_file_menu = 0;
    window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    "my_paint", sfResize | sfClose, NULL);
    if (!window)
        return;
    sfRenderWindow_setFramerateLimit(window, 60);

    window_size = sfRenderWindow_getSize(window);
    create_all_data();

    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, &event);
        sfRenderWindow_clear(window, BG_COLOR);
        for (int i = 0; i < size_user_interface; ++i) {
            sfRenderWindow_drawSprite(window, ui_sprite[i].sprite, NULL);
        }
        for (int i = 0; i < size_selection_color; ++i) {
            sfRenderWindow_drawRectangleShape(window, selection_color[i].rectangle, NULL);
        }
        sfRenderWindow_drawSprite(window, chromatic_wheel.sprite, NULL);
        
        for (int i = 0; i < size_text_selection_color; ++i) {
            sfRenderWindow_drawText(window, text_color_selection[i].text, NULL);
        }

        for (int i = 0; i < size_button_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, button_header[i].rectangle, NULL);
        }
        for (int i = 0; i < size_text_button_header; ++i) {
            sfRenderWindow_drawText(window, text_button_header[i].text, NULL);
        }

        verif_open_file_menu = gestion_header_file_menu(event , window, &verif_open_file_menu);

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
