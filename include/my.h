/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "my_error.h"
    #include "my_def.h"
    #include <SFML/Graphics.h>
    #include "data.h"

    #define BG_COLOR (sfColor) {.r = 128, .g = 128, .b = 128, .a = 255}
    #define DEFAULT_WINDOW_SIZE_X 1920
    #define DEFAULT_WINDOW_SIZE_Y 1080

extern sfVector2u window_size;

void main_loop(void);
void manage_event(sfRenderWindow *window, sfEvent *event);
void create_all_data(void);
void free_all_data(void);

void ini_bg_user_interface(void);
void ini_draw_img_user_interface(void);

void create_button(int i);
void init_all_button_selection(void);

void ini_chromatic_wheel(void);

void init_all_text_selection_color(void);

void ini_button_header(void);
void ini_text_button_header(void);

#endif /* !MY_H_ */
