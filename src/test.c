#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfConvexShape* rectangle;

    // Créer une fenêtre
    window = sfRenderWindow_create(mode, "Arrondir les bords d'un rectangle avec sfConvexShape en CSFML en C", sfResize | sfClose, NULL);

    // Créer un rectangle
    rectangle = sfConvexShape_create();
    sfConvexShape_setPointCount(rectangle, 16); // Nombre de sommets
    sfConvexShape_setFillColor(rectangle, sfBlue);
    sfConvexShape_setPosition(rectangle, (sfVector2f){300, 250});

    // Définir les sommets du rectangle
    float width = 200;
    float height = 100;
    float radius = 20;
    sfVector2f point;
    for (int i = 0; i < 4; i++)
    {
        point.x = i % 2 ? width - radius : radius;
        point.y = i < 2 ? height - radius : radius;
        sfConvexShape_setPoint(rectangle, i * 4, point);
        sfConvexShape_setPoint(rectangle, i * 4 + 1, (sfVector2f){point.x + radius, point.y});
        sfConvexShape_setPoint(rectangle, i * 4 + 2, (sfVector2f){point.x + radius, point.y + radius});
        sfConvexShape_setPoint(rectangle, i * 4 + 3, (sfVector2f){point.x, point.y + radius});
    }

    while (sfRenderWindow_isOpen(window))
    {
        // Gérer les événements
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        // Rotation du rectangle
        sfConvexShape_setRotation(rectangle, 45);

        // Afficher le rectangle dans la fenêtre
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawConvexShape(window, rectangle, NULL);
        sfRenderWindow_display(window);
    }

    // Libérer les ressources
    sfConvexShape_destroy(rectangle);
    sfRenderWindow_destroy(window);

    return 0;
}
