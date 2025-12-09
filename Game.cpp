#include "Game.h"
#include "GameState.h"

Game::Game()
    : m_platforma(100.f, 15.f, sf::Color::Blue, { 350.f, 550.f }, 6.f),
    m_pilka(8.f, sf::Color::White, { 400.f, 300.f }, { 4.f, -4.f })
{
    reset();
}

void Game::reset()
{
    m_bloki.clear();

    const int cols = 10;
    const int rows = 5;
    const float brickWidth = 70.f;
    const float brickHeight = 20.f;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            sf::Vector2f pos(60.f + j * (brickWidth + 5.f), 50.f + i * (brickHeight + 5.f));
            m_bloki.emplace_back(brickWidth, brickHeight, sf::Color::Green, pos, 3);
        }
    }

    m_platforma = Platforma(100.f, 15.f, sf::Color::Blue, { 350.f, 550.f }, 6.f);
    m_pilka = Pilka1(8.f, sf::Color::White, { 400.f, 300.f }, { 4.f, -4.f });
}

void Game::applyState(const GameState& state)
{
    m_platforma.setPosition(state.paddlePosition);
    m_pilka.setPosition(state.ballPosition);
    m_pilka.setVelocity(state.ballVelocity);

    m_bloki.clear();

    for (const auto& b : state.blocks)
    {
        Cegla cegla(70.f, 20.f, sf::Color::Green, { b.x, b.y }, b.hp);
        cegla.setHP(b.hp);
        m_bloki.push_back(cegla);
    }
}

void Game::update(sf::Time dt, sf::RenderWindow& window)
{
    m_platforma.update(window);
    m_pilka.update(window);

    m_pilka.kolizjaZPlatforma(m_platforma);
    m_pilka.kolizjaZCegly(m_bloki);
}

bool Game::isGameOver(const sf::RenderWindow& window) const
{
    return m_pilka.getPosition().y > window.getSize().y;
}

void Game::render(sf::RenderTarget& target)
{
    for (auto& c : m_bloki)
        c.draw(target);

    m_platforma.draw(target);
    m_pilka.draw(target);
}
