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

    #define FPS 240

    #define SIZE_IMAGE_X 1920
    #define SIZE_IMAGE_Y 1080

extern sfRenderWindow *window;
extern sfVector2i window_pos;
extern sfVector2u window_size;
extern sfVector2f render_sheet_resolution;
extern sfVector2f render_sheet_pos;
extern sfVector2f render_sheet_scale;
extern sfVector2i mouse_pos;

void main_loop(void);
void manage_event(sfRenderWindow *window, sfEvent *event,
    bool *is_button_pressed);
void create_all_data(void);
void free_all_data(void);

#endif /* !MY_H_ */
