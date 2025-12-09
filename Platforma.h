#pragma once
#include <SFML/Graphics.hpp>

class Platforma
{
private:
    sf::RectangleShape shape;
    float speed;

public:
    Platforma(float width, float height, sf::Color color, sf::Vector2f startPos, float speed);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderTarget& target);

    void setPosition(const sf::Vector2f& pos) { shape.setPosition(pos); }
    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }
};