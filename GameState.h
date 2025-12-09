#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Platforma.h"
#include "Pilka1.h"
#include "Cegla.h"
#include "BlockData.h"

class Game;

class GameState
{
public:
    sf::Vector2f paddlePosition;
    sf::Vector2f ballPosition;
    sf::Vector2f ballVelocity;
    std::vector<BlockData> blocks;

    void capture(const Platforma& platforma, const Pilka1& pilka, const std::vector<Cegla>& cegly);
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
    void apply(Game& game) const;
};