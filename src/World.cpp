#include "World.h"

game::World::World(sf::RenderWindow& win)
: m_DefaultPipe("res/textures/pipe_default.png"),
  m_TopPipe("res/textures/pipe_corner_upview.png"),
  m_LowPipe("res/textures/pipe_corner_downview.png"),
  m_WindowRef(win)
{
}

void game::World::render(sf::RenderTarget& renderTarget)
{
    for(uint32_t i = 0; i < m_PipeLines.size(); i++)
        for(uint32_t j = 0; j < m_PipeLines[i].getSegments().size(); j++)
            renderTarget.draw(m_PipeLines[i].getSegments()[j].getGFX());
}

#include <cmath>

void game::World::addLine(float xPos, uint8_t pipeMap)
{
    game::PipeLine line(xPos, m_WindowRef.getSize().y / 8.f);
    for(uint32_t i = 0; i < line.getSegments().size(); i++)
    {
        uint8_t digit = pow(2, 7-i);
        line.getSegments()[i].setType((uint32_t)((pipeMap&digit) >> (7-i)) == 1? &m_DefaultPipe : nullptr);
    }
    m_PipeLines.push_back(line);
}
