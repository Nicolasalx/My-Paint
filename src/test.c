#include <SFML/Graphics.h>

void scrollHandle(sfRectangleShape* handle_rect, int scroll_amount, sfVector2f scrollbar_pos, sfVector2f scrollbar_size) {
    // Get the current position of the handle rectangle
    sfVector2f handle_pos = sfRectangleShape_getPosition(handle_rect);
    // Calculate the new position of the handle rectangle
    float handle_y = handle_pos.y + scroll_amount;
    // Make sure the handle stays within the bounds of the scrollbar
    if (handle_y < scrollbar_pos.y)
        handle_y = scrollbar_pos.y;
    else if (handle_y + sfRectangleShape_getSize(handle_rect).y > scrollbar_pos.y + scrollbar_size.y)
        handle_y = scrollbar_pos.y + scrollbar_size.y - sfRectangleShape_getSize(handle_rect).y;
    // Set the new position of the handle rectangle
    sfRectangleShape_setPosition(handle_rect, (sfVector2f){handle_pos.x, handle_y});
}

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Scrollbar", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    // Define the size and position of the scrollbar rectangle
    sfVector2f scrollbar_pos = {700, 50};
    sfVector2f scrollbar_size = {20, 500};

    // Create the scrollbar rectangle
    sfRectangleShape* scrollbar_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(scrollbar_rect, scrollbar_pos);
    sfRectangleShape_setSize(scrollbar_rect, scrollbar_size);
    sfRectangleShape_setFillColor(scrollbar_rect, sfColor_fromRGB(150, 150, 150));

    // Create the scrollbar handle rectangle
    sfVector2f handle_pos = {700, 100};
    sfVector2f handle_size = {20, 100};
    sfRectangleShape* handle_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(handle_rect, handle_pos);
    sfRectangleShape_setSize(handle_rect, handle_size);
    sfRectangleShape_setFillColor(handle_rect, sfColor_fromRGB(200, 200, 200));

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (event.type == sfEvtMouseWheelScrolled) // Handle mouse wheel scrolling
            {
                int scroll_amount = event.mouseWheelScroll.delta * -10;
                scrollHandle(handle_rect, scroll_amount, scrollbar_pos, scrollbar_size);
            }
        }

        sfRenderWindow_clear(window, sfBlack);

        // Draw the scrollbar rectangles
        sfRenderWindow_drawRectangleShape(window, scrollbar_rect, NULL);
        sfRenderWindow_drawRectangleShape(window, handle_rect, NULL);

        sfRenderWindow_display(window);
    }

    sfRectangleShape_destroy(scrollbar_rect);
    sfRectangleShape_destroy(handle_rect);
    sfRenderWindow_destroy(window);

    return 0;
}
