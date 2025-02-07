
#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.h"

class Bullet {

private:

    bool playerBullet;
    sf::Vector2f pos;
    sf::Angle angle;
    sf::CircleShape self;
    bool showBox;
    sf::FloatRect boundingBox;

    void move();
    bool inBounds() const;

    void drawBoundingBox(sf::RenderWindow& target) const;

public:

    Bullet(const sf::Vector2f& spwnPoint, const sf::Angle& direction, const bool shotFromPlayer);
    ~Bullet();

    bool draw(sf::RenderWindow& target);
    void toggleBoundingBox();
    
};

#endif
