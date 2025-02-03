#include <SFML/Graphics.hpp>
#include "./include/player.h"

int main() {

    sf::RenderWindow window(sf::VideoMode({640, 480}), "My Window");
    window.setVerticalSyncEnabled(true);

    sf::CircleShape tri(80.f, 3);
    tri.setFillColor(sf::Color::Green);

    Player me(sf::Color::Green);



    bool moveRightDown = false;
    bool moveLeftDown = false;

    bool turnRightDown = false;
    bool turnLeftDown = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if ((keyPressed->scancode == sf::Keyboard::Scancode::D) && (!moveLeftDown)) {
                    moveRightDown = true;
                } else if ((keyPressed->scancode == sf::Keyboard::Scancode::A) && (!moveRightDown)) {
                    moveLeftDown = true;
                } else if ((keyPressed->scancode == sf::Keyboard::Scancode::Right) && (!turnLeftDown)) {
                    turnRightDown = true;
                } else if ((keyPressed->scancode == sf::Keyboard::Scancode::Left) && (!turnRightDown)) {
                    turnLeftDown = true;
                }

            } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {

                if (keyReleased->scancode == sf::Keyboard::Scancode::D) {
                    moveRightDown = false;
                } else if (keyReleased->scancode == sf::Keyboard::Scancode::A) {
                    moveLeftDown = false;
                } else if (keyReleased->scancode == sf::Keyboard::Scancode::Right) {
                    turnRightDown = false;
                } else if (keyReleased->scancode == sf::Keyboard::Scancode::Left) {
                    turnLeftDown = false;
                }
            }
        }

        if (moveRightDown) {
            me.moveRight(5);
        } else if (moveLeftDown) {
            me.moveLeft(5);
        }

        if (turnRightDown) {
            me.rotateRight(5);
        } else if (turnLeftDown) {
            me.rotateLeft(5);
        }

        window.clear(sf::Color::Black);
        window.draw(me.getPlayer());
        window.display();
    }
}



