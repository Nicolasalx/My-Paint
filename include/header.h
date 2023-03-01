/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #define SIZE_OUTLINE_BUTTON 2

typedef struct button_header_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} button_header_t;

typedef struct text_button_header_t {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_button_header_t;

typedef struct file_menu_header_t {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} file_menu_header_t;

extern button_header_t button_header[];
extern const int size_button_header;

extern text_button_header_t text_button_header[];
extern const int size_text_button_header;

extern file_menu_header_t file_menu_header[];
extern const int size_file_menu_header;


void ini_file_menu_header(void);


#endif /* !HEADER_H_ */
