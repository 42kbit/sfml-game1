#include <SFML/Graphics.hpp>

#include "Player.h"
#include "World.h"

#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::Event event;

    window.setFramerateLimit(60);

    game::World world(window);
    game::Player player(window, world);

    sf::Clock pipeClock;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                player.wing();
        }

        world.updatePipeLines();
        player.update();

        if(pipeClock.getElapsedTime().asSeconds() > 3.f){
            uint8_t nextPattern = 255 - pow(2, rand() % 8);
            world.addLine(window.getSize().x, nextPattern);
            pipeClock.restart();
        }

        window.clear();
            world.render(window);
            window.draw(player.getGFX());
        window.display();
    }

    return 0;
}
