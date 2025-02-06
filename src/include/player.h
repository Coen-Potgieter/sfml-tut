
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "constants.h"

class Player {

private:
    sf::Color color;
    sf::CircleShape self;
    float maxRot;
    float moveAmount;
    float rotAmount;

    uint8_t checkRotationBounds();

public:
    Player(sf::Color inpCol);
    ~Player();

    void moveLeft();
    void moveRight();
    void rotateRight();
    void rotateLeft();


    sf::CircleShape getPlayer();

};

#endif
