#include <SFML/Graphics.hpp>
#include <stdint.h>
#include <iostream>
#include <unordered_map>
#include <array>

#include "./include/constants.h"
#include "./include/player.h"
#include "./include/bullet.h"

void updateMovement(std::unordered_map<sf::Keyboard::Scancode, uint8_t>& states, 
                    const sf::Keyboard::Scancode& keyPressed, 
                    const bool pressed);

int main() {

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "My Window", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    // Set up Player and Bullets
    Player me;
    int8_t ammoIdx = AMMO_COUNT - 1;
    std::array<Bullet*, AMMO_COUNT> playerBullets;
    for (int i = 0; i < AMMO_COUNT; i++) {
        playerBullets[i] = nullptr;
    }

    std::unordered_map<sf::Keyboard::Scancode, uint8_t> movementStates = {
        {sf::Keyboard::Scancode::D, 0},
        {sf::Keyboard::Scancode::A, 0},
        {sf::Keyboard::Scancode::Right, 0},
        {sf::Keyboard::Scancode::Left, 0},
    };


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();

            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

                if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {

                    if (ammoIdx < 0) {
                        std::cout << "No AMMO CUNT" << std::endl;
                    } else {
                        playerBullets[ammoIdx] = new Bullet({300.f, 300.f}, sf::degrees(0.f), true);
                        ammoIdx -= 1;
                        std::cout << "You Got: " << static_cast<int>(ammoIdx + 1) << "Left" << std::endl;
                    }

                } else if (keyPressed->scancode == sf::Keyboard::Scancode::B) {
                    me.toggleBoundingBox();
                    for (uint8_t i = 0; i < AMMO_COUNT; i++) {
                        if (playerBullets[i]) {
                            playerBullets[i]->toggleBoundingBox();
                        }
                    }
                } else {
                    updateMovement(movementStates, keyPressed->scancode, true);
                }
            } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                updateMovement(movementStates, keyReleased->scancode, false);
            }
        }

        if (movementStates[sf::Keyboard::Scancode::D] || movementStates[sf::Keyboard::Scancode::A]) {
            if (movementStates[sf::Keyboard::Scancode::D] > movementStates[sf::Keyboard::Scancode::A]) {
                me.moveRight();
            } else {
                me.moveLeft();
            } 
        }

        if (movementStates[sf::Keyboard::Scancode::Right] || movementStates[sf::Keyboard::Scancode::Left]) {
            if (movementStates[sf::Keyboard::Scancode::Right] > movementStates[sf::Keyboard::Scancode::Left]) {
                me.rotateRight();
            } else {
                me.rotateLeft();
            } 
        }

        window.clear(sf::Color::Black);
        me.draw(window);

        // Loop through bullets & draw if it exists
        for (uint8_t i = 0; i < AMMO_COUNT; i++) {

            if (playerBullets[i]) {
                if (playerBullets[i]->draw(window)) {
                    delete playerBullets[i];
                    playerBullets[i] = nullptr;
                    ammoIdx += 1;
                }
            }
        }
        window.display();
    }
}


void updateMovement(std::unordered_map<sf::Keyboard::Scancode, uint8_t>& states, 
                    const sf::Keyboard::Scancode& keyPressed, 
                    const bool pressed) {

    if (pressed) {
        if (keyPressed == sf::Keyboard::Scancode::D) {
            states[sf::Keyboard::Scancode::D] = (states[sf::Keyboard::Scancode::A]) ? 2 : 1;
            states[sf::Keyboard::Scancode::A] = (states[sf::Keyboard::Scancode::A]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::A) {
            states[sf::Keyboard::Scancode::A] = (states[sf::Keyboard::Scancode::D]) ? 2 : 1;
            states[sf::Keyboard::Scancode::D] = (states[sf::Keyboard::Scancode::D]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::Right) {
            states[sf::Keyboard::Scancode::Right] = (states[sf::Keyboard::Scancode::Left]) ? 2 : 1;
            states[sf::Keyboard::Scancode::Left] = (states[sf::Keyboard::Scancode::Left]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::Left) {
            states[sf::Keyboard::Scancode::Left] = (states[sf::Keyboard::Scancode::Right]) ? 2 : 1;
            states[sf::Keyboard::Scancode::Right] = (states[sf::Keyboard::Scancode::Right]) ? 1 : 0;
        }

    } else {
        states[keyPressed] = 0;
    }
}

