#include "Background.h"

game::Background::Background(sf::RenderWindow& win)
{
    sf::Texture* tex = new sf::Texture;
    tex->loadFromFile("res/textures/background.png");
    m_GFX.setTexture(tex);

    m_GFX.setSize(sf::Vector2f(win.getSize()));
}

game::Background::~Background()
{

}
