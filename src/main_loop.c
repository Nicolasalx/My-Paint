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
#include "toolbar.h"
#include <stdbool.h>
#include <stdio.h>
#include "my_graphical.h"

sfVector2u window_size;

void gestion_header_file_menu(sfEvent event, sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= button_header[0].pos.x && mouse_pos.x <= button_header[0].pos.x + button_header[0].size.x) {
            if (mouse_pos.y >= button_header[0].pos.y && mouse_pos.y <= button_header[0].pos.y + button_header[0].size.y) {
                verif_open_file_menu = true;
            }
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, file_menu_header[i].rectangle, NULL);
        }
        for (int i = 0; i < size_text_file_header; ++i) {
            sfRenderWindow_drawText(window, text_file_header[i].text, NULL);
        }
    }
    if (verif_open_file_menu == true) {
        if (event.type == sfEvtMouseButtonPressed) {
            if (mouse_pos.x <= button_header[0].pos.x || mouse_pos.x >= edit_menu_header[0].pos.x + edit_menu_header[0].size.x || mouse_pos.y <= button_header[0].pos.y || mouse_pos.y >= edit_menu_header[0].pos.y + edit_menu_header[0].size.y) {
                    verif_open_file_menu = false;
            }
        }
    }
}

void gestion_header_edit_menu(sfEvent event, sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= button_header[1].pos.x && mouse_pos.x <= button_header[1].pos.x + button_header[1].size.x) {
            if (mouse_pos.y >= button_header[1].pos.y && mouse_pos.y <= button_header[1].pos.y + button_header[1].size.y) {
                verif_open_file_menu = true;
            }
        }
    }
    if (verif_open_file_menu == true) {

        for (int i = 0; i < size_edit_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, edit_menu_header[i].rectangle, NULL);
            for (int i = 0; i < size_text_edit_header; ++i) {
            sfRenderWindow_drawText(window, text_edit_header[i].text, NULL);
        }
        }
    }
    if (verif_open_file_menu == true) {
        if (event.type == sfEvtMouseButtonPressed) {
            if (mouse_pos.x <= button_header[1].pos.x || mouse_pos.x >= edit_menu_header[0].pos.x + edit_menu_header[0].size.x || mouse_pos.y <= button_header[1].pos.y || mouse_pos.y >= edit_menu_header[0].pos.y + edit_menu_header[0].size.y) {
                    verif_open_file_menu = false;
            }
        }
    }
}

void gestion_header_view_menu(sfEvent event, sfRenderWindow *window, sfVector2i mouse_pos)
{
    static bool verif_open_file_menu = false;
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= button_header[2].pos.x && mouse_pos.x <= button_header[2].pos.x + button_header[2].size.x) {
            if (mouse_pos.y >= button_header[2].pos.y && mouse_pos.y <= button_header[2].pos.y + button_header[2].size.y) {
                verif_open_file_menu = true;
            }
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_view_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, view_menu_header[i].rectangle, NULL);
            for (int i = 0; i < size_text_view_header; ++i) {
                sfRenderWindow_drawText(window, text_view_header[i].text, NULL);
            }
        }
    }
    if (verif_open_file_menu == true) {
        if (event.type == sfEvtMouseButtonPressed) {
            if (mouse_pos.x <= button_header[2].pos.x || mouse_pos.x >= edit_menu_header[0].pos.x + edit_menu_header[0].size.x || mouse_pos.y <= button_header[2].pos.y || mouse_pos.y >= edit_menu_header[0].pos.y + edit_menu_header[0].size.y) {
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
    int index_icon_color = 0;
    int stay_on_icon = 0;
    bool verif = false;
    bool is_button_pressed = false;

    int index_view_icon = 0;

    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, &event);
        sfRenderWindow_clear(window, BG_COLOR);
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

        // ! Icon Toolbar
        if (event.type == sfEvtMouseButtonPressed) {
            for (int i = 0; i < size_icon_rectangle; ++i) {
                if (icon_rectangle[i].can_draw == true) {
                    if (mouse_pos.x >= icon_rectangle[i].pos.x && mouse_pos.x <= icon_rectangle[i].pos.x + icon_rectangle[i].size.x) {
                        if (mouse_pos.y >= icon_rectangle[i].pos.y && mouse_pos.y <= icon_rectangle[i].pos.y + icon_rectangle[i].size.y) {
                            sfRectangleShape_setFillColor(icon_rectangle[index_icon_color].rectangle, BG_COLOR);
                            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {51, 51, 255, 255});
                            index_icon_color = i;
                            verif = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < size_icon_rectangle; ++i) {
            if (icon_rectangle[i].can_draw == true) {
                if (i != index_view_icon) {
                    if (verif == true) {
                        sfRectangleShape_setFillColor(icon_rectangle[index_icon_color].rectangle, BG_COLOR);
                        sfRectangleShape_setFillColor(icon_rectangle[index_icon_color].rectangle, (sfColor) {51, 51, 255, 255});
                    }
                    if (mouse_pos.x >= icon_rectangle[i].pos.x && mouse_pos.x <= icon_rectangle[i].pos.x + icon_rectangle[i].size.x) {
                        if (mouse_pos.y >= icon_rectangle[i].pos.y && mouse_pos.y <= icon_rectangle[i].pos.y + icon_rectangle[i].size.y) {
                            sfRectangleShape_setFillColor(icon_rectangle[stay_on_icon].rectangle, BG_COLOR);
                            sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, (sfColor) {51, 153, 255, 255});
                            stay_on_icon = i;
                        }
                    } else {
                        sfRectangleShape_setFillColor(icon_rectangle[i].rectangle, BG_COLOR);
                    }
                }
            }
        }


        if (event.type == sfEvtMouseButtonPressed) {
            is_button_pressed = true;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            is_button_pressed = false;
        }
        
        gestion_header_file_menu(event , window, mouse_pos);
        gestion_header_edit_menu(event, window, mouse_pos);
        gestion_header_view_menu(event, window, mouse_pos);
        if (is_button_pressed == true || (is_button_pressed == true && event.type == sfEvtMouseMoved)) {
            if (mouse_pos.x >= icon_rectangle[size_icon_rectangle].pos.x && mouse_pos.x <= icon_rectangle[size_icon_rectangle].pos.x + icon_rectangle[size_icon_rectangle].size.x) {
                if (mouse_pos.y <= icon_rectangle[size_icon_rectangle].pos.y && mouse_pos.y >= icon_rectangle[size_icon_rectangle].pos.y - icon_rectangle[size_icon_rectangle - 1].size.y) {
                    int size_difference = size_pen.pos.y - mouse_pos.y;
                    sfRectangleShape_setSize(size_pen.rectangle, (sfVector2f) {40, -size_difference});
                }
            }
        }
        sfRenderWindow_drawRectangleShape(window, size_pen.rectangle, NULL);

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
