/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** main_loop
*/

#include "my.h"
#include "header.h"
#include "my_graphical.h"
#include <stdio.h>
#include "toolbar.h"
#include "tool.h"

void select_tool_edit(int i)
{
    if (edit_menu_header[i].tool_draw_shape == false) {
        switch (edit_menu_header[i].tool_to_select) {
            case PENCIL:
                selected_tool = PENCIL;
                pencil.draw_mode = edit_menu_header[i].draw_mode;
                break;
            case ERASER:
                selected_tool = ERASER;
                eraser.draw_mode = edit_menu_header[i].draw_mode;
                break;
            default:
                break;
        }
    } else {
        switch (selected_tool)
        {
        case PENCIL:
            switch (edit_menu_header[i].draw_mode)
            {
                case RECTANGLE_DRAW:
                    pencil.draw_mode = RECTANGLE_DRAW;
                break;
                case CIRCLE_DRAW:
                    pencil.draw_mode = CIRCLE_DRAW;
                break;
                case BRUSH_DRAW:
                    pencil.draw_mode = BRUSH_DRAW;
                break;
            }
        
        break;
        
        
        case ERASER:
            switch (edit_menu_header[i].draw_mode)
            {
                case RECTANGLE_DRAW:
                    eraser.draw_mode = RECTANGLE_DRAW;
                break;
                case CIRCLE_DRAW:
                    eraser.draw_mode = CIRCLE_DRAW;
                break;
                case BRUSH_DRAW:
                    eraser.draw_mode = BRUSH_DRAW;
                break;
            }
            break;
        default:
            break;
        }

    }
}

void display_icon_edit(sfRenderWindow *window)
{
    for (int i = 0; i < size_edit_menu_header; ++i) {
        sfRenderWindow_drawRectangleShape(window,
            edit_menu_header[i].rectangle, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            is_mouse_over_rectangle_shape(edit_menu_header[i].rectangle)) {
            select_tool_edit(i);
        }
        for (int i = 0; i < size_text_edit_header; ++i) {
            sfRenderWindow_drawText(window, text_edit_header[i].text, NULL);
        }
    }
}

void close_menu_edit(int *verif_close_menu, int i)
{
    if (is_mouse_over_rectangle_shape
        (edit_menu_header[i].rectangle) == true)
        ++ *verif_close_menu;
    if (is_mouse_over_rectangle_shape
        (button_header[1].rectangle) == true) {
        ++ *verif_close_menu;
    }
}

void gestion_header_edit_menu(sfRenderWindow *window)
{
    static bool verif_open_file_menu = false;
    int verif_close_menu = 0;
    if (mouse_button_pressed == true) {
        if (is_mouse_over_rectangle_shape(button_header[1].rectangle)) {
            verif_open_file_menu = true;
        }
    }
    if (verif_open_file_menu == true) {
        display_icon_edit(window);
    }
    if (verif_open_file_menu == true) {
        for (int i = 0; i < size_edit_menu_header; ++i) {
            close_menu_edit(&verif_close_menu, i);
        }
    }
    if (verif_close_menu == 0 && mouse_button_pressed == true) {
        verif_open_file_menu = false;
    }
}
