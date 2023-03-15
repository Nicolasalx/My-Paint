/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** save_from_file
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
#include "save_file.h"

bool mouse_button_pressed_save_file = false;
bool mouse_button_released_save_file = false;
bool can_press = false;
sfVector2i mouse_position_save;

void interaction_button_save(sfRenderWindow *window, int *index_can_draw,
    char *inputText, int i)
{
    if (is_mouse_over_rectangle_shape_save_file(selection_extension_button[i].
        rectangle, mouse_position_save) == true &&
            mouse_button_pressed_save_file == true) {
        set_color_to_button_save(i, index_can_draw);
        if (selection_extension_button[i].validate == true && can_press ==
            true && my_strlen(inputText) > 0) {
            char str[40];
            my_strcpy(str, inputText);
            my_strcat(str, ".");
            my_strcat(str, selection_extension_button[* index_can_draw].
                content_text);
            export_image(str);
            sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_drawRectangleShape(window, selection_extension_button[i].
        rectangle, NULL);
    sfRenderWindow_drawText(window, selection_extension_button[i].text, NULL);
}

void loop_save_from_file(sfRenderWindow *window, sfEvent *event,
    char *inputText, sfText *text)
{
    int index_can_draw = 0;
    can_press = false;
    while (sfRenderWindow_isOpen(window)) {
        manage_event_save_file(window, event, inputText, text);
        sfRenderWindow_clear(window, (sfColor) {128, 128, 128, 255});
        mouse_position_save = sfMouse_getPositionRenderWindow(window);
        for (int i = 0; i < size_selection_extension_button; ++i) {
            interaction_button_save(window, &index_can_draw, inputText, i);
        }
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
}

void ini_text_save_from_file(int i)
{
    selection_extension_button[i].text = sfText_create();
    sfText_setFont(selection_extension_button[i].text, FONT);
    sfText_setCharacterSize(selection_extension_button[i].text, 25);
    sfText_setColor(selection_extension_button[i].text, sfBlack);
    sfText_setPosition(selection_extension_button[i].text,
        selection_extension_button[i].pos_text);
    sfText_setString(selection_extension_button[i].text,
        selection_extension_button[i].content_text);
}

void initialise_save_from_file(void)
{
    for (int i = 0; i < size_selection_extension_button; ++i) {
        selection_extension_button[i].rectangle = sfRectangleShape_create();
        sfRectangleShape_setOutlineThickness(selection_extension_button[i].
            rectangle, 3);
        sfRectangleShape_setOutlineColor(selection_extension_button[i].
            rectangle, (sfColor) {50, 50, 50, 255});
        sfRectangleShape_setSize(selection_extension_button[i].rectangle,
            selection_extension_button[i].size);
        sfRectangleShape_setFillColor(selection_extension_button[i].rectangle,
            selection_extension_button[i].color);
        sfRectangleShape_setPosition(selection_extension_button[i].rectangle,
            selection_extension_button[i].pos);
        ini_text_save_from_file(i);
    }
}

void save_from_file(void)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {800, 600, desktop.bitsPerPixel};
    sfRenderWindow* window;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "Save Image", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    sfEvent event;
    sfFont* font = FONT;
    sfText* text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){100, 100});
    char inputText[30] = "";
    initialise_save_from_file();
    loop_save_from_file(window, &event, inputText, text);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
}
