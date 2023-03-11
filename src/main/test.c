#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

#define MAX_TEXT_LENGTH 100

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Ma fenêtre", sfResize | sfClose, NULL);

    sfFont* font = FONT;
    sfText* text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){100, 100});

    char inputText[MAX_TEXT_LENGTH + 1] = "";
    size_t textLength = 0;

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }
            else if (event.type == sfEvtTextEntered)
            {
                if (event.text.unicode < 128 && textLength < MAX_TEXT_LENGTH)
                {
                    inputText[textLength] = (char)event.text.unicode;
                    inputText[textLength + 1] = '\0';
                    textLength++;
                    sfText_setString(text, inputText);
                }
            }
            else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyBackspace)
            {
                if (textLength > 0)
                {
                    inputText[textLength - 1] = '\0';
                    textLength--;
                    sfText_setString(text, inputText);
                }
            }
        }

        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_drawText(window, text, NULL);

        sfRenderWindow_display(window);
    }

    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    return 0;
}
