/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_ui_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void compute_pos_ui_layer(sfRenderWindow *window, sfEvent *event, float *pos_y)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp &&
        *pos_y > -146) {
        *pos_y -= 1;
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown &&
        *pos_y < -60 + (my_listlen(&head_layer) * SPACE_BETWEEN_UI_LAYER)) {
        *pos_y += 1;
    }
    set_pos_rect_with_anchor(background_ui_layer,
        (sfVector2f) {-30, 750}, TOP_RIGHT);
    sfRenderWindow_drawRectangleShape(window, background_ui_layer, NULL);
}

void compute_dependent_pos_ui_layer(node_t *current, sfVector2f current_pos)
{
    set_pos_rect_with_anchor(GET_DATA(
        current, layer_t)->ui_layer.box_ui_layer.box, current_pos, TOP_RIGHT);
    sfVector2f rect_pos = sfRectangleShape_getPosition(
        GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box);
    sfText_setPosition(GET_DATA(current, layer_t)->ui_layer.box_ui_layer.text,
        (sfVector2f) {rect_pos.x - 210, rect_pos.y + 10});
    sfRectangleShape_setPosition(
        GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.box,
        (sfVector2f) {rect_pos.x - 260, rect_pos.y + 10});
    sfSprite_setPosition(
        GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.sprite,
        (sfVector2f) {rect_pos.x - 259, rect_pos.y + 14});
}

void render_layer_box_ui_layer(sfRenderWindow *window, node_t *current)
{
    if (current == selected_layer) {
        sfRectangleShape_setFillColor(
        GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box,
        (sfColor) {SELECTED_LAYER_COLOR});
    } else {
        sfRectangleShape_setFillColor(
        GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box, sfWhite);
    }

    sfRenderWindow_drawRectangleShape(window,
        GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box, NULL);
    sfRenderWindow_drawText(window,
        GET_DATA(current, layer_t)->ui_layer.box_ui_layer.text, NULL);
    sfRenderWindow_drawRectangleShape(window,
        GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.box, NULL);
    if (GET_DATA(current, layer_t)->hidden == false) {
        sfRenderWindow_drawSprite(window,
        GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.sprite, NULL);
    }
}

void render_ui_layer(sfRenderWindow *window, sfEvent *event)
{
    static float pos_y = 0;
    node_t *current = head_layer;
    sfVector2f current_pos = {-40, pos_y + 905};
    compute_pos_ui_layer(window, event, &pos_y);
    do {
        compute_dependent_pos_ui_layer(current, current_pos);
        if (mouse_button_pressed && is_mouse_over_rectangle_shape(
                GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.box) &&
            is_mouse_over_rectangle_shape(background_ui_layer)) {
            GET_DATA(current, layer_t)->hidden =
                !GET_DATA(current, layer_t)->hidden;
        } else if (mouse_button_pressed && is_mouse_over_rectangle_shape(
                GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box) &&
            is_mouse_over_rectangle_shape(background_ui_layer)) {
            selected_layer = current;
        }
        render_layer_box_ui_layer(window, current);
        current_pos.y -= SPACE_BETWEEN_UI_LAYER;
        current = current->next;
    } while (current != head_layer);
}
