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

    #define BRUSH_SIZE_MULT 2.25f
    #define DEFAULT_BRUSH_RADIUS 10
    #define DEFAULT_BRUSH_COLOR {0, 0, 0, 150}

    #define FEATHER_PEN_SIZE_MULT 2.25f
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

typedef enum {
    CIRCLE_DRAW,
    RECTANGLE_DRAW,
    BRUSH_DRAW
} draw_mode_t;

typedef struct {
    sfCircleShape *circle;
    float radius;
    sfColor color;
    draw_mode_t draw_mode;
} pencil_t;

typedef struct {
    sfCircleShape *circle;
    float radius;
    draw_mode_t draw_mode;
} eraser_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2u texture_size;
    float radius;
    sfColor color;
    draw_mode_t draw_mode;
} brush_t;

typedef struct {
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
