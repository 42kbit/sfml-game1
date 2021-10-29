#include "Player.h"

game::Player::Player(sf::RenderWindow& win, World& world)
: m_WorldRef(world)
{
    sf::Texture* birdTex = new sf::Texture;
    birdTex->loadFromFile("res/textures/bird.png");

    m_GFX.setTexture(birdTex);
    m_GFX.setSize(sf::Vector2f(60,40));
    m_GFX.setOrigin(m_GFX.getSize() / 2.f);
    m_GFX.setPosition(sf::Vector2f(win.getSize().x / 8, win.getSize().y / 2u));

    m_Velocity = {0.f, 0.f};
}

static void lose()
{
    exit(0);
}

void game::Player::update()
{
    m_GFX.move(m_Velocity);

    if(m_Velocity.y < -0.1f) // if flying up
        m_Velocity.y = m_Velocity.y * DRAG;
    m_Velocity.y += 0.5f;

    m_GFX.setRotation(m_Velocity.y * 5.f);

    for(uint32_t i = 0; i < m_WorldRef.getPipeLines().size(); i++)
        for(uint32_t j = 0; j < m_WorldRef.getPipeLines()[i]->getSegments().size(); j++)
        {
            auto& currentSegment = m_WorldRef.getPipeLines()[i]->getSegments()[j];
            const auto& currentBounds = currentSegment.getGFX().getGlobalBounds();
            auto& playerPos = m_GFX.getPosition();

            if(playerPos.x > currentBounds.left && playerPos.x < currentBounds.left + currentBounds.width){
                if(currentSegment.getType() != nullptr &&
                   (playerPos.y > currentBounds.top && playerPos.y < currentBounds.top + currentBounds.height))
                {
                    lose();
                }
            }
        }
    if(m_GFX.getPosition().y < 0 || m_GFX.getPosition().y > m_WorldRef.getWindow().getSize().y)
        lose();
}

void game::Player::wing()
{
    m_Velocity = {m_Velocity.x, -PUNCH_FORCE};
}

void game::Player::addScore(uint32_t value)
{
    m_Score += value;
}

game::Player::~Player()
{

}
