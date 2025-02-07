#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>
#include <SFML/Graphics.hpp>

// Window Config
constexpr uint16_t WINDOW_WIDTH = 800;
constexpr uint16_t WINDOW_HEIGHT = 800;

// Player Config
constexpr float PLAYER_SIZE = 20;
constexpr float MAX_ROT = 70;
constexpr float MOVE_AMOUNT = 2.3;
constexpr float ROT_AMOUNT = 2;
const sf::Color BODY_COL = sf::Color(113, 156, 178);
const sf::Color GUN_COL = sf::Color(31, 78, 116);
constexpr uint8_t AMMO_COUNT = 5;

// Bullet Config
constexpr float BULLET_SIZE = 20;
constexpr float BULLET_X_SCALE = 0.3;
constexpr float BULLET_SPEED = 2;
const sf::Color PLAYER_BULLET_COL = sf::Color::Green;
const sf::Color ENEMY_BULLET_COL = sf::Color::Red;

#endif
