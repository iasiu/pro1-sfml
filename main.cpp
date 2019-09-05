#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "THE SETTLERS");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return 0; // a moze exit(0)?
                window.close();
            }
        }


        window.clear();
        window.display();
    }

    return 0;
}
