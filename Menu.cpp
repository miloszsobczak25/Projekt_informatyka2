#include "Menu.h"

Menu::Menu(float width, float height)
{
    m_items = { "Nowa gra", "Wczytaj zapis", "Wyjscie" };
    m_selected = 0;

    m_font.loadFromFile("OpenSans-Regular.TTF");

    for (int i = 0; i < m_items.size(); i++)
    {
        sf::Text text;
        text.setFont(m_font);
        text.setString(m_items[i]);
        text.setCharacterSize(36);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        text.setPosition(width / 2 - 150, height / 2 + i * 50);
        m_texts.push_back(text);
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    for (auto& t : m_texts)
        window.draw(t);
}

void Menu::moveUp()
{
    if (m_selected > 0)
    {
        m_texts[m_selected].setFillColor(sf::Color::White);
        m_selected--;
        m_texts[m_selected].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (m_selected < m_items.size() - 1)
    {
        m_texts[m_selected].setFillColor(sf::Color::White);
        m_selected++;
        m_texts[m_selected].setFillColor(sf::Color::Red);
    }
}
