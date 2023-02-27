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

void main_loop(void);
void manage_event(sfRenderWindow *window, sfEvent *event);
void ini_all_data(void);
void create_all_data(void);
void free_all_data(void);

#endif /* !MY_H_ */
