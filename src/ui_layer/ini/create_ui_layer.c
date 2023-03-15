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

void create_background_ui_layer(void)
{
    background_ui_layer = sfRectangleShape_create();
    sfRectangleShape_setSize(background_ui_layer, (sfVector2f) {290, 215});
    sfRectangleShape_setFillColor(background_ui_layer, (sfColor) BG_COLOR);
    ini_anchor_rect(background_ui_layer, TOP_RIGHT);
}

void create_button_ui_layer(void)
{
    for (int i = 0; i < size_button_ui_layer; ++i) {
        button_ui_layer[i].box = sfRectangleShape_create();
        sfRectangleShape_setSize(button_ui_layer[i].box,
            button_ui_layer[i].size);
        sfRectangleShape_setOutlineThickness(button_ui_layer[i].box, 2);
        sfRectangleShape_setOutlineColor(button_ui_layer[i].box, sfBlack);
        sfRectangleShape_setFillColor(button_ui_layer[i].box,
            (sfColor) {150, 150, 150, 255});
        ini_anchor_rect(button_ui_layer[i].box, button_ui_layer[i].anchor);

        button_ui_layer[i].sprite = sfSprite_create();
        button_ui_layer[i].texture = sfTexture_createFromFile(
            button_ui_layer[i].path, NULL);
        sfSprite_setTexture(button_ui_layer[i].sprite,
            button_ui_layer[i].texture, sfTrue);
        sfSprite_setScale(button_ui_layer[i].sprite, button_ui_layer[i].scale);
        ini_anchor_sprite(button_ui_layer[i].sprite, TOP_RIGHT);
    }
}

void create_icon_ui_layer(layer_t *layer)
{
    layer->ui_layer.eye_ui_layer.box = sfRectangleShape_create();
    sfRectangleShape_setSize(layer->ui_layer.eye_ui_layer.box,
        (sfVector2f) {33, 33});
    sfRectangleShape_setOutlineThickness(layer->ui_layer.eye_ui_layer.box,
        UI_LAYER_THICKNESS);
    sfRectangleShape_setOutlineColor(layer->ui_layer.eye_ui_layer.box,
        sfBlack);
    sfRectangleShape_setFillColor(layer->ui_layer.eye_ui_layer.box,
        (sfColor) {150, 150, 150, 255});

    layer->ui_layer.eye_ui_layer.texture =
        sfTexture_createFromFile(UI_LAYER_EYE_PATH, NULL);
    layer->ui_layer.eye_ui_layer.sprite = sfSprite_create();
    sfSprite_setTexture(layer->ui_layer.eye_ui_layer.sprite,
        layer->ui_layer.eye_ui_layer.texture, sfTrue);
    sfSprite_setColor(layer->ui_layer.eye_ui_layer.sprite,
        (sfColor) {255, 255, 255, 255});
}

void create_ui_layer(layer_t *layer)
{
    layer->ui_layer.box_ui_layer.box = sfRectangleShape_create();
    sfRectangleShape_setSize(layer->ui_layer.box_ui_layer.box,
        (sfVector2f) {UI_LAYER_SIZE});
    sfRectangleShape_setOutlineThickness(layer->ui_layer.box_ui_layer.box,
        UI_LAYER_THICKNESS);
    sfRectangleShape_setOutlineColor(layer->ui_layer.box_ui_layer.box,
        sfBlack);
    sfRectangleShape_setFillColor(layer->ui_layer.box_ui_layer.box, sfWhite);
    ini_anchor_rect(layer->ui_layer.box_ui_layer.box, TOP_RIGHT);
    layer->ui_layer.box_ui_layer.font =
        sfFont_createFromFile(UI_LAYER_FONT_PATH);
    layer->ui_layer.box_ui_layer.text = sfText_create();
    sfText_setFont(layer->ui_layer.box_ui_layer.text,
        layer->ui_layer.box_ui_layer.font);
    sfText_setCharacterSize(layer->ui_layer.box_ui_layer.text,
        UI_LAYER_TEXT_SIZE);
    sfText_setColor(layer->ui_layer.box_ui_layer.text, sfBlack);
    sfText_setString(layer->ui_layer.box_ui_layer.text, layer->layer_name);
    create_icon_ui_layer(layer);
}
