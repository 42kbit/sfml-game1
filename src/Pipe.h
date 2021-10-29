#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace game{

class PipeType
{
public:
    PipeType(std::string path)
    {
        m_Texture.loadFromFile(path);
    }

    inline sf::Texture& getTexture() { return m_Texture;};
private:
    sf::Texture m_Texture;
};

class PipeSegment
{
public:
    PipeSegment() : m_Type(nullptr) {};
    PipeSegment(PipeType* type)
    {
        setType(type);
    }

    void setType(PipeType* newType)
    {
         m_Type = newType;
         if(m_Type)
            m_GFX.setTexture(&m_Type->getTexture());
         else
            m_GFX.setFillColor(sf::Color::Transparent);
    };

    inline PipeType* getType() { return m_Type; };
    inline sf::RectangleShape& getGFX() { return m_GFX; };
private:
    PipeType* m_Type;

    sf::RectangleShape m_GFX;
};

class PipeLine
{
public:
    PipeLine(float xPos, float size)
    {
        for(uint32_t i = 0; i < m_Segments.size(); i++)
        {
            m_Segments[i].getGFX().setPosition(sf::Vector2f(xPos, i * size));
            m_Segments[i].getGFX().setSize(sf::Vector2f(size, size));
        }
    }

    PipeLine(PipeLine& other)
    {
        m_Segments = other.m_Segments;
    }

    const float MOVE_X_SPEED = -1.8f;

    void update()
    {
        move({MOVE_X_SPEED, 0});
    }

    void move(sf::Vector2f dp)
    {
        for(uint32_t i = 0; i < m_Segments.size(); i++){
            m_Segments[i].getGFX().move(dp);
        }
    }

    bool isOutOfView(){
        auto& zeroElementGFX = m_Segments[0].getGFX();
        if(zeroElementGFX.getPosition().x + zeroElementGFX.getSize().x < 0)
            return true;
        return false;
    }

    inline std::array<PipeSegment, 8>& getSegments() { return m_Segments; };
private:
    std::array<PipeSegment, 8> m_Segments;
};

}
#endif // PIPE_H_INCLUDED
