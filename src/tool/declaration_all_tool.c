/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_tool
*/

#include "tool.h"

tool_t selected_tool = ERASER;

pencil_t pencil = {
    .radius = DEFAULT_PENCIL_RADIUS,
    .color = DEFAULT_PENCIL_COLOR
};

eraser_t eraser = {.radius = DEFAULT_ERASER_RADIUS};

brush_t brush = {.radius = DEFAULT_BRUSH_RADIUS, .color = DEFAULT_BRUSH_COLOR};

feather_pen_t feather_pen = {
    .radius = DEFAULT_FEATHER_PEN_RADIUS,
    .color = DEFAULT_FEATHER_PEN_COLOR
};
