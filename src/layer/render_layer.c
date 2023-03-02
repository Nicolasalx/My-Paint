/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** render_layer
*/

#include "my.h"
#include "layer.h"

void render_layer(sfRenderWindow *window, sfVector2f pos, sfVector2f scale)
{
    node_t *current = head_layer;

    do {
//        sfRenderTexture_drawCircleShape(GET_DATA(current, layer_t)->render_texture, circle, NULL);

        sfSprite_setTexture(GET_DATA(current, layer_t)->render_sprite, GET_DATA(current, layer_t)->texture_render_texture, sfTrue);

        sfSprite_setPosition(GET_DATA(current, layer_t)->render_sprite, pos);
        sfSprite_setScale(GET_DATA(current, layer_t)->render_sprite, scale);

        sfRenderWindow_drawSprite(window, GET_DATA(current, layer_t)->render_sprite, NULL);
        current = current->next;
    } while (current != head_layer);
}

// ?      sfSprite *renderSprite = sfSprite_create();
// ?      sfTexture *renderTextureTexture = sfRenderTexture_getTexture(renderTexture);

// ?      sfRenderTexture_drawCircleShape(renderTexture, circle, NULL);
// ?      sfSprite_setTexture(renderSprite, renderTextureTexture, sfTrue);
// ?      sfRenderWindow_drawSprite(window, renderSprite, NULL);
