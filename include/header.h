/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #define SIZE_OUTLINE_BUTTON 2
    #define COLOR_OVERHEAD_HEADER (sfColor) {0, 204, 204, 255}

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} button_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_button_header_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} file_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_file_header_t;


typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} edit_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_edit_header_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} view_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_view_header_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} layer_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_layer_header_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
} help_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_help_header_t;

extern help_menu_header_t help_menu_header[];
extern const int size_help_menu_header;

extern text_help_header_t text_help_header[];
extern const int size_text_help_header;


extern edit_menu_header_t edit_menu_header[];
extern const int size_edit_menu_header;

extern text_edit_header_t text_edit_header[];
extern const int size_text_edit_header;

extern view_menu_header_t view_menu_header[];
extern const int size_view_menu_header;

extern text_view_header_t text_view_header[];
extern const int size_text_view_header;

extern layer_menu_header_t layer_menu_header[];
extern const int size_layer_menu_header;

extern text_layer_header_t text_layer_header[];
extern const int size_text_layer_header;

extern button_header_t button_header[];
extern const int size_button_header;

extern text_button_header_t text_button_header[];
extern const int size_text_button_header;

extern file_menu_header_t file_menu_header[];
extern const int size_file_menu_header;

extern text_file_header_t text_file_header[];
extern const int size_text_file_header;

void ini_file_menu_header(void);
void gestion_header_file_menu(sfRenderWindow *window,
    sfVector2i mouse_pos, bool is_button_pressed);
void gestion_header_edit_menu(sfRenderWindow *window,
    sfVector2i mouse_pos, bool is_button_pressed);
void gestion_header_view_menu(sfRenderWindow *window,
    sfVector2i mouse_pos, bool is_button_pressed);
void gestion_header_layer_menu(sfRenderWindow *window,
    sfVector2i mouse_pos, bool is_button_pressed);
void gestion_header_help_menu(sfRenderWindow *window,
    sfVector2i mouse_pos, bool is_button_pressed);
void gestion_header_menu(sfVector2i mouse_pos, bool is_button_pressed,
    int *stay_on_icon_header);
void management_button_header(sfRenderWindow *window, bool is_button_pressed,
    int *stay_on_icon_header);
void ini_help_text(void);
void ini_edit_menu_header_rectangle_icon(void);
void ini_layer_menu_header_rectangle_icon(void);
void ini_layer_text(void);
void ini_help_menu_header_rectangle_icon(void);
void ini_file_text(void);
void ini_edit_text(void);
void ini_edit_menu_header(void);
void ini_view_text(void);
void ini_button_header(void);
void ini_text_button_header(void);
void ini_file_menu_header(void);

#endif /* !HEADER_H_ */
