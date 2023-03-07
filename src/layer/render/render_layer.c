/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"

void render_layer(sfRenderWindow *window)
{
    node_t *current = head_layer;

    do {
        sfSprite_setTexture(GET_DATA(current, layer_t)->render_sprite,
            GET_DATA(current, layer_t)->texture_render_texture, sfFalse);

        sfSprite_setPosition(GET_DATA(current, layer_t)->render_sprite,
            render_sheet_pos);
        sfSprite_setScale(GET_DATA(current, layer_t)->render_sprite,
            render_sheet_scale);

        sfRenderWindow_drawSprite(window, GET_DATA(current, layer_t)->render_sprite,
        NULL);
        current = current->next;
    } while (current != head_layer);
}

void interaction_layer_move_up(sfEvent *event)
{
    if (box_icon_layer[size_box_icon_layer - 1].pos.y - 60 > 750) {
        for (int i = 0; i < size_box_icon_layer; ++i) {
            sfRectangleShape_setPosition(box_icon_layer[i].rectangle,
                (sfVector2f) {.x = box_icon_layer[i].pos.x,
                    .y = box_icon_layer[i].pos.y - 60});
            sfText_setPosition(text_icon_layer[i].text, (sfVector2f)
            {1670 , .y = text_icon_layer[i].pos.y - 60});
            sfSprite_setPosition(icon_eye_layer[i].sprite, (sfVector2f)
                {.x = 1619, .y = icon_eye_layer[i].pos.y - 60});
            sfRectangleShape_setPosition(button_eye_layer[i].rectangle,
                (sfVector2f) {.x = 1624, .y = button_eye_layer[i].pos.y - 60});
            text_icon_layer[i].pos.y -= 60;
            icon_eye_layer[i].pos.y -= 60;
            button_eye_layer[i].pos.y -= 60;
            box_icon_layer[i].pos.y -= 60;
        }
        event->type = sfEvtKeyReleased;
    }
}

void interaction_layer_move_down(sfEvent *event)
{
    if (box_icon_layer[size_box_icon_layer - 1].pos.y - 60 < 800) {
        for (int i = 0; i < size_box_icon_layer; ++i) {
            sfRectangleShape_setPosition(box_icon_layer[i].rectangle,
                (sfVector2f) {.x = box_icon_layer[i].pos.x,
                    .y = box_icon_layer[i].pos.y + 60});
            sfText_setPosition(text_icon_layer[i].text, (sfVector2f)
                {.x = 1670, .y = text_icon_layer[i].pos.y + 60});
            sfSprite_setPosition(icon_eye_layer[i].sprite, (sfVector2f)
                {.x = 1619, .y = icon_eye_layer[i].pos.y + 60});
            sfRectangleShape_setPosition(button_eye_layer[i].rectangle,
                (sfVector2f) {.x = 1624, .y = button_eye_layer[i].pos.y + 60});
            text_icon_layer[i].pos.y += 60;
            icon_eye_layer[i].pos.y += 60;
            button_eye_layer[i].pos.y += 60;
            box_icon_layer[i].pos.y += 60;
        }
        event->type = sfEvtKeyReleased;
    }
}

void layer_display(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp)
        interaction_layer_move_up(event);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown) {
        interaction_layer_move_down(event);
    }
    for (int i = 0; i < size_box_icon_layer; ++i) {
        sfRenderWindow_drawRectangleShape(window, box_icon_layer[i].rectangle,
            NULL);
    }
    for (int i = 0; i < size_text_icon_layer; ++i) {
        sfRenderWindow_drawText(window, text_icon_layer[i].text, NULL);
    }
    for (int i = 0; i < size_button_eye_layer; ++i) {
        sfRenderWindow_drawRectangleShape(window, button_eye_layer[i].rectangle,
            NULL);
    }
    for (int i = 0; i < size_icon_eye_layer; ++i) {
        sfRenderWindow_drawSprite(window, icon_eye_layer[i].sprite, NULL);
    }
}
