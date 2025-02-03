
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {

private:
    sf::Color color;
    sf::CircleShape self;

    bool checkRotationBounds();

public:
    Player(sf::Color inpCol);
    ~Player();

    void moveLeft(const float dist);
    void moveRight(const float dist);
    void rotateRight(const float angle);
    void rotateLeft(const float angle);


    sf::CircleShape getPlayer();

};

#endif
