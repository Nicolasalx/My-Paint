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

    #define BG_COLOR {128, 128, 128, 255}
    #define DEFAULT_WINDOW_SIZE_X 1920
    #define DEFAULT_WINDOW_SIZE_Y 1080

    #define FPS 144

    #define FAIL 0
    #define SUCCESS 1

extern sfVector2i window_pos;
extern sfVector2u window_size;
extern sfVector2u render_sheet_res;
extern sfVector2f render_sheet_pos;
extern sfVector2f render_sheet_scale;
extern sfVector2i mouse_pos;
extern sfBool mouse_button_pressed;
extern sfBool mouse_button_maintain;
extern sfBool mouse_button_released;

void main_loop(void);
void update_window_data(sfRenderWindow *window, sfView *window_view);
void manage_event(sfRenderWindow *window, sfEvent *event, sfView *window_view);
void create_all_data(void);
void free_all_data(void);

#endif /* !MY_H_ */
