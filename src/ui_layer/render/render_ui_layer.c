/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_ui_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void render_ui_layer(sfRenderWindow *window, sfEvent *event)
{
//    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp)
//        interaction_layer_move_up(event);
//    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown) {
//        interaction_layer_move_down(event);
//    }
    node_t *current = head_layer;
    sfVector2f current_pos = {UI_LAYER_OFFSET};

    do {
        sfRenderWindow_drawRectangleShape(window, GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box, NULL);
        sfRenderWindow_drawText(window, GET_DATA(current, layer_t)->ui_layer.box_ui_layer.text, NULL);
        sfRenderWindow_drawRectangleShape(window, GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.box, NULL);
        sfRenderWindow_drawSprite(window, GET_DATA(current, layer_t)->ui_layer.eye_ui_layer.sprite, NULL);

        set_pos_rect_with_anchor(GET_DATA(current, layer_t)->ui_layer.box_ui_layer.box, (sfVector2f) {UI_LAYER_OFFSET}, TOP_RIGHT);
        current = current->next;
    } while (current != head_layer);
}
