#include <SFML/Graphics.h>

int main()
{
    // Create the window
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "My window", sfResize | sfClose, NULL);

    // Set the window size to a fixed value
    sfRenderWindow_setSize(window, mode);

    // Prevent the window from being resized
    sfRenderWindow_setSize(window, mode.width, mode.height);
sfRenderWindow_setSizeable
    // Run the main loop
    while (sfRenderWindow_isOpen(window))
    {
        // Handle events
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }
        }

        // Clear the window
        sfRenderWindow_clear(window, sfBlack);

        // Draw objects here

        // Display the window
        sfRenderWindow_display(window);
    }

    // Cleanup
    sfRenderWindow_destroy(window);

    return 0;
}
