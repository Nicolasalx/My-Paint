#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "my_malloc.h"
#include "my_string.h"
#include "header.h"
#include "my_linkedlist.h"
#include "my.h"
#include "my_graphical.h"
#include "image.h"
#include "import_image.h"

bool is_key_up_pressed_and_released(void)
{
    static bool is_key_up_pressed = false;
    bool is_key_up_released = false;
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (!is_key_up_pressed) {
            is_key_up_pressed = true;
        }
    } else {
        if (is_key_up_pressed) {
            is_key_up_pressed = false;
            is_key_up_released = true;
        }
    }
    return is_key_up_released;
}

bool is_key_down_pressed_and_released(void)
{
    static bool is_key_down_pressed = false;
    bool is_key_down_released = false;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (!is_key_down_pressed) {
            is_key_down_pressed = true;
        }
    } else {
        if (is_key_down_pressed) {
            is_key_down_pressed = false;
            is_key_down_released = true;
        }
    }
    return is_key_down_released;
}

void manage_event_file(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        mouse_button_pressed = false;
        mouse_button_released = false;
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
            pos_text.y = 0;
        }
        if (event->type == sfEvtMouseButtonPressed) {
            state_button_pressed = true;
        }
        if (event->type == sfEvtMouseButtonReleased) {
            state_button_released = true;
        }
    }
}