#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Pipe.h"

namespace game{

class World
{
public:
    World(sf::RenderWindow&);

    void render(sf::RenderTarget& renderTarget);

    void addLine(float xPos, uint8_t pipeMap);

    inline std::vector<PipeLine>& getPipeLines() { return m_PipeLines; };
private:
    std::vector<PipeLine> m_PipeLines;

    PipeType m_DefaultPipe;
    PipeType m_TopPipe;
    PipeType m_LowPipe;

    sf::RenderWindow& m_WindowRef;
};

}

#endif // WORLD_H_INCLUDED
