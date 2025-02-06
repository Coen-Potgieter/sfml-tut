
#include "../include/player.h"

Player::Player() {

    // Create Shapes
    body = sf::CircleShape(PLAYER_SIZE);
    gun = sf::RectangleShape({static_cast<float>(PLAYER_SIZE / 2), PLAYER_SIZE});

    // Colours
    body.setFillColor(BODY_COL);
    gun.setFillColor(GUN_COL);

    // Set Origin For Gun Barrel Rotation
    sf::Vector2f gunOrigin = gun.getSize() + sf::Vector2f({-static_cast<float>(gun.getSize().x / 2), PLAYER_SIZE});
    gun.setOrigin(gunOrigin);

    // Entity Position & Rotation
    pos = { static_cast<float>(WINDOW_WIDTH/2.0), static_cast<float>(WINDOW_HEIGHT - PLAYER_SIZE*2 - PLAYER_SIZE*0.5)};
    currRot = sf::Angle(sf::degrees(0.f));

    // Set Pos & Rot
    body.setPosition(pos);
    sf::Vector2f gunOffset = {PLAYER_SIZE, PLAYER_SIZE};
    gun.setPosition(pos + gunOffset);
    gun.setRotation(currRot);

    std::cout << "Player Created..." << std::endl;
}

Player::~Player() {
    std::cout << "Player Destroyed..." << std::endl;
}

bool Player::checkRotationBounds() {
    return (!((currRot.asDegrees() < -MAX_ROT) || (currRot.asDegrees() > MAX_ROT)));
}

void Player::moveLeft() {
    body.move({-MOVE_AMOUNT, 0});
    gun.move({-MOVE_AMOUNT, 0});

}
void Player::moveRight() {
    body.move({MOVE_AMOUNT, 0});
    gun.move({MOVE_AMOUNT, 0});
}

void Player::rotateRight() {
    currRot += sf::degrees(ROT_AMOUNT);

    if (checkRotationBounds()) {
        gun.setRotation(currRot);
    } else {
        currRot -= sf::degrees(ROT_AMOUNT);
    }
}

void Player::rotateLeft() {
    currRot += sf::degrees(-ROT_AMOUNT);
    if (checkRotationBounds()) {
        gun.setRotation(currRot);
    } else {
        currRot -= sf::degrees(-ROT_AMOUNT);
    }
}


void Player::draw(sf::RenderWindow& target) const {
    target.draw(body);
    target.draw(gun);
}








