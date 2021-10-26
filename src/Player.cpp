#include "Player.h"

game::Player::Player(sf::RenderWindow& win)
{
    sf::Texture* birdTex = new sf::Texture;
    birdTex->loadFromFile("res/textures/bird.png");

    m_GFX.setTexture(birdTex);
    m_GFX.setSize(sf::Vector2f(60,40));
    m_GFX.setOrigin(m_GFX.getSize() / 2.f);
    m_GFX.setPosition(sf::Vector2f(win.getSize().x / 8, win.getSize().y / 2u));

    m_Velocity = {0.f, 0.f};
}

void game::Player::update()
{
    m_GFX.move(m_Velocity);

    if(m_Velocity.y < -1.f) // if flying up
        m_Velocity *= DRAG;
    m_Velocity.y += DRAG / 5.f;

    m_GFX.setRotation(m_Velocity.y * 5.f);
}

void game::Player::wing()
{
    m_Velocity = {0, -PUNCH_FORCE};
}

void game::Player::addScore(uint32_t value)
{
    m_Score += value;
}

game::Player::~Player()
{

}
