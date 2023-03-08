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
sfVector2u render_sheet_res = {1920, 1080};
sfVector2f render_sheet_pos = {85, 140};
sfVector2f render_sheet_scale = {0.75, 0.75};
sfVector2i mouse_pos = {0, 0};

void main_loop(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "my_paint", sfResize | sfClose, NULL);
    if (window == FAIL) {
        print_fatal_error_and_exit(WINDOW_CREATION_FAIL);
    }
    set_render_window_icon(window, "game_data/user_interface/logo.png");
    sfView *window_view = sfView_createFromRect((sfFloatRect) {0, 0, window_size.x, window_size.y});
    sfRenderWindow_setFramerateLimit(window, FPS);
    int index_button_color = 0; //! <- doit disparaitre
    bool is_button_pressed = false; //! <- doit disparaitre
    int stay_on_icon_header = 0; //! <- doit disparaitre
    while (sfRenderWindow_isOpen(window)) {
        update_window_data(window, window_view);
        manage_event(window, &event, &is_button_pressed, window_view);
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
