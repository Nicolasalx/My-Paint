/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-thibaud.cathala
** File description:
** image
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <stdbool.h>

void import_image(char *image_path);
void export_image(char *image_name);
bool load_image(char *image_path);

#endif /* !IMAGE_H_ */
