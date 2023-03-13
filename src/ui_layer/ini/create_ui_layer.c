/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** create_ui_layer
*/

#include "my.h"
#include "layer.h"
#include "ui_layer.h"
#include "my_string.h"
#include "my_number.h"

void create_ui_layer(layer_t *layer)
{
    layer->ui_layer.box_ui_layer.box = sfRectangleShape_create();
    sfRectangleShape_setSize(layer->ui_layer.box_ui_layer.box, (sfVector2f) {UI_LAYER_SIZE});
    sfRectangleShape_setOutlineThickness(layer->ui_layer.box_ui_layer.box, UI_LAYER_THICKNESS);
    sfRectangleShape_setOutlineColor(layer->ui_layer.box_ui_layer.box, sfBlack);
    sfRectangleShape_setFillColor(layer->ui_layer.box_ui_layer.box, sfWhite);
    ini_anchor_rect(layer->ui_layer.box_ui_layer.box, TOP_RIGHT);
    layer->ui_layer.box_ui_layer.pos = sfRectangleShape_getPosition(layer->ui_layer.box_ui_layer.box);

    layer->ui_layer.box_ui_layer.font = sfFont_createFromFile(UI_LAYER_FONT_PATH);
    layer->ui_layer.box_ui_layer.text = sfText_create();
    sfText_setFont(layer->ui_layer.box_ui_layer.text, layer->ui_layer.box_ui_layer.font);
    sfText_setCharacterSize(layer->ui_layer.box_ui_layer.text, UI_LAYER_TEXT_SIZE);
    sfText_setColor(layer->ui_layer.box_ui_layer.text, sfBlack);
    sfText_setPosition(layer->ui_layer.box_ui_layer.text, (sfVector2f) {
        layer->ui_layer.box_ui_layer.pos.x + 55,
        layer->ui_layer.box_ui_layer.pos.y + 10
    });
    sfText_setString(layer->ui_layer.box_ui_layer.text, layer->layer_name);

    layer->ui_layer.eye_ui_layer.box = sfRectangleShape_create();
    sfRectangleShape_setSize(layer->ui_layer.eye_ui_layer.box, (sfVector2f) {33, 33});
    sfRectangleShape_setOutlineThickness(layer->ui_layer.eye_ui_layer.box, UI_LAYER_THICKNESS);
    sfRectangleShape_setOutlineColor(layer->ui_layer.eye_ui_layer.box, sfBlack);
    sfRectangleShape_setFillColor(layer->ui_layer.eye_ui_layer.box, (sfColor) {150, 150, 150, 255});
    sfRectangleShape_setPosition(layer->ui_layer.eye_ui_layer.box, (sfVector2f) {
        layer->ui_layer.box_ui_layer.pos.x + 8,
        layer->ui_layer.box_ui_layer.pos.y + 10
    });

    layer->ui_layer.eye_ui_layer.texture = sfTexture_createFromFile(UI_LAYER_EYE_PATH, NULL);
    layer->ui_layer.eye_ui_layer.sprite = sfSprite_create();
    sfSprite_setTexture(layer->ui_layer.eye_ui_layer.sprite, layer->ui_layer.eye_ui_layer.texture, sfTrue);
    sfSprite_setColor(layer->ui_layer.eye_ui_layer.sprite, (sfColor) {255, 255, 255, 255});
    sfSprite_setPosition(layer->ui_layer.eye_ui_layer.sprite, (sfVector2f) {
        layer->ui_layer.box_ui_layer.pos.x + 9,
        layer->ui_layer.box_ui_layer.pos.y + 14
    });
}
