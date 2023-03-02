/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "my_error.h"
#include "user_interface.h"
#include "color_selection.h"
#include "header.h"
#include "data.h"
#include "toolbar.h"
#include "layer.h"
#include <stdbool.h>

sfVector2u window_size;
sfVector2f render_window_pos = {85, 140};
sfVector2f render_window_scale = {0.75, 0.75};

void gestion_header_file_menu(sfEvent event, sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    
    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= 61 && mouse_pos.x <= 137) && (mouse_pos.y >= 16 && mouse_pos.y <= 69)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, file_menu_header[i].rectangle, NULL);
        }
    }
    if (verif_open_file_menu == true) {
        if (event.type == sfEvtMouseButtonPressed) {
            if ((mouse_pos.x <= 60 || mouse_pos.x >= 210) || (mouse_pos.y <= 15 || mouse_pos.y >= 220)) {
                verif_open_file_menu = false;
            }
        }
    }
}

void main_loop(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "my_paint", sfResize | sfClose, NULL);
    if (window == 0) {
        print_fatal_error_and_exit(WINDOW_CREATION_FAIL);
    }
    sfRenderWindow_setFramerateLimit(window, FPS);
    window_size = sfRenderWindow_getSize(window);

    int index_button_color = 0;

    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, &event);
        sfRenderWindow_clear(window, BG_COLOR);

        // ! --- white sheet start
        render_layer(window, render_window_pos, render_window_scale);
        // ! --- white sheet end

        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
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

        for (int i = 0; i < size_icon_rectangle; ++i) {
            sfRenderWindow_drawRectangleShape(window, icon_rectangle[i].rectangle, NULL);
        }

        for (int i = 0; i < size_icon_sprite; ++i) {
            sfRenderWindow_drawSprite(window, icon_sprite[i].sprite, NULL);
        }

        if (event.type == sfEvtMouseButtonPressed) {
            for (int i = 0; i < size_icon_rectangle; ++i) {
                if (mouse_pos.x >= icon_rectangle[i].pos.x && mouse_pos.x <= icon_rectangle[i].pos.x + icon_rectangle[i].size.x) {
                    if (mouse_pos.y >= icon_rectangle[i].pos.y && mouse_pos.y <= icon_rectangle[i].pos.y + icon_rectangle[i].size.y) {
                        sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {0, 0, 0, 255});
                    }
                }
            }
        }

        if (event.type == sfEvtMouseButtonPressed) {
            for (int i = 0; i < size_selection_color; ++i) {
                if (mouse_pos.x >= selection_color[i].pos.x && mouse_pos.x <= selection_color[i].pos.x + selection_color[i].size.x) {
                    if (mouse_pos.y >= selection_color[i].pos.y && mouse_pos.y <= selection_color[i].pos.y + selection_color[i].size.y) {
                        sfRectangleShape_setOutlineThickness(selection_color[index_button_color].rectangle, SIZE_OUTLINE_BUTTON);
                        sfRectangleShape_setOutlineThickness(selection_color[i].rectangle, 5);
                        index_button_color = i;
                    }
                }
            }
        }


        gestion_header_file_menu(event , window, mouse_pos);

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
