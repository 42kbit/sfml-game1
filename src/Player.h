#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "World.h"

#include <cinttypes>

namespace game{

class Player
{
public:
    Player(sf::RenderWindow& win, World& world);
    ~Player();

    inline sf::RectangleShape& getGFX() { return m_GFX; };

    void wing();
    void update();

    void addScore(uint32_t value);
    inline uint32_t getScore() { return m_Score; };

    const float DRAG = 0.97f;
    const float PUNCH_FORCE = 10.f;

    const float PLAYER_X_SPEED = 4.f;

private:
    World& m_WorldRef;

    sf::Vector2f m_Velocity;
    sf::RectangleShape m_GFX;

    uint32_t m_Score;
};

}
#endif // PLAYER_H_INCLUDED
