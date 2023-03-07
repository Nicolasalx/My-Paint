/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** layer
*/

#ifndef LAYER_H_
    #define LAYER_H_

    #include "my_linkedlist.h"

    #define BACKGROUND_COLOR {200, 200, 200, 255}

    #define DEFAULT_LAYER_COLOR {255, 255, 255, 255}
    #define MAX_LAYER_NAME_SIZE 20

    #define OVERVIEW_POS {1611, 524}
    #define OVERVIEW_SCALE {0.14, 0.14}

typedef struct layer_t {
    bool hidden;
    char layer_name[MAX_LAYER_NAME_SIZE];
    sfRenderTexture *render_texture;
    sfTexture *texture_render_texture;
    sfSprite *render_sprite;
    node_t *head_undo;
} layer_t;

typedef struct undo_t {
    sfSprite *screen_shoot;
    bool is_active;
} undo_t;

extern sfRectangleShape *background;
extern node_t *head_layer;
extern node_t *selected_layer;

void create_default_layer(void);
void create_new_layer(char *layer_name);
sfSprite *create_screen_shot(sfTexture *texture_render_texture);
void render_layer(sfRenderWindow *window);
void render_background(sfRenderWindow *window);
void render_overview(sfRenderWindow *window);

#endif /* !LAYER_H_ */
