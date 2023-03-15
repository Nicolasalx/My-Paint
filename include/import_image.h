/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** import_image
*/

#ifndef IMPORT_IMAGE_H_
    #define IMPORT_IMAGE_H_

    #include <SFML/Graphics.h>
    #include "header.h"

    #define INCREMATION_SIZE 30
    #define SIZE_EXTENSION 2
    #define MOVE_TEXT_SCREEN 20

extern sfVector2f pos_text;
extern bool key_up_pressed;
extern bool key_down_pressed;
extern bool state_button_pressed;
extern bool state_button_released;
extern char *path_to_open_dir;
extern bool can_free_dir;
extern char *new_path;
extern int new_size_path;
extern int size_name_of_file;
extern int size_already_name_malloc;

void directory_append_text(struct stat st, const char *path_of_file,
    node_t *head);
void file_append_text(struct stat st, const char *path_of_file,
    node_t *head, char **all_extension);
void detect_type_of_files(struct stat st, const char *filename,
    char **all_extension, node_t *head);
bool is_key_up_pressed_and_released(void);
bool is_key_down_pressed_and_released(void);
void manage_event_file(sfRenderWindow *window, sfEvent *event);
int create_window_from_file(node_t *head);
file_name_t *create_text(char *str, bool is_a_dir);
void event_text_display(node_t *head, node_t *current);
bool is_mouse_over_texte(sfText* text, sfRenderWindow* window);
void open_new_directory(struct stat st, char **all_extension, node_t *head);


#endif /* !IMPORT_IMAGE_H_ */
