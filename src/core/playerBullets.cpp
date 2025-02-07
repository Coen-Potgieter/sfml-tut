
#include "../include/playerBullets.h"

PlayerBullets::PlayerBullets(const uint8_t ammoCapacity) {
    shotIdx = 0;
    showBox = false;
    maxCap = ammoCapacity;

    std::cout << "Player Bullets Constructed..." << std::endl;
}

PlayerBullets::~PlayerBullets() {

    for (uint8_t i = 0; i < bullets.size(); i++) {
        delete bullets[i];
        bullets.erase(bullets.begin() + i);
    }
    std::cout << "Deleted All of Player's Bullets..." << std::endl;
}

void PlayerBullets::shoot(const sf::Vector2f& pos, const sf::Angle& direction){

    if (shotIdx >= maxCap) {
        std::cout << "No Bullets Remaining" << std::endl;
        return;
    }

    bullets.push_back(new Bullet(pos, direction, true));
    if (showBox) {
        bullets[shotIdx]->toggleBoundingBox();
    }
    shotIdx += 1;

}
void PlayerBullets::draw(sf::RenderWindow& target) {

    for (uint8_t i = 0; i < bullets.size(); i++) {
        if (bullets[i]->draw(target)) {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
            std::cout << "Bullet #" << i << " Destroyed..." << std::endl;
            shotIdx -= 1;
        }
    }
}

void PlayerBullets::toggleBoundingBox() {
    showBox = (!showBox);
    std::cout << "Toggled PlayerBullet's Hitbox" << std::endl;

    for (uint8_t i = 0; i < bullets.size(); i++) {
        bullets[i]->toggleBoundingBox();
    }
}
