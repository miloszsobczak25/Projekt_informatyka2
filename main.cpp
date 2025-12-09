#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "GameState.h"

enum class AppState { Menu, Playing, Paused, Win, Exiting };

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
    window.setFramerateLimit(60);

    Menu menu(window.getSize().x, window.getSize().y);
    Game game;
    GameState snapshot;
    GameState loadedState;

    AppState state = AppState::Menu;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (state == AppState::Menu)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                        menu.moveUp();

                    if (event.key.code == sf::Keyboard::Down)
                        menu.moveDown();

                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        if (menu.getSelectedItem() == 0)
                        {
                            game.reset();
                            state = AppState::Playing;
                        }
                        else
                            state = AppState::Exiting;
                    }

                    if (event.key.code == sf::Keyboard::F9)
                    {
                        if (loadedState.loadFromFile("savegame.txt"))
                        {
                            loadedState.apply(game);
                            state = AppState::Playing;
                        }
                    }
                }
            }
            else if (state == AppState::Playing)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::P)
                    {
                        snapshot.capture(game.getPlatform(), game.getBall(), game.getBlocks());
                        state = AppState::Paused;
                    }

                    if (event.key.code == sf::Keyboard::F5)
                    {
                        GameState gs;
                        gs.capture(game.getPlatform(), game.getBall(), game.getBlocks());
                        gs.saveToFile("savegame.txt");
                    }

                    if (event.key.code == sf::Keyboard::Escape)
                        state = AppState::Menu;
                }
            }
            else if (state == AppState::Paused)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::P)
                        state = AppState::Playing;

                    if (event.key.code == sf::Keyboard::F5)
                    {
                        GameState gs;
                        gs.capture(game.getPlatform(), game.getBall(), game.getBlocks());
                        gs.saveToFile("savegame.txt");
                    }

                    if (event.key.code == sf::Keyboard::Escape)
                        state = AppState::Menu;
                }
            }
            else if (state == AppState::Win)
            {
                if (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Enter)
                {
                    game.reset();
                    state = AppState::Menu;
                }
            }
        }

        sf::Time dt = clock.restart();

        if (state == AppState::Playing)
        {
            game.update(dt, window);

            if (game.isGameOver(window))
                state = AppState::Menu;

            if (game.isWin())
                state = AppState::Win;
        }

        window.clear();

        if (state == AppState::Menu)
            menu.draw(window);
        else if (state == AppState::Playing)
            game.render(window);
        else if (state == AppState::Paused)
        {
            game.render(window);
            sf::Font font;
            font.loadFromFile("OpenSans-Regular.TTF");

            sf::Text t("PAUZA (P) | ZAPIS (F5)", font, 30);
            t.setFillColor(sf::Color::Yellow);
            t.setPosition(180, 300);
            window.draw(t);
        }
        else if (state == AppState::Win)
        {
            sf::Font font;
            font.loadFromFile("OpenSans-Regular.TTF");

            sf::Text t("WYGRANA! Wcisnij ENTER", font, 40);
            t.setFillColor(sf::Color::Green);
            t.setPosition(120, 260);
            window.draw(t);
        }

        window.display();

        if (state == AppState::Exiting)
            window.close();
    }

    return 0;
}
