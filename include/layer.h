/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** layer
*/

#ifndef LAYER_H_
    #define LAYER_H_

    #include "my_linkedlist.h"
    #include "SFML/Graphics.h"
    #include "stdbool.h"
    #include "my_graphical.h"
    #include "ui_layer.h"

    #define BACKGROUND_OUTLINE_COLOR {50, 50, 50, 255}
    #define BACKGROUND_OUTLINE_THICKNESS 2.0f

    #define DEFAULT_LAYER_COLOR {255, 255, 255, 255}

    #define MAX_LAYER_NAME_SIZE 20
    #define DEFAULT_LAYER_NAME "layer_"

    #define OVERVIEW_BACKGROUND_OUTLINE_THICKNESS 6.0f

    #define UNDO_REDO_DISABLE_COLOR {255, 255, 255, 100}
    #define UNDO_REDO_ENABLE_COLOR {255, 255, 255, 255}
    #define UNDO_REDO_OVERED_COLOR {255, 255, 255, 170}
    #define UNDO_REDO_MAINTAIN_COLOR {200, 255, 200, 255}

    #define UNDO 0
    #define REDO 1

typedef struct {
    bool hidden;
    char layer_name[MAX_LAYER_NAME_SIZE];
    sfRenderTexture *render_texture;
    sfTexture *texture_render_texture;
    sfSprite *render_sprite;
    node_t *head_undo;
    node_t *current_version;
    ui_layer_t ui_layer;
} layer_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f offset;
    sfVector2f scale;
    anchor_t anchor;
    char *path;
    void (*redirect)(void);
    bool enable;
} icon_undo_redo_t;

extern sfRectangleShape *background;
extern node_t *head_layer;
extern node_t *selected_layer;
extern sfVector2f overview_pos;
extern sfVector2f overview_scale;

extern icon_undo_redo_t icon_undo_redo[];
extern const int size_icon_undo_redo;

void create_default_layer(void);
void create_new_layer(char *layer_name);
sfTexture *create_screen_shot(sfTexture *texture_render_texture);
void render_layer(sfRenderWindow *window);
void render_background(sfRenderWindow *window);
void render_overview(sfRenderWindow *window);
void create_undo_redo(void);
void render_undo_redo(sfRenderWindow *window);
void redo(void);
void undo(void);
char *create_layer_name(char *layer_name_str);
void save_change(void);
void create_ui_layer(layer_t *layer);

#endif /* !LAYER_H_ */
