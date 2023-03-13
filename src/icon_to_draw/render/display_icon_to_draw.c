/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** display_icon_to_draw
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"
#include <SFML/Graphics.h>
#include "save_image.h"
#include "icon_to_draw.h"

#include "math.h"

void set_circle_shape_draw(sfRenderWindow *window, int i, float *radius_size)
{
    sfCircleShape_setRadius(icon_to_draw[i].circle, * radius_size);
    sfVector2f circle_pos =
        sfCircleShape_getPosition(icon_to_draw[i].circle);
    float radius = sfCircleShape_getRadius(icon_to_draw[i].circle);
    float distance = sqrt((mouse_pos.x - circle_pos.x) *
        (mouse_pos.x - circle_pos.x) + (mouse_pos.y - circle_pos.y) *
            (mouse_pos.y - circle_pos.y));
    float percentage = distance / radius * 100;
    if (percentage > 100) {
        percentage = 100;
    }
    float new_x = mouse_pos.x - percentage * radius / 100;
    float new_y = mouse_pos.y - percentage * radius / 100;
    sfCircleShape_setPosition(icon_to_draw[i].circle, (sfVector2f)
        {new_x, new_y});
    sfRenderWindow_drawCircleShape(window, icon_to_draw[i].circle, NULL);
}

void pen_size_tool(sfRenderWindow *window, float *radius_size, int i)
{
    sfRenderWindow_setMouseCursorVisible(window, false);
    if (pencil.radius <= 30) {
        * radius_size = pencil.radius - 8.0f;
    } else if (pencil.radius > 30 && pencil.radius <= 80) {
        * radius_size = pencil.radius - 16.0f;
    } else if (pencil.radius > 80) {
        * radius_size = pencil.radius - 25.0f;
    }
    if (icon_to_draw[i].tool_to_select == PENCIL) {
        sfSprite_setPosition(icon_to_draw[i].sprite, (sfVector2f)
            {mouse_pos.x, mouse_pos.y - 50});
        sfRenderWindow_drawSprite(window, icon_to_draw[i].sprite, NULL);
        sfCircleShape_setOutlineColor(icon_to_draw[i].circle, pencil.color);
        set_circle_shape_draw(window, i, radius_size);
    }
}

void eraser_size_tool(sfRenderWindow *window, float *radius_size, int i)
{
    sfRenderWindow_setMouseCursorVisible(window, false);
    if (eraser.radius <= 30) {
        * radius_size = eraser.radius - 8.0f;
    } else if (eraser.radius > 30 && eraser.radius <= 80) {
        * radius_size = eraser.radius - 16.0f;
    } else if (eraser.radius > 80) {
        * radius_size = eraser.radius - 25.0f;
    }
    if (icon_to_draw[i].tool_to_select == ERASER) {
        sfSprite_setPosition(icon_to_draw[i].sprite, (sfVector2f)
            {mouse_pos.x, mouse_pos.y - 50});
        sfRenderWindow_drawSprite(window, icon_to_draw[i].sprite, NULL);
        sfCircleShape_setOutlineColor(icon_to_draw[i].circle,
            (sfColor) {128, 128, 128, 255});
        set_circle_shape_draw(window, i, radius_size);
    }
}

void brush_size_tool(sfRenderWindow *window, float *radius_size, int i)
{
    sfRenderWindow_setMouseCursorVisible(window, false);
    if (brush.radius <= 30) {
        * radius_size = brush.radius - 8.0f;
    } else if (brush.radius > 30 && brush.radius <= 80) {
        * radius_size = brush.radius - 16.0f;
    } else if (brush.radius > 80) {
        * radius_size = brush.radius - 25.0f;
    }
    if (icon_to_draw[i].tool_to_select == BRUSH) {
        sfSprite_setPosition(icon_to_draw[i].sprite, (sfVector2f)
            {mouse_pos.x, mouse_pos.y - 50});
        sfRenderWindow_drawSprite(window, icon_to_draw[i].sprite, NULL);
        sfCircleShape_setOutlineColor(icon_to_draw[i].circle, brush.color);
        set_circle_shape_draw(window, i, radius_size);
    }
}

void display_icon_to_draw(sfRenderWindow *window)
{
    for (int i = 0; i < size_icon_to_draw; ++i) {
        float radius_size = 0;
        switch (selected_tool) {
        case PENCIL:
            pen_size_tool(window, &radius_size, i);
        break;
        case ERASER:
            eraser_size_tool(window, &radius_size, i);
        break;
        case BRUSH:
            brush_size_tool(window, &radius_size, i);
            break;
        default: sfRenderWindow_setMouseCursorVisible(window, true);
            break;
        }
    }
}
