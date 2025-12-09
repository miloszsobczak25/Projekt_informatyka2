#pragma once
#include <SFML/Graphics.hpp>

class Cegla
{
private:
    sf::RectangleShape shape;
    int zycia;

public:
    Cegla(float width, float height, sf::Color color, sf::Vector2f pos, int zyciaStart)
        : zycia(zyciaStart)
    {
        shape.setSize({ width, height });
        shape.setPosition(pos);
        setHP(zyciaStart);
    }

    void draw(sf::RenderTarget& target)
    {
        target.draw(shape);
    }

    sf::FloatRect getBounds() const
    {
        return shape.getGlobalBounds();
    }

    int getHP() const
    {
        return zycia;
    }

    bool czyZniszczona() const
    {
        return zycia <= 0;
    }

    void traf()
    {
        zycia--;
        setHP(zycia);
    }

    void setHP(int hp)
    {
        zycia = hp;

        if (zycia >= 3)
            shape.setFillColor(sf::Color::Green);
        else if (zycia == 2)
            shape.setFillColor(sf::Color::Yellow);
        else if (zycia == 1)
            shape.setFillColor(sf::Color::Red);
        else
            shape.setFillColor(sf::Color::Transparent);
    }
};
