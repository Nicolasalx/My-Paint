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

sfVector2f pos_text = {0, 0};
bool key_up_pressed = false;
bool key_down_pressed = false;
bool state_button_pressed = false;
bool state_button_released = false;
char *path_to_open_dir = "\0";
bool can_free_dir = false;
