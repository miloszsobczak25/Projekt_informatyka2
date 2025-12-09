#include "Pilka1.h"
#include <cmath>

Pilka1::Pilka1(float radius, sf::Color color, sf::Vector2f startPos, sf::Vector2f startVel)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(startPos);
    velocity = startVel;
}

void Pilka1::update(const sf::RenderWindow& window)
{
    shape.move(velocity);

    float r = shape.getRadius();
    sf::Vector2f pos = shape.getPosition();
    float W = static_cast<float>(window.getSize().x);

    if (pos.x <= 0.f || pos.x + 2.f * r >= W)
        odbijX();

    if (pos.y <= 0.f)
        odbijY();
}

void Pilka1::draw(sf::RenderTarget& target)
{
    target.draw(shape);
}

void Pilka1::odbijY()
{
    velocity.y = -velocity.y;
}

void Pilka1::odbijX()
{
    velocity.x = -velocity.x;
}

void Pilka1::kolizjaZPlatforma(Platforma& platforma)
{
    if (shape.getGlobalBounds().intersects(platforma.getBounds()))
    {
        odbijY();

        float paddleCenter = platforma.getBounds().left + platforma.getBounds().width / 2.f;
        float hitPos = (shape.getPosition().x + shape.getRadius()) - paddleCenter;
        velocity.x = hitPos * 0.1f;
    }
}

void Pilka1::kolizjaZCegly(std::vector<Cegla>& cegly)
{
    for (auto it = cegly.begin(); it != cegly.end();)
    {
        if (shape.getGlobalBounds().intersects(it->getBounds()))
        {
            it->traf();
            odbijY();

            if (it->czyZniszczona())
                it = cegly.erase(it);
            else
                ++it;
        }
        else
        {
            ++it;
        }
    }
}

void Pilka1::reset(const sf::Vector2f& pos, const sf::Vector2f& vel)
{
    shape.setPosition(pos);
    velocity = vel;
}
