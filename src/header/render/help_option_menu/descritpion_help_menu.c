/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void initialise_info_description(void)
{
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == DESCRIPTION) {
            option_text_menu_help[i].text = sfText_create();
            sfText_setString(option_text_menu_help[i].text,
                option_text_menu_help[i].content_text);
            sfText_setFont(option_text_menu_help[i].text, FONT);
            sfText_setCharacterSize(option_text_menu_help[i].text,
                option_text_menu_help[i].size_text);
        }
    }
}

void display_loop_description(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, (sfColor) {128, 128, 128, 255});
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == DESCRIPTION) {
            sfRenderWindow_drawText(window, option_text_menu_help[i].text,
                NULL);
        }
    }
    sfRenderWindow_display(window);
}

void display_description_screen(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_isOpen(window)) {
        display_loop_description(window, event);
    }
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == DESCRIPTION) {
            sfText_destroy(option_text_menu_help[i].text);
        }
    }
}

void description_help_menu(void)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {800, 600, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "Description", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    initialise_info_description();
    display_description_screen(window, &event);
    sfRenderWindow_destroy(window);
    return;
}
