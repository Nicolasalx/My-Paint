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

    #define FPS 60

    #define SIZE_IMAGE_X 1920
    #define SIZE_IMAGE_Y 1080

extern sfVector2u window_size;
extern sfVector2f render_window_pos;
extern sfVector2f render_window_scale;

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
void ini_file_menu_header(void);
void ini_icon_rectangle(void);
void ini_icon_sprite(void);
void ini_size_pen(void);
void ini_file_text(void);
void ini_edit_text(void);
void ini_edit_menu_header(void);
void ini_view_text(void);
void ini_edit_menu_header_rectangle_icon(void);

#endif /* !MY_H_ */
