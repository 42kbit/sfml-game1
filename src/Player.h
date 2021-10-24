#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace game{

class Player
{
public:
    Player(sf::RenderWindow& win);
    ~Player();

    inline sf::RectangleShape& getGFX() { return m_GFX; };

    void wing();

    void update();

    const float DRAG = 0.97f;
    const float PUNCH_FORCE = 10.f;

private:
    sf::Vector2f m_Velocity;
    sf::RectangleShape m_GFX;
};

}
#endif // PLAYER_H_INCLUDED
