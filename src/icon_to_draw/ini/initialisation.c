/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** initialisation
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

void initialise_icon_to_draw(int i)
{
    icon_to_draw[i].circle = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(icon_to_draw[i].circle, 2);
    sfCircleShape_setOutlineColor(icon_to_draw[i].circle, (sfColor) {128, 128, 128, 255});
    sfCircleShape_setFillColor(icon_to_draw[i].circle, icon_to_draw[i].color_circle);
    sfCircleShape_setPosition(icon_to_draw[i].circle, icon_to_draw[i].pos_circle);

    icon_to_draw[i].texture = sfTexture_createFromFile(icon_to_draw[i].path_img, NULL);
    icon_to_draw[i].sprite = sfSprite_create();
    sfSprite_setTexture(icon_to_draw[i].sprite, icon_to_draw[i].texture, sfTrue);
    sfSprite_setScale(icon_to_draw[i].sprite, icon_to_draw[i].size_sprite);
}

void create_all_icon_to_draw(void)
{
    
    for (int i = 0; i < size_icon_to_draw; ++i) {
        initialise_icon_to_draw(i);
    }
}
