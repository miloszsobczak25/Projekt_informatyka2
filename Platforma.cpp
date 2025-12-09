#include "Platforma.h"

Platforma::Platforma(float width, float height, sf::Color color, sf::Vector2f startPos, float spd)
{
    shape.setSize({ width, height });
    shape.setFillColor(color);
    shape.setPosition(startPos);
    speed = spd;
}

void Platforma::update(const sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shape.move(-speed, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shape.move(speed, 0.f);

    float W = static_cast<float>(window.getSize().x);

    if (shape.getPosition().x < 0.f)
        shape.setPosition(0.f, shape.getPosition().y);

    if (shape.getPosition().x + shape.getSize().x > W)
        shape.setPosition(W - shape.getSize().x, shape.getPosition().y);
}

void Platforma::draw(sf::RenderTarget& target)
{
    target.draw(shape);
}
