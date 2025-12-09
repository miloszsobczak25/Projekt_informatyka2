#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Platforma.h"
#include "Pilka1.h"
#include "Cegla.h"
#include "BlockData.h"

class GameState;

class Game
{
private:
    Platforma m_platforma;
    Pilka1 m_pilka;
    std::vector<Cegla> m_bloki;

public:
    Game();

    void update(sf::Time dt, sf::RenderWindow& window);
    void render(sf::RenderTarget& target);

    bool isGameOver(const sf::RenderWindow& window) const;
    bool isWin() const { return m_bloki.empty(); }

    Platforma& getPlatform() { return m_platforma; }
    Pilka1& getBall() { return m_pilka; }
    std::vector<Cegla>& getBlocks() { return m_bloki; }

    void reset();
    void applyState(const GameState& state);
};
