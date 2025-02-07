
#ifndef PLAYER_BULLETS_H
#define PLAYER_BULLETS_H

#include "bullet.h"
#include <stdint.h>
#include <vector>

class PlayerBullets {

private:

    std::vector<Bullet*> bullets;
    uint8_t shotIdx;
    uint8_t maxCap;
    bool showBox;



public:
    PlayerBullets(const uint8_t ammoCapacity);
    ~PlayerBullets();

    void shoot(const sf::Vector2f& pos, const sf::Angle& direction);
    void draw(sf::RenderWindow& target);
    void toggleBoundingBox();

};

#endif
