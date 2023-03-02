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
#include <stdio.h>
#include "my_graphical.h"
#include "ui_layer.h"
#include <SFML/Graphics.h>
#include "tool.h"

sfVector2u window_size = {1920, 1080};
sfVector2f render_window_pos = {85, 140};
sfVector2f render_window_scale = {0.75, 0.75};
sfVector2i mouse_pos = {0, 0};

void gestion_header_file_menu(sfRenderWindow *window, sfVector2i mouse_pos, bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[0].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, file_menu_header[i].rectangle, NULL);
            for (int i = 0; i < size_text_file_header; ++i) {
                sfRenderWindow_drawText(window, text_file_header[i].text, NULL);
            }
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_file_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(file_menu_header[i].rectangle, mouse_pos) == true)
                ++verif_close_menu;
            if (is_mouse_over_rectangle_shape(button_header[0].rectangle, mouse_pos) == true) {
                ++verif_close_menu;
            }
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

void gestion_header_edit_menu(sfRenderWindow *window, sfVector2i mouse_pos, bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[1].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
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
        for (int i = 0; i < size_edit_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(edit_menu_header[i].rectangle, mouse_pos) == true)
                ++verif_close_menu;
            if (is_mouse_over_rectangle_shape(button_header[1].rectangle, mouse_pos) == true) {
                ++verif_close_menu;
            }
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

void gestion_header_view_menu(sfRenderWindow *window, sfVector2i mouse_pos, bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[2].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
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
        for (int i = 0; i < size_view_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(view_menu_header[i].rectangle, mouse_pos) == true)
                ++verif_close_menu;
            if (is_mouse_over_rectangle_shape(button_header[2].rectangle, mouse_pos) == true) {
                ++verif_close_menu;
            }
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

void gestion_header_layer_menu(sfRenderWindow *window, sfVector2i mouse_pos, bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[3].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_layer_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, layer_menu_header[i].rectangle, NULL);
            for (int i = 0; i < size_text_layer_header; ++i) {
                sfRenderWindow_drawText(window, text_layer_header[i].text, NULL);
            }
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_layer_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(layer_menu_header[i].rectangle, mouse_pos) == true)
                ++verif_close_menu;
            if (is_mouse_over_rectangle_shape(button_header[3].rectangle, mouse_pos) == true) {
                ++verif_close_menu;
            }
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

void gestion_header_help_menu(sfRenderWindow *window, sfVector2i mouse_pos, bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[4].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_help_menu_header; ++i) {
            sfRenderWindow_drawRectangleShape(window, help_menu_header[i].rectangle, NULL);
            for (int i = 0; i < size_text_help_header; ++i) {
                sfRenderWindow_drawText(window, text_help_header[i].text, NULL);
            }
        }
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_help_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(help_menu_header[i].rectangle, mouse_pos) == true)
                ++verif_close_menu;
            if (is_mouse_over_rectangle_shape(button_header[4].rectangle, mouse_pos) == true) {
                ++verif_close_menu;
            }
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}

void gestion_header_menu(sfVector2i mouse_pos, bool is_button_pressed, int *stay_on_icon_header)
{
    int verif_mouse_in_box = 0;
    static int pressed_min_one_time = 0;
    for (int i = 0; i < size_button_header; ++i) {
        if (is_mouse_over_rectangle_shape(button_header[i].rectangle, mouse_pos) == true && is_button_pressed == true) {
            sfRectangleShape_setFillColor(button_header[* stay_on_icon_header].rectangle, BG_COLOR);
            sfRectangleShape_setFillColor(button_header[i].rectangle, sfBlue);
            * stay_on_icon_header = i;
            ++ pressed_min_one_time;
        }
    }

    if (pressed_min_one_time > 0) {
        for (int i = 0; i < size_button_header; ++i) {
            if (is_mouse_over_rectangle_shape(button_header[i].rectangle, mouse_pos) == false && is_button_pressed == true) {
                ++ verif_mouse_in_box;
            }
        }
    }

    if (pressed_min_one_time > 0 && verif_mouse_in_box == size_button_header) {
        for (int i = 0; i < size_button_header; ++i) {
            sfRectangleShape_setFillColor(button_header[i].rectangle, BG_COLOR);
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

    int index_button_color = 0;
    int index_icon_color = 0;
    int stay_on_icon = 0;
    bool verif = false;
    bool is_button_pressed = false;

    int stay_on_icon_header = 0;

    int index_view_icon = 0;
    while (sfRenderWindow_isOpen(window)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        manage_event(window, &event);
        sfRenderWindow_clear(window, BG_COLOR);

        // ! layer
        render_layer(window, render_window_pos, render_window_scale);

        // ! tool
        render_pencil();

        if (event.type == sfEvtMouseButtonPressed) {
            is_button_pressed = true;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            is_button_pressed = false;
        }

        // ! LAYER MOVE

        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            if (box_icon_layer[size_box_icon_layer - 1].pos.y - 60 > 750) { // ? Mod valeur en dur
                for (int i = 0; i < size_box_icon_layer; ++i) {
                    sfRectangleShape_setPosition(box_icon_layer[i].rectangle, (sfVector2f) {.x = box_icon_layer[i].pos.x, .y = box_icon_layer[i].pos.y - 60});
                    sfText_setPosition(text_icon_layer[i].text, (sfVector2f) {1670 , .y = text_icon_layer[i].pos.y - 60});
                    sfSprite_setPosition(icon_eye_layer[i].sprite, (sfVector2f) {.x = 1619, .y = icon_eye_layer[i].pos.y - 60});
                    sfRectangleShape_setPosition(button_eye_layer[i].rectangle, (sfVector2f) {.x = 1624, .y = button_eye_layer[i].pos.y - 60});
                    text_icon_layer[i].pos.y -= 60;
                    icon_eye_layer[i].pos.y -= 60;
                    button_eye_layer[i].pos.y -= 60;
                    box_icon_layer[i].pos.y -= 60;
                }
                event.type = sfEvtKeyReleased;
            }
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
            if (box_icon_layer[size_box_icon_layer - 1].pos.y - 60 < 800) { // ? Mod valeur en dur
                for (int i = 0; i < size_box_icon_layer; ++i) {
                    sfRectangleShape_setPosition(box_icon_layer[i].rectangle, (sfVector2f) {.x = box_icon_layer[i].pos.x, .y = box_icon_layer[i].pos.y + 60});
                    sfText_setPosition(text_icon_layer[i].text, (sfVector2f) {.x = 1670, .y = text_icon_layer[i].pos.y + 60});
                    sfSprite_setPosition(icon_eye_layer[i].sprite, (sfVector2f) {.x = 1619, .y = icon_eye_layer[i].pos.y + 60});
                    sfRectangleShape_setPosition(button_eye_layer[i].rectangle, (sfVector2f) {.x = 1624, .y = button_eye_layer[i].pos.y + 60});
                    text_icon_layer[i].pos.y += 60;
                    icon_eye_layer[i].pos.y += 60;
                    button_eye_layer[i].pos.y += 60;
                    box_icon_layer[i].pos.y += 60;
                }
                event.type = sfEvtKeyReleased;
            }
        }

        // ! LAYER (Draw dans le bon ordre)
        for (int i = 0; i < size_box_icon_layer; ++i) {
            sfRenderWindow_drawRectangleShape(window, box_icon_layer[i].rectangle, NULL);
        }

        for (int i = 0; i < size_text_icon_layer; ++i) {
            sfRenderWindow_drawText(window, text_icon_layer[i].text, NULL);
        }

        for (int i = 0; i < size_button_eye_layer; ++i) {
            sfRenderWindow_drawRectangleShape(window, button_eye_layer[i].rectangle, NULL);
        }

        for (int i = 0; i < size_icon_eye_layer; ++i) {
            sfRenderWindow_drawSprite(window, icon_eye_layer[i].sprite, NULL);
        }

        // ! FIN LAYER


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

        // ! HEADER
        gestion_header_menu(mouse_pos, is_button_pressed, &stay_on_icon_header);

        // ! FILE HEADER
        for (int i = 0; i < size_file_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(file_menu_header[i].rectangle, mouse_pos) == true) {
                sfRectangleShape_setFillColor(file_menu_header[i].rectangle, (sfColor) {102, 255, 102, 255});
            } else {
                sfRectangleShape_setFillColor(file_menu_header[i].rectangle, sfWhite);
            }
        }
        gestion_header_file_menu(window, mouse_pos, is_button_pressed);

        // ! EDIT HEADER
        for (int i = 0; i < size_edit_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(edit_menu_header[i].rectangle, mouse_pos) == true) {
                sfRectangleShape_setFillColor(edit_menu_header[i].rectangle, (sfColor) {102, 255, 102, 255});
            } else {
                sfRectangleShape_setFillColor(edit_menu_header[i].rectangle, sfWhite);
            }
        }
        gestion_header_edit_menu(window, mouse_pos, is_button_pressed);

        // ! VIEW HEADER
        for (int i = 0; i < size_view_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(view_menu_header[i].rectangle, mouse_pos) == true) {
                sfRectangleShape_setFillColor(view_menu_header[i].rectangle, (sfColor) {102, 255, 102, 255});
            } else {
                sfRectangleShape_setFillColor(view_menu_header[i].rectangle, sfWhite);
            }
        }
        gestion_header_view_menu(window, mouse_pos, is_button_pressed);

        // ! LAYER HEADER
        for (int i = 0; i < size_layer_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(layer_menu_header[i].rectangle, mouse_pos) == true) {
                sfRectangleShape_setFillColor(layer_menu_header[i].rectangle, (sfColor) {102, 255, 102, 255});
            } else {
                sfRectangleShape_setFillColor(layer_menu_header[i].rectangle, sfWhite);
            }
        }
        gestion_header_layer_menu(window, mouse_pos, is_button_pressed);

        // ! HELP HEADER
        for (int i = 0; i < size_help_menu_header; ++i) {
            if (is_mouse_over_rectangle_shape(help_menu_header[i].rectangle, mouse_pos) == true) {
                sfRectangleShape_setFillColor(help_menu_header[i].rectangle, (sfColor) {102, 255, 102, 255});
            } else {
                sfRectangleShape_setFillColor(help_menu_header[i].rectangle, sfWhite);
            }
        }
        gestion_header_help_menu(window, mouse_pos, is_button_pressed);

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
