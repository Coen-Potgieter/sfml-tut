
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "constants.h"

class Player {

private:
    sf::CircleShape body;
    sf::RectangleShape gun;
    sf::Vector2f pos;
    sf::Angle currRot;


    bool checkRotationBounds();
    uint8_t checkPositionBounds();

public:
    Player();
    ~Player();

    void moveLeft();
    void moveRight();
    void rotateRight();
    void rotateLeft();

    void draw(sf::RenderWindow& target) const;

};

#endif
