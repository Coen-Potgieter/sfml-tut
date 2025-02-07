
#include "../include/bullet.h"
Bullet::Bullet(const sf::Vector2f& spwnPoint, const sf::Angle& direction, const bool shotFromPlayer) {

    self = sf::CircleShape(BULLET_SIZE);
    self.setScale({BULLET_X_SCALE, 1.f});

    pos = spwnPoint;
    self.setPosition(pos);

    angle = direction;
    self.setRotation(angle);

    playerBullet = shotFromPlayer;

    if (playerBullet) {
        std::cout << "Player Bullet Shot..." << std::endl;
        self.setFillColor(PLAYER_BULLET_COL);

    } else {
        std::cout << "Enemy Bullet Shot..." << std::endl;
        self.setFillColor(ENEMY_BULLET_COL);
    }

    // Misc
    showBox = false;
    boundingBox = self.getGlobalBounds();

    moveX = BULLET_SPEED * std::sin(angle.asRadians());
    moveY = -BULLET_SPEED * std::cos(angle.asRadians());
}

Bullet::~Bullet() {
    if (playerBullet) {
        std::cout << "Player Bullet Destroyed..." << std::endl;
    } else {
        std::cout << "Enemy Bullet Destroyed..." << std::endl;
    }
}

void Bullet::move() {

    pos.y += moveY;
    pos.x += moveX;
    self.move({moveX, moveY});

    if (showBox) {
        boundingBox.position.y += moveY;
        boundingBox.position.x += moveX;
    }
}

bool Bullet::inBounds() const {
    return  (!((pos.x > WINDOW_WIDTH) || (pos.x < 0) || (pos.y < 0)));
}

// Will return true if needs to be destroyed else false
bool Bullet::draw(sf::RenderWindow& target) {
    this->move();
    if (inBounds()) {
        target.draw(self);
        if (showBox) this->drawBoundingBox(target);
        return false;
    } else {
        return true;
    }
}

void Bullet::toggleBoundingBox() {
    showBox = (!showBox);
    std::cout << "Toggled Hitbox" << std::endl;

    if (showBox) {
        boundingBox = self.getGlobalBounds();
    }
}
void Bullet::drawBoundingBox(sf::RenderWindow& target) const {

    sf::RectangleShape hitBox(boundingBox.size);
    hitBox.setPosition(boundingBox.position);
    hitBox.setFillColor(sf::Color::Transparent);
    hitBox.setOutlineThickness(3.f);
    hitBox.setOutlineColor(sf::Color::Red);

    target.draw(hitBox);
}

