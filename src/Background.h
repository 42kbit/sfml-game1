#include <SFML/Graphics.hpp>
#include <string>

namespace game{

class Background
{
public:
    Background(sf::RenderWindow& win);
    ~Background();

    inline sf::RectangleShape& getGFX() { return m_GFX; };
private:
    sf::RectangleShape m_GFX;
};

}
