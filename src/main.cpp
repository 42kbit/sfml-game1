#include <SFML/Graphics.hpp>

#include "Player.h"
#include "World.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Event event;

    window.setFramerateLimit(60);

    game::Player player(window);
    game::World world(window);

    world.addLine(500, 0b11111011);

    player.wing();
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                player.wing();
        }

        player.update();

        window.clear();
            world.render(window);
            window.draw(player.getGFX());
        window.display();
    }

    return 0;
}
