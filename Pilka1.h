#pragma once
#include <SFML/Graphics.hpp>
#include "Platforma.h"
#include "Cegla.h"
#include <vector>

class Pilka1
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Pilka1(float radius, sf::Color color, sf::Vector2f startPos, sf::Vector2f startVel);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderTarget& target);

    void odbijY();
    void odbijX();

    void setPosition(const sf::Vector2f& pos) { shape.setPosition(pos); }
    void setVelocity(const sf::Vector2f& vel) { velocity = vel; }

    sf::Vector2f getPosition() const { return shape.getPosition(); }
    sf::Vector2f getVelocity() const { return velocity; }
    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }

    void kolizjaZPlatforma(Platforma& platforma);
    void kolizjaZCegly(std::vector<Cegla>& cegly);

    void reset(const sf::Vector2f& pos, const sf::Vector2f& vel);
};
