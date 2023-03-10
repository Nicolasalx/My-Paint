/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** manage_event
*/

#include "my.h"
#include "toolbar.h"
#include "my_graphical.h"

void manage_window_resize(sfRenderWindow *window, sfView *window_view)
{
    static bool was_resize = false;
    if (is_window_resized() == true || was_resize == true) {
        if (was_resize == false) {
            was_resize = true;
        } else {
            was_resize = false;
        }
        sfView_reset(window_view,
            (sfFloatRect) {0, 0, window_size.x, window_size.y});
        sfRenderWindow_setView(window, window_view);
        sfFloatRect sheet_bound = {render_sheet_pos.x, render_sheet_pos.y,
            render_sheet_res.x, render_sheet_res.y};
        sheet_bound = compute_rect_pos_and_scale(
            sfRectangleShape_getGlobalBounds(edition_zone),
            sheet_bound, DEFAULT_IMAGE_PADDING);
        render_sheet_pos.x = sheet_bound.left;
        render_sheet_pos.y = sheet_bound.top;
        render_sheet_scale.x = sheet_bound.width / render_sheet_res.x;
        render_sheet_scale.y = sheet_bound.height / render_sheet_res.y;
    }
}

void manage_event(sfRenderWindow *window, sfEvent *event, sfView *window_view)
{
    mouse_button_maintain = sfMouse_isButtonPressed(sfMouseLeft);
    mouse_button_pressed = false;
    mouse_button_released = false;
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event->type == sfEvtMouseButtonPressed) {
            mouse_button_pressed = true;
        }
        if (event->type == sfEvtMouseButtonReleased) {
            mouse_button_released = true;
        }
    }
    manage_window_resize(window, window_view);
}
