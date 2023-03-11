/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** ini_undo_redo
*/

#include "my.h"
#include "layer.h"

void create_icon_undo_redo(int i)
{
    icon_undo_redo[i].texture =
        sfTexture_createFromFile(icon_undo_redo[i].path, NULL);
    icon_undo_redo[i].sprite = sfSprite_create();
    sfSprite_setTexture(icon_undo_redo[i].sprite, icon_undo_redo[i].texture,
        sfTrue);
    sfSprite_setScale(icon_undo_redo[i].sprite, icon_undo_redo[i].size);
    sfSprite_setPosition(icon_undo_redo[i].sprite, icon_undo_redo[i].pos);
}

void ini_icon_undo_redo(void)
{
    for (int i = 0; i < size_icon_undo_redo; ++i) {
        create_icon_undo_redo(i);
    }
}
