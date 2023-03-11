/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** save_image
*/

#ifndef SAVE_IMAGE_H_
    #define SAVE_IMAGE_H_

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    char *path;
    sfText *text;
    sfFont *font;
    sfVector2f pos_text;
    char *content_text;
    char *font_path;
    bool can_click;
    bool validate;
} selection_extension_button_t;

extern selection_extension_button_t selection_extension_button[];
extern const int size_selection_extension_button;

#endif /* !SAVE_IMAGE_H_ */
