/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_pencil
*/

#include "my.h"
#include "my_graphical.h"
#include "layer.h"
#include "tool.h"
#include <stdlib.h>

void remove_all_node_after(node_t **head, node_t *node)
{
    node_t *current = node->next;
    node_t *next;
    node_t *removed_node;

    while (current != *head) {
        next = current->next;
        removed_node = remove_node(head, current);
        sfTexture_destroy(removed_node->data);
        free(removed_node);

        current = next;
    }
}

void save_change(void)
{
    if (GET_DATA(selected_layer, layer_t)->current_version !=
    GET_DATA(selected_layer, layer_t)->head_undo->prev) {
        remove_all_node_after(&GET_DATA(selected_layer, layer_t)->head_undo, GET_DATA(selected_layer, layer_t)->current_version);
    }
    append_node(&GET_DATA(selected_layer, layer_t)->head_undo,
    create_node(create_screen_shot(
    GET_DATA(selected_layer, layer_t)->texture_render_texture)));
    GET_DATA(selected_layer, layer_t)->current_version = GET_DATA(selected_layer, layer_t)->head_undo->prev;
}

void render_pencil(void)
{
    if (mouse_button_maintain == true) {
        sfVector2f circle_draw_pos = get_mouse_pos_on_sheet();
        circle_draw_pos.x -= pencil.radius;
        circle_draw_pos.y -= pencil.radius;

        sfCircleShape_setPosition(pencil.circle, circle_draw_pos);
        sfCircleShape_setRadius(pencil.circle, pencil.radius);
        sfCircleShape_setFillColor(pencil.circle, pencil.color);
        sfRenderTexture_drawCircleShape(GET_DATA(selected_layer, layer_t)->render_texture, pencil.circle, NULL);
        sfRenderTexture_display(GET_DATA(selected_layer, layer_t)->render_texture);
    } else if (mouse_button_released) {
        save_change();
    }
}
