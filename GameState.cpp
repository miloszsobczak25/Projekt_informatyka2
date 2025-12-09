#include "GameState.h"
#include "Game.h"
#include <fstream>

void GameState::capture(const Platforma& platforma,
    const Pilka1& pilka,
    const std::vector<Cegla>& cegly)
{
    sf::FloatRect p = platforma.getBounds();
    paddlePosition = { p.left, p.top };

    ballPosition = pilka.getPosition();
    ballVelocity = pilka.getVelocity();

    blocks.clear();

    for (const auto& c : cegly)
    {
        BlockData b;
        sf::FloatRect r = c.getBounds();
        b.x = r.left;
        b.y = r.top;
        b.hp = c.getHP();
        blocks.push_back(b);
    }
}

bool GameState::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    file << paddlePosition.x << " " << paddlePosition.y << "\n";
    file << ballPosition.x << " " << ballPosition.y << " "
        << ballVelocity.x << " " << ballVelocity.y << "\n";

    file << blocks.size() << "\n";

    for (const auto& b : blocks)
        file << b.x << " " << b.y << " " << b.hp << "\n";

    return true;
}

bool GameState::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    file >> paddlePosition.x >> paddlePosition.y;
    file >> ballPosition.x >> ballPosition.y >> ballVelocity.x >> ballVelocity.y;

    int count;
    file >> count;

    blocks.clear();
    blocks.reserve(count);

    for (int i = 0; i < count; i++)
    {
        BlockData b;
        file >> b.x >> b.y >> b.hp;
        blocks.push_back(b);
    }

    return true;
}

void GameState::apply(Game& game) const
{
    game.applyState(*this);
}
