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

typedef struct icon_undo_redo_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path;
    void (*redirect)(void);
} icon_undo_redo_t;

extern sfRectangleShape *background;
extern node_t *head_layer;
extern node_t *selected_layer;

extern icon_undo_redo_t icon_undo_redo[];
extern const int size_icon_undo_redo;

void create_default_layer(void);
void create_new_layer(char *layer_name);
sfSprite *create_screen_shot(sfTexture *texture_render_texture);
void render_layer(sfRenderWindow *window);
void render_background(sfRenderWindow *window);
void render_overview(sfRenderWindow *window);
void ini_icon_undo_redo(void);
void display_undo_redo(sfRenderWindow *window);
void redo(void);
void undo(void);

#endif /* !LAYER_H_ */
