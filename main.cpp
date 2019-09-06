#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
    Game game;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), GAME_NAME);

    window.setFramerateLimit(WIN_FRAMERATE);

    while (window.isOpen())
    {
        sf::Event event;
        //game.printToConsole(window); //ODKOMENTUJ PO INFO O MYSZCE
        game.update(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return 0;
                window.close();
            }
        }

        window.clear();
        game.printMap(window);
        window.display();
    }

    return 0;
}
