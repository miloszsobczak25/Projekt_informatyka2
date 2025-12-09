#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu
{
private:
    std::vector<std::string> m_items;
    std::vector<sf::Text> m_texts;
    sf::Font m_font;
    int m_selected;

public:
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int getSelectedItem() const { return m_selected; }
};
