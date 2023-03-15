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
    #define DESCRIPTION true
    #define ABOUT false
    #define COLOR_BG 128, 128, 128, 255
    #define SIZE_BUTTON 120, 100
    #include "tool.h"
    

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
    void (*redirect)(void);
} file_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_file_header_t;

typedef struct {
    sfText *text;
    char *content_text;
    sfVector2f pos_text;
    bool is_a_dir;
} file_name_t;

typedef struct {
    sfRectangleShape *rectangle;
    sfColor color;
    sfVector2f pos;
    char *path;
    sfVector2f size;
    tool_t tool_to_select;
    draw_mode_t draw_mode;
    bool tool_draw_shape;
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
    void (*redirect)(void);
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
    void (*redirect)(void);
} help_menu_header_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *path;
    char *font_path;
} text_help_header_t;

typedef struct {
    sfText *text;
    char *content_text;
    int size_text;
    bool choose_option;
} option_text_menu_help_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    char *path_img;
} img_about_option_help_t;

extern option_text_menu_help_t option_text_menu_help[];
extern const int size_option_text_menu_help;

extern img_about_option_help_t img_about_option_help[];
extern const int size_img_about_option_help;

extern help_menu_header_t help_menu_header[];
extern const int size_help_menu_header;

extern text_help_header_t text_help_header[];
extern const int size_text_help_header;

extern file_name_t *file_name;

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
void gestion_header_file_menu(sfRenderWindow *window);
void gestion_header_edit_menu(sfRenderWindow *window);
void gestion_header_view_menu(sfRenderWindow *window);
void gestion_header_layer_menu(sfRenderWindow *window);
void gestion_header_help_menu(sfRenderWindow *window);
void gestion_header_menu(int *stay_on_icon_header);
void management_button_header(sfRenderWindow *window);
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

void new_file(void);
void open_file(void);
void save_img_file(void);
void exit_file(void);

void import_from_files(void);

void about_help_menu(void);
void description_help_menu(void);

void save_from_file(void);

#endif /* !HEADER_H_ */
