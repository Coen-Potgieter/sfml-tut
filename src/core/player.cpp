
#include "../include/player.h"

Player::Player(sf::Color inpCol) {

    color = inpCol;
    maxRot = MAX_ROT;
    moveAmount = MOVE_AMOUNT;
    rotAmount = ROT_AMOUNT;
    
    self = sf::CircleShape(80.f, 3);
    self.setPosition({ 100.f, 100.f });
    self.setOrigin({80.f, 80.f});
    self.setRotation(sf::degrees(0));
    std::cout << "Player Created..." << std::endl;
}

Player::~Player() {
    std::cout << "Player Destroyed..." << std::endl;
}


// 0 all good
// 1 too far right
// 2 too far left
uint8_t Player::checkRotationBounds() {

    sf::Angle currRot = self.getRotation();

    if (currRot.asDegrees() >= maxRot) {

        if (currRot.asDegrees() >= (360 - maxRot)) {
            return 0;
        } 

        if (currRot.asDegrees() > 180) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void Player::moveLeft() {
    self.move({-moveAmount, 0});

}
void Player::moveRight() {
    self.move({moveAmount, 0});
}

void Player::rotateRight() {
    self.rotate(sf::degrees(rotAmount));

    uint8_t rotStatus = checkRotationBounds();
    if (rotStatus == 0) {
        return;
    } else if (rotStatus == 1) {
        self.setRotation(sf::degrees(maxRot));
    } else {
        self.setRotation(sf::degrees(360 - maxRot));
    }
}

void Player::rotateLeft() {

    self.rotate(sf::degrees(-rotAmount));
    uint8_t rotStatus = checkRotationBounds();
    if (rotStatus == 0) {
        return;
    } else if (rotStatus == 1) {
        self.setRotation(sf::degrees(maxRot));
    } else {
        self.setRotation(sf::degrees(360 - maxRot));
    }
}

sf::CircleShape Player::getPlayer() {
    return self;
}

