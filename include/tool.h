/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** tool
*/

#ifndef TOOL_H_
    #define TOOL_H_

    #include "SFML/Graphics.h"

    #define DEFAULT_PENCIL_RADIUS 10
    #define DEFAULT_PENCIL_COLOR {0, 0, 0, 255}

    #define DEFAULT_ERASER_RADIUS 10

    #define DEFAULT_BRUSH_RADIUS 10
    #define DEFAULT_BRUSH_COLOR {255, 0, 0, 150}

    #define DEFAULT_FEATHER_PEN_RADIUS 10
    #define DEFAULT_FEATHER_PEN_COLOR {0, 0, 0, 255}

typedef enum {
    PENCIL,
    ERASER,
    BRUSH,
    FEATHER_PEN,
    HAND,
    MOUSE
} tool_t;

typedef struct pencil_t {
    sfCircleShape *circle;
    float radius;
    sfColor color;
} pencil_t;

typedef struct eraser_t {
    sfCircleShape *circle;
    float radius;
} eraser_t;

typedef struct brush_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2u texture_size;
    float radius;
    sfColor color;
} brush_t;

typedef struct feather_pen_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2u texture_size;
    float radius;
    sfColor color;
} feather_pen_t;

extern tool_t selected_tool;

extern pencil_t pencil;
extern eraser_t eraser;
extern brush_t brush;
extern feather_pen_t feather_pen;

void create_all_tool(void);
void render_all_tool(void);

void create_pencil(void);
void render_pencil(void);

void create_eraser(void);
void render_eraser(void);

void create_brush(void);
void render_brush(void);

void create_feather_pen(void);
void render_feather_pen(void);

void render_hand(void);

#endif /* !TOOL_H_ */
