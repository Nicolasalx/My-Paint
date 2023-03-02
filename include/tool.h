/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** tool
*/

#ifndef TOOL_H_
    #define TOOL_H_

    #include "SFML/Graphics.h"

    #define DEFAULT_PENCIL_COLOR {0, 0, 0, 255}

typedef struct pencil_t {
    sfCircleShape *circle;
    float radius;
    sfColor color;
} pencil_t;

extern pencil_t pencil;

void create_all_tool(void);

void create_pencil(void);
void render_pencil(void);

#endif /* !TOOL_H_ */
