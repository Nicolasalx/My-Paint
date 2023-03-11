/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void initialise_img_about(void)
{
    for (int i = 0; i < size_img_about_option_help; ++i) {
        img_about_option_help[i].texture =
        sfTexture_createFromFile(img_about_option_help[i].path_img, NULL);
        img_about_option_help[i].sprite = sfSprite_create();
        sfSprite_setTexture(img_about_option_help[i].sprite,
            img_about_option_help[i].texture, sfTrue);
        sfSprite_setScale(img_about_option_help[i].sprite,
            img_about_option_help[i].size);
        sfSprite_setPosition(img_about_option_help[i].sprite,
            img_about_option_help[i].pos);
    }
}

void initialise_info_about(void)
{
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == ABOUT) {
            option_text_menu_help[i].text = sfText_create();
            sfText_setString(option_text_menu_help[i].text,
                option_text_menu_help[i].content_text);
            sfText_setFont(option_text_menu_help[i].text, FONT);
            sfText_setCharacterSize(option_text_menu_help[i].text,
                option_text_menu_help[i].size_text);
        }
    }
    initialise_img_about();
}

void display_loop_about(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, (sfColor) {128, 128, 128, 255});
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == ABOUT) {
            sfRenderWindow_drawText(window, option_text_menu_help[i].text,
                NULL);
        }
    }
    for (int i = 0; i < size_img_about_option_help; ++i) {
        sfRenderWindow_drawSprite(window, img_about_option_help[i].sprite,
            NULL);
    }
    sfRenderWindow_display(window);
}

void display_about_screen(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_isOpen(window)) {
        display_loop_about(window, event);
    }
    for (int i = 0; i < size_option_text_menu_help; ++i) {
        if (option_text_menu_help[i].choose_option == DESCRIPTION) {
            sfText_destroy(option_text_menu_help[i].text);
        }
    }
}

void about_help_menu(void)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {800, 600, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "About", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    initialise_info_about();
    display_about_screen(window, &event);
    sfRenderWindow_destroy(window);
    return;
}
