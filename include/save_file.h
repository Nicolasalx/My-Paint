/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** save_file
*/

#ifndef SAVE_FILE_H_
    #define SAVE_FILE_H_

extern bool mouse_button_pressed_save_file;
extern bool mouse_button_released_save_file;
extern bool can_press;

void get_input_text_user(sfEvent *event, char *inputText, sfText *text);
void event_input_text_save_file(sfEvent *event, char *inputText, sfText *text);
void manage_event_save_file(sfRenderWindow *window, sfEvent *event,
    char *inputText, sfText *text);
sfBool is_mouse_over_rectangle_shape_save_file(
    sfRectangleShape *rectangle_shape, sfVector2i mouse_position_save);
void set_color_to_button_save(int i, int *index_can_draw);

#endif /* !SAVE_FILE_H_ */
