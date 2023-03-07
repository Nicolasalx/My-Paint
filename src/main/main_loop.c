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
#include "layer.h"
#include <stdbool.h>
#include <stdio.h>
#include "my_graphical.h"
#include "ui_layer.h"
#include <SFML/Graphics.h>
#include "tool.h"

sfVector2i window_pos = {0, 0};
sfVector2u window_size = {1920, 1080};
sfVector2f render_sheet_resolution = {1920, 1080};
sfVector2f render_sheet_pos = {85, 140};
sfVector2f render_sheet_scale = {0.75, 0.75};
sfVector2i mouse_pos = {0, 0};

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
    bool is_button_pressed = false;
    int stay_on_icon_header = 0;
    while (sfRenderWindow_isOpen(window)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        window_pos = sfRenderWindow_getPosition(window);
        window_size = sfRenderWindow_getSize(window);
        manage_event(window, &event, &is_button_pressed);
        sfRenderWindow_clear(window, (sfColor) BG_COLOR);

        render_layer(window);
        render_all_tool();
        layer_display(window, &event);
        
        display_ui(window);

        display_color_selection_icon(window, event, &index_button_color);
        management_button_header(window, is_button_pressed, &stay_on_icon_header);
        display_toolbar(window, event, is_button_pressed);
        render_overview(window);
        display_undo_redo(window);
        
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
