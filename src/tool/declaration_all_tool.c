/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** declaration_tool
*/

#include "tool.h"

tool_t selected_tool = BRUSH;

pencil_t pencil = {.radius = DEFAULT_PENCIL_RADIUS, .color = DEFAULT_PENCIL_COLOR};

eraser_t eraser = {.radius = DEFAULT_ERASER_RADIUS};

brush_t brush = {.radius = DEFAULT_BRUSH_RADIUS, .color = DEFAULT_BRUSH_COLOR};
