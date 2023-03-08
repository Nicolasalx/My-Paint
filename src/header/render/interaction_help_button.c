/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"

void description_edit_menu(void)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {800, 600, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfFont* font;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "Description", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    if (!window)
        return;
    font = sfFont_createFromFile("game_data/font/JetBrainsMono-Regular.ttf");
    if (!font)
        return;

    sfText* description = sfText_create();
    char description_to_draw[] = "\t\tDescritpion\n";
    sfText_setString(description, description_to_draw);
    sfText_setFont(description, font);
    sfText_setCharacterSize(description, 50);

    sfText* str = sfText_create();
    char str_to_draw[] = "\n\n\n\n My_paint is a software application that allows users to\n create and edit digital images on their computers.\n\n"
    " The main features of our logiciel include the ability to\n draw, paint, and manipulate shapes, lines, and text.\n\n"
    " Paint provides a range of tools and brushes for users\n to use, including a pencil, brush, and eraser,\n as well as a range of fill and gradient options."
    "\n There is also a color palette that allows users to select\n and customize their preferred colors."
    "\n Additionally, the program includes a zoom function,\n making it easier to work on detailed areas of an image.";
    sfText_setString(str, str_to_draw);
    sfText_setFont(str, font);
    sfText_setCharacterSize(str, 22);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, (sfColor) {128, 128, 128, 255});
        sfRenderWindow_drawText(window, description, NULL);
        sfRenderWindow_drawText(window, str, NULL);
        sfRenderWindow_display(window);
    }
    sfText_destroy(description);
    sfText_destroy(str);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    return;
}

void about_edit_menu(void)
{
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {800, 600, desktop.bitsPerPixel};
    sfRenderWindow* window;
    sfFont* font;
    sfEvent event;
    int posX = (desktop.width - mode.width) / 2;
    int posY = (desktop.height - mode.height) / 2;
    window = sfRenderWindow_create(mode, "About", 0 | sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){posX, posY});
    if (!window)
        return;
    font = sfFont_createFromFile("game_data/font/JetBrainsMono-Regular.ttf");
    if (!font)
        return;

    sfTexture *texture_thibaud = sfTexture_createFromFile("game_data/creator/thibaud_creator.png", NULL);
    sfSprite *thibaud_creator = sfSprite_create();
    sfSprite_setTexture(thibaud_creator, texture_thibaud, sfTrue);
    sfSprite_setScale(thibaud_creator, (sfVector2f) {2, 2});
    sfSprite_setPosition(thibaud_creator, (sfVector2f) {70, 100});

    sfTexture *texture_nicolas = sfTexture_createFromFile("game_data/creator/nicolas_creator.png", NULL);
    sfSprite *nicolas_creator = sfSprite_create();
    sfSprite_setTexture(nicolas_creator, texture_nicolas, sfTrue);
    sfSprite_setScale(nicolas_creator, (sfVector2f) {2, 2});
    sfSprite_setPosition(nicolas_creator, (sfVector2f) {400, 100});

    sfText* description = sfText_create();
    char description_to_draw[] = "\t\t  About\n";
    sfText_setString(description, description_to_draw);
    sfText_setFont(description, font);
    sfText_setCharacterSize(description, 50);

    sfText* str = sfText_create();
    char str_to_draw[] = "\n\n\n\n\t\t\t   Thibaud CATHALA\t\t  Nicolas ALEXANDRE\n\n"
    "\t\t\t   Epitech Paris\t\t\tEpitech Paris\n"
    "\t\t\t   07 83 63 34 31\t\t   07 83 11 94 55"
    "\n\n\n\n\tthibaud.cathala@epitech.eu|nicolas1.alexandre@epitech.eu\n\n"
    " Hello, we are two computer software developers at epitech\n paris in the class of 2027.\n"
    " We carried out this graphic project in 3 weeks.\n\n\t\t\t\t\tEnjoy our software!";
    sfText_setString(str, str_to_draw);
    sfText_setFont(str, font);
    sfText_setCharacterSize(str, 22);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, (sfColor) {128, 128, 128, 255});
        sfRenderWindow_drawSprite(window, thibaud_creator, NULL);
        sfRenderWindow_drawSprite(window, nicolas_creator, NULL);
        sfRenderWindow_drawText(window, description, NULL);
        sfRenderWindow_drawText(window, str, NULL);
        sfRenderWindow_display(window);
    }
    sfText_destroy(description);
    sfText_destroy(str);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    return;
}

void interaction_menu_component(int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_mouse_over_rectangle_shape(help_menu_header[i].rectangle, mouse_pos)) {
        help_menu_header[i].redirect();
    }
}

void display_icon_help(sfRenderWindow *window)
{
    for (int i = 0; i < size_help_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape
            (window, help_menu_header[i].rectangle, NULL);
        interaction_menu_component(i);
        for (int i = 0; i < size_text_help_header; ++i) {
            sfRenderWindow_drawText(window, text_help_header[i].text, NULL);
        }
    }
}

void close_menu_help(int i, int *verif_close_menu)
{
    if (is_mouse_over_rectangle_shape
        (help_menu_header[i].rectangle, mouse_pos) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape
        (button_header[4].rectangle, mouse_pos) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_help_menu(sfRenderWindow *window, sfVector2i mouse_pos,
    bool is_button_pressed)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (is_button_pressed == true) {
        if (is_mouse_over_rectangle_shape
            (button_header[4].rectangle, mouse_pos)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_help(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_help_menu_header; ++i) {
            close_menu_help(i, &verif_close_menu);
        }
    }
    if (verif_close_menu == 0 && is_button_pressed == true) {
        verif_open_file_menu = false;
    }
}
