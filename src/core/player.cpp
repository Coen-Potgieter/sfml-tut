
#include "../include/player.h"

Player::Player(sf::Color inpCol) {

    color = inpCol;
    self = sf::CircleShape(80.f, 3);
    self.setPosition({ 100.f, 100.f });
    self.setOrigin({80.f, 80.f});
    self.setRotation(sf::degrees(0));
    std::cout << "Player Created..." << std::endl;
}

Player::~Player() {
    std::cout << "Player Destroyed..." << std::endl;
}

bool Player::checkRotationBounds() {

    sf::Angle currRot = self.getRotation();
    if (currRot > sf::degrees(270)) {
        std::cout << "!!!!" << std::endl;
        return true;
    }
    return false;

}
void Player::moveLeft(const float dist) {
    self.move({-dist, 0});

}
void Player::moveRight(const float dist) {
    self.move({dist, 0});
}

void Player::rotateRight(const float angle) {
    if (checkRotationBounds()) {

    }
    self.rotate(sf::degrees(angle));
}

void Player::rotateLeft(const float angle) {
    if (checkRotationBounds()) {

    }
    self.rotate(sf::degrees(-angle));
}

sf::CircleShape Player::getPlayer() {
    return self;
}

